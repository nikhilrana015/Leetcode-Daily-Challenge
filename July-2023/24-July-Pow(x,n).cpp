class Solution {
public:

    double exponentialPower(double x, long long int n)
    {
        if(x==0)
            return 0;

        double ans = 1.0;

        while(n>0)
        {
            if(n&1)
            {
                ans = ans * x;
            }

            x = x * x;
            n = n>>1;
        }
        
        return ans;
    }

    double myPow(double x, int n) {

        if(x==0)
            return (double)0;

        bool isPowerNegative = false;

        if(n<0)
            isPowerNegative = true;

        double ans = exponentialPower(x,abs(n));

        cout<<ans<<" ";

        if(isPowerNegative)
            return 1.0/ans;

        return ans;
    }
};