//24 de Junio 2026 19:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

ll exp(ll b, ll e, ll mod){
	if(e == 0) return 1;
	if(e == 1) return b;
	ll mid = exp(b, e/2, mod);
	if(e % 2 == 0){
		return (mid*mid) % mod;
	}
	return mid*mid % mod * b % mod;
}

vl fac, inv;

void prec(){
	ll n = 1e6+5;
	fac = vl(n);
	inv = vl(n);
	fac[0] = 1;
	ll mod = 1e9+7;
	ff(i, 1, n){
		fac[i] = fac[i-1]*i % mod;
	}
	inv[n-1] = exp(fac[n-1], mod-2, mod);
	for(ll i = n-2; i >= 0; i--){
		inv[i] = inv[i+1]*(i+1) % mod;
	}
}

ll nCk(ll a, ll b){
	ll mod = 1e9+7;
	return fac[a]*inv[b] % mod * inv[a-b] % mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	prec();
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		cout << nCk(a, b) << ed;
	}
	
}
