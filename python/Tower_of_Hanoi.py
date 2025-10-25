def tower_of_hanoi(n, source, destination, auxiliary):
    """
    Solves the Tower of Hanoi puzzle recursively.

    n: The number of disks to move (Disk 'n' is the largest).
    source: The starting rod (e.g., 'A').
    destination: The final rod (e.g., 'C').
    auxiliary: The intermediate rod (e.g., 'B').
    """
    
    # 1. Base Case: If there is only one disk, move it directly.
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return

    # 2. Recursive Step 1: Move n-1 disks from Source to Auxiliary, 
    #    using Destination as the temporary rod.
    tower_of_hanoi(n - 1, source, auxiliary, destination)

    # 3. Move the largest disk (disk 'n') from Source to Destination.
    print(f"Move disk {n} from {source} to {destination}")

    # 4. Recursive Step 2: Move the n-1 disks from Auxiliary to Destination, 
    #    using Source as the temporary rod.
    tower_of_hanoi(n - 1, auxiliary, destination, source)

# --- Example Usage ---
N_DISKS = 3 # You can change this number
print(f"--- Solving Tower of Hanoi for {N_DISKS} Disks ---")

# Call the function to move the disks from 'A' (Source) to 'C' (Destination) 
# using 'B' (Auxiliary)
tower_of_hanoi(N_DISKS, 'A', 'C', 'B') 

# The total number of moves will be 2^N - 1 (e.g., 7 moves for 3 disks)