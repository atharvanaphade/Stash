#include <bits/stdc++.h>
#define MAXN 200001
#define ll long long
#define rep(i,a,b) for (int i = a; i < int(b); i++)

using namespace std;

const ll INF = 1e18 + 10;
const int MX = 2e5 + 10;

template<int N>
struct SegLz {
	ll st[4*N], lz[4*N];
	const ll NIL = INF;
	
	ll mrg(ll a, ll b) { return min(a, b); }
	
	SegLz() { rep(i,0,4*N) st[i] = NIL, lz[i] = 0; }
	
	void prop(int v) {
		rep(u,2*v,2*v+2) st[u] += lz[v], lz[u] += lz[v];
		lz[v] = 0; }
		
	void upd(int l, int r, ll x, int v = 1, int b = 0, int e = N) {
		if(l >= r) return;
		if(b == l && e == r) { 
			st[v] += x, lz[v] += x;
			return; }
		int md = (b+e)/2; prop(v);
		upd(l, min(r,md), x, 2*v, b, md); upd(max(l,md), r, x, 2*v+1, md, e);
		st[v] = mrg(st[2*v], st[2*v+1]); }
	
	void set(int i, ll x, int v = 1, int b = 0, int e = N) {
		if(e-b == 1) { st[v] = x; return; }
		int md = (b+e)/2; prop(v);
		if(i < md) set(i, x, 2*v, b, md);
		else       set(i, x, 2*v+1, md, e);
		st[v] = mrg(st[2*v], st[2*v+1]); }
	
	ll qry(int l, int r, int v = 1, int b = 0, int e = N) {
		if(l >= r) return NIL;
		if(b == l && e == r) return st[v];
		int md = (b+e)/2; prop(v);
		return mrg(qry(l, min(md,r), 2*v, b, md), qry(max(l,md), r, 2*v+1, md, e)); }
};

int x[MX];
SegLz<MX> one, two;

int main () {
	int n, q, A, B;
	cin >> n >> q >> A >> B;
	--A; --B;
	x[0] = A;
	for(int i = 1; i <= q; i++) {
		cin >> x[i];
		--x[i];
	}
	one.set(B, -B);
	two.set(B, B);
	for(int i = 1; i <= q; i++) {
		ll add = abs(x[i] - x[i-1]);
		ll first = one.qry(0, x[i]) + x[i];
		ll second = two.qry(x[i], n) - x[i];
		ll val = one.qry(x[i-1], x[i-1]+1) + x[i-1] + add; // my actual value
		val = min({val, first, second});
		one.upd(0, n, add);
		two.upd(0, n, add);
		one.set(x[i-1], val - x[i-1]);
		two.set(x[i-1], val + x[i-1]);
	}
	ll ans = INF;
	for(int i = 0; i < n; i++) {
		ans = min(ans, one.qry(i, i+1) + i);
	}
	cout << ans << "\n";
}