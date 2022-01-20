# You are given an array A containing N integers. You are also given an integer K. An array is good if A ≤ A[i + K], i = 1, 2, 3, .. , N - K.
# In one operation, you can choose any element and convert it to an arbitrary integer.
# For each test case in a new line, print the minimum number of operations to make the array good.

from typing import List
from collections import defaultdict
import bisect
def minOperations (n, arr, k):
    dic=defaultdict(list)
    for i,val in enumerate(arr):
        imod=i%k
        idx=bisect.bisect_right(dic[imod],val)
        if idx == len(dic[imod]):
            dic[imod].append(val)
        else:
            dic[imod][idx]=val
    acc=0
    for key,lst in dic.items():
        ln=(n-1-key)//k +1
        acc+= ln-len(lst)
    return acc
   

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    K = int(input())

    out_ = minOperations(N, A, K)
    print (out_)