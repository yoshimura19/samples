#coding:utf-8

import sys

if len(sys.argv) <= 1:
    #print >> sys.stderr, "Usage: read2_en.py <input file>
    print "ERROR"
    sys.exit(1)

input_file_name = sys.argv[1]

line_count = 0
with open(input_file_name, "r") as f:
    for l in f.readlines():
        line_count += 1
        print ("%d:" % line_count), l.strip()
