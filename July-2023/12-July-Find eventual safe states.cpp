class Solution {
public:

    bool dfs(int curr, vector<vector<int>>&graph, vector<int>&isVisited, vector<int>&dp)
    {
        if(graph[curr].size()==0)
            return true;

        if(dp[curr]!=-1)
            return dp[curr];

        isVisited[curr] = 1;
        int cnt = 0;

        for(int neighb: graph[curr])
        {   
            if(dp[neighb]==1)
                cnt+=1;

            else if(isVisited[neighb]==0)
            {
                cnt += (int)dfs(neighb, graph, isVisited, dp);
            }
        }

        //cout<<curr<<": "<<cnt<<": "<<graph[curr].size()<<"\n";

        return dp[curr] = (cnt==graph[curr].size());
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int size = graph.size();
        vector<int>safe;
        vector<int>dp(size,-1);

        for(int i=0; i<size; i++)
        {   
            vector<int>isVisited(size,0);
            bool ans = dfs(i, graph, isVisited, dp);
            if(ans)
                safe.push_back(i);
        }

        return safe;
    }
};