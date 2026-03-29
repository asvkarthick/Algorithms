# Longest Substring With Unique Characters
# Given a string, determine the length of its longest substring that consists only
# of unique characters
# Example: Input s = "abcba", Output = 3

def longest_substring(s: str) -> int:
    left = right = 0
    hash_set = set()
    max_len = 0
    while right < len(s):
        while s[right] in hash_set:
            hash_set.remove(s[left])
            left += 1
        max_len = max(max_len, right - left + 1)
        hash_set.add(s[right])
        right += 1
    return max_len

s = "abcba"
print(longest_substring(s))
