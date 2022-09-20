import numpy as np
#A=array p=start r=end q=mid
def Merge(array,start,mid,end):
    n1=mid-start+1
    n2=end-mid
    L=[0]*(n1+1)
    R=[0]*(n2+1)
    for i in range(n1):
        L[i]=array[start+i]
    for j in range(n2):
        R[j]=array[mid+j+1]
    L[len(L)-1]=np.inf
    R[len(R)-1]=np.inf
    i=j=0
  
    for s in range(start,end+1):
        if(L[i]<=R[j]):
            array[s]=L[i]
            i+=1
        else:
            array[s]=R[j]
            j=j+1
def MergeSort(array, start, end):
    if(start!=end):     
        mid=start+(end-start)//2
        print(start,mid,end)
        MergeSort(array, start, mid)
        MergeSort(array, mid+1, end)
        Merge(array, start, mid, end)
    else:
        return
A=[1,3,54,2,72,23,12,32,12]
MergeSort(A,1,len(A)-1)
print(A)