#include <bits/stdc++.h>

using namespace std;

int countHighlyProfitableMonths(vector<int> stockPrices,int k){
    int n=stockPrices.size(),count=1;
    vector<int> a;
    for(int i=0;i+1<n;i++){
        if(stockPrices[i+1]>stockPrices[i])
            count+=1;
        else{
            a.push_back(count);
            count=1;
        }
    }
    a.push_back(count);
    int ans=0;
    for(auto x:a){
        if(x>=k)
            ans+=(x-k+1);
    }
    return ans;
}

int main () {
	return 0;
}