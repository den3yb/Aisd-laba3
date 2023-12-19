import matplotlib.pyplot as plt
import numpy

def creat_quick_graph() -> None:
    
    x1, y1, z1 = numpy.loadtxt(f"quick_rand.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    

    x2, y2, z2 = numpy.loadtxt(f"quick_order.txt", unpack=True)    
    plt.plot(x2, y2, marker=".")
    plt.plot(x2, z2, marker='.')

    x3, y3, z3 = numpy.loadtxt(f"quick_reverse.txt", unpack=True)    
    plt.plot(x3, y3, marker=".")
    plt.plot(x3, z3, marker='.')

    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')

    plt.show()

creat_quick_graph()