import matplotlib.pyplot as plt

powers = range(5, 15)

file_lines = []
doubles = []
floats = []
ints = []
with open('task2.out') as f:
    file_lines = f.read().splitlines()

for i in range(len(file_lines)):
    if i == 0:
        continue
    if i >= len(file_lines):
        break
    x = i + 1
    if x % 9 == 0:
        doubles.append(file_lines[i])
    elif x % 6 == 0:
        floats.append(file_lines[i])
    elif x % 3 == 0:
        ints.append(file_lines[i])

doubles = [float(d) for d in doubles]
floats = [float(d) for d in floats]
ints = [float(d) for d in ints]

print(doubles)
print(floats)
print(ints)

plt.plot(powers, doubles, linestyle='--', color='blue', marker='o', label='TYPE=double, block_dim=32')
plt.plot(powers, floats, linestyle='--', color='red', marker='o', label='TYPE=float, block_dim=32')
plt.plot(powers, ints, linestyle='--', color='green', marker='o', label='TYPE=int, block_dim=32')
plt.title('Assignment 5, Problem: 2c')
plt.xlabel('n')
plt.xticks(range(5, 14, 1))
plt.ylabel('time (ms)')
plt.legend()
plt.savefig('task2.pdf')
