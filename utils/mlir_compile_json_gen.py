#!/usr/bin/env python

import json
import glob
import hashlib
import os

total_elapsed = 0

class test_result:
    code: str
    elapsed: float
    name: str

    def __init__(self, res_path):
        with open(res_path) as res:
            global total_elapsed
            lines = [line.rstrip() for line in res]
            code = int(lines[0].split()[1])
            base_name = os.path.splitext(res_path)[0]

            self.elapsed = float(lines[2].split()[1]) # get user time
            total_elapsed += self.elapsed

            self.metrics = dict([
                ("compile_time", self.elapsed),
                ("exec_time", 0.0)
                ])
            if (code == 0):
                mlir_file = base_name + '.mlir'
                h = hashlib.md5()
                h.update(open(mlir_file , "rb").read())
                self.metrics["hash"] = h.hexdigest()

            self.name = "test-suite :: " + base_name + ".test"

            if (code != 0):
                self.code = "FAIL"
            else:
                self.code = "PASS"

    def __str__(self):
        return "code: " + self.code + " elapsed: " + str(self.elapsed) + " name: " + name

def obj_dict(obj):
    return obj.__dict__

def main():
    results = glob.iglob('**/*.time', recursive = True)
    tests = [test_result(result) for result in results]
    data = dict([
        ("elapsed", total_elapsed),
        ("tests", tests)
        ])
    print(json.dumps(data, default = obj_dict, indent = 2))

main()
