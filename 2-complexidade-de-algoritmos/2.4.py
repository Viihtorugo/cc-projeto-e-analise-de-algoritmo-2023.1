import time
import matplotlib.pyplot as plt

def fib_rec (n):
    if (n <= 0):
        return 0
    
    if (n == 1 or n == 2):
        return 1
    
    return fib_rec(n - 1) + fib_rec(n - 2)

i = 0

x = []
y_rec = []

count_time = 0

while i < 100 and count_time <= 60:
    inicio = time.time()
    fib_rec(i)
    fim = time.time()
    x.append(i)
    count_time += (fim - inicio)
    print(count_time)
    y_rec.append(fim - inicio)
    i += 1

print("n max: ", i)

def fib(n, f):
    if (n <= 0):
      f.append(0)
    
    if (n == 1 or n == 2):
      f.append(1)

    f.append(f[n - 1] + f[n - 2])

i = 0

y_it = []
f = [0, 1, 1]

while i < 42:
    inicio = time.time()
    if (i <= 0):
      f[0] = 0
    elif (i == 1 or i == 2):
      f[i] = 1
    else:
      fib(i, f)
    fim = time.time()
    #x.append(i)
    y_it.append(fim - inicio)
    i += 1

plt.plot(x, y_rec, label='Recursivo')
plt.plot(x, y_it, label='Iterativo')

plt.xlabel('i-Esimo elemento do fibbonaci')
plt.ylabel('Tempo de execussão')
plt.title('Fib. Recursivo x Fib. Iterativo')
plt.legend()

plt.show()