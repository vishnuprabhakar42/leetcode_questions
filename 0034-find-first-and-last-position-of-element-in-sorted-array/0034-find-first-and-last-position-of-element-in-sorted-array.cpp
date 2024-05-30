class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lpos=-1;
        int fpos=-1;
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(target==nums[mid])
            {
                int mid=(low+high)/2;
                fpos=mid;
                high=mid-1;
            }
            else if(target>nums[mid])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            // int mid=(low+high)/2;
        }
        
        //for from last
        
         low=0;
        high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(target==nums[mid])
            {
                int mid=(low+high)/2;
                lpos=mid;
                low=mid+1;
            }
            else if(target>nums[mid])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            // int mid=(low+high)/2;
        }
        return {fpos, lpos};
        
    }
    
};