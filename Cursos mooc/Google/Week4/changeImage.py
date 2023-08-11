#!/usr/bin/env python3

import os
import sys
from PIL import Image

path = "supplier-data/images"

images = os.listdir(path)

for image in images:
        if image.endswith(".tiff"):
                im = Image.open(path+"/"+image)
                im.convert("RGB").resize((600,400)).save(path+"/"+image.replace(".tiff", ".jpeg"))