#! /usr/bin/env python3

import os
import datetime
import reports

path = "supplier-data/descriptions"
files = os.listdir(path)

for file in files:
        if file.endswith(".txt"):
                with open(path+"/"+file) as f:
                        lines = []
                        for line in f:
                                lines.append(line)
                f.close()
                text = lines[0] + lines[1]
