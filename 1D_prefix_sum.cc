#include <bitset>/stdc++.h>

using namespace std;

vector<int> findPrefixSums(const vector<int> &a) {
    int n = a.size();
    vector<int> p(n + 1,0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}
// queries work this way
// the sum [l, r) is p[r] - p[l];

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& val : arr) {
        cin >> val;
    }
    vector<int> prefixSums = findPrefixSums(arr);
 
    int queriesNumber;
    cin >> queriesNumber;
    for (int i = 0; i < queriesNumber; i++) {
        int left, right;
        cin >> left >> right;
        left--;
        cout << prefixSums[right] - prefixSums[left] << '\n';
    }
    return 0;
}