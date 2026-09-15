class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxi = 0;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            int a = h * w;
            maxi = max(maxi, a);

            if(height[left] > height[right])right--;
            else left++;
        }
        return maxi;
    }
};