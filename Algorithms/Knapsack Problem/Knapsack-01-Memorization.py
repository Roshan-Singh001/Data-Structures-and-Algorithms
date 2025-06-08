# Recursive Approach
import sys

def knapsack_problem(dp,n,capacity,values,weights):
    pass

def knapsackDP(n,capacity,values,weights):
    dp = [[-1 for i in range((capacity+1))]for j in range(n)]
    return knapsack_problem(dp,n,capacity,values,weights)

values = [10,5,15,7,6,18,3]
weights = [2,3,5,7,1,4,1]
capacity = 15
n = len(values)

print(f"Values: {values}")
print(f"Weights: {weights}\n")

print(f"Maximum Profit: {knapsackDP(n,capacity,values,weights)}")