# Linked List Midpoint detection
# Given a singly linked list, find and return the middle node. If there are two middle nodes,
# return the second one

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

    def midpoint(self) -> Node:
        slow = fast = self.head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow

l1 = LinkedList()
l1.append(10)
l1.append(20)
l1.append(40)
l1.append(70)
l1.append(30)
print(l1.midpoint().data)
l2 = LinkedList()
l2.append(10)
l2.append(20)
l2.append(40)
l2.append(70)
print(l2.midpoint().data)
