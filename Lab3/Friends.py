# -*- coding: utf-8 -*-
"""
Created on Sat Sep 24 06:58:45 2022

@author: Hammad Hassan
"""
#(b)
def friendFaster(arr):
    result=[]
    
    return result


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
A=[[1,4],[2,5],[7,9],[9,10],[6,10]]
print(friendSlower(A))
print(friendFaster(A))