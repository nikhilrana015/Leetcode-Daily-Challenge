class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    bool isValid(int nx, int ny, int M, int N, vector<vector<int>>&isVisited)
    {
        if(nx<0 or ny<0 or nx>=M or ny>=N)
            return false;

        if(isVisited[nx][ny])
            return false;

        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>isVisited(m, vector<int>(n, 0));
        vector<vector<int>>dist(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    isVisited[i][j] = 1;
                }
                    
            }
        }

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                pair<int,int>p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(isValid(nx, ny, m, n, isVisited))
                    {
                        isVisited[nx][ny] = 1;
                        dist[nx][ny] = 1 + dist[x][y];
                        q.push({nx,ny});
                    }
                }
            }
        }

        return dist;
    }
};
