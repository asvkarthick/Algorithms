# Longest Uniform Substring After Replacements
# A uniform substring is one in which all characters are identical. Given a string, determine the
# length of the longest uniform substring that can be formed by replacing up to K characters
# Example: aabcdcca, k = 2, Output: 5 (aaccccca)

def longest_uniform_substring_after_replacements(s: str, k: int) -> int:
    freqs = {}
    highest_freq = max_len = 0
    left = right = 0
    while right < len(s):
        freqs[s[right]] = freqs.get(s[right], 0) + 1
        highest_freq = max(highest_freq, freqs[s[right]])
        num_chars_to_replace = (right - left + 1) - highest_freq
        if num_chars_to_replace > k:
            freqs[s[left]] -= 1
            left += 1
        max_len = right - left + 1
        right += 1
    return max_len

s = "aabcdcca"
print(longest_uniform_substring_after_replacements(s, 2))
