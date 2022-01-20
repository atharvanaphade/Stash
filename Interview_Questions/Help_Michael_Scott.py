def isPowerOfTwo (x):
    return (x and (not(x & (x - 1))) )
from math import log
def log2(x, base):
    return int(log(x) // log(base))
def findPreviousPowerOf2(n):
    return 1 << log2(n, 2)
def log2(x, base):
    return int(log(x) // log(base))
n=int(input())
count=0
while(n>0):
    if(n==1):
        count+=1
        n-=1
        continue
    if(isPowerOfTwo(n)):
        count+=1
        n-=n
    else:
        t=findPreviousPowerOf2(n)
        count+=1
        n-=t
print(count)