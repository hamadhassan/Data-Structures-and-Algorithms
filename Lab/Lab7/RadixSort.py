# -*- coding: utf-8 -*-
"""
Created on Wed Oct 19 12:55:55 2022

@author: Hammad Hassan
"""

def CountingSort(input,exp):
    k=len(input)
    count=[0]*(10)
    output=[0]*(k) 
    for i in range(0,k):
        j=input[i]//exp
        count[j%10] += 1
    for i in range(1,10):
        count[i]+=count[i-1]
    for i in range(k-1,-1,-1):
        j=input[i]//exp
        output[count[j % 10] - 1] = input[i]
        count[j % 10] -= 1
    for i in range(0, len(input)):
        input[i] = output[i]
def radixSort(input):
    maximum = max(input)
    exp = 1
    while maximum / exp >= 1:
        CountingSort(input, exp)
        exp *= 10
    return input

input = [110,45,65,50,90,602,24,2,66]
 

print(radixSort(input))