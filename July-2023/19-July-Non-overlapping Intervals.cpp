class Solution {
public:

    static bool compare(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 0;

        for(int i=1; i<intervals.size(); i++)
        {
            if(end<=intervals[i][0])
            {
                end = max(end, intervals[i][1]);
            } else {
                cnt+=1;
            }
        }

        return cnt;
    }
};