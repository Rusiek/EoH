import numpy as np
 
def split(M):
    half = len(M) // 2
    return M[:half][:half], M[:half][half:], M[half:][:half], M[half:][half:]
 
def strassen(A, B):
    if len(A) == 1 or len(B) == 1: 
        return A * B
 
    a11, a12, a21, a22 = split(A)
    b11, b12, b21, b22 = split(B)
 
    m1 = strassen(a11 + a22 , b11 + b22) 
    m2 = strassen(a21 + a22 , b11)       
    m3 = strassen(a11       , b12 - b22)       
    m4 = strassen(a22       , b21 - b11)       
    m5 = strassen(a11 + a12 , b22)       
    m6 = strassen(a21 - a11 , b11 + b12) 
    m7 = strassen(a12 - a22 , b21 + b22) 
 
    c11 = m1 + m4 - m5 + m7
    c12 = m3 + m5
    c21 = m2 + m4
    c22 = m1 - m2 + m3 + m6 
 
    output = np.vstack((np.hstack((c11, c21)), np.hstack((c12, c22))))
 
    return output


A = np.array([[1, 2, 3, 2], [4, 5, 6, 2], [1, 3, 3, 2], [2, 9, 2, 1]])
B = np.array([[3, 2, 2, 1], [1, 3, 2, 1], [1, 7, 2, 0], [3, 3, 2, 2]])

print(strassen(A, B))