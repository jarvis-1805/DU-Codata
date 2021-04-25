from sys import stdin

def knapsack(prod, wt, val, W) :
    n = len(val)
    dp = [[0 for j in range(W+1)] for i in range(n+1)]
    
    for i in range(1, n+1):
        for j in range(1, W+1):
            if j < wt[i-1]:
                ans = dp[i-1][j]
            else:
                ans1 = val[i-1] + dp[i-1][j-wt[i-1]]
                ans2 = dp[i-1][j]
                ans = max(ans1, ans2)
            dp[i][j] = ans

    reconstruction = []
    i = len(wt)
    j = W
    while i > 0:
        if dp[i][j] != dp[i - 1][j]:
            reconstruction.append([prod[i - 1], wt[i - 1], val[i - 1]])
            j -= wt[i - 1]
        i -= 1

    reconstruction.reverse()

    return dp[n][W], reconstruction

	

def takeInput() :

    '''
            ----------------------------------------------------
           | Jute bag  |  Product in   |   Weight of  |  Price  |
           |  number   |    bag        |   jute bag   |   (Rs)  |
           |           |               |     (Kg)     |         |
           |-----------|---------------|--------------|---------|
           |     1     |  Onions       |       2      |    63   |
           |     2     |  Potatoes     |       2      |    80   |
           |     3     |  Maize        |       3      |    95   |
           |     4     |  Rice         |       4      |    430  |
           |     5     |  Wheat        |       5      |    450  |
            ----------------------------------------------------
    '''


    n = 5
    products = ['Onions', 'Potatoes', 'Maize', 'Rice', 'Wheat']
    weights = [2, 2, 3, 4, 5]
    values = [63, 80, 95, 430, 450]

    # Maximum weight will be 110 - 102 since 8Kg is only the
    # weight other than boatman and farmer that boat can afford.
    maxWeight = int(8)

    return products, weights, values, n, maxWeight


#main
products, weights, values, n, maxWeight = takeInput()
maxim, reconstructed = knapsack(products, weights, values, maxWeight)
print("The farmer should select:")
for i in reconstructed:
    print(i[0] + " of weight " + str(i[1]) + " of value " + str(i[2]))

print("\nThen the maximum price the farmer can get is:", maxim)