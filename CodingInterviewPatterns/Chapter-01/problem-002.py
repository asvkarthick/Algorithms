def pair_sum_sorted(nums: list[int], target: int) -> list[int]:
    left, right = 0, len(nums) - 1
    while left < right:
        sum = nums[left] + nums[right]
        if sum < target:
            left = left + 1
        elif sum > target:
            right = right - 1
        else:
            return [left, right]

    return []

l = [1, 2, 3, 4, 5]
print(pair_sum_sorted(l, 9))
print(pair_sum_sorted(l, 2))
