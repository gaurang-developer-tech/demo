import pandas as pd

# Create Sample DataFrames
data1 = {
    "ID": [1, 2, 3, 4, 5],
    "Name": ["A", "B", "C", "D", "E"],
    "Marks": [80, 90, None, 70, 60]
}

data2 = {
    "ID": [1, 2, 3, 4, 5],
    "City": ["Delhi", "Mumbai", "Pune", None, "Chennai"]
}

df1 = pd.DataFrame(data1)
df2 = pd.DataFrame(data2)

print("Original DataFrame 1:\n", df1)
print("\nOriginal DataFrame 2:\n", df2)

# 1. Handling Missing Values (FIXED: Reassignment instead of inplace)
df1["Marks"] = df1["Marks"].fillna(df1["Marks"].mean())   # replace with mean
df2["City"] = df2["City"].fillna("Unknown")               # replace with unknown

print("\nAfter Handling Missing Values:\n", df1, "\n", df2)

# 2. Filtering Data
filtered = df1[df1["Marks"] > 75]
print("\nFiltered Students (Marks > 75):\n", filtered)

# 3. Merging Data
merged = pd.merge(df1, df2, on="ID")
print("\nMerged Data:\n", merged)

# 4. Reshaping Data
# Convert wide → long (melt)
reshaped = pd.melt(merged, id_vars=["ID", "Name"], 
                   value_vars=["Marks", "City"],
                   var_name="Attribute", value_name="Value")

print("\nReshaped (Melted) Data:\n", reshaped)