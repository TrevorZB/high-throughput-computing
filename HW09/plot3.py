import matplotlib.pyplot as plt

powers = range(1, 26)
file_lines = []
lines = []
with open('task3.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    lines.append(file_lines[i])

lines = [float(l) for l in lines]

plt.plot(powers, lines, linestyle='--', color='blue', marker='o', label='MPI communication')
plt.title('HW09, Problem: 3b')
plt.xlabel('log (base 2) 2^n')
plt.xticks(range(1, 26, 1))
plt.ylabel('log time (ms)')
plt.yscale('log', base=10)
plt.legend()
plt.savefig('task3.pdf')