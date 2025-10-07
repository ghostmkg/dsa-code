def find_leaders(arr):
    n = len(arr)
    leaders = []
    
    # Start from the last element, which is always a leader
    max_from_right = arr[-1]
    leaders.append(max_from_right)
    
    # Traverse the array from right to left
    for i in range(n - 2, -1, -1):
        if arr[i] > max_from_right:
            leaders.append(arr[i])
            max_from_right = arr[i]
    
    # Reverse the result since we collected leaders from the right
    leaders.reverse()
    return leaders


#main
arr = list(map(int, input("Enter elements of array separated by space: ").split()))

print("Leaders in the array are:", find_leaders(arr))
