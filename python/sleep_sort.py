import time
import threading

def sleep_sort(numbers):
    """
    Sorts a list of positive numbers using the Sleep Sort algorithm.
    WARNING: This is a conceptual and impractical algorithm. Do not use
    it for serious applications. It may not work reliably and is
    inefficient for large numbers or lists.
    """
    sorted_result = []

    def sleep_and_append(num):
    
        time.sleep(num / 100) 
        sorted_result.append(num)

    threads = []
    for num in numbers:
        thread = threading.Thread(target=sleep_and_append, args=(num,))
        threads.append(thread)
        thread.start()

    
    for thread in threads:
        thread.join()
        
    return sorted_result

my_numbers = [64, 34, 25, 12, 22, 11, 90]
print(f"Original: {my_numbers}")

sorted_numbers = sleep_sort(my_numbers)
print(f"Sorted:   {sorted_numbers}")
