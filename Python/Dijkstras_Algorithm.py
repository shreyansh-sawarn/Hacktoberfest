class MinHeap:
    def __init__(self):
        self.h = []

    def minheapify(self, i):
        l = 2 * i + 1
        r = 2 * (i + 1)
        if l <= len(self.h) - 1 and self.h[l].dis < self.h[i].dis:
            lar = l
        else:
            lar = i
        if r <= len(self.h) - 1 and self.h[r].dis < self.h[lar].dis:
            lar = r
        if lar != i:
            temp = self.h[i]
            self.h[i] = self.h[lar]
            self.h[lar] = temp
            self.minheapify(lar)

    def mini(self):
        return self.h[0]

    def insert(self, x):
        self.h.append(x)
        if len(self.h) != 1:
            r = len(self.h) - 1
            i = int((r - 1) / 2)
            while self.h[i].dis > self.h[r].dis:
                temp = self.h[i]
                self.h[i] = self.h[r]
                self.h[r] = temp
                if i == 0:
                    break
                r = i
                i = int((i - 1) / 2)

    def extractMin(self):
        l = self.h[0]
        self.h[0] = self.h[len(self.h) - 1]
        self.h.pop()
        self.minheapify(0)
        return l

    def updatePrio(self, v):
        for i in range(len(self.h)):
            if self.h[i] == v:
                j = int((i - 1) / 2)
                while self.h[i].dis > self.h[j].dis:
                    temp = self.h[j]
                    self.h[j] = self.h[i]
                    self.h[i] = temp
                    if j == 0:
                        break
                    i = j
                    j = int((j - 1) / 2)


class Vertex:
    def __init__(self, k):
        self.dis = 20000
        self.key = k
        self.next = None


class Edge:
    def __init__(self, v1, v2, w):
        self.e1 = v1
        self.e2 = v2
        self.wei = w


class Node:
    def __init__(self, k):
        self.val = k
        self.next = None


def main():
    L = []
    E = []
    n = int(input("Enter number of vertices:"))
    for i in range(n):
        tmp = Vertex(i)
        L.append(tmp)
    # print(L[i])
    # M=[[0 for i in range(0,n)]for j in range(0,n)]
    e = int(input("Enter number of edges:"))
    print("Enter the edges in the format \"Endpoint1 Endpoint2 Distance\":")
    for i in range(0, e):
        v1, v2, w = input().split()
        v1, v2, w = int(v1), int(v2), int(w)

        N1 = Node(v1)

        N2 = Node(v2)
        E.append(Edge(v1, v2, w))
        if L[v1].next is None:
            L[v1].next = N2
        else:
            tmp = L[v1].next
            N2.next = tmp
            L[v1].next = N2

        """if L[v2].next==None:
            L[v2].next=N1
        else:
            tmp=L[v2].next
            N1.next=tmp
            L[v2].next=N1"""
    s = int(input("Enter the source vertex:"))
    DSP(L, E, s)
    for i in range(len(L)):
        print("Shortest distance of vertex", i, "from the source vertex: ", L[i].dis)


def DSP(L, E, s):
    L[s].dis = 0
    H = MinHeap()
    for i in range(len(L)):
        u = L[i]
        H.insert(u)
    while len(H.h) != 0:
        w = H.extractMin()
        # print("w",w.key)
        tmp = w.next
        # print(L[tmp.val])
        while tmp is not None:
            for i in range(len(E)):
                if (E[i].e1 == w.key and E[i].e2 == tmp.val) or (E[i].e2 == w.key and E[i].e1 == tmp.val):
                    cd = E[i].wei
            if w.dis + cd < L[tmp.val].dis:
                L[tmp.val].dis = w.dis + cd
                H.updatePrio(L[tmp.val])
            tmp = tmp.next


if __name__ == '__main__':
    main()
