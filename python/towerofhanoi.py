def tower_of_hanoi(n, source, auxiliary, destination):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return
    
    # Move n-1 disks from source to auxiliary
    tower_of_hanoi(n - 1, source, destination, auxiliary)
    
    # Move the nth disk from source to destination
    print(f"Move disk {n} from {source} to {destination}")
    
    # Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n - 1, auxiliary, source, destination)

# Main function
def main():
    n = int(input("Enter number of disks: "))
    print("The sequence of moves involved:")
    tower_of_hanoi(n, 'A', 'B', 'C')  # A=source, B=auxiliary, C=destination

if __name__ == "__main__":
    main()
