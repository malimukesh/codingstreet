from Node.node import Node

class SinglyLinkedList:
    head = None
    tail = None

    def __init__(self):
        head = None
        tail = None

    def addAtEnd(self, node):
        if (node==None):
            return self

        if (self.head == None):
            self.head = node
            self.tail = self.head
            return self
        else:
            self.tail.setNext(node)
            self.tail = self.tail.getNext();

        return self

    def addAtBegin(self, node):
        if (node==None):
            return self
        if (self.head == None):
            self.head = node
            self.tail = self.head
            return self
        else:
            node.setNext(self.head)
            self.head = node

    def isEmpty(self):
        if (head == None):
            return True
        else:
            return False

    def printList(self):
        tmp = self.head
        while(tmp!=None):
            print tmp.data
            tmp = tmp.getNext()


s1 = SinglyLinkedList()

n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
s1.addAtEnd(n1)
s1.addAtEnd(n2)
s1.addAtBegin(n3)

s1.printList()