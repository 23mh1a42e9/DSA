class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX,profit=0;
        for(int p:prices){
            minprice=min(minprice,p);
            profit=max(profit,p-minprice);
        }
        return profit;
    }
};