import matplotlib.pyplot as plt

file = open("data.txt", 'r')
i = 49
output = [[] for _ in range(50)]


for line in file:
    if line == "RAPORT: 50\n": pass
    elif line[0] == "R":
        i -= 1 
    else:
        output[i].append(line)
file.close()

for i in range(len(output)):
    for j in range(len(output[i])):
        output[i][j] = output[i][j][:-1]
        output[i][j] = output[i][j].rsplit(" ")
        for k in range(len(output[i][j])):
            output[i][j][k] = int(output[i][j][k])
        add = 0
        for k in range(len(output[i][j])):
            add += output[i][j][k]
        output[i][j].append(add)
        for k in range(len(output[i][j]) - 1):
            if output[i][j][3]:
                output[i][j][k] /= output[i][j][3]
                output[i][j][k] = round(output[i][j][k], 5)

for i in output[0]:
    print(i)
print(len(output[0]))
print(len(output[0][0]))

x_axis = [5 * i for i in range(len(output[0]))]

for i in range(len(output)):
    for j in range(len(output[0][0]) - 1):
        y_axis = []
        for k in range(len(output[0])):
            y_axis.append(output[i][k][j])
        if j == 0:
            plt.scatter(x_axis, y_axis, color = 'brown')
        elif j == 1:
            plt.scatter(x_axis, y_axis, color = 'green')
        else:
            plt.scatter(x_axis, y_axis, color = 'blue')

plt.show()
