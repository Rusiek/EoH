def add(A, B):
    C = [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]
    return C

def sub(A, B):
    C = [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]
    return C

def merge_v(A, B):
    C = []
    for i in A:
        C.append(i)

    for i in B:
        C.append(i)

    return C

def merge_h(A, B):
    C = []
    for i in range(len(A)):
        C.append(A[i] + B[i])

    return C

def make(A):
    i = 1
    while i < len(A):
        i *= 2

    output = [[0 for k in range(i)] for j in range(i)]

    for i in range(len(A)):
        for j in range(len(A[0])):
            output[i][j] = A[i][j]

    return output

def split(M):
    m11 = [[M[i][j] for j in range(len(M) // 2)]            for i in range(len(M) // 2)]
    m12 = [[M[i][j] for j in range(len(M) // 2, len(M))]    for i in range(len(M) // 2)]
    m21 = [[M[i][j] for j in range(len(M) // 2)]            for i in range(len(M) // 2, len(M))]
    m22 = [[M[i][j] for j in range(len(M) // 2, len(M))]    for i in range(len(M) // 2, len(M))]
    return m11, m12, m21, m22

def multi(A, B):
    if len(A) == 1:
        output = A[0][0] * B[0][0]
        return [[output]]

    a11, a12, a21, a22 = split(A)
    b11, b12, b21, b22 = split(B)

    m1 = multi(add(a11, a22), add(b11, b22))
    m2 = multi(add(a21, a22), b11)
    m3 = multi(a11          , sub(b12, b22))
    m4 = multi(a22          , sub(b21, b11))
    m5 = multi(add(a11, a12), b22)
    m6 = multi(sub(a21, a11), add(b11, b12))
    m7 = multi(sub(a12, a22), add(b21, b22))

    c11 = add(sub(add(m1, m4), m5), m7)
    c12 = add(m3, m5)
    c21 = add(m2, m4)
    c22 = add(add(sub(m1, m2), m3), m6)

    output = merge_v(merge_h(c11, c12), merge_h(c21, c22))

    return output

def strassen(A, B):
    X, Y = make(A), make(B)
    print(X, Y)
    temp = multi(X, Y)
    output = [[temp[i][j] for j in range(len(A))] for i in range(len(A))]
    return output
