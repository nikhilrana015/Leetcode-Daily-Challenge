class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;


        while(start<=end)
        {
            int mid = (start+end)/2;

            if(mid-1>=0 and mid+1<arr.size() and arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
                return mid;

            else if(mid+1<arr.size() and arr[mid]<arr[mid+1])
                start = mid+1;
            else
                end = mid-1;
            
        }

        return -1;

    }
};