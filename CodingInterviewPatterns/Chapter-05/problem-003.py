# Longest Substring With Unique Characters
# Given a string, determine the length of its longest substring that consists only
# of unique characters
# Example: Input s = "abcba", Output = 3

def longest_substring(s: str) -> int:
    left = right = 0
    hash_map = {}
    max_len = 0
    while right < len(s):
        if s[right] in hash_map and hash_map[s[right]] >= left:
            left = hash_map[s[right]] + 1
        max_len = max(max_len, right - left + 1)
        hash_map[s[right]] = right
        right += 1
    return max_len

s = "abcba"
print(longest_substring(s))
