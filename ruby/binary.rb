# ============================================================
# Complex Binary Search Implementation in Ruby
# Features:
#   - Supports custom comparators
#   - Iterative and recursive modes
#   - Can find first/last occurrence or insertion index
#   - Optional tracing for debugging
# ============================================================

class BinarySearch
    attr_reader :trace_enabled
  
    def initialize(trace: false)
      @trace_enabled = trace
    end
  
    # ------------------------------------------------------------
    # Public search interface
    # mode: :iterative or :recursive
    # variant: :exact, :first, :last, :insert
    # comparator: custom comparison block
    # ------------------------------------------------------------
    def search(array, target, mode: :iterative, variant: :exact, &comparator)
      comparator ||= proc { |a, b| a <=> b }
      array = array.dup.freeze # Defensive copy for safety
  
      check_sorted!(array, &comparator)
  
      case mode
      when :iterative
        send("iterative_#{variant}", array, target, &comparator)
      when :recursive
        send("recursive_#{variant}", array, target, 0, array.size - 1, &comparator)
      else
        raise ArgumentError, "Unsupported mode: #{mode}"
      end
    end
  
    private
  
    # ------------------------------------------------------------
    # Iterative exact match
    # ------------------------------------------------------------
    def iterative_exact(array, target, &comparator)
      left, right = 0, array.size - 1
  
      while left <= right
        mid = (left + right) / 2
        trace(left, mid, right, array[mid])
  
        case comparator.call(array[mid], target)
        when 0 then return mid
        when -1 then left = mid + 1
        when 1 then right = mid - 1
        end
      end
  
      nil
    end
  
    # ------------------------------------------------------------
    # Iterative first occurrence
    # ------------------------------------------------------------
    def iterative_first(array, target, &comparator)
      result = nil
      left, right = 0, array.size - 1
  
      while left <= right
        mid = (left + right) / 2
        trace(left, mid, right, array[mid])
  
        case comparator.call(array[mid], target)
        when 0
          result = mid
          right = mid - 1
        when -1
          left = mid + 1
        when 1
          right = mid - 1
        end
      end
  
      result
    end
  
    # ------------------------------------------------------------
    # Iterative last occurrence
    # ------------------------------------------------------------
    def iterative_last(array, target, &comparator)
      result = nil
      left, right = 0, array.size - 1
  
      while left <= right
        mid = (left + right) / 2
        trace(left, mid, right, array[mid])
  
        case comparator.call(array[mid], target)
        when 0
          result = mid
          left = mid + 1
        when -1
          left = mid + 1
        when 1
          right = mid - 1
        end
      end
  
      result
    end
  
    # ------------------------------------------------------------
    # Iterative insertion index (where target should go)
    # ------------------------------------------------------------
    def iterative_insert(array, target, &comparator)
      left, right = 0, array.size
  
      while left < right
        mid = (left + right) / 2
        trace(left, mid, right, array[mid])
  
        if comparator.call(array[mid], target) < 0
          left = mid + 1
        else
          right = mid
        end
      end
  
      left
    end
  
    # ------------------------------------------------------------
    # Recursive search variants
    # ------------------------------------------------------------
    def recursive_exact(array, target, left, right, &comparator)
      return nil if left > right
      mid = (left + right) / 2
      trace(left, mid, right, array[mid])
  
      case comparator.call(array[mid], target)
      when 0
        mid
      when -1
        recursive_exact(array, target, mid + 1, right, &comparator)
      when 1
        recursive_exact(array, target, left, mid - 1, &comparator)
      end
    end
  
    def recursive_first(array, target, left, right, &comparator)
      return nil if left > right
      mid = (left + right) / 2
      trace(left, mid, right, array[mid])
  
      case comparator.call(array[mid], target)
      when 0
        left_result = recursive_first(array, target, left, mid - 1, &comparator)
        left_result.nil? ? mid : left_result
      when -1
        recursive_first(array, target, mid + 1, right, &comparator)
      when 1
        recursive_first(array, target, left, mid - 1, &comparator)
      end
    end
  
    def recursive_last(array, target, left, right, &comparator)
      return nil if left > right
      mid = (left + right) / 2
      trace(left, mid, right, array[mid])
  
      case comparator.call(array[mid], target)
      when 0
        right_result = recursive_last(array, target, mid + 1, right, &comparator)
        right_result.nil? ? mid : right_result
      when -1
        recursive_last(array, target, mid + 1, right, &comparator)
      when 1
        recursive_last(array, target, left, mid - 1, &comparator)
      end
    end
  
    def recursive_insert(array, target, left, right, &comparator)
      return left if left >= right
      mid = (left + right) / 2
      trace(left, mid, right, array[mid])
  
      if comparator.call(array[mid], target) < 0
        recursive_insert(array, target, mid + 1, right, &comparator)
      else
        recursive_insert(array, target, left, mid, &comparator)
      end
    end
  
    # ------------------------------------------------------------
    # Utility methods
    # ------------------------------------------------------------
    def check_sorted!(array, &comparator)
      (0...array.size - 1).each do |i|
        if comparator.call(array[i], array[i + 1]) > 0
          raise ArgumentError, "Array must be sorted for binary search."
        end
      end
    end
  
    def trace(left, mid, right, value)
      return unless trace_enabled
      puts "[TRACE] Left=#{left}, Mid=#{mid}, Right=#{right}, MidVal=#{value.inspect}"
    end
  end
  
  # ============================================================
  # Example Usage
  # ============================================================
  
  if __FILE__ == $0
    arr = [1, 2, 3, 3, 3, 4, 5, 7, 9, 11]
    bs = BinarySearch.new(trace: true)
  
    puts "\nExact match (3): #{bs.search(arr, 3, mode: :iterative)}"
    puts "First occurrence (3): #{bs.search(arr, 3, variant: :first)}"
    puts "Last occurrence (3): #{bs.search(arr, 3, variant: :last)}"
    puts "Insertion index (6): #{bs.search(arr, 6, variant: :insert)}"
  
    # Custom comparator example (descending array)
    arr_desc = arr.reverse
    puts "\nDescending search (9): " +
         "#{bs.search(arr_desc, 9, variant: :exact) { |a, b| b <=> a }}"
  end
  