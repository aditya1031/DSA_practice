#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> missingNumbers(const vector<int>& arr, const vector<int>& brr) {
    int i = 0, j = 0;
    vector<int> missing;
    
    // Sort both arrays
    vector<int> sorted_arr = arr;
    vector<int> sorted_brr = brr;
    sort(sorted_arr.begin(), sorted_arr.end());
    sort(sorted_brr.begin(), sorted_brr.end());

    while (i < sorted_arr.size() && j < sorted_brr.size()) {
        if (sorted_arr[i] == sorted_brr[j]) {
            i++;
            j++;
        } else if (sorted_arr[i] > sorted_brr[j]) {
            // Element missing from arr
            if (missing.empty() || missing.back() != sorted_brr[j]) {
                missing.push_back(sorted_brr[j]);
            }
            j++;
        } else {
            i++;
        }
    }

    while (j < sorted_brr.size()) {
        if (missing.empty() || missing.back() != sorted_brr[j]) {
            missing.push_back(sorted_brr[j]);
        }
        j++;
    }

    return missing;
}

int main() {
    int n, m, value;
    vector<int> arr, brr;

    cout << "Enter the number of elements in the first array: ";
    cin >> n;

    cout << "Enter the elements of the first array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        arr.push_back(value);
    }

    cout << "Enter the number of elements in the second array: ";
    cin >> m;

    cout << "Enter the elements of the second array:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> value;
        brr.push_back(value);
    }

    vector<int> result = missingNumbers(arr, brr);

    cout << "Missing numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
