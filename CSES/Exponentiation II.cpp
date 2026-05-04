#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>


ll modexp(ll b, ll e, ll MOD){
	if(e == 0) return 1LL;
	if(e == 1) return b;
	ll mid = modexp(b, e/2, MOD);
	if(e % 2 == 0) return (mid*mid) % MOD;
	return (((mid*mid) % MOD)*b)%MOD;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a, b, c;
		 cin >> a >> b >> c;
		 ll p = modexp(b, c, 1e9+6);
		 cout << modexp(a, p, 1e9+7) << ed;
	}
}
