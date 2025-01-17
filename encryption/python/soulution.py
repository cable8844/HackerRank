#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'encryption' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def encryption(s) -> str:
    # Write your code here
    s = s.replace(" ", "")
    sqrt = math.sqrt(len(s))
    numRows = math.floor(sqrt)
    numColumns = math.ceil(sqrt)
    if len(s) != numRows * numColumns:
        numRows += 1
    
    result = ""
    for c in range(numColumns):
        for r in range(numRows):
            index = c + numColumns * r;
            if index >= len(s):
                break
            else:
                result += s[index] # Index is the column we are at + numColumns (makes up one row) * the current row we are on

        result += " "
        

    return result.strip()
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()

