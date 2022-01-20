#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z, vector<int> sv) {
    int no_of_stocks = 0;
    int n = sv.size();
    int spend = z;
    vector<pair<int, int>> stcks;
    for (int i = 1; i <= n; i++) {
        stcks.push_back({ sv[i - 1], i });
    }
    sort(stcks.begin(), stcks.end());
    int i = 0;
    while (spend >= stcks[i].first) {
        cout << stcks[i].first << "\n";
        for (int j = 1; j <= stcks[i].second; j++) {
            if (spend - stcks[i].first > 0) {
                no_of_stocks++;
                spend -= stcks[i].first;
            } else {
                break;
            }
        }
        i++;
    }
    return no_of_stocks;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z, input_data);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
