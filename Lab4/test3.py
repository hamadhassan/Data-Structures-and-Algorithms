# -*- coding: utf-8 -*-
"""
Created on Fri Sep 30 6:30:00 2022

@author: Hammad Hassan
"""
##----------------------- libraries ----------------------------##

##----------------------- (1) ----------------------------##
def printMatrix(A,starting_Index,row,colums):
     for i in range(starting_Index[0],row):
         for j in range(starting_Index[1],colums):
             print(A[i][j],end=(" "))
         print()
A=[[3,4,5],[2,5,7]]
starting_index=(0,0)
row=2 #Number of row wants to print
column=3 #Number of Column wants to print
# printMatrix(A,starting_index,row,column) 
##----------------------- (2) ----------------------------##
def MatAdd(A,B): #Function only work for square matrix
    n=len(A)
    result = [0]*n
    if(n==len(B)):
        for i in range(n):
            sum=0
            for k in range(n):
                sum+=(int(A[i][k])+int(B[i][k]))
            result[i]=sum
    return result
A=[(3,4),(2,5)]
B=[(3,4),(2,5)]
result=MatAdd(A,B)
# print(result)
##----------------------- (3) ----------------------------##
def MatAddPartial(A,B,start,size): 
    result =[]
    for i in range(start,size):
        sum=0
        for k in range(start,size):
            sum+=(int(A[i][k])+int(B[i][k]))
        result.append(sum)
    return result         
A=[(3,4),(2,5)]
B=[(3,4),(2,5)]
result=MatAddPartial(A,B,0,1)  
# print(result)              
##----------------------- (4) ----------------------------##           
def MatMul(A,B): #Function only work for square matrix
    n=len(A)
    result = [[0]*n]*n
    if(n==len(B)):
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    result[i][j]=result[i][j]+(int(A[i][k])*int(B[k][j]))  
    return result
A=[(3,4),(2,5)]
B=[(3,4),(2,5)]
# result=MatMul(A,B)
# printMatrix(result,(0,0),2,2)             