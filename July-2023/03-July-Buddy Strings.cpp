class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.length()!=goal.length())
            return false;

        int len = s.length();

        if(s==goal)
        {
            unordered_map<int,int>cnt;
            
            for(int i=0; i<len; i++)
            {
                cnt[s[i]]++;

                if(cnt[s[i]]>=2)
                    return true;
            }

            return false;

        }

        int cnt = 0;
        
        int idx1, idx2;
        idx1 = idx2 = -1;

        for(int i=0; i<len; i++)
        {
            if(s[i]!=goal[i])
            {
                cnt+=1;
                
                if(idx1==-1)
                    idx1 = i;

                else if(idx2==-1)
                    idx2 = i;
            }
        }

        if(cnt!=2)
            return false;
            
        swap(s[idx1],s[idx2]);

        return s==goal;
        
    }
};