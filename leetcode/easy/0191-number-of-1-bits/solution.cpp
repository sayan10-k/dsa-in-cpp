class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0) {
            int lastdig=n&1;
            count=count+lastdig;
            n=n>>1;
        }
        return count;
    }
};