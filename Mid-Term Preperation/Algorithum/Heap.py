# -*- coding: utf-8 -*-
"""
Created on Tue Nov  1 09:09:11 2022

@author: Hammad Hassan
"""

class Heap():
    def Parent(self,i):
        return i//2
    def Left(self,i):
        return 2*i
    def Right(self,i):
        return 2*i+1
    def MaxHeapify(self,A,i):
        l=self.Left(i)
        r=self.Right(i)
        if(l<=len(A) and A[l]>A[i]):
            largest=i
        else:
            largest=l
        if(r<=len(A) and A[r]>A[largest]):
            largest=r
        if(largest!=i):
            A[i],A[largest]=A[largest],A[i]
            self.MaxHeapify(A, largest)
    def BuildMaxHeap(self,A):
        for i  in range(len(A)//2,0):
            self.MaxHeapify(A,i)
    def HeapSort(self,A):
        self.BuildMaxHeap(A)
        for i in range(len(A),1):
            l=self.Left(i)
            A[l],A[i]=A[i],A[l]
            len(A-1)
            self.MaxHeapify(A, l)
            

            
        