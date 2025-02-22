def maxSubArray(nums):
    sm, curr = float('-inf'), 0
    left = 0
    for right in range(len(nums)):
        curr += nums[right]
        sm = max(sm, curr)
        if curr < 0:
            curr=0           
    return sm

def circularSubarraySum(arr):    
    #max subarray sum using kadanes algo without circle
    curr=0
    nonCircularmx=float('-inf')
    total=sum(arr)
    for i in arr:
        curr+=i
        nonCircularmx=max(nonCircularmx,curr)
        curr=max(curr,0)
    
    #wrapping
    #min subarray sum using kadanes algo 
    nonCircularmn=float('inf')
    curr=0
    for i in arr:
        curr+=i
        nonCircularmn=min(nonCircularmn,curr)
        curr=min(curr,0)
    circularmx=total-nonCircularmn
    if circularmx==0:#if all elements are negaitive it becomes 0 
        return nonCircularmx
    return max(circularmx,nonCircularmx)
    