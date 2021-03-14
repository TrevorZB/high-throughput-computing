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


file_lines2 = []
lines2 = []
with open('thrust_times.out') as f:
    file_lines2 = f.read().splitlines()

for i in range(len(file_lines2)):
    if i % 2 != 0:
        lines2.append(file_lines2[i])

lines2 = [float(l) for l in lines2]


file_lines3 = []
lines3 = []
with open('cub_times.out') as f:
    file_lines3 = f.read().splitlines()

for i in range(len(file_lines3)):
    if i % 2 != 0:
        lines3.append(file_lines3[i])

lines3 = [float(l) for l in lines3]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='HW05, threads_per_block=1024')
plt.plot(powers, lines1, linestyle=':', color='red', marker='x', label='HW05, threads_per_block=512')
plt.plot(powers, lines2, linestyle=':', color='green', marker='*', label='HW07, thrust')
plt.plot(powers, lines3, linestyle=':', color='cyan', marker='.', label='HW07, cub')
plt.title('HW07, Problem: 1c')
plt.xlabel('n')
plt.xticks(range(10, 31, 2))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task1.pdf')
