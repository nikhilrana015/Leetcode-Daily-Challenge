class Solution {
public:

    bool isPossibleToTravel(vector<int>&dist, double hour, int speed)
    {   
        double totalTimeTaken = 0;
        int size = dist.size();

        for(int i=0; i<size; i++)
        {
            double timeTaken = dist[i]/(double)speed;
            totalTimeTaken += timeTaken;

            if(i!=size-1)
            {
                totalTimeTaken = ceil(totalTimeTaken);
            }
        }

        return totalTimeTaken<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1000000000;
        int ans = -1;

        while(left<=right)
        {
            int mid = (left+right)/2;

            if(isPossibleToTravel(dist, hour, mid))
            {   
                ans = mid;
                right = mid-1;

            } else {
                left = mid+1;
            }
        }

        return ans;

    }
};
