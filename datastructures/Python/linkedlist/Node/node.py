class Node:
    data = None
    nextNode = None
    prevNode = None

    def __init__(self, data=None):
        self.data = data
        self.nextNode = None
        self.prevNode = None

    def setData(self, data):
        self.data = data
        return self

    def getData(self):
        return self.data

    def setNext(self, node=None):
        self.nextNode = node
        return self

    def getNext(self):
        return self.nextNode

    def setPrev(self, node=None):
        self.prevNode = node
        return self

    def getPrev(self):
        return self.prevNode
