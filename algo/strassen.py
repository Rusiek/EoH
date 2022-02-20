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
        temp = []
        for j in A[i]:
            temp.append(j)
        for j in B[i]:
            temp.append(j)
        C.append(temp)
    return C

def split(M):
    h_row = len(M[0]) // 2
    h_col = len(M) // 2
    
    M11 = [[M[i][j] for j in range(h_row)]              for i in range(h_col)]
    M12 = [[M[i][j] for j in range(h_row, len(M[0]))]   for i in range(h_col)]
    M21 = [[M[i][j] for j in range(h_row)]              for i in range(h_col, len(M))]
    M22 = [[M[i][j] for j in range(h_row, len(M[0]))]   for i in range(h_col, len(M))]
    
    return M11, M12, M21, M22
