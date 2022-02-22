def power(A, n):
    output = A
    for _ in range(n - 1):
        output *= A
    return output
