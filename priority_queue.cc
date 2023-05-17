class Compare {
public:
    bool operator()(pair<int, int> below, pair<int, int> above) {
        return below.second >= above.second;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int i = 0, x1, y1;
        priority_queue< pair<int, int>, vector<pair<int, int>>, Compare> q;

        for (auto point : points) {
            x1 = point[0]; y1 = point[1];

            q.push({i++, x1*x1 + y1*y1});
        }



        vector<vector<int>> ans;

        while (k--) {

            ans.push_back(points[q.top().first]); q.pop();
        }

        return ans;
    }
};