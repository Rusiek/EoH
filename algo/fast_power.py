def fast_power(A, Id, n):
    if n == 0:
        return Id
    elif n % 2 == 1:
        return A * fast_power(A, Id, n - 1)
    else:
        temp = fast_power(A, Id, n // 2)
        return temp * temp
