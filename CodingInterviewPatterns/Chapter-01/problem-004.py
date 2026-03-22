# Given an array of integers, return all triplets [a, b, c] such that a + b + c = 0
# The solution must not contain duplicate triplets
# If no such triplets are found return an empty array

def triplet_sum(nums: list[int]) -> list[list[int]]:
    triplets = []
    nums.sort()
    for i in range(len(nums)):
        # Sorted array, sum of positive numbers will not yield 0, so stop
        if nums[i] > 0:
            break
        # Avoid duplicate triplets by skipping same 'a' value [a, b, c]
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        pairs = pair_sum_sorted_all_pairs(nums, i + 1, -nums[i])
        for pair in pairs:
            triplets.append([nums[i]] + pair)
    return triplets

def pair_sum_sorted_all_pairs(nums: list[int], start: int, target: int) -> list[int]:
    pairs = []
    left, right = start, len(nums) - 1
    while left < right:
        sum = nums[left] + nums[right]
        if sum == target:
            pairs.append([nums[left], nums[right]])
            left += 1
            while left < right and nums[left] == nums[left - 1]:
                left += 1
        elif sum < target:
            left += 1
        else:
            right -= 1
    return pairs

l = [0, -1, 2, -3, 1]
print(triplet_sum(l))
