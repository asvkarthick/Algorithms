# Remove the Kth last node from a linked list
# Return the head of a singly linked list after removing the Kth node from the end of it

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data: int):
        node = Node(data)
        if not self.head:
            self.head = node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = node

    def append_list(self, l) -> None:
        if not self.head:
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = l.head

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

    def find_list_intersection(self, l1, l2) -> bool:
        ptr1 = l1.head
        ptr2 = l2.head
        while ptr1 != ptr2:
            ptr1 = ptr1.next if ptr1 else l2.head
            ptr2 = ptr2.next if ptr2 else l1.head
        return True if ptr1 else False

l1 = LinkedList()
l1.append(10)
l1.append(20)
l1.append(30)
l1.display()
l2 = LinkedList()
l2.append(1)
l2.append(2)
l2.append(3)
l2.display()
l2.append_list(l1)
l2.display()
l3 = LinkedList()
l3.append(100)
l3.append(200)
l3.display()
l3.append_list(l1)
l3.display()
print(l3.find_list_intersection(l2, l3))
l4 = LinkedList()
l4.append(10)
l4.append(20)
l4.append(30)
print(l3.find_list_intersection(l1, l4))
