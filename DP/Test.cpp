#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][0]不操作
        //dp[i][1]第一次持有
        //dp[i][2]第一次不持有
        //dp[i][3]第二次持有
        //dp[i][4]第二次不持有
        int sz = prices.size();
        vector<vector<int>> dp(sz, vector<int>(5, 0));
        dp[0][1] = dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        // for(int i=0; i<prices.size(); i++)
        // {
        //     cout<<dp[i][0]<< " "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<dp[i][4]<<endl;
        // }
        return dp[prices.size() - 1][4];
    }
};