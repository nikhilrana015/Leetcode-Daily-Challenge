class Solution {
public:

    void helper(string &digits, unordered_map<int,string>&mapping, vector<string>&ans, string &ss, int idx)
    {
        if(idx==digits.length())
        {
            ans.push_back(ss);
            return;
        }

        string digit = mapping[digits[idx]-'0'];

        for(char ch: digit)
        {   
            ss.push_back(ch);
            helper(digits, mapping, ans, ss, idx+1);
            ss.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {

        if(digits=="")
            return {};

        unordered_map<int,string>mapping;

        int no = 2;

        for(char ch='a'; ch<='z'; ch++)
        {
            if(no==7 or no==9)
            {
                mapping[no]+=ch;

                if(mapping[no].length()==4)
                    no+=1;
            }

            else
            {
                mapping[no] += ch;

                if(mapping[no].length()==3)
                    no+=1;
            }
        }

        vector<string>ans;
        string curr = "";
        helper(digits, mapping, ans, curr, 0);

        return ans;
    }
};
