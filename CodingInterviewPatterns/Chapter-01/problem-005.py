# Is Palindrome Valid
# A palindrome is a sequence of characters that reads the same forward and backward
# Given a string, determine if it's a palindrome after removing all non-alphanumeric
# characters. A character is alphanumeric if it's either a letter or a number

def is_palindrome(s: str) -> bool:
    left, right = 0, len(s) - 1
    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True

s = "madam"
print(s, is_palindrome(s))
s = "ma!!da$$m"
print(s, is_palindrome(s))
s = "ma!!dia$$m"
print(s, is_palindrome(s))
