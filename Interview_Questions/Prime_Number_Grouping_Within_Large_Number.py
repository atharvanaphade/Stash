#Prime Number Grouping Within Large Number
def findPrimesByGrouping(largeNumber,groupingCount):
    temp=1
    lst=[]
    k=2
    for i in range (0,len(largeNumber),groupingCount):
        ss=slice(i,k,1)
        k+=2
        if(isPrime(int(largeNumber[ss]),2)):
            print(largeNumber[ss])
            temp=0
    if(temp==1):
        print("NA")
def isPrime(n, i):
    if (n == 0 or n == 1):
        return False
    if (n == i):
        return True
    if (n % i == 0):
        return False
    i += 1
    return isPrime(n, i)