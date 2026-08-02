class Solution {
public:
    int reversal(int n){
        int rev=0;
        while(n){
            int dig=n%10;
            rev=rev*10+dig;
            n/=10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev=reversal(n);
        return abs(rev-n);
    }
};