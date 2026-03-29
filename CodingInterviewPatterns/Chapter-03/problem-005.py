# LRU Cache
# Design and implement a data structure for the Least Recently Used (LRU) cache that
# supports the following operations:
# LRUCache(capacity: int): Initialize an LRU cache with the specified capacity
# get(key: int) -> int: Return the value associated with a key. Return -1 if the
#                       key doesn't exist
# put(key: int, value: int) -> None: Add a key and its value to the cache. If adding
#                       the key would result in the cache exceeding its size capacity
#                       evict the least recently used element. If the key already
#                       exists in the cache, update its value

class DoublyLinkedList:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hashmap = {}
        self.head_node = DoublyLinkedList(-1, -1)
        self.tail_node = DoublyLinkedList(-1, -1)
        self.head_node.next = self.tail_node
        self.tail_node.prev = self.head_node

    def add_to_tail(self, node: DoublyLinkedList) -> None:
        node.next = self.tail_node
        node.prev = self.tail_node.prev
        node.prev.next = node
        self.tail_node.prev = node

    def remove_node(self, node: DoublyLinkedList) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def get(self, key: int) -> int:
        if key not in self.hashmap:
            return -1
        self.remove_node(self.hashmap[key])
        self.add_to_tail(self.hashmap[key])
        return self.hashmap[key].value

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            self.remove_node(self.hashmap[key])
        node = DoublyLinkedList(key, value)
        self.hashmap[key] = node
        if len(self.hashmap) > self.capacity:
            del self.hashmap[self.head_node.next.key]
            self.remove_node(self.head_node.next)
        self.add_to_tail(node)

cache = LRUCache(3)
cache.put(1, 100)
cache.put(2, 250)
print(cache.get(2))
cache.put(4, 300)
cache.put(3, 200)
print(cache.get(4))
print(cache.get(1))
print(cache.get(3))
cache.put(3, 500)
print(cache.get(3))
