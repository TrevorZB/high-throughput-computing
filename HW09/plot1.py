import matplotlib.pyplot as plt

powers = range(1, 11)
file_lines = []
lines = []
with open('task1.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    if (i + 1) % 3 == 0:
        lines.append(file_lines[i])

lines = [float(l) for l in lines]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='cluster function')
plt.title('HW09, Problem: 1c')
plt.xlabel('# threads')
plt.xticks(range(1, 11, 1))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task11.pdf')