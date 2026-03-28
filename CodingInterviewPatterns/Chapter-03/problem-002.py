# Linked List Reversal
# Reverse a singly linked list using recursion

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = node

    def reverse_recursion(self, node: Node) -> Node:
        if not node or not node.next:
            return node
        new_head = self.reverse_recursion(node.next)
        node.next.next = node
        node.next = None
        return new_head

    def reverse(self):
        self.head = self.reverse_recursion(self.head)

    def display(self):
        data = []
        current = self.head
        while current:
            data.append(str(current.data))
            current = current.next
        print(" -> ".join(data) + " -> None")

l = LinkedList()
l.append(10)
l.append(20)
l.append(30)
l.display()
l.reverse()
l.display()
