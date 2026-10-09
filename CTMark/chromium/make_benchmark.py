#!/usr/bin/env python3
"""Regenerates this benchmark from a Chromium compile-time benchmark bundle.

usage: make_benchmark.py <bundle dir> <tus.json> <files.json> <chromium checkout>

<tus.json> lists the translation units (entries with "src" and "command", as in the
bundle's tus/*.json), <files.json> the files they read, relative to the bundle's src/
(e.g. from `clang -M`). Copies those files to src/, writes tus.cmake, and collects the
license files of the projects the files come from (from a full Chromium checkout of the
same revision, since the bundle doesn't have them) into licenses/ and LICENSE.txt.
"""
import glob, json, os, re, shlex, shutil, sys

bundle, tus_json, files_json, checkout = sys.argv[1:5]
here = os.path.dirname(os.path.abspath(__file__))
src_in = os.path.join(bundle, 'src')
src_out = os.path.join(here, 'src')
files = json.load(open(files_json))

shutil.rmtree(src_out, ignore_errors=True)
for f in files:
    os.makedirs(os.path.dirname(os.path.join(src_out, f)), exist_ok=True)
    shutil.copyfile(os.path.join(src_in, f), os.path.join(src_out, f))

# Licenses.
SYSROOT = 'build/linux/debian_bullseye_amd64-sysroot/'
GEN = 'out/gnlinux/gen/'
SYSROOT_LICENSES = {  # Debian package -> license of the headers it ships
    'libc6-dev': 'LGPL-2.1-or-later (GNU C Library)',
    'libglib2.0-dev': 'LGPL-2.1-or-later (GLib)',
    'linux-libc-dev': 'GPL-2.0-only WITH Linux-syscall-note (Linux UAPI headers)',
    'libdbus-1-dev': 'AFL-2.1 OR GPL-2.0-or-later (D-Bus)',
    'x11proto-dev': 'MIT (X.Org)',
    'libx11-dev': 'MIT (X.Org)',
    'libxcb1-dev': 'MIT (X.Org)',
}


def readme_fields(d):
    fields = {}
    for line in open(os.path.join(checkout, d, 'README.chromium'), errors='replace'):
        m = re.match(r'(License|License File|Name):\s*(.*)', line)
        if m and m.group(1) not in fields:
            fields[m.group(1)] = m.group(2).strip()
    return fields


def project(path):
    """(project dir, license, [license files relative to the checkout]) for a source path."""
    if path.startswith(GEN):
        path = path[len(GEN):]  # Generated files belong to the project they're generated from.
    d = os.path.dirname(path)
    nearest_license = None  # For projects without third-party metadata.
    while d:
        if not nearest_license:
            for lf in ('LICENSE', 'LICENSE.txt', 'LICENSE.TXT', 'COPYING'):
                if os.path.isfile(os.path.join(checkout, d, lf)):
                    nearest_license = (d, os.path.join(d, lf))
                    break
        fields = {}
        if os.path.isfile(os.path.join(checkout, d, 'README.chromium')):
            fields = readme_fields(d)  # Some are just documentation, without fields.
        if 'License' in fields or 'Name' in fields:
            lic_files = []
            for lf in fields.get('License File', '').split(','):
                lf = lf.strip()
                if not lf or lf == 'NOT_SHIPPED':
                    continue
                lf = lf[2:] if lf.startswith('//') else os.path.join(d, lf)
                if os.path.isfile(os.path.join(checkout, lf)):
                    lic_files.append(lf)
            return d, fields.get('License', '?'), lic_files
        if d == 'third_party/blink':
            return d, 'BSD-2-Clause, BSD-3-Clause, LGPL-2.0-or-later, LGPL-2.1-or-later', \
                ['third_party/blink/LICENSE_FOR_ABOUT_CREDITS']
        if d == 'v8':
            return d, 'BSD-3-Clause', ['v8/LICENSE']
        d = os.path.dirname(d)
    if nearest_license:
        text = open(os.path.join(checkout, nearest_license[1]), errors='replace').read()
        bsd3 = 'Redistribution and use' in text and 'Neither the name' in text
        return nearest_license[0], 'BSD-3-Clause' if bsd3 else 'see license file', \
            [nearest_license[1]]
    return '', 'BSD-3-Clause', ['LICENSE']


sysroot_owner = {}
for m in glob.glob(os.path.join(checkout, SYSROOT, 'debian/*/DEBIAN/md5sums')):
    for line in open(m, errors='replace'):
        sysroot_owner[line.split(None, 1)[1].strip()] = m.split('/')[-3]

projects, packages = {}, {}
for f in files:
    if f.startswith(SYSROOT):
        pkg = sysroot_owner[f[len(SYSROOT):]]
        packages[pkg] = packages.get(pkg, 0) + 1
        continue
    d, lic, lic_files = project(f)
    p = projects.setdefault(d, {'license': lic, 'files': lic_files, 'count': 0})
    p['count'] += 1

lic_out = os.path.join(here, 'licenses')
shutil.rmtree(lic_out, ignore_errors=True)
md = ['# Licenses', '',
      'The files in src/ come from Chromium and the projects below, under these licenses.',
      'The license files are copied to licenses/, in the same layout as src/.', '',
      '| directory in src/ | files | license | license files |', '|---|---|---|---|']
for d, p in sorted(projects.items()):
    for lf in p['files']:
        os.makedirs(os.path.dirname(os.path.join(lic_out, lf)) or lic_out, exist_ok=True)
        shutil.copyfile(os.path.join(checkout, lf), os.path.join(lic_out, lf))
    md.append('| %s | %d | %s | %s |' % (d or '(Chromium)', p['count'], p['license'],
                                        ', '.join('licenses/' + lf for lf in p['files'])))
md += ['', 'Headers from the Debian bullseye sysroot (`src/%s`), by Debian package. The sysroot '
       "doesn't include the packages' copyright files; the headers carry their own license "
       'notices.' % SYSROOT.rstrip('/'), '', '| package | files | license |', '|---|---|---|']
md += ['| %s | %d | %s |' % (k, v, SYSROOT_LICENSES[k]) for k, v in sorted(packages.items())]
open(os.path.join(here, 'LICENSE.txt'), 'w').write('\n'.join(md) + '\n')


def clean(args):
    """Drops the compiler, Chromium's clang plugins, dependency file and output flags."""
    out, i = [], 1
    while i < len(args):
        x = args[i]
        if x == '-Xclang' and i + 1 < len(args) and (
                args[i + 1] in ('-add-plugin', '-load') or args[i + 1].startswith('-plugin-arg-')):
            i += 4  # -Xclang -add-plugin -Xclang <name>, etc.
            continue
        if x in ('-MF', '-o'):
            i += 2
            continue
        if x in ('-MMD', '-MD', '-c'):
            i += 1
            continue
        out.append(x)
        i += 1
    return out


lines = ['# Generated by make_benchmark.py. One chromium_tu(<name> <C|CXX> <source> <flags...>)',
         '# per translation unit; paths are relative to src/out/gnlinux.', '']
for n, tu in enumerate(json.load(open(tus_json))):
    args = shlex.split(tu['command'])
    lang = 'CXX' if args[0].endswith('++') else 'C'
    flags = [a for a in clean(args) if a != tu['src']]
    name = '%02d_%s' % (n, os.path.splitext(os.path.basename(tu['src']))[0])
    lines.append('chromium_tu(%s %s %s' % (name, lang, tu['src']))
    lines += ['  [==[%s]==]' % a for a in flags]
    lines.append(')')
open(os.path.join(here, 'tus.cmake'), 'w').write('\n'.join(lines) + '\n')
