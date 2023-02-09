import matplotlib.pyplot as plt
import csv

x_without_opt = []
y_without_opt = []

x_with_opt = []
y_with_opt = []

with open('time_without_optimization.txt', 'r') as file:
    plotting = csv.reader(file, delimiter = ' ')
    for rows in plotting:
        x_without_opt.append(float(rows[0]))
        y_without_opt.append(float(rows[1]))

with open('time_with_optimization.txt', 'r') as file:
    plotting = csv.reader(file, delimiter = ' ')
    for rows in plotting:
        x_with_opt.append(float(rows[0]))
        y_with_opt.append(float(rows[1]))

plt.plot(x_without_opt, y_without_opt, color='g')
plt.plot(x_with_opt, y_with_opt, color='r')
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig('image.png')