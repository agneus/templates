// default
int binary_search(vector<int> a, int target){
    int l = 0; int r = n - 1;
    while(l <= r) {
        int m = l + (r - l)/2;
        if(a[m] == target) return m;
        else if (a[m] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
// lower_bound
int Lower_bound(vector<int a, int target) {
    int l = 0; int r = n - 1;
    int ans = -1;
    while(l < r) {
        int m = l + (r - l)/2;
        if(a[m] >= target) { // condition for true
            ans = m;
            r = m - 1; // better value
        }
        else{
            l = m - 1; // make it true
        }
    }
}

// rotated array
int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int p;
        while(l <= r){
            int m = l + (r - l)/2;
            if(nums[m] <= nums[r]) {
                p = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
            
        }
        if(target >= nums[p] && target <= nums[r]) {
            l = p; r = nums.size() - 1;
        } else {
            l = 0; r = p;
        }
        while(l <= r) {
            int m = l + (r - l)/2;
            if( nums[m] == target) return m;
            else if(nums[m] < target) {
                l = m + 1;
            }
            else r = m - 1;
        }
        return -1;
    }


// find peak


// sqrt
int sqrt(int x, int pres) {
    int l = 0; r = x;
    while(r - l > pres) {
        int m = l + (r - l)/2;
        if( m * m < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l + (r - l)/2;
}