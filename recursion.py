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
msg=sum(10)
print(msg)  
# print array of element
def printArray(arr,start,end):
    if(start==end):
        print(arr[start])
    else:
        print(arr[start])
        printArray(arr, start+1, end)

arr=[1,2,3,4,5,6,7,8,9,10]
printArray(arr, 0, len(arr)-1)
# calculating power function through recursion
def power(n,k):
    if(k==1):
        return n
    else:
        return n*power(n,k-1)
result=power(2, 5)
print(result)
#factorial of number using recursion
def recur_factorial(num):
    if(num<0):
        return -1
    elif (num == 0 or num == 1):
        return 1
    else:
        return num*recur_factorial(num-1)
num=int(input("Enter a number: "))
print("The factorial of",num,"is",recur_factorial(num))