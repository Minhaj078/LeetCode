class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxi = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;
            maxi = max(maxi, area);

            if(height[left] > height[right])right--;
            else left++;
        }
        return maxi;
    }
};