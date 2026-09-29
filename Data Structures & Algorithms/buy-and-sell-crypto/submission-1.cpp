class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int l=0,r=1;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit=0;
                profit += prices[r]-prices[l];
                maxProfit=max(maxProfit,profit);
            }else{
                l=r;
            }
            r++;
        }
        return maxProfit;
    }
};
