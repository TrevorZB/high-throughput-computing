import matplotlib.pyplot as plt

powers = range(1, 11)
file_lines = []
lines = []
with open('task31.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    if (i + 1) % 3 == 0:
        lines.append(file_lines[i])

lines = [float(l) for l in lines]


plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='msort, n=10^6, t=8')
plt.title('HW08, Problem: 3c')
plt.xlabel('log (base 2) ts')
plt.xticks(range(1, 11, 1))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task3_ts.pdf')