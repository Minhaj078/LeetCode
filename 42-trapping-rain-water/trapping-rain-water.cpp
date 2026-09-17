class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;

        int leftmx = 0, rightmx = 0;
        
        int water = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > leftmx) leftmx = height[left];
                else {
                    water += leftmx - height[left];
                }
                left++;
            }
            else{
                if(height[right] > rightmx) rightmx = height[right];
                else {
                    water += rightmx - height[right];
                }
                right--;
            }
        }
        return water;
    }
};