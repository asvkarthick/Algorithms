# Substring Anagrams
# Given two strings, s and t, both consisting of lowercase English letters, return the number
# of substrings in s that are anagrams of t.
# An anagram is a word or phrase formed by rearranging the letters of another word or phrase,
# using all the original letters exactly once
# Example: Input s = "caabab", t = "aba", Output: 2 (aab, aba)

def substring_anagram(s: str, t: str) -> int:
    if len(t) > len(s):
        return 0
    left = right = 0
    num_substrings = 0
    expected_freqs, window_freqs = [0] * 26, [0] * 26
    for c in t:
        expected_freqs[ord(c) - ord('a')] += 1
    while right < len(s):
        window_freqs[ord(s[right]) - ord('a')] += 1
        if right - left == len(t) - 1:
            if expected_freqs == window_freqs:
                num_substrings += 1
            window_freqs[ord(s[left]) - ord('a')] -= 1
            left += 1
        right += 1
    return num_substrings

s = "caabab"
t = "aba"
print(substring_anagram(s, t))
