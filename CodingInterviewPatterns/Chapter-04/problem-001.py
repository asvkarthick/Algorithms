# Linked List Loop
# Given a singly linked list, determine if it contains a cycle.
# A cycle occurs if a node's next pointer references an earlier
# node in the list, causing a loop

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

    def linked_list_loop(self) -> bool:
        hashset = set()
        node = self.head
        while node:
            if node in hashset:
                return True
            hashset.add(node)
            node = node.next
        return False

l = LinkedList()
l.append(10)
l.append(20)
l.append(30)
print(l.linked_list_loop())
node = Node(40)
node.next = Node(50)
node.next.next = Node(60)
node.next.next.next = l.head.next
l.head.next.next.next = node
print(l.linked_list_loop())
