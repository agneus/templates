#include <bitset>/stdc++.h>

using namespace std;

vector<vector<int>> findPrefixSums2D(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            p[i +1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + a[i][j];
        }
    }
    return p;
}

//queries are answered as follows
// sum of [lx,ly] * [rx,ry] is
// p[rx][ry] - p[lx][ry] - p[rx][ly] + p[lx][ly]

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];prefix
        }
    }
    vector<vector<int>> prefixSums = findPrefixSums2D(arr);
    int queriesNumber;
    cin >> queriesNumber;
    for (int i = 0; i < queriesNumber; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        lx--;
        ly--;
        cout << prefixSums[rx][ry] - prefixSums[lx][ry] - prefixSums[rx][ly] + prefixSums[lx][ly] << '\n';
    }
}
