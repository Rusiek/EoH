def dynamic(n, k, x, a, b = 0):
    for i in range(k, n):
        temp = b
        for j in range(1, k + 1):
            temp += a[j - 1] * x[(i - j) % k]
        x[i % k] = temp
    return x[(n - 1) % k]
