# Remove the Kth last node from a linked list
# Return the head of a singly linked list after removing the Kth node from the end of it

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

    def removeKthNodeFromLast(self, k: int):
        if not self.head:
            return

        dummy = Node(-1)
        dummy.next = self.head
        leader = trailer = dummy
        for _ in range(k):
            if leader:
                leader = leader.next
        while leader.next:
            trailer = trailer.next
            leader = leader.next
        print(trailer.data)
        trailer.next = trailer.next.next

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
l.removeKthNodeFromLast(2)
l.display()
