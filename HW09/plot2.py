import matplotlib.pyplot as plt

powers = range(1, 11)
file_lines = []
lines = []
with open('task2wo.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    lines.append(file_lines[i])

lines = [float(l) for l in lines]

file_lines2 = []
lines2 = []
with open('task2wi.out') as f:
    file_lines2 = f.read().splitlines()

for i in range(len(file_lines2)):
    lines2.append(file_lines2[i])

lines2 = [float(l) for l in lines2]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='pi estimation, without simd')
plt.plot(powers, lines2, linestyle='--', color='red', marker='o', label='pi estimation, with simd')
plt.title('HW09, Problem: 2c')
plt.xlabel('# threads')
plt.xticks(range(1, 11, 1))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task2.pdf')