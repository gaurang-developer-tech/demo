#write a python program to compute mean .media , mode standard deviation in a dataset using python program 


import statistics as stats

# Input dataset
data = list(map(float, input("Enter numbers separated by space: ").split()))

mean = stats.mean(data)
median = stats.median(data)
mode = stats.mode(data)
std_dev = stats.stdev(data) 

print("\nResults:")
print("Mean =", mean)
print("Median =", median)
print("Mode =", mode)
print("Standard Deviation =", std_dev)
