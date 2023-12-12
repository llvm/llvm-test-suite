#!/bin/python3
import argparse
import os
import csv
import time

def parse_arguments():
    parser = argparse.ArgumentParser(description='Record data and calculate statistics.')
    parser.add_argument('--data', type=float, required=True, help='The data value to record.')
    parser.add_argument('--log-file', type=str, required=True, help='The file to log data to.')
    parser.add_argument('--label', type=str, required=True, help='The label for the data.')
    parser.add_argument('--time-stamp', type=str, required=False, help='The timestamp for the data.')
    
    args = parser.parse_args()
    return args

def read_existing_data(file_name):
    data = []
    if os.path.exists(file_name) and os.path.getsize(file_name) > 0:
        with open(file_name, 'r') as file:
            reader = csv.reader(file)
            for row in reader:
                if row and row[2].strip():
                    try:
                        data.append(float(row[2].strip()))
                    except ValueError:
                        continue
    return data

def calculate_average(data):
    if not data:
        return 0.0
    non_zero_data = [d for d in data if d != 0]
    if len(non_zero_data) == 0:
        return 0.0
    if len(non_zero_data) > 10:
        non_zero_data = non_zero_data[-10:]
    return sum(non_zero_data) / len(non_zero_data)

def calculate_percentage_difference(new_value, average):
    if average == 0:
        return 0.0
    return ((new_value - average) / average) * 100

def append_data(file_name, time_stamp, label, data):
    with open(file_name, 'a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([time_stamp, label, data])

def main():
    args = parse_arguments()
    
    data = args.data
    log_file = args.log_file
    label = args.label
    time_stamp = args.time_stamp if args.time_stamp else time.strftime("%Y-%m-%d %H:%M:%S")
    
    existing_data = read_existing_data(log_file)
    if not existing_data:
        average = data
        percentage_diff = 0.0
    else:
        average = calculate_average(existing_data)
        percentage_diff = calculate_percentage_difference(data, average)
    
    append_data(log_file, time_stamp, label, data)
    
    print(f"Average of the last 10 non-zero data points: {average:.3g}")
    print(f"Percentage difference from current data: {percentage_diff:.2f}%")

if __name__ == "__main__":
    main()
