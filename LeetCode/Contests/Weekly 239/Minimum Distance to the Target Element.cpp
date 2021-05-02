class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int index=0;
        int mini=INT_MAX;
        for(auto ele:nums){
            if(ele==target){
                mini=min(abs(start-index),mini);
            }
            index++;
        }
        return mini;       
    }
};