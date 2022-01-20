#include <bits/stdc++.h>

using namespace std;

int main () {
	string s = "MALYALAM";
	set<char> st;
	for(char i : s) {
		if (st.count(i) > 0) {
			continue;
		} else {
			cout << i << endl;
			st.insert(i);
		}
	}
}