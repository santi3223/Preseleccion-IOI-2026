//18 de Marzo 2026 23:06
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
const ll MOD = 1e9+7;

const int MAXN = 2e5+5;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

ll choose(int n, int k){
	if(k > n) return 0;
	return fac[n] * inv[k] % MOD * inv[n - k] % MOD; 
}

int main(){
    factorial();
    inverses();
    ll t;
    cin >> t;
    while(t--){
		ll n, m, k;
		cin >> n >> m >> k;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(all(arr));
		ll c = 0;
		ff(i, 0, n){
			ll l = i+1, r = upper_bound(all(arr), arr[i]+k) - arr.begin();
			c = (c+choose(r-l, m-1)) % MOD;
		}
		cout << c << ed;
	}
}
