class Solution {
public:
    /**
     * 计算你能获得的最大收益
     * 
     * @param prices Prices[i]即第i天的股价
     * @return 整型
     */
    int calculateMax(vector<int> prices) {
		int len = prices.size();
        vector<int> leftmax(len);
        vector<int> rightmax(len);
        
        //正序遍历
        int primin = prices[0];
        leftmax[0] = 0;
        for(int i=1;i<len;++i){
            primin = min(primin, prices[i]);
            leftmax[i] = max(leftmax[i-1], prices[i] - primin);
        }
        
        //后序遍历
        int primax = prices[len-1];
        rightmax[len-1] = 0;
        for(int i=len-2;i>=0;--i){
            primin = max(primax, prices[i]);
            rightmax[i] = max(rightmax[i+1], primax - prices[i]);
        }
        
        int pmax = 0;
        for(int i=0;i<len;++i)
            pmax = max(pmax, leftmax[i] + rightmax[i]);
        return pmax;
        
    }
};