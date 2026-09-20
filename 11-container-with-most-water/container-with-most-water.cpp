class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1;
        int maxi = 0;

        while(l < r){
            int h = min(height[l],height[r]);
            int w = r - l;
            int a = h * w;
            maxi = max(maxi, a);

            if(height[l] < height[r])l++;
            else r--;
        }
        return maxi;
    }
};