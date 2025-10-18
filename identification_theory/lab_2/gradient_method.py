import numpy as np

x1 = np.array([5, 10, 15, 20], dtype=float)
x2 = np.array([2, 4, 8, 16], dtype=float)
x3 = np.array([1, 2, 3, 4], dtype=float)
y  = np.array([2.569, 3.339, 4.312, 5.317], dtype=float)

b1, b2, b3 = 0.5, 2.0, 1.0
lmbd = 0.001  

def predict(b1, b2, b3):
    return b1 * np.log(x1) + np.log(b2) / np.log(x2) + b3 * x3

def error(b1, b2, b3):
    return y - predict(b1, b2, b3)

def F(b1, b2, b3):
    e = error(b1, b2, b3)
    return np.sum(e**2)

def dF_db1(b1, b2, b3):
    e = error(b1, b2, b3)
    return -2 * np.sum(e * np.log(x1))

def dF_db2(b1, b2, b3):
    e = error(b1, b2, b3)
    return -2 * np.sum(e * (1 / (b2 * np.log(x2))))

def dF_db3(b1, b2, b3):
    e = error(b1, b2, b3)
    return -2 * np.sum(e * x3)


max_iter = 100000
tol = 0.001
for step in range(max_iter):
    F_val = F(b1, b2, b3)

    if F_val < tol:
        break

    db1 = dF_db1(b1, b2, b3)
    db2 = dF_db2(b1, b2, b3)
    db3 = dF_db3(b1, b2, b3)

    b1 -= lmbd * db1
    b2 -= lmbd * db2
    b3 -= lmbd * db3

    if step % 100 == 0:
        print(f"iter={step}, F={F_val:.6f}, b1={b1:.4f}, b2={b2:.4f}, b3={b3:.4f}")

print("\n--- Result ---")
print(f"Iterations: {step}")
print(f"F = {F_val:.6f}")
print(f"b1 = {b1:.6f}, b2 = {b2:.6f}, b3 = {b3:.6f}")
