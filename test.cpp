#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        arr.push_back(temp);
    }

    vector<int> sum;
    for (int i = 0; i < n; i++) {
        vector<int> path;
        int j = i;
        int tempSum = 0;
        while (arr[i] < arr.size() and arr[j] != i and arr[j] != -1 and !(find(path.begin(), path.end(), j) != path.end())) {
            path.push_back(j);
            tempSum += j;
            j = arr[j];
            if (arr[j] == i) {
                tempSum += j;
                break;
            }
        }
        if (i < n and i == arr[j]) {
            sum.push_back(tempSum);
        }
    }
    if (sum.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    cout << *max_element(sum.begin(), sum.end()) << endl;
}