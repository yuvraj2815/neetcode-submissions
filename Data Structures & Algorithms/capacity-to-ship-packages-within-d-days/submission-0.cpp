class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int res=r;
        while(l<=r){
            int cap=(l+r)/2;
            if(carShip(weights,days,cap)){
                res=min(res,cap);
                r=cap-1;
            }else{
                l=cap+1;
            }
        }
        return res;
    }

private:
    bool carShip(const vector<int> &weights,int &days, int &cap){
        int ship=1;
        int currCap=cap;
        for(int w:weights){
            if(currCap-w<0){
                ship++;
                if(ship>days) return false;
                currCap=cap;
            }
            currCap -=w;
        }
        return true;
    }
};