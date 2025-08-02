class Solution {
public:
    int binary_search(vector<int>& arr, int l, int r, int x) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x <= arr[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int minRemoval1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = n;
        if (nums[0] * (long long)k >= nums[n - 1])
            return 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] * (long long)k >= nums[n - 1]) {
                ans = min(ans, i);
            } else {
                int j = binary_search(nums, i, n, nums[i] * k + 1);
                ans = min(ans, i + (n - j));
            }
        }
        return ans;
    }

    int minRemoval(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = n;
        for (int l = 0, r = 0; l < n; ++l) {
            while (r < n && nums[r] <= (long long)nums[l] * k)
                ++r;
            ans = min(ans, n - (r - l));
        }
        return ans;
    }
};
