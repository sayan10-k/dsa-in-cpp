class Solution {
public:
    bool isPalindrome(int x) {
        
        int palin=x;
        long sum=0;
        while(x>0) {
            
            sum=(sum * 10) + (x % 10);
            x=x/10;

        }
        if(sum==palin) {
            return true;
        }
        else{
            return false;
        }
        
    }
};