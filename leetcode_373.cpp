#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// leetcode pair sum
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < min(k, (int)nums1.size()); i++) {
        for (int j = 0; j < min(k, (int)nums2.size()); j++) {
            pq.push(make_pair(-(nums1[i] + nums2[j]), make_pair(nums1[i], nums2[j])));
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> res = kSmallestPairs(nums1, nums2, k);
    for (auto& r : res) {
        cout << "[" << r[0] << ", " << r[1] << "]" << endl;
    }
    return 0;
}