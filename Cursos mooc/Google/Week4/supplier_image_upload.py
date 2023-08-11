#! /usr/bin/env python3

import requests
import os

url = "http://localhost/upload/"
path = "supplier-data/images"

images = os.listdir(path)

for image in images:
        if image.endswith(".jpeg"):
                with open(path+"/"+image, 'rb') as im:
                        r = requests.post(url, files={'file': im})
