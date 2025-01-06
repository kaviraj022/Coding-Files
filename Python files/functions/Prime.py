import math
def isPrime(n):
    if(n==1):
        return False
    if(n==2):
        return True
    sq=int(math.sqrt(n))
    for i in range(2,sq+1):
        if(n%i==0):
            return False
    return True
print(isPrime(int(input())))