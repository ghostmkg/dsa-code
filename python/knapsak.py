def fractional_knapsack(values, weights, max_capacity):
    n = len(values)
    items = [[values[i], weights[i]] for i in range(n)]
    items.sort(key=lambda x: x[0] / x[1], reverse=True)

    total_value = 0.0
    remaining_capacity = max_capacity

    for value, weight in items:
        if weight <= remaining_capacity:
            total_value += value
            remaining_capacity -= weight
        else:
            total_value += (value / weight) * remaining_capacity
            break

    return total_value


if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [10, 20, 30]
    max_capacity = 50

    print(fractional_knapsack(values, weights, max_capacity))
