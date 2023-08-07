class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = (row*col)-1;

        while(start<=end)
        {
            int mid = (start+end)/2;
            int findRow = mid/col;
            int findCol = mid%col;

            cout<<findRow<<" "<<findCol<<"\n";
            cout<<start<<" "<<end<<"\n";

            if(matrix[findRow][findCol]==target)
                return true;

            if(matrix[findRow][findCol]>target)
                end = mid-1;

            else
                start = mid+1;

            
        }

        return false;
    }
};
