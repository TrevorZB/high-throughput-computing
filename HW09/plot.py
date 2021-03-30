import matplotlib.pyplot as plt

powers = range(1, 11)
file_lines = []
lines = []
with open('task1fixed.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    lines.append(file_lines[i])

lines = [float(l) for l in lines]


file_lines1 = []
lines1 = []
with open('task1bad.out') as f:
    file_lines1 = f.read().splitlines()

for i in range(len(file_lines1)):
    lines1.append(file_lines1[i])

lines1 = [float(l) for l in lines1]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='without false share')
plt.plot(powers, lines1, linestyle='--', color='red', marker='o', label='with false share')
plt.title('HW09, Problem: 1c')
plt.xlabel('# threads')
plt.xticks(range(1, 11, 1))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task1.pdf')