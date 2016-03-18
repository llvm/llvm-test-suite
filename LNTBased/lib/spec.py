#!/usr/bin/env python
# -*- Python -*-

import os
import shutil
import stat

# We import test functionity from LNT.
from lnt.tests import nt
from lnt.testing import TestSamples, PASS, FAIL, XFAIL
from lnt.testing.util import commands

# Implement cp -rf such that src can be both a file or a directory and if
# the dst exists create the file/dir under dst rather than rename on the
# fly.
def cp_rf(src, dst):
    if os.path.isfile(src):
        shutil.copy(src, dst)
    else:
        newdst = dst
        if os.path.exists(dst):
            newdst = os.path.join(dst, os.path.basename(src))
        shutil.copytree(src, newdst)

# Test module classes are currently required to subclass 'nt.TestModule'.
class TestModule(nt.TestModule):

    timeout = 5000

    def __init__(self):
        # The subdirectory name under externals E.g. CINT2006
        self.suite = 'C' + self.category.upper() + str(self.year)

        # Name to identify this LNT test, e.g. nts.LNT/CINT2006_ref/456.hmmer
        self.testname = "nts.LNT/%s_ref/%s" % (self.suite, self.benchmark)

        # Executable name, e.g. 456.hmmer.simple
        self.exe = self.benchmark + '.simple'

    def configure_test_suite(self, working_dir):
        args = [os.path.realpath(os.path.join(self.config.test_suite_root,
                                              'configure'))]
        if self.config.without_llvm:
            args.extend(['--without-llvmsrc', '--without-llvmobj'])
        else:
            args.extend(['--with-llvmsrc=%s' % self.config.llvm_src_root,
                         '--with-llvmobj=%s' % self.config.llvm_obj_root])

        if self.config.test_suite_externals:
            args.append('--with-externals=%s' %
                        os.path.realpath(self.config.test_suite_externals))

        return self.call(args, cwd=working_dir)

    def fail(self):
        return [TestSamples(self.testname + '.compile.status', [FAIL])]

    def copy_input_set(self, dest_dir, size):
        if size == 'train':
            input_set = self.train_input_set
        elif size == 'ref':
            input_set = self.ref_input_set
        else:
            fatal('only train and ref are supported for now')

        for f in input_set:
            cp_rf(os.path.join(self.datadir, f), dest_dir)

    def copy_output_set(self, dest_dir, size):
        if size == 'train':
            output_set = self.train_output_set
        else:
            output_set = self.ref_output_set

        for f in output_set:
            cp_rf(os.path.join(self.datadir, f), dest_dir)

    def run_safely(self, args, **kwargs):
        if kwargs.get('shell', False):
            argstr = args
        else:
            argstr = ' '.join(args)
            kwargs['shell'] = True

        if 'file_index' in kwargs:
            file_index = kwargs['file_index']
            # Remove so that it can be forwarded to self.call.
            del kwargs['file_index']
        else:
            file_index = 0

        # Generate a unique file for each training run (if requested)
        timeit = ['LLVM_PROFILE_FILE=run_%d.profraw' % file_index,
                  os.path.join(self.OBJROOT, 'tools', 'timeit-target')]

        cwd = kwargs.get('cwd',  os.getcwd())
        summary_file = os.path.join(cwd, 'summary_%d.time' % file_index)
        timeit.extend(['--limit-core', '0',
                       '--limit-cpu', str(self.timeout),
                       '--timeout', str(self.timeout),
                       '--limit-file-size', '104857600',
                       '--limit-rss-size', '838860800',
                       '--summary', summary_file])
        timeit.append(argstr)
        cmdstr = ' '.join(timeit)

        if self.config.remote:
            command_file = os.path.join(cwd, 'command_%d' % file_index)
            with open(command_file, 'w') as f:
                # Chdir here so that the redirects are put into CWD as well.
                remote_command = 'cd %s\n%s\n' % (cwd, cmdstr)
                print >>self.log, "command:", remote_command,
                f.write(remote_command)

            st = os.stat(command_file)
            os.chmod(command_file, st.st_mode | stat.S_IEXEC)

            res = self.call([self.config.remote_client,
                             '-l', self.config.remote_user,
                             self.config.remote_host,
                             '-p', str(self.config.remote_port),
                             command_file])

        else:
            kwargs['shell'] = True
            res = self.call(cmdstr, **kwargs)

        if res != 0:
            return (res, 0)

        summary = open(summary_file, 'r').readlines()
        status = [line.split()[1] for line in summary if line.startswith('exit')]
        assert len(status) == 1, 'incorrect exit status'
        time = [line.split()[1] for line in summary
                if line.startswith(self.config.test_time_stat)]
        assert len(time) == 1, 'incorrect ellapsed time'

        return (int(status[0]), float(time[0]))

    def execute_test(self, options, make_variables, config):
        MODULENAME = options['MODULENAME']
        self.SRCROOT = options['SRCROOT']
        self.config = config
        self.OBJROOT = options['OBJROOT']
        CC = options['CC']
        CFLAGS = options['CFLAGS']
        TEST_SUITE_EXTERNALS = config.test_suite_externals

        # test-suite-externals//speccpu2006/benchspec/CPU2006/400.perlbench vs
        # test-suite-externals//speccpu2000/benchspec/CINT2000/164.gzip
        suitedir = os.path.join(TEST_SUITE_EXTERNALS, 'speccpu' + str(self.year), 'benchspec')
        if self.year == '2000':
            suitedir = os.path.join(suitedir, 'C%s2000' % self.category.upper())
        else:
            suitedir = os.path.join(suitedir, 'CPU' + self.year)

        self.datadir = os.path.join(suitedir, self.benchmark, 'data')
        print >>self.log, "%s\n  options: %s\n\nmake variables: %s\n\n" % (self.testname, str(options), str(make_variables))

        if not os.path.exists(self.datadir):
            print >>self.log, "skipping, no source under externals"
            return []

        res = self.configure_test_suite(self.OBJROOT)
        if res != 0:
            return self.fail()

        make_cmd = ['make', '-k']
        make_cmd.extend('%s=%s' % (k,v) for k,v in make_variables.items())

        # RunSafely.sh requires timeit, build it.
        res = self.call(make_cmd + ['tools'], cwd=self.OBJROOT)
        if res != 0:
            return self.fail()

        make_cmd.append('USE_SPEC_TEST_MODULE=1')

        # Run make clean to create the benchmark directories.
        external_obj = os.path.join(self.OBJROOT, 'External', 'SPEC', self.suite, self.benchmark)
        clean_cmd = make_cmd
        external_spec_obj = os.path.split(external_obj)[0]
        result = self.call(make_cmd + ['-C', external_spec_obj, 'clean'])
        if result != 0:
            return self.fail()

        # From this on, we are operating in the 456.hmmer directory.
        make_cmd.extend(['-C', external_obj])
        exe_file = os.path.join('Output', self.exe)

        if config.spec_with_pgo:
            pgo_dir = os.path.join(self.OBJROOT, 'pgo')
            os.mkdir(pgo_dir)

            target_flags = make_variables['TARGET_FLAGS'] + ' -fprofile-instr-generate'
            pgo_make_cmd = make_cmd[:]
            pgo_make_cmd.append("TARGET_FLAGS=%s" % target_flags)
            result = self.call(pgo_make_cmd + [ exe_file ])

            exe = os.path.join(external_obj, exe_file)
            if result != 0 or not os.path.exists(exe):
                return self.fail()
            shutil.copy(exe, pgo_dir)

            self.copy_input_set(pgo_dir, 'train')

            for (i, args) in enumerate(self.train_args):
                pgo_cmd = './%s %s' % (self.exe, args)
                (result, time) = self.run_safely(pgo_cmd, cwd=pgo_dir, shell=True, env=os.environ, file_index=i)
                if result != 0:
                    return self.fail()
                if not os.path.exists(os.path.join(pgo_dir, 'run_%d.profraw' % i)):
                    print >>self.log, 'Failed to create PGO output'
                    return self.fail()

            llvm_profdata = os.path.join(os.path.dirname(CC), 'llvm-profdata')
            result = self.call(llvm_profdata + ' merge -output=code.profdata pgo/run_*.profraw', shell=True, cwd=self.OBJROOT)
            if result != 0:
                return self.fail()

            target_flags = make_variables['TARGET_FLAGS'] + ' -fprofile-instr-use=' + os.path.join(self.OBJROOT, 'code.profdata')
            make_cmd.append("TARGET_FLAGS=%s" % target_flags)

            result = self.call(make_cmd + ['-C', external_spec_obj, 'clean'])
            if result != 0:
                return self.fail()

        start_time = self.get_time()
        result = self.call(make_cmd + [ exe_file ])
        compile_time = self.get_time() - start_time

        exe = os.path.join(external_obj, exe_file)
        if result != 0 or not os.path.exists(exe):
            return self.fail()

        shutil.copy(exe, self.OBJROOT)

        self.copy_input_set(self.OBJROOT, 'ref')
        self.copy_output_set(self.OBJROOT, 'ref')

        run_cmds = ['./%s %s' % (self.exe, args) for args in self.ref_args]
        status = PASS

        exec_time = 0
        for (file_index, cmd) in enumerate(run_cmds):
            (result, time) = self.run_safely(cmd, cwd=self.OBJROOT, shell=True, file_index=file_index)
            if result != 0:
                status = FAIL
            exec_time += time

        os.environ['PATH'] += ':' + os.path.join(self.OBJROOT, 'tools')
        for cmd in self.ref_cmp_cmds:
            if self.call(cmd, cwd=self.OBJROOT, shell=True, env=os.environ) != 0:
                status = FAIL

        result =  [
            TestSamples(self.testname + '.compile', [compile_time]),
            TestSamples(self.testname + '.exec', [exec_time])]
        if status == FAIL:
            result.append(TestSamples(self.testname + '.exec.status', [status]))

        return result
