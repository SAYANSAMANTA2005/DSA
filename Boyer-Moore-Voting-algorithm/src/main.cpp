
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x= nums[0],Xcnt=0;
        for(auto it:nums){
            if(Xcnt==0) x=it;
            if(it==x) Xcnt++;
            else Xcnt--;
        }
        // check if candidate ans is majority ele (freq>n/2)
        int cnt=0;
        for(auto it:nums){
            if(it==x) cnt++; }
        if(cnt> (double)nums.size()/2.0) return x;
        else return -1;// no majority ele
    }
};