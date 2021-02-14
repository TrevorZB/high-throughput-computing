import matplotlib.pyplot as plt

lines = []
with open('Task3.out') as f:
    lines = f.read().splitlines()[::3]
lines = [float(line) for line in lines]
powers = list(range(10, 30))

lines16 = []
with open('Task3_two.out') as f:
    lines16 = f.read().splitlines()[::3]
lines16 = [float(line) for line in lines16]


plt.plot(powers, lines, linestyle='--', marker='o')
plt.plot(powers, lines16, linestyle='--', marker='o')
plt.title('Assignment 3, Problem: 3c')
plt.xlabel('n')
plt.xticks(range(10, 30, 2))
plt.ylabel('time (ms)')
plt.savefig('task3.pdf')
