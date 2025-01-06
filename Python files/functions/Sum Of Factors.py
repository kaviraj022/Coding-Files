import math
def isPerfectSquare(n):
    sq=math.sqrt(n)
    return sq.is_integer()
def sum_facts(n):
    sq=int(math.sqrt(n))
    sm=0
    for i in range(1,sq+1):
        if(n%i==0):
            sm+=i+n//i
    if(isPerfectSquare(n)):
        sm-=sq
    return sm
print(sum_facts(int(input())))