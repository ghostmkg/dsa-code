# Stack implementation using list

stack = []

# Push elements
stack.append(10)
stack.append(20)
stack.append(30)
print("Stack after pushes:", stack)

# Pop element
popped = stack.pop()
print("Popped element:", popped)
print("Stack after pop:", stack)

# Peek top element
print("Top element:", stack[-1])
