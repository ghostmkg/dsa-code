def wrap(string, max_width):
    result = ""
    for i in range(0, len(string), max_width):
        result += string[i:i+max_width] + "\n"
    return result.strip()

#take input 1. string 2. maximum_width
string = input().strip()
max_width = int(input().strip())

print(wrap(string, max_width))