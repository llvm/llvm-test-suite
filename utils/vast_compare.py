import argparse
import json
import pandas as pd
import sys

def strip_name_fully(name):
    name = name.split("/")[-1]
    if name.endswith(".test"):
        name = name[:-5]
    return name

def read_json(filename):
    with open(filename) as raw:
        jsondata = json.load(raw)
        results: dict[str, (str, float)] = dict()

        if "tests" not in jsondata:
            print("%s: Could not find toplevel tests key")
            sys.exit(1)
        for test in jsondata["tests"]:
            name = strip_name_fully(test.get("name"))
            result = test.get("code")
            if name is None:
                sys.stderr.write("Error: Found unnamed test\n" % name)
                sys.exit(1)
            #if "metrics" not in test:
            #    print("Warning: '%s' has no metrics, skipping!" % name)
            #    continue
            metrics = test.get("metrics")
            if metrics is None:
                time = 0.0
            else:
                time = test.get("metrics").get("compile_time")
            results[name] = (result, time)
        return results
    print("Could not open file %s", filename)
    sys.exit(1)

def create_df(results: list[dict[str, (str, float)]], names):
    create_result = lambda code, time: str(time) if code == 'PASS' else "FAIL"
    results = [{k: create_result(*v) for k, v in result.items()} for result in results]
    df = pd.DataFrame.from_records(results, index=names).transpose().sort_index()
    size = df.index.size

    totals = []
    for column in df.columns:
        failed = df.value_counts(column)['FAIL']
        totals.append(str(size-failed) + '/' + str(size))

    return pd.concat([pd.DataFrame([totals], index=['TOTAL'], columns=names), df])

def main():
    parser = argparse.ArgumentParser(prog="vast_compare.py")
    parser.add_argument("--files")
    parser.add_argument("--columns")
    parser.add_argument("--output")
    config = parser.parse_args()
    results = [read_json(file) for file in config.files.split(',')]
    df = create_df(results, config.columns.split(','))
    with open(config.output + ".csv", "w") as res_csv:
        res_csv.write(df.to_csv())
    with open(config.output + ".md", "w") as res_csv:
        res_csv.write(df.to_markdown())

main()
