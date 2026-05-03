//2 de Mayo 2026 20:07
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
ll MOD = 1e9+7;

ll modexp(ll b, ll p){
	if(p == 0) return 1LL;
	if(p == 1) return b;
	ll mid = modexp(b, p/2);
	mid %= MOD;
	ll o = (mid*mid) % MOD;
	if(p%2 == 0) return o;
	return (o*b) % MOD;
}

int main(){
	ll n;
	cin >> n;
	vl a(n);
	ff(i, 0, n){
		cin >> a[i];
		a[i]--;
	}
	vb vis(n);
	map<ll, ll> mp;
	ff(i, 0, n){
		if(vis[i]) continue;
		ll cur = i;
		ll c = 0;
		while(!vis[cur]){
			vis[cur] = 1;
			c++;
			cur = a[cur];
		}
		ll x = c;
		for(ll i = 2; i*i <= x; i++){
			ll coun = 0;
			while(x % i == 0){
				x /= i;
				coun++;
			}
			if(coun) mp[i] = max(mp[i], coun);
		}
		if(x > 1) mp[x] = max(mp[x], 1LL);
	}
	ll ans = 1;
	for(auto &[p, e] : mp){
		ans = ans*modexp(p, e) % MOD;
	}
	cout << ans%MOD;
}
