class Solution {
public:
    int canMakeBouq(vector<int> bloomDay, int mid, int k) {
        int bouqCount = 0;
        int consucative_count = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consucative_count++;

            } else {
                consucative_count = 0;
            }

            if (consucative_count == k) {
                bouqCount++;
                consucative_count = 0;
            }
        }
        return bouqCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start_day = 0;
        int end_day = *max_element(begin(bloomDay), end(bloomDay));

        int min_Day = -1;

        while (start_day <= end_day) {
            int mid = start_day + (end_day - start_day) / 2;

            if (canMakeBouq(bloomDay, mid, k) >= m) {
                min_Day = mid;
                end_day = mid - 1;
            } else {
                start_day = mid + 1;
            }
        }
        return min_Day;
    }
};