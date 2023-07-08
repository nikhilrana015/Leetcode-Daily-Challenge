#define ll long long 
class Solution {
public:

    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;

        for(int i=1; i<weights.size(); i++)
        {   
            ll sum = 1ll*(weights[i] + weights[i-1]);
            pq1.push(sum);
            pq2.push(sum);
        }

        ll maxii = 0, minii = 0;

        while(k>1)
        {
            maxii += pq1.top();
            minii += pq2.top();
            pq1.pop();
            pq2.pop();
            k--;
        }

        return maxii-minii;
        
    }
};