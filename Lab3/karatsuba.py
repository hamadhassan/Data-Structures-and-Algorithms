# -*- coding: utf-8 -*-
"""
Created on Tue Sep 20 13:48:19 2022

@author: Hammad Hassan
"""
#(i)
from math import ceil, floor
def Multiply_integer(a,b):
    if a < 10 and b< 10: # in other words, if x and y are single digits
        return a*b
    x=str(a)
    y=str(b)
    result=[]
    isReminder=True
    rowResult=""
    t=0
    o=0
    sum=0
    for i in  reversed(range(len(y))):
        for z in range(t):
            rowResult=rowResult+"0"
        for j in reversed(range(len(x))):
            rowMul=int(y[i])*int(x[j])
            if(rowMul>9):
                reminder=rowMul%10
                carry=rowMul//10
                if(isReminder):
                    rowResult=rowResult+str(reminder)
                    isReminder=False
                else:
                    rowMul=rowMul+carry
                    rowResult=str(rowMul)+rowResult
                    if(j==0):
                        result.append(int(rowResult))
                        rowResult=""
                        t+=1
            else:
                rowResult=str(rowMul)+rowResult
                o+=1
                if(j==0):
                    result.append(int(rowResult))
                    rowResult=""
                    t+=1
    for i in range(len(result)):
        sum+=result[i]
    return sum                               
#print(Multiply_integer(22,45))
#(ii)
def Multiply_string(a,b):
    if int(a) < 10 and int(b)< 10: # in other words, if x and y are single digits
        return a*b
    result=[]
    isReminder=True
    rowResult=""
    t=0
    o=0
    sum=0
    for i in  reversed(range(len(b))):
        for z in range(t):
            rowResult=rowResult+"0"
        for j in reversed(range(len(a))):
            rowMul=int(b[i])*int(a[j])
            if(rowMul>9):
                reminder=rowMul%10
                carry=rowMul//10
                if(isReminder):
                    rowResult=rowResult+str(reminder)
                    isReminder=False
                else:
                    rowMul=rowMul+carry
                    rowResult=str(rowMul)+rowResult
                    if(j==0):
                        result.append(int(rowResult))
                        rowResult=""
                        t+=1
            else:
                rowResult=str(rowMul)+rowResult
                o+=1
                if(j==0):
                    result.append(int(rowResult))
                    rowResult=""
                    t+=1
    for i in range(len(result)):
        sum+=result[i]
    return sum                               
#print(Multiply_string("22","45"))
#(iii)
def Visualize_Karatsuba(a,b):
    if a < 10 and b< 10: # in other words, if x and y are single digits
        return a*b
    x=str(a)
    y=str(b)
    result=[]
    isReminder=True
    rowResult=""
    t=0
    o=0
    sum=0
    for i in  reversed(range(len(y))):
        for z in range(t):
            rowResult=rowResult+"0"
        for j in reversed(range(len(x))):
            rowMul=int(y[i])*int(x[j])
            if(rowMul>9):
                reminder=rowMul%10
                carry=rowMul//10
                if(isReminder):
                    rowResult=rowResult+str(reminder)
                    isReminder=False
                else:
                    rowMul=rowMul+carry
                    rowResult=str(rowMul)+rowResult
                    if(j==0):
                        result.append(int(rowResult))
                        rowResult=""
                        t+=1
            else:
                rowResult=str(rowMul)+rowResult
                o+=1
                if(j==0):
                    result.append(int(rowResult))
                    rowResult=""
                    t+=1 
    print(a)
    print(b)
    print("-----")
    for i in range(len(result)):
        sum+=result[i]
        print(result[i])
    print("-----")
    print(sum)                        
#Visualize_Karatsuba(22,45)
       
#(iv)
arr1=[]
arr2=[]
sum=[]
def Multiply_Recursive(a,b):
    if(a<10 or b<10):
        arr1.append(a%10)
        arr2.append(b%10)
    else:
        arr1.append(a%10)
        a=a//10
        arr2.append(b%10)
        b=b//10
        return(Multiply_Recursive(a,b))
    carry=0
    toadd1=""
    for i in range(len(arr2)):
        for j in range(len(arr1)):
            mul=arr2[i]*arr1[j]
            if(mul>=10):
              carry=mul//10
              if(carry>=1 and j<len(arr2)-1):
                  mul+=carry
                  toadd=str(mul%10)
              else:
                  toadd+=str(mul)
                  sum.append(toadd) 
                  
            else:
                if(j<len(arr2)-1):
                    toadd1+=str(mul)+"0"                 
                else:
                    sum.append(str(mul)+toadd1)
    total=0
    for i in range(len(sum)):
        total=total+int(sum[i])
    return total
#print(Multiply_Recursive(22,45))
#(v)
def Karatsuba_Recursive(x,y):
    #base case
    if x < 10 and y < 10: # in other words, if x and y are single digits
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   #Cast n into a float because n might lie outside the representable range of integers.

    xLeft  = floor(x / 10**m)
    xRight = x % (10**m)
    yLeft = floor(y / 10**m)
    yRight = y % (10**m)

    #recursive steps
    ac = Karatsuba_Recursive(xLeft,yLeft)
    bd = Karatsuba_Recursive(xRight,yRight)
    ad_plus_bc_and_ac_minus_bd = Karatsuba_Recursive(xLeft + xRight, yLeft + yRight) - ac - bd

    return ac*(10**(m*2)) + ad_plus_bc_and_ac_minus_bd*(10**m) + bd

#print(Karatsuba_Recursive(22,45))
#(vi)
def Multiply2(x,y):
    #base case
    if x < 2 and y < 2: # in other words, if x and y are single digits
        return x*y
    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   #Cast n into a float because n might lie outside the representable range of integers.
    xLeft  = floor(x / 2**m)
    xRight = x % (2**m)
    yLeft = floor(y / 2**m)
    yRight = y % (2**m)
    #recursive steps
    ac = Multiply2(xLeft,yLeft)
    bd = Multiply2(xRight,yRight)
    ad_plus_bc_and_ac_minus_bd = Multiply2(xLeft + xRight, yLeft + yRight) - ac - bd
    return ac*(2**(m*2)) + ad_plus_bc_and_ac_minus_bd*(2**m) + bd
#Validate
def ValidateMultiply2():
    x=input("Enter First Number: ")
    y=input("Enter Second Number: ")
    isValidate=True
    for i in range(len(x)):
        if(int(x[i])>=2):
            isValidate=False
    if(isValidate==True):
        print(Multiply2(int(x),int(y)))
    else:
        print("Invalid Input")
#ValidateMultiply2()
#(vii)
def Multiply16(x,y):
    #base case
    if x < 16 and y < 16: # in other words, if x and y are single digits
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)   #Cast n into a float because n might lie outside the representable range of integers.

    xLeft  = floor(x / 16**m)
    xRight = x % (16**m)
    yLeft = floor(y / 16**m)
    yRight = y % (16**m)

    #recursive steps
    ac = Multiply16(xLeft,yLeft)
    bd = Multiply16(xRight,yRight)
    ad_plus_bc_and_ac_minus_bd = Multiply16(xLeft + xRight, yLeft + yRight) - ac - bd

    return int(ac*(16**(m*2)) + ad_plus_bc_and_ac_minus_bd*(16**m) + bd)
    
#print(Multiply16(101,110))

