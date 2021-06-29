#!usr/bin/env python3

import os
import zipfile

os.chdir(os.path.dirname(os.path.abspath(__file__)))
if not os.path.exists("./prebuilt/linux/libcef.so") and os.path.exists("./prebuilt/linux/libcef.zip"):
    with zipfile.ZipFile("./prebuilt/linux/libcef.zip", "r", zipfile.ZIP_DEFLATED) as f:
        f.extractall("./prebuilt/linux")
