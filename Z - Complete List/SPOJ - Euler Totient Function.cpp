//3 de Mayo 2026 22:57
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

vl phi(1e6+5);

void build(){
	ll n = 1e6+5;
	ff(i, 1, n) phi[i] = i;
	ff(i, 2, n){
		if(phi[i] == i) for(ll j = i; j < n; j += i) phi[j] -= phi[j]/i;
	}
}

int main(){
	ll t;
	cin >> t;
	build();
	while(t--){
		ll x;
		cin >> x;
		cout << phi[x] << ed;
	}
}
