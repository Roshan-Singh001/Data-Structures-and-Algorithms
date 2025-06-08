# Greedy Approach

def fractional_knapsack(values,weights,capacity):
    n = len(values)
    items = [(i,values[i],weights[i],values[i]/weights[i]) for i in range(n)]
    items.sort(key=lambda x: x[3],reverse=True)
    total_profit = 0.0

    for index,value,weight,ratio in items:
        if weight <= capacity:
            total_profit+=value
            capacity-=weight
        else:
            fraction = capacity/weight
            total_profit+= fraction*value
            break
    return total_profit

values = [10,5,15,7,6,18,3]
weights = [2,3,5,7,1,4,1]
capacity = 15
print(f"Values: {values}")
print(f"Weights: {weights}\n")

print(f"Maximum Profit: {fractional_knapsack(values,weights,capacity)}")