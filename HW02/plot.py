import matplotlib.pyplot as plt

lines = []
with open('Plot.out') as f:
    lines = f.read().splitlines()[::3]

lines = [float(line) for line in lines]
powers = list(range(10, 31))

plt.plot(powers, lines, linestyle='--', marker='o')
plt.title('Assignment 2, Problem: 1c')
plt.xlabel('n')
plt.xticks(range(10, 31, 2))
plt.ylabel('time (ms)')
plt.savefig('task1.pdf')
