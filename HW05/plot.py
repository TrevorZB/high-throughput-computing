import matplotlib.pyplot as plt

powers = range(10, 31)

file_lines = []
lines = []
with open('task1024.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    if i % 2 != 0:
        lines.append(file_lines[i])

lines = [float(l) for l in lines]


file_lines1 = []
lines1 = []
with open('task512.out') as f:
    file_lines1 = f.read().splitlines()

for i in range(len(file_lines1)):
    if i % 2 != 0:
        lines1.append(file_lines1[i])

lines1 = [float(l) for l in lines1]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='1024')
plt.plot(powers, lines1, linestyle=':', color='red', marker='x', label='512')
plt.title('Assignment 5, Problem: 2c')
plt.xlabel('n')
plt.xticks(range(10, 31, 2))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task1.pdf')
