# Pair Sum - Unsorted
# Given an array of integers, return the indexes of any two numbers that add up to a target
# The order of the indexes in the result doesn't matter. If no pair is found, return an empty
# array

def pair_sum(nums: list[int], target: int) -> list[int]:
    hashmap = {}
    for i, x in enumerate(nums):
        if target - x in hashmap:
            return [i, hashmap[target - x]]
        hashmap[x] = i
    return []


l = [-1, 3, 4, 2]
print(l, pair_sum(l, 3))
print(l, pair_sum(l, 5))
print(l, pair_sum(l, 7))
