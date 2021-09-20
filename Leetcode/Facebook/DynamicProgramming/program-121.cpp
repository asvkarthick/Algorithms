/* Program: Best time to Buy and Sell stock
 * Weblink: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (minPrice > prices[i])
                minPrice = prices[i];
            if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};
