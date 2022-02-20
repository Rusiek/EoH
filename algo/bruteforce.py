
def x(n, k, a, x, b = 0):
    if n <= k:
        return x[n]
    
    output = b
    for i in range(1, k + 1):
        output += a[i] * x(n - i, k, a, x, b)
    return output