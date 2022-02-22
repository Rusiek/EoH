def x(n, k, a, x):
    if n <= k:
        return x[n]
    
    output = 0
    for i in range(1, k + 1):
        output += a[i] * x(n - i, k, a, x)
    return output