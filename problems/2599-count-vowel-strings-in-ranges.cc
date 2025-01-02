/*
 words = ["aba", "bcb", "ece", "aa", "e"]
prefixSum = [1, 1, 2, 3, 4]  // cumulative count of valid words
queries = [[0,2], [1,4]]  // example queries

For query [0,2]:
- Want count from index 0 to 2
- prefixSum[2] - prefixSum[-1] = 2 - 0 = 2 valid words

For query [1,4]:
- Want count from index 1 to 4
- prefixSum[4] - prefixSum[0] = 4 - 1 = 3 valid words
 */ 


