class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj_lists;
        for(const auto e : edges) {
            const auto from = e[0], to = e[1], weight = e[2];
            adj_lists[from].push_back({to, weight});
            adj_lists[to].push_back({from, weight*2});
        }
        vector<int> ans(n, -1);
        ans[0] = 0;
        // -cost, node
        priority_queue<pair<int, int>> pq;
        pq.push({0,0});
        while(pq.size()) {
            const auto cur_pair = pq.top();
            pq.pop();
            const int cur_cost = -cur_pair.first, cur_node = cur_pair.second;
            for(const auto next_pair : adj_lists[cur_node]) {
                const auto next_node = next_pair.first, next_cost = next_pair.second + cur_cost;
                if(ans[next_node] == -1 || ans[next_node] > next_cost) {
                    ans[next_node] = next_cost;
                    pq.push({-next_cost, next_node});
                }
            }
        }
        return ans[n-1];
    }
};
