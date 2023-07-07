class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        /*
            TTFF
            1 2 2 2
        */
        int i = 0;
        int j = 0;
        int cnt_T=0;
        int cnt_F=0;
        int maxLen = 0;


        while(j<answerKey.length())
        {
            cnt_T += (answerKey[j]=='T')? 1:0;
            cnt_F += (answerKey[j]=='F')? 1:0;

            while(cnt_T>k and cnt_F>k) {
                
                if(answerKey[i]=='T')
                    cnt_T-=1;
                else
                    cnt_F-=1;

                i++;                
            }


            maxLen = max(maxLen, (j-i+1));

            j++;
        }




        return maxLen;

    



    }
};