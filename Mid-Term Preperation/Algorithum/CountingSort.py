# -*- coding: utf-8 -*-
"""
Created on Wed Oct 19 07:44:27 2022

@author: Hammad Hassan
"""
def key(value,minimumElement):
    return value-minimumElement

def CountingSort(input):
    maximum = int(max(input))
    minimum = int(min(input))
    k=maximum-minimum 
    count=[0]*(k+1)
    output=[0]*(len(input)) 
    for i in range(0,len(input)):
        j=key(input[i],minimum)
        count[j] += 1
    for i in range(1,k+1):
        count[i]+=count[i-1]
    for i in range(len(input)-1,-1,-1):
        j=key(input[i],minimum)
        count[j]-=1
        output[count[j]]=input[i]
    return output
input=[2,5,3,0,2,3,0,3]
print(CountingSort(input))