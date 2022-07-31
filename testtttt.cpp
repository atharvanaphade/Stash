#include<bits/stdc++.h>
using namespace std;

bool isGood(vector<int>& arr) {
    int min_ele = *min_element(arr.begin(), arr.end());
    int max_ele = *max_element(arr.begin(), arr.end());
    vector<int> good_seq_list;
    for (int i = min_ele; i <= max_ele; i++) {
        good_seq_list.push_back(i);
    }
    vector<int> _sorted;
    vector<int> checked;
    for (auto i : arr) _sorted.push_back(i);
    bool fl = true;
    for (int i = 0; i < good_seq_list.size(); i++) {
        if (good_seq_list[i] != _sorted[i]) fl = false;
    }
    for (auto i : arr) {
        if (find(checked.begin(), checked.end(), i) != checked.end()) {
            return 0;
        } else {
            checked.push_back(i);
        }
    }

    return 1;
}

int main() {
    vector<int> arr;
    vector<vector<int>> good_seq;
    for (int i = 1; i < arr.size() + 1; i++) {
        vector<int> t = next_permutation(arr.begin(), arr.end());
        for (auto j : t) {
            if (isGood(j)) {
                good_seq.push_back(j);
            }
        }
    }

    cout << good_seq.size();
}