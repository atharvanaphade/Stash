# You are given a positive integer N.
# You have to divide the number N into two numbers P1 and P2 such that:
# Each digit of N should belong to exactly one of P1 or one of P2 and this, in turn, would utilize every digit of the number N.
# Form the numbers P1 and P2 in a manner such that their sum is minimum.
# For each test case, print the minimum possible sum of the two numbers P1 and P2.

def solve (N):
    # Write your code here
    num=str(N)
    temp=sorted(num)
    p1=""
    p2=""
    for i in range(len(temp)):
        if(i%2==0):
            p1+=temp[i]
        else:
            p2+=temp[i]
    return int(p1)+int(p2)

T = int(input())
for _ in range(T):
    N = int(input())

    out_ = solve(N)
    print (out_)