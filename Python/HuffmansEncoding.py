class Node:
    def __init__(self, label=None, frequency=0, left=None, right=None):
        self.left = left
        self.right = right
        self.label = label
        self.frequency = frequency

    def __lt__(self, other):
        return self.frequency < other.frequency

    def __gt__(self, other):
        return self.frequency > other.frequency

    def __eq__(self, other):
        return self.frequency == other.frequency


def printEncode(x: Node):
    if (x.right is None) and (x.left is None):
        print(":", x.label)
    elif (x.right is not None):
        print(1, end=" ")
        printEncode(x.right)
    else:
        print(0, end=" ")
        printEncode(x.left)


def main():
    from heapq import heappush, heappop
    heap = []
    n = int(input("Enter the number of characters"))
    for i in range(n):
        a, b = input("Enter char : freq").split()
        b = int(b)
        temp = Node(a, b)
        heappush(heap, temp)

    for i in range(1, n):
        x = heappop(heap)
        y = heappop(heap)
        node = Node("#", x.frequency + y.frequency, x, y)
        heappush(heap, node)
    printEncode(heap[0])


if __name__ == '__main__':
    main()
