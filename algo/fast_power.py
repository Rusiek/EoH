def fast_power(A, n):
    if n == 1:
        return A
    elif n % 2 == 1:
        return A * fast_power(A, n - 1)
    else:
        temp = fast_power(A, n // 2)
        return temp * temp
