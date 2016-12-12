from math import sqrt

def seidel(A, b, eps):
    n = len(b)
    r = range(n)
    x = [0 for i in r]

    converge = False
    while not converge:
        x_new = x.copy()
        for i in r:
            s1 = sum(A[i][j] * x_new[j] for j in range(i))
            s2 = sum(A[i][j] * x[j] for j in range(i + 1, n))
            x_new[i] = (b[i] - s1 - s2) / A[i][i]

        converge = (sqrt(sum((x_new[i] - x[i]) ** 2 for i in r)) <= eps)
        x = x_new

    return x

A = [[2, 1, 3],
     [11, 7, 5],
     [9, 8, 4]]

b = [1, -6, -5]

print(seidel(A, b, 0.0000001))
