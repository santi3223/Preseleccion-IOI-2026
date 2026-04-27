//19 de Marzo 2026 23:22
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
const ll MAXN = 1e5;
vl sieve;

void s(){
	sieve = vl(MAXN+5);
	ff(i, 1, MAXN+1)sieve[i] = i;
	ff(i, 2, MAXN+1){
		if(sieve[i] == i){
			for(ll j = i*i; j < MAXN+1; j += i){
				if(sieve[j] == j) sieve[j] = i;
			}
		}
	}
}

vector<pll> factor(ll x, ll k){
	map<ll, ll> mp;
	while(x > 1){
		mp[sieve[x]]++;
		x /= sieve[x];
	}
	vector<pll> res;
	for(auto [a, b] : mp){
		b %= k;
		if(b != 0) res.pb({a, b});
	}
	return res;
}

vector<pll> complement(vector<pll> &v, ll k){
	vector<pll> res;
	for(auto [a, b] : v){
		res.pb({a, (k-b)%k});
	}
	return res;
}

int main(){
	s();
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	map<vector<pll>, ll> cnt;
	ll c = 0;
	ff(i, 0, n){
		auto f = factor(arr[i], k);
		auto comp = complement(f, k);
		c += cnt[comp];
		cnt[f]++;
	}
	cout << c;
}
