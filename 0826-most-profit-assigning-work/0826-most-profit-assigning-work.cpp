class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(begin(vec), end(vec));

        //Pre-processing to find the maximum profit till index i at constant time
        for(int i = 1; i < vec.size(); i++) {
            vec[i].second = max(vec[i].second, vec[i-1].second);
        }


        int totalProfit = 0;
        for(int i = 0; i < m; i++) {

            int workerDiffLevel = worker[i];

            //apply b.search on vec
            int l = 0, r = vec.size()-1;
            int maxProfit = 0;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(vec[mid].first <= workerDiffLevel) {
                    maxProfit = max(maxProfit, vec[mid].second);
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }

            totalProfit += maxProfit;

        }

        return totalProfit;
    }
        
    
};