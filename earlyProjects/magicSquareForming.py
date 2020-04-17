#!/bin/python3

import math
import os
import random
import re
import sys
def diffSquares(unsolvedSquare, solvedSquare):
    diff = 0
    for i in range(3):
        for j in range(3):
            diff += abs(unsolvedSquare[i][j] - solvedSquare[i][j])
    return diff
def check(workingS):
    for i in workingS:
        if sum(workingS) != 15:
            return False
    for i in range(3):
        v = []
        for j in range(3):
            v += workings[j][i]
        if sum(v) != 15:
            return False
    if sum([x for i in range(5:])

def magicSquareRecur(unsolvedSquare, workingS, numbersFilled, x, y, used):
    if numbersFilled > 8:
        return diffSquares(unsolvedSquare, workingS)
    if numbersFilled < 6:
        if (x,y) = (1,1):
            return 10000
    
    minimum = 1000000
    if numbersFilled == 0:
        #try all the spots for 1
        for i in range(3):
            for j in range(3):
                for (dx, dy) in [(1,2), (2,1)]:
                    workingS[i][j] = 1
                    minimum = min(magicSquareRecur(unsolvedSquare, workingS, numbersFilled+1, (i+dx)%3, (j+dy)%3, set(1)), minimum)

                    workingS[i][j] = 0
        return minimum
    
    if numbersFilled > 5:
        s = set()
        for x in range(3):
            s.add(15 -  sum(workingS))
        if s != {4,5,6}:
            return 10000
        
        for i in range(3):
            for j in range(3):
                if workingS[i][j] == 0:
                    workingS[i][j] = 15 - sum(workingS[i])
        minimum = min(diffSquares(unsolvedSquare, solvedSquare), minimum)
    selection = [[1,2,3],[7,8,9],[4,5,6]]
    for val in set(selection[numbersFilled%3]) ^ used:
        for (dx, dy) in [(1,2), (2,1)]:
            workingS[(x+dx)%3][(y+dy)%3] = val
            minimum = min(magicSquareRecur(unsolvedSquare, workingS, numbersFilled+1, (x+dx)%3, (y+dy)%3, used + val), minimum )
            workingS[(x+dx)%3][(y+dy)%3] = 0
            
# Complete the formingMagicSquare function below.
def formingMagicSquare(s):
    return magicSquareRecur(s, [[0,0,0] for i in range(3)], 0)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()

