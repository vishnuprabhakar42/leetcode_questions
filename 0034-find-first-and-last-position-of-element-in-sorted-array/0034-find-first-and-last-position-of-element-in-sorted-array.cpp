class Solution {
public:
    int findRightMost(vector<int>& nums, int target, int n) {
        int right_most = -1;
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                right_most = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return right_most;
    }

    int findLeftMost(vector<int>& nums, int target, int n) {
        int left_most = -1;
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                left_most = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {

                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return left_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = findLeftMost(nums, target, n);
        int r = findRightMost(nums, target, n);

        return {l, r};
    }
};