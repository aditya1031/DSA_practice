// Git - aditya1031
#include <bits/stdc++.h>
using namespace std;

// ---------------------- BRUTE FORCE ----------------------
// Count reverse pairs (i < j and nums[i] > 2*nums[j])
// TC = O(n^2), SC = O(1)
int reversePairBrute(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)nums[i] > 2LL * nums[j]) { // avoid overflow
                ans++;
            }
        }
    }

    return ans;
}

// ---------------------- MERGE FUNCTION ----------------------
// Standard merge function for merge sort
// TC = O(n) per merge, SC = O(n)
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low]; // map temp[0..] to arr[low..high]
    }
}

// ---------------------- COUNT REVERSE PAIRS ----------------------
// Counts cross reverse pairs between left and right halves
// TC = O(n) per merge, SC = O(1)
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        // Move right pointer until arr[i] <= 2*arr[right]
        while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    return cnt;
}

// ---------------------- MERGESORT ----------------------
// Merge sort that counts reverse pairs
// TC = O(n log n), SC = O(n) due to temp array in merge
int mergesort(vector<int> &arr, int low, int high) {
    int ans = 0;
    if (low >= high) return ans; // base case: 0 or 1 element

    int mid = low + (high - low) / 2;

    ans += mergesort(arr, low, mid);       // inversions in left half
    ans += mergesort(arr, mid + 1, high);  // inversions in right half
    ans += countPairs(arr, low, mid, high); // cross inversions
    merge(arr, low, mid, high);             // sort array for next merge

    return ans;
}

// ---------------------- REVERSE PAIRS (BETTER) ----------------------
// Wrapper function
int reversePairBetter(vector<int> &nums) {
    int n = nums.size();
    return mergesort(nums, 0, n - 1);
}

// ---------------------- MAIN ----------------------
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << reversePairBetter(arr);

    return 0;
}
