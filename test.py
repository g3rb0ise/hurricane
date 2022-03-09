#!/usr/bin/env python

import subprocess
import sys
import os

def getSHA256sumResult(path):
    """
    Execute sha256sum command and extract result
    """
    result = subprocess.run(['sha256sum', path], stdout=subprocess.PIPE)
    return result.stdout[0:64]
    
def getBinSumResult(binary,path):
    """
    Execute binary checksum and extract result
    """
    result = subprocess.run([binary,'checksum', path], stdout=subprocess.PIPE)
    return result.stdout[0:64]

def testChecksum(binary,path="./test/checksum"):
    """
    Test file checksum with bash command sha256sum
    """
    files = []
    for r,d,f in os.walk(path):
        for file in f:
            if file.endswith(".test"):
                files.append(os.path.join(r,file))
    for file in files:
        if getBinSumResult(binary,file) != getSHA256sumResult(file):
            print("\t[FAILED] "+file)
            return False
        else:
            print("\t[OK] "+file)
    return True

if len(sys.argv) != 2 :
    print("Usage : test.py <bin>")
else:
    print("[Test] checksum")
    if not testChecksum(sys.argv[1]):
        print(sys.stderr, "Test failed")
        exit(1)