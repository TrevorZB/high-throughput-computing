import matplotlib.pyplot as plt

powers = range(5, 25)
file_lines = []
lines = []
with open('task2.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    if (i+1) % 3 == 0:
        lines.append(file_lines[i])

lines = [float(l) for l in lines]

plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='task2.cu runtime')
plt.title('HW07, Problem: 2d')
plt.xlabel('n')
plt.xticks(range(5, 25, 2))
plt.ylabel('time (ms)')
plt.yscale('log', base=10)
plt.legend()
plt.savefig('task2.pdf')