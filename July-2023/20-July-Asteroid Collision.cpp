class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;

        ans.push_back(asteroids[0]);
        int size = 1;

        for(int i=1; i<asteroids.size();)
        {
            if(size==0 or (ans[size-1]>0 and asteroids[i]>0) or (ans[size-1]<0 and asteroids[i]<0))
            {
                ans.push_back(asteroids[i]);
                size+=1;
                i+=1;
            }
            else
            {
                int element_ans = ans[size-1];
                int element_curr = asteroids[i];

                if(element_ans<0 and element_curr>0)
                {
                    ans.push_back(element_curr);
                    size+=1;
                    i+=1;
                }

                else if(abs(element_ans)<abs(element_curr))
                {
                    ans.pop_back();
                    size-=1;

                    if(size==0)
                    {
                        ans.push_back(element_curr);
                        size = 1;
                        i+=1;
                    }
                }
                
                else if(abs(element_ans)==abs(element_curr))
                {
                    ans.pop_back();
                    size-=1;
                    i+=1;
                }
                else
                {
                    i+=1;
                }
            }
        }

        return ans;
    }
};