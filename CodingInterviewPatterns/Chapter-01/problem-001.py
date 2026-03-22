# Given an array of integers sorted in ascending order and a target value
# return the indexes of the pair of numbers in that array that sum to the target.
# The order of the indexes doesn't matter
# If no pair is found, return an empty array

def pair_sum_sorted_brute_force(nums: list[int], target: int) -> list[int]:
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []


l = [1, 2, 3, 4, 5]
print(pair_sum_sorted_brute_force(l, 9))
print(pair_sum_sorted_brute_force(l, 2))
