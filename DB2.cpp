#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main () {
    ll n,m,k;
    cin>>n>>m>>k;

    vector<ll>a(n),mods(n);
    for(ll i = 0;i<n;i++) {
        cin>>a[i];
    }
    ll ans = 0;
    for(ll i = 0;i<n;i++) {
        mods[i] = (m - a[i]%m)%m;
    }
    sort(mods.begin(),mods.end());
    for(ll i = 0;i<n;i++) {
        if(mods[i]<=k)ans++,k-=mods[i];
    }

    cout<<ans<<"\n";
}