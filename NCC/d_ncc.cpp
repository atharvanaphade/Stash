
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef std::vector<ll> vll;
typedef std::vector<pll> vpll;
typedef std::vector<vll> vvll;
typedef map<ll,ll>mll;
typedef map<ll,pll>mpll;
typedef set<ll> sll;

//USEFUL MACROS
#define test            ll t;cin>>t;while(t--)
#define in(n)          ll n;cin>>n;
#define inp(a,n)        vll a(n);for(ll i = 0;i<n;i++) cin>>a[i];
#define inp1(a,n)        vll a(n+1);a[0] = 0;for(ll i = 1;i<=n;i++) cin>>a[i];
#define forn(a,n)       for(ll i = a;i<n;i++)
#define sz(a)           ll(a.size())
#define nl              cout<<endl;
#define F               first
#define S               second
#define pb              push_back
#define mod             1000000007
#define mod1            998244353
#define inf             1e18
#define dec(x)         cout<<fixed<<setprecision(x)<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vec(a)          (a).begin(),(a).end()
#define sortvec(a)    sort(vec(a),greater<ll>())
#define minVec(a)       *min_element(vec(a))
#define maxVec(a)       *max_element(vec(a))
#define inpstr(s)      string s;cin>>s; 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//USEFUL FUNCTIONS
int expo(int x,int y){ int res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
bool isPrime(ll n){if(n <= 1)return false;if(n <= 3)return true;if(n%2 == 0 || n%3 == 0)return false;for(ll i=5; i*i<=n; i=i+6)if(n%i == 0 || n%(i+2) == 0)return false;return true;}
ll nextPrime(ll N){if(N<=1)return 2;ll prime = N;bool found = false;while(!found){prime++;if(isPrime(prime))found=true;}return prime;}
ll cl(ll n,ll d){return (n+d-1)/d;} 
ll binToDec(string s){return bitset<64>(s).to_ullong();}
string decToBin(ll a){return bitset<64>(a).to_string();}
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*b)/(gcd(a,b));}
void print(pll a){cout<<a.F<<' '<<a.S;nl;}
void print(ll a){cout<<a;nl}
void print(vll a){for(auto i : a)cout<<i<<' ';nl;}
void print(string s){cout<<s;nl;}
void printr(vll a,ll start,ll end){for(ll i =start;i<end;i++)cout<<a[i]<<' ';nl;}
void print(ll a,ll b){cout<<a<<' '<<b;}
void amax(ll &a, ll b){a=max(a,b);}
void amin(ll &a, ll b){a=min(a,b);}
ll madd(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll mmul(ll a,ll b){return ((a%mod)*(b%mod))%mod;}
ll msub(ll a,ll b){return ((a%mod)-(b%mod)+mod)%mod;}
ll fpow(ll x,ll y,ll p=mod){x%=p;ll sum = 1;while(y){if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;} return sum;}
bool isPerSquare(long double a) {if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a);}
bool isPalindrome(string str){ll low = 0,high = sz(str) - 1;while (low < high){if (str[low] != str[high])return false;low++,high--;}return true;}




#define MAXN   10000001
int spf[MAXN];
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
mll getFactorization(int x)
{
    mll ret;
    while (x != 1)
    {
        ret[(spf[x])]++;
        x = x / spf[x];
    }
    return ret;
}


void solve(){
    in(n);
    mll mp = getFactorization(n);
    for(auto i : mp){
        //num ->4*n + 3
        // pow => odd
        if((i.F - 3)%4 == 0 && i.S&1){
            print("NO");
            return;
        }
    }
    print("YES");
}



signed main()
{ 
    FIO;
    sieve();
    test
        solve();
}