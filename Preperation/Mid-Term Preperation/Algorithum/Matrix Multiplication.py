# -*- coding: utf-8 -*-
"""
Created on Mon Oct 24 17:42:28 2022

@author: Hammad Hassan
"""

##----------------------- libraries ----------------------------##
import numpy as np
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
# result=MatAdd(A,B)
# print(result)
##----------------------- (3) ----------------------------##
def MatAddPartial(A,B,start,size): 
    result =[]
    for i in range(start[0],size):
        sum=0
        for k in range(start[1],size):
            sum+=(int(A[i][k])+int(B[i][k]))
        result.append(sum)
    return result         
A=[(3,4),(2,5,2)]
B=[(3,4),(2,5,3)]
result=MatAddPartial(A,B,(2,3),2)
print(result)              
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
#*---------------------- Split the matrix ----------------*#
def split(matrix):
    row, col = matrix.shape
    row2, col2 = row//2, col//2
    return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]
##----------------------- (5) ----------------------------##           
def MatMulRecursive(A,B,n):#This function only work for 4-by-4 matrix
    if(len(A)==1):
        return int(A[0])*int(B[0])
    else:
        A11,A12,A21,A22=split(A)
        B11,B12,B21,B22=split(B)
        C11=MatMulRecursive(A11,B11,n//2)+MatMulRecursive(A12,B21,n//2)
        C12=MatMulRecursive(A11,B12,n//2)+MatMulRecursive(A12,B22,n//2)
        C21=MatMulRecursive(A21,B11,n//2)+MatMulRecursive(A22,B21,n//2)
        C22=MatMulRecursive(A21,B12,n//2)+MatMulRecursive(A22,B22,n//2)
    return C11,C12,C21,C22
A=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
B=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
result=MatMulRecursive(A, B,4)
# print(result)
##----------------------- (6) ----------------------------##           
def MatMulStrassen(A,B):#This function only work for 4-by-4 matrix
    if(len(A)==1):
        return int(A[0])*int(B[0])
    else:
        m = A.shape[0]   
        if (m % 2 == 1):
            A = np.pad(A, (0, 1), mode='constant')
            B = np.pad(B, (0, 1), mode='constant')
     
        n = int(np.ceil(m / 2))
        A11,A12,A21,A22=split(A)
        B11,B12,B21,B22=split(B)
        P1=MatMulStrassen(A11,B12-B22)
        P2=MatMulStrassen(A11+A22,B22)
        P3=MatMulStrassen(A21+A22,B11)
        P4=MatMulStrassen(A22,B21-B11)
        P5=MatMulStrassen(A11+A22,B11+B22)
        P6=MatMulStrassen(A12-A22,B21-B22)
        P7=MatMulStrassen(A11-A21,B11-B12)
        result = np.zeros((2 * n, 2 * n), dtype=np.int32)
        result[: n, : n] = P5 + P4 - P2 + P6
        result[: n, n:] = P1 + P2
        result[n:, : n] = P3 + P4
        result[n:, n:] = P1 + P5 - P3 - P7
    return result[: m, : m]
A=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
B=np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
result=MatMulStrassen(A, B)
# print(result)