t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    sum=0
    c = 0
    b=1
    for i in range(n):
        sum+=a[i]
    for i in range(n,0,-1):
        c = 0
        b=1
        if sum%i==0:
            n1 = sum//i
            for j in range(n):
                c+=a[j]
                if c>n1:
                    b = 0
                    break
                if c==n1:
                    c=0
            if b==1:
                print(n-i)
                break
            