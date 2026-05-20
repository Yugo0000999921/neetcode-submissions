class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int score = 0;
        
        while (left < right) {
            int current_area = (right - left) * min(heights[left], heights[right]);
            if (score < current_area) {
                score = current_area;
            }
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return score;
    }
};