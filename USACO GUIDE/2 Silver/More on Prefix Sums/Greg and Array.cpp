//25 de Febrero 2026 22:37
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
#define ed "\n"

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vector<pair<pll, ll>> brr(m);
	ff(i, 0, m){
		ll x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		brr[i] = {{x, y}, z};
	}
	vl ops(m+5, 0);
	ff(i, 0, k){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		ops[a]++;
		ops[b+1]--;
	}
	ff(i, 1, m){
		ops[i] += ops[i-1];
	}
	vl ad(n+5, 0);
	ff(i, 0, m){
		ll l = brr[i].fi.fi, r = brr[i].fi.se, d = brr[i].se;
		ad[l]   += d*ops[i];
		ad[r+1] -= d*ops[i];
	}
	ff(i, 1, n){
		ad[i] += ad[i-1];
	}
	ff(i, 0, n){
		cout << ad[i]+arr[i] << " ";
	}
	
}
