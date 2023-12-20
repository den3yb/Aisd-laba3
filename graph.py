import matplotlib.pyplot as plt
import numpy


def quick_rand () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quick_rand.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость quick_rand количества обработки количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def quick_order () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quick_order.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость quick_order количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def quick_reverse () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quick_reverse.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость quick_reverse количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()


def creat_quick_graph() -> None:
    quick_rand()
    quick_order()
    quick_reverse()

    
def pyramid_rand () -> None:
    x1, y1, z1 = numpy.loadtxt(f"pyramid_rand.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость pyramid_rand количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def pyramid_order () -> None:
    x1, y1, z1 = numpy.loadtxt(f"pyramid_order.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость pyramid_order количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def pyramid_reverse () -> None:
    x1, y1, z1 = numpy.loadtxt(f"pyramid_reverse.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость pyramid_reverse количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()


def creat_pyramid_graph() -> None:
    pyramid_rand()
    pyramid_order()
    pyramid_reverse()
   

creat_quick_graph()
creat_pyramid_graph()