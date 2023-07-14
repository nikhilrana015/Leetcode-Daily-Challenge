class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preReq) {
        
        vector<int>indegree(numCourses, 0);
        unordered_map<int,vector<int>>graph;

        for(int i=0; i<preReq.size(); i++)
        {   
            int a = preReq[i][0];
            int b = preReq[i][1];

            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;
        
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        int cnt = 0;

        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            cnt+=1;

            for(int neighb: graph[val])
            {
                indegree[neighb]-=1;
                
                if(indegree[neighb]==0)
                    q.push(neighb);
            }
        }

        return cnt==numCourses;
    }
};