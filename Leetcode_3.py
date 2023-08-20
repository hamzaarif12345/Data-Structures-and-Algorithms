# length of maximum substring 

def length_of_longest_substring(s: str) -> int:
    left, right = 0, 0
    chars = set()
    max_length = 0
    
    while right < len(s):
        if s[right] not in chars:
            chars.add(s[right])
            right += 1
            max_length = max(max_length, right - left)
        else:
            chars.remove(s[left])
            left += 1
    
    return max_length