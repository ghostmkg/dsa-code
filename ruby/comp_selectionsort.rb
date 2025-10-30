# ============================================================
# Complex Selection Sort Implementation in Ruby
# Features:
#   - Custom comparators
#   - Optional in-place or copy sorting
#   - Stable mode (optional)
#   - Tracing for visualization
# ============================================================

class SelectionSort
    attr_reader :trace_enabled, :stable_mode
  
    def initialize(trace: false, stable: false)
      @trace_enabled = trace
      @stable_mode = stable
    end
  
    # ------------------------------------------------------------
    # Public interface
    # in_place: true → modifies the array directly
    # comparator: optional custom block
    # ------------------------------------------------------------
    def sort(array, in_place: false, &comparator)
      comparator ||= proc { |a, b| a <=> b }
      arr = in_place ? array : array.dup
  
      trace("Starting Selection Sort", arr)
  
      if stable_mode
        stable_selection_sort!(arr, &comparator)
      else
        standard_selection_sort!(arr, &comparator)
      end
  
      trace("Final sorted array", arr)
      arr
    end
  
    private
  
    # ------------------------------------------------------------
    # Standard (unstable) selection sort
    # ------------------------------------------------------------
    def standard_selection_sort!(arr, &comparator)
      n = arr.size
      (0...n - 1).each do |i|
        min_idx = i
        ((i + 1)...n).each do |j|
          if comparator.call(arr[j], arr[min_idx]) < 0
            min_idx = j
          end
        end
  
        trace("Swapping index #{i} (#{arr[i]}) with #{min_idx} (#{arr[min_idx]})", arr)
        arr[i], arr[min_idx] = arr[min_idx], arr[i] unless i == min_idx
      end
    end
  
    # ------------------------------------------------------------
    # Stable variant of selection sort
    # ------------------------------------------------------------
    def stable_selection_sort!(arr, &comparator)
      n = arr.size
      (0...n - 1).each do |i|
        min_idx = i
        ((i + 1)...n).each do |j|
          if comparator.call(arr[j], arr[min_idx]) < 0
            min_idx = j
          end
        end
  
        min_value = arr[min_idx]
  
        # Move elements between i and min_idx forward to make space
        while min_idx > i
          arr[min_idx] = arr[min_idx - 1]
          min_idx -= 1
        end
  
        arr[i] = min_value
        trace("Inserted #{min_value.inspect} at index #{i}", arr)
      end
    end
  
    # ------------------------------------------------------------
    # Tracing utility
    # ------------------------------------------------------------
    def trace(msg, arr)
      return unless trace_enabled
      puts "[TRACE] #{msg}: #{arr.inspect}"
    end
  end
  
  # ============================================================
  # Example Usage
  # ============================================================
  
  if __FILE__ == $0
    data = [5, 3, 8, 3, 1, 9, 2]
  
    puts "Original: #{data.inspect}\n\n"
  
    # Standard Selection Sort
    sorter = SelectionSort.new(trace: true)
    sorted = sorter.sort(data)
    puts "\nUnstable sort result: #{sorted.inspect}"
  
    # Stable Selection Sort (preserves order of equal elements)
    stable_sorter = SelectionSort.new(trace: true, stable: true)
    sorted_stable = stable_sorter.sort(data)
    puts "\nStable sort result: #{sorted_stable.inspect}"
  
    # Custom comparator (descending order)
    desc_sorted = sorter.sort(data) { |a, b| b <=> a }
    puts "\nDescending order: #{desc_sorted.inspect}"
  end
  