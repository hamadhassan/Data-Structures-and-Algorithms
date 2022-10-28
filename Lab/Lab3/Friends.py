# -*- coding: utf-8 -*-
"""
Created on Sat Sep 24 06:58:45 2022

@author: Hammad Hassan
"""
A=[[1,4],[2,5],[7,9],[9,10],[6,10]]
#(a)
def friendSlower(arr):
    result=[]
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if(arr[j][0]<arr[i][1]):
                result.append(tuple((i+1,j+1)))
            elif(arr[i][1]==arr[j][0]):
                result.append(tuple((i+1,j+1)))  
    return result
print(friendSlower(A))
#(b)
def friendFaster(arr):
    result=[]
    for i in range(len(arr)-1):
        if(arr[i+1][0]<arr[i][1]):
            result.append(tuple((i+1,i+2)))
        elif(arr[i][1]==arr[i+1][0]):
            result.append(tuple((i+1,i+2)))  
        elif(arr[i+1][0]>arr[i][1]):
             result.append(tuple((i+2,i+3)))
    return result
print(friendFaster(A))