import funcs as f
import time as t
given_file=open(file='words.txt',mode='r')
lines=given_file.read()
words=[]
arr=lines.split()
for s in arr:
    words.append(s)
#Inseration Sort 
for i in range(len(words)):
    #Check the time for process 
    start_time=t.time() #Time Start
    f.InsertionSort(words,0,len(words))
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
print("Insertion Sort",run_time)
#Inseration Sort  of Shuffle
for i in range(len(words)):
    #Check the time for process 
    start_time=t.time() #Time Start
    f.ShuffleArray(words, 0,len(words))
    f.InsertionSort(words,0,len(words))
    end_time=t.time() #Time End
    run_time=end_time-start_time #Calculate run time
print("After Shuffle Insertion Sort",run_time)