def findModeInEuclideanDistances(n,cordinate):
    lst=[]
    for i in range(n-1):
        a=cordinate[i]
        b=cordinate[i+1]
        res = eud(a,b)
        lst.append(res)
    ans = max(lst, key = lst.count)
    return ans
def eud(a,b):
    x1,y1=a[0],a[1]
    x2,y2=b[0],b[1]
    res = ((x2-x1)**2 + (y2-y1)**2)**0.5
    return int(res)
n = int(input())
m=input()
cord = []
for i in range(n):
    l = list(map(int,input().split()))
    cord.append(l)
print(findModeInEuclideanDistances(n,cord))