from itertools import combinations
from functools import reduce
n=int(input())
lst=list(map(int,input().split()))
res=[]
for i in range(n//2):
    c=combinations(lst,i+1)
    for j in c:
        res.append(list(j))
mx=-1
for i in res:
    mx=max(mx,reduce(lambda x,y:x^y,i))
print(mx)