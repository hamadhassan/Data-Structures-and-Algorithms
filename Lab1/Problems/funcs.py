# -*- coding: utf-8 -*-
"""
Created on Fri Sep  9 5:45:15 2022

@author: Hammad Hassan
"""
import numpy as np 
#Prob1
def SearchA(Arr,x):
    searchArr=[]
    for i in range(len(Arr)):
        if(x==Arr[i]):
            searchArr.append(i)
    return searchArr
#Prob2
def SearchA(Arr,x):
    searchArr=[]
    for i in range(len(Arr)):
        if(x==Arr[i]):
            searchArr.append(i)
    return searchArr
#Prob3
def Minimum(Arr,starting,ending):
    minNum=Arr[starting]
    index=starting;
    for starting in range(ending+1):
        if(Arr[starting]<minNum):
            minNum=Arr[starting]
            index=starting;
    return index
#Prob4
def Sort4(Arr):
    minIndex=Minimum(Arr,0,len(Arr)-1)
    minValue=Arr[minIndex]
    temp=Arr[0]
    Arr[0]=minValue
    Arr[minIndex]=temp
    for i in range (len(Arr)):
        for j in range(i + 1, len(Arr)):
            if(Arr[i] > Arr[j]):
                temp = Arr[i]
                Arr[i] = Arr[j]
                Arr[j] = temp
    return Arr
#Prob5
def StringReverse(str,starting,ending):
    str=str[starting:ending]
    str=str[::-1]
    return str
#Prob6
    #Iterative Method
def SumIterative(number):
    sum=0
    for i in range(number):
        sum+=number%10;
        number=int(number/10)
    return sum
    #Sum Recursive
def SumRecursive(number):
    if(number<=10):
        return number
    else:
        return number%10+SumRecursive(int(number/10))
#Prob7
    #Row sum
def RowWiseSum(Mat):
    row=[]
    row=np.sum(Mat, axis = 1)
    return row
    #Column sum 
def ColumnWisSum(Mat):
    col=[]
    col=np.sum(Mat,axis=0)
    return col
#Prob8
def SortedMerge(Arr1,Arr2):
    Arr3 = [None]*(len(Arr1)+len(Arr2))
    a1=len(Arr1)
    a2=len(Arr2)
    i=0 
    j=0
    k=0
    while(i<a1 and j<a2):
        if(Arr1[i]<Arr2[j]):
            Arr3[k]=Arr1[i]
            k+=1
            i+=1
        else:
            Arr3[k]=Arr2[j]
            k+=1
            j+=1
    while (i<a1):
        Arr3[k]=Arr1[i]
        k+=1
        i+=1
    while(j<a2):
        Arr3[k]=Arr2[j]
        k+=1
        j+=1
    return Arr3
#Prob9
def PalindeomRecursie(str):
    if(len(str)<2):
        return True
    elif str[0]==str[len(str)-1]:
        return PalindeomRecursie(str[1:len(str)-1])
    else:
        return False
#Prob10
def Sort10(Arr):
    positive=[];
    negative=[];
    for i in range(len(Arr)):
        if(Arr[i]>=0):
            positive.append(Arr[i])
        else:
            negative.append(Arr[i])
    positive.sort()
    negative.sort()
    mergeArr=[None]*(len(positive)+len(negative))
    shuffle=1 #1 means odd turn   #2 means even trun
    n=0#negative number index
    p=0#positive number index
    lenN=len(negative)#nagative list length
    lenP=len(positive)#positive list length
    for i in range(len(Arr)):
        if(shuffle==1):
            if(lenN>0):
                mergeArr[i]=negative[n]
                n+=1
                shuffle=2
                lenN-=1
                if(lenP==0):
                    shuffle=1
        elif(shuffle==2):
            mergeArr[i]=positive[p]
            p+=1
            shuffle=1
            lenP-=1
            if(lenN==0):
                shuffle=2     
    return mergeArr
