#!/usr/bin/env python3

import os
import sys
import getopt
import Functions
from colorama import Fore, Back, Style


def main(argv):
    binPath = None

    opts = Functions.GetOpt(argv, "r:")
    if None == opts:
        sys.exit(1)

    for opt, arg in opts:
        if opt == "-r":
            binPath = arg

    if not binPath:
        sys.exit(1)

    if not os.path.isabs(binPath):
        binPath = os.path.abspath(binPath)
    binDir = os.path.dirname(binPath)
    os.chdir(binDir)
    os.system(binPath)

    return True


if __name__ == "__main__":
    if not main(sys.argv[1:]):
        sys.exit(1)
