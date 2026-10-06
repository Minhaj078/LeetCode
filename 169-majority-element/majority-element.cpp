class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int person = 0, count = 0;
        for(int x : nums){
            if(count == 0)person = x;
            if(x == person)count++;
            else count--;
        }
        return person;
    }
};