class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l=1;
        int h=x;
        while(l<=h){
            double m=l+(h-l)/2;
            if((double)m*m<x)l=m+1;
            else if((double)m*m>x)h=m-1;
            else return m;
        }
        return l-1;
    }
};