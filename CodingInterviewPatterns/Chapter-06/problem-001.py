# Find the insertion index
# You are given a sorted array that contains unique values, along with an integer target
# If the array contains the target value, return its index
# Otherwise, return the insertion index. This is the index where the target would be if it
# were inserted in order, maintaining the sorted sequence of the array
# Example: Input: nums=[1, 2, 4, 5, 7, 8, 9], target = 4, Output = 2
# Example: Input: nums=[1, 2, 4, 5, 7, 8, 9], target = 6, Output = 4

def find_insertion_index(nums: list[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] >= target:
            right = mid
        else:
            left = mid + 1
    return left

nums = [1, 2, 4, 5, 7, 8, 9]
print(find_insertion_index(nums, 4))
print(find_insertion_index(nums, 6))
