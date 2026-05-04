//3 de Mayo 2026 22:27
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

vl phi(1e5+5), pref(1e5+5), nw(1e5+5);

void build(){
	ff(i, 1, 1e5+2) phi[i] = i;
	ff(i, 2, 1e5+2){
		if(phi[i] == i){
			for(ll j = i; j < 1e5+2; j += i) phi[j] -= phi[j]/i;
		}
	}
	ff(i, 1, 1e5+5){
		pref[i] = i-phi[i];
		nw[i] = nw[i-1]+pref[i];
	}
}

int main(){
	ll n;
	cin >> n;
	build();
	
	ff(i, 0, n){
		ll x;
		cin >> x;
		cout << "Case " << i+1 << ": " << nw[x] << ed;
	}
}
