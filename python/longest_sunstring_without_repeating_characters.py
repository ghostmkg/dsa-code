dup = set()
left = 0
max_len = 0
for right in range(len(s)):
  while s[right] in dup:
    dup.remove(s[left])
    left+=1
  dup.add(s[right])
  max_len = max(max_len, right-left+1)
print(max_len)