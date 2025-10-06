t = int(input())
for _ in range(t):
    word = input()
    letters = list(word)
    letters.reverse()
    letters[0] = ""
    letters[1] = "i"
    letters.reverse()
    ans = "".join(letters)
    print(ans)
