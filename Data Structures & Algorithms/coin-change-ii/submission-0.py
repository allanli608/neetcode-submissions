class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        """
        x   dollar amt
        coins avaialbel

        dp[i][j] means using the first 0-i coins, how many unique ways are there to achieve j?
        dp[i][j] = dp[i-1][j-coin[i]] + dp[i-1][j]

        """

        dp = [[0] * (amount + 1)] * len(coins)

        # there is always 1 way to make 0 for each: which is just to use 0 coins

        for i in range(len(coins)):
            for j in range(amount + 1):
                if j == 0:
                    dp[i][j] = 1 # to make 0 coins there is 1 way, you just dont add anything
                    continue
                res = 0
                if j - coins[i] >= 0:
                    res += dp[i][j - coins[i]]
                
                if i - 1 >= 0:
                    res += dp[i - 1][j]
                dp[i][j] = res
        
        return dp[len(coins) - 1][amount]
                
