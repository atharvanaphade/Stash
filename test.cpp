#include <bits/stdc++.h>
#define MAX 256

using namespace std;

bool cmp (char arr1[], char arr2[]) {
	for (int i = 0; i < MAX; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}

void search(char* pat, char* txt) {
	int m = strlen(pat), n = strlen(txt);
	char countP[MAX] = {0}, countTW[MAX] = {0};
	for (int i = 0; i < m; i++) {
		(countP[pat[i]])++;
        (countTW[txt[i]])++;
	}
	for (int i = m; i < n; i++) {
        if (cmp(countP, countTW))
            cout << (i - m) << endl;
        (countTW[txt[i]])++;
        countTW[txt[i-m]]--;
    }
 
    if (cmp(countP, countTW))
        cout << (n - m) << endl;
}