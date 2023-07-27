#define ll long long
class Solution {
public:

    bool isPossible(int n, vector<int>&batteries, ll currTime)
    {
        /*
            2 [3,5,9]
            9 5
        */
        ll sum = 0;

        for(int k: batteries)
        {
            sum += min((ll)k, currTime);
        }
        
        return sum>=1ll*n*currTime;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        int size = batteries.size();

        ll left = 1;
        ll right = 0;
        ll ans = 0;

        //sort(batteris.begin(), batteries.end(), greater<int>());

        for(auto v: batteries)
            right += v;

        right /= n;

        while(left<=right)
        {
            ll mid = (left+right)/(ll)2;
            bool isCorrectTime = isPossible(n, batteries, mid);

            if(isCorrectTime) {
                ans = mid;
                left = mid+1;
            }else {
                right = mid-1;
            }
        }

        return ans;
        
    }
};
