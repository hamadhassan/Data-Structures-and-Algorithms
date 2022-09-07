# -*- coding: utf-8 -*-
"""
Created on Wed Sep  7 14:41:24 2022

@author: Hammad Hassan
"""
def sum(n):
    if(n==0):
        return n
    else:
        return n+sum(n-1)
   
print(sum(10))
# print array of element
def printArray(arr,start,end):
    if(start==end):
        print(arr[start])
    else:
        print(arr[start])
        printArray(arr, start+1, end)

arr=[1,2,3,4,5,6,7,8,9,10]
printArray(arr, 0, len(arr)-1)

