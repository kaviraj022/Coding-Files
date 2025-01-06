def MyPower(x,n): 
    if(n<0):
        x=1/x
        n=-n
    def calc(x,n):
        if(n==0):
            return 1
        if(n%2==0):
            return calc(x*x,n//2)
        return x*calc(x*x,n//2)
        return calc(x,n)