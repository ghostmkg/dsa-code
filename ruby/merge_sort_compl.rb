# ============================================================
# Complex Merge Sort Implementation in Ruby
# Supports:
#   - Custom comparators via blocks
#   - Partial in-place optimization
#   - Optional tracing for visualization
# ============================================================

class MergeSort
    attr_reader :array, :trace_enabled
  
    def initialize(array, trace: false)
      @array = array.dup
      @trace_enabled = trace
    end
  
    # Public method to sort the array
    def sort(&comparator)
      comparator ||= proc { |a, b| a <=> b }  # Default ascending
      merge_sort!(@array, 0, @array.size - 1, &comparator)
      @array
    end
  
    private
  
    # Recursive merge sort helper
    def merge_sort!(arr, left, right, &comparator)
      if right - left <= 8
        insertion_sort!(arr, left, right, &comparator) # Optimization for small arrays
        return
      end
  
      mid = (left + right) / 2
      trace(arr, left, mid, right, "Dividing")
  
      merge_sort!(arr, left, mid, &comparator)
      merge_sort!(arr, mid + 1, right, &comparator)
  
      # Skip merge if already sorted
      return if comparator.call(arr[mid], arr[mid + 1]) <= 0
  
      merge!(arr, left, mid, right, &comparator)
      trace(arr, left, mid, right, "Merged")
    end
  
    # Merge step
    def merge!(arr, left, mid, right, &comparator)
      left_part = arr[left..mid]
      right_part = arr[(mid + 1)..right]
  
      i = 0
      j = 0
      k = left
  
      while i < left_part.size && j < right_part.size
        if comparator.call(left_part[i], right_part[j]) <= 0
          arr[k] = left_part[i]
          i += 1
        else
          arr[k] = right_part[j]
          j += 1
        end
        k += 1
      end
  
      # Copy remaining elements
      while i < left_part.size
        arr[k] = left_part[i]
        i += 1
        k += 1
      end
  
      while j < right_part.size
        arr[k] = right_part[j]
        j += 1
        k += 1
      end
    end
  
    # Simple insertion sort for small subarrays
    def insertion_sort!(arr, left, right, &comparator)
      (left + 1).upto(right) do |i|
        key = arr[i]
        j = i - 1
        while j >= left && comparator.call(arr[j], key) > 0
          arr[j + 1] = arr[j]
          j -= 1
        end
        arr[j + 1] = key
      end
    end
  
    # Debugging/tracing visualization
    def trace(arr, left, mid, right, stage)
      return unless trace_enabled
      puts "[TRACE] #{stage}: #{arr[left..right].inspect} | Left=#{left}, Mid=#{mid}, Right=#{right}"
    end
  end
  
  # ============================================================
  # Example Usage
  # ============================================================
  
  if __FILE__ == $0
    data = Array.new(15) { rand(1..100) }
  
    puts "Original: #{data.inspect}"
  
    sorter = MergeSort.new(data, trace: true)
    sorted = sorter.sort { |a, b| a <=> b }
  
    puts "\nSorted (ascending): #{sorted.inspect}"
  
    # Descending order example
    sorted_desc = MergeSort.new(data).sort { |a, b| b <=> a }
    puts "\nSorted (descending): #{sorted_desc.inspect}"
  end
  