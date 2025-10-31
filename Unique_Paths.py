dp ={}
def uniquePaths(m , n):
    if n<1 or m<1:
        return 0

    if m==1 and n==1:
        return 1

    if (n,m) in dp:
        return dp[(n,m)]
    
    dp[(n,m)] = uniquePaths(m-1,n) + uniquePaths(m,n-1)
    
    return dp[(n,m)]
