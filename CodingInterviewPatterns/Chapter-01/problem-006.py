# Largest Container
# You are given an array of numbers, each representing the height of a vertical line
# on a graph. A container can be formed with any pair of these lines, along the
# x-axis of the graph.
# Return the amount of water which the largest container can hold

def max_volume(height: list[int]) -> int:
    left, right = 0, len(height) - 1
    maxvol = 0
    while left < right:
        vol = min(height[left], height[right]) * (right - left)
        maxvol = max(maxvol, vol)
        if height[left] < height[right]:
            left += 1
        elif height[left] > height[right]:
            right -= 1
        else:
            left += 1
            right -= 1
    return maxvol

heights = []
print(heights, "Max volume = ", max_volume(heights))
heights = [1]
print(heights, "Max volume = ", max_volume(heights))
heights = [0, 1, 0]
print(heights, "Max volume = ", max_volume(heights))
heights = [3, 3, 3, 3]
print(heights, "Max volume = ", max_volume(heights))
heights = [2, 7, 8, 3, 7, 6]
print(heights, "Max volume = ", max_volume(heights))
