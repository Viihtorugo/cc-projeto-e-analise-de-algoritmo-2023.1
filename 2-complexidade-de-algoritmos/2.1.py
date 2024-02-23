import matplotlib.pyplot as plt

x = []
y = [11966, 24303, 39992, 53010, 67272, 78692, 91274, 113063, 129799, 140538]

for i in range (1, 11):
    x.append(i * 1000)

plt.plot(x, y, label='f(x)')

plt.xlabel('SIZE')
plt.ylabel('COUNT')

plt.legend()

plt.show()