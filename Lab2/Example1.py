# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 12:53:06 2022

@author: Hammad Hassan
"""
def factorial(n):
    if(n==0):
        return 1
    else:
        return n* factorial(n-1)
import time as t
start_time=t.time()
n=1500
ans=factorial(n)
end_time=t.time()
run_time=end_time-start_time
print("Runtime of factorial at",n,"is",run_time,"seconds")
