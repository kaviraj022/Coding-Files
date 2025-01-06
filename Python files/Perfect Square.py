def isPerfectSquare(n): 
    i=1
    j=num
    while(i<=j):
        m=(i+j)//2  
        if(m*m==num):
            return True
        if(m*m>num):
            j=m-1
        else:
            i=m+1
    return False