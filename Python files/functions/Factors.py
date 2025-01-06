import math
def Factors(n):
    sq=int(math.sqrt(n))
    facts=[]
    for i in range(1,sq+1):
        if(n%i==0):
            facts.append(i)
            facts.append(n//i)
    facts=list(set(facts))
    facts.sort()
    return facts
print(*Factors(int(input())))
