class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        // 左半分がソート済み
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;  // targetが左半分にある
            else
                left = mid + 1;   // targetが右半分にある
        }
        // 右半分がソート済み
        else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;   // targetが右半分にある
            else
                right = mid - 1;  // targetが左半分にある
            }
        }
        return -1;
    }
};
