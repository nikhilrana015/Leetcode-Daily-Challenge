class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<int>>mapping;

        for(int i=0; i<roads.size(); i++)
        {
            vector<int>road = roads[i];

            int a = road[0];
            int b = road[1];

            mapping[a].push_back(b);
            mapping[b].push_back(a);

        }

        int maxii = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;

                else
                {
                    int cnt_a = mapping[i].size();
                    int cnt_b = mapping[j].size();
                    int toSubtract = 0;

                    for(int k: mapping[i])
                    {
                        if(k==j)
                        {
                            toSubtract = 1;
                            break;
                        }
                    }

                    maxii = max(maxii, (cnt_a + cnt_b) - toSubtract);

                }
            }
        }

        return maxii;

    }
};
