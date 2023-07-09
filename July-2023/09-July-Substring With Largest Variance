class Solution {
public:

    int calculate(vector<int>&cnt)
    {
        int minV = INT_MAX;
        int maxV = INT_MIN;

        for(int i=0; i<26; i++)
        {
            if(cnt[i]>0)
            {
                minV = min(minV, cnt[i]);
                maxV = max(maxV, cnt[i]);
            }
        }

        return maxV-minV;

    }

    int largestVariance(string s) {
        int size = s.length();
        unordered_map<char,int>uniqueChars;
        int maxVariance = 0;
        vector<char>chars;

        for(int i=0; i<size; i++)
        {
            if(uniqueChars.find(s[i])==uniqueChars.end())
                chars.push_back(s[i]);

            uniqueChars[s[i]] = 1;
        }

        for(int m=1; m<=2; m++)
        {
            for(int i=0; i<chars.size(); i++)
            {
                for(int j=0; j<chars.size(); j++)
                {   
                    if(i==j)
                        continue;

                    int cnt1 = 0;
                    int cnt2 = 0;

                    for(int k=0; k<size; k++)
                    {
                        if(s[k]==chars[i])
                            cnt1+=1;
                        else if(s[k]==chars[j])
                            cnt2+=1;

                        if(cnt1<cnt2)
                            cnt1 = cnt2 = 0;

                        if(cnt1>cnt2 and cnt1>0 and cnt2>0)
                            maxVariance = max(maxVariance, cnt1-cnt2);
                    }
                }
            }

            reverse(s.begin(), s.end());
        }
        

        return maxVariance;

    }
};