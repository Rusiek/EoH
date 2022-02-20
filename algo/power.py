def power(A, Id, n):
    output = Id
    for _ in range(n):
        output *= A
    return output
