# Given an array of integers, return all triplets [a, b, c] such that a + b + c = 0
# The solution must not contain duplicate triplets
# If no such triplets are found return an empty array
def triplet_sum_brute_force(nums: list[int]) -> list[int]:
    n = len(nums)
    triplets = set()

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if nums[i] + nums[j] + nums[k] == 0:
                    triplet = tuple(sorted([nums[i], nums[j], nums[k]]))
                    triplets.add(triplet)

    return [list(triplet) for triplet in triplets]

l = [0, -1, 2, -3, 1]
print(triplet_sum_brute_force(l))
