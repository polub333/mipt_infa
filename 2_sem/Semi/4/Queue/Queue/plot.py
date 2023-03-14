import matplotlib.pyplot as plt
import csv

x = []
y_add_1 = []
y_del_1 = []
y_add_2 = []
y_del_2 = []
y_add_3 = []
y_del_3 = []

with open('vector_queue.txt', 'r') as file:
    plotting = csv.reader(file, delimiter = ' ')
    for rows in plotting:
        x.append(float(rows[0]))
        y_add_1.append(float(rows[1]))
        y_del_1.append(float(rows[2]))

with open('list_queue.txt', 'r') as file:
    plotting = csv.reader(file, delimiter = ' ')
    for rows in plotting:
        y_add_2.append(float(rows[1]))
        y_del_2.append(float(rows[2]))

with open('circular_buffer_queue.txt', 'r') as file:
    plotting = csv.reader(file, delimiter = ' ')
    for rows in plotting:
        y_add_3.append(float(rows[1]))
        y_del_3.append(float(rows[2]))

figure, axis = plt.subplots(1, 3)

figure.set_figheight(5)
figure.set_figwidth(16)
figure.tight_layout()

axis[0].plot(x, y_add_1, color='g')
axis[0].plot(x, y_del_1, color='r')
axis[0].set_title('Vector queue')

axis[1].plot(x, y_add_2, color='g')
axis[1].plot(x, y_del_2, color='r')
axis[1].set_title('List queue')

axis[2].plot(x, y_add_3, color='g')
axis[2].plot(x, y_del_3, color='r')
axis[2].set_title('Circular buffer queue')

'''
for i in range(0, 3):
    axis[i].figure(figsize=3)
'''

x_pows_of_two = [2**x for x in range(14, 18)]
for xc in x_pows_of_two:
    axis[0].axvline(x=xc, color='b')
    axis[1].axvline(x=xc, color='b')
    axis[2].axvline(x=xc, color='b')

plt.savefig("figure.png")
