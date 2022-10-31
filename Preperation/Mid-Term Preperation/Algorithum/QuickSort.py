def Partication(arr,start,end):
    pivot=arr[end]
    j=start-1
    for i in range(start,end):
        if(arr[i]<=pivot):
            j+=1
            arr[j],arr[i]=arr[i],arr[j]
    arr[j+1],arr[end]=arr[end],arr[j+1]
    return j+1
def QuickSort(arr,start,end):
    if(start<end):
        pi=Partication(arr,start,end)
        QuickSort(arr,start,pi-1)
        QuickSort(arr,pi+1,end)
    return arr