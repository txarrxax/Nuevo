#! /usr/bin/env python3

import os
import requests
import json

path = "supplier-data/descriptions"
files = os.listdir(path)
url = "http://104.198.147.125/fruits/"

for file in files:
        if file.endswith(".txt"):
                with open(path+"/"+file) as f:
                        lines = []
                        for line in f:
                                lines.append(line)
                f.close()
                fruit = {"name": lines[0].replace("\n", ""), "weight": int(lines[1].replace(" lbs", "")), "description": lines[2].replace("\n", ""),
                    "image_name": file.replace(".txt", ".jpeg")}
                fruit_json = json.dumps(fruit, indent=2)

                response = requests.post(url, json=fruit_json)
                print(response)
