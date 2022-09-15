# -*- coding: utf-8 -*-
"""
Created on Thu Sep 15 13:20:46 2022

@author: Hammad Hassan
"""

def partialMult(arr1,arr2):
    zero="0"
    arr=[]*(len(arr1)+len(arr2))
    totalSum=0
    #Adding zero
    for i in reversed(range(len(arr1))):
        for j in range(i):
            arr1[j]=arr1[j]+zero
    for i in reversed(range(len(arr2))):
        for j in range(i):
            arr2[j]=arr2[j]+zero
    #Multiply the two array
    for x in reversed(range(len(arr1))):
        for y in reversed(range(len(arr2))):
            result=int(arr1[x])*int(arr2[y])
            print(result,"=",int(arr1[x]),"*",int(arr2[y]))
            arr.append(result)
    #Sum the numbers 
    for i in range(len(arr)):
        totalSum+=arr[i]   
    return totalSum
arr1=["1","2","3","4"]
arr2=["5","6","7","8"]
print(partialMult(arr1,arr2))

