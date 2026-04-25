//23 de Abril 2026 14:40
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

ll MAXX  = 2e5+5;
vl psum;

ll cou(ll x){
	ll c = 0;
	while(x){
		x /= 3;
		c++;
	}
	return c;
}


int main(){
	ll t;
	cin >> t;
	psum = vl(MAXX, 0);
	ff(i, 1, MAXX){
		ll x = cou(i);
		psum[i] = psum[i-1]+x;
	}
	while(t--){
		ll l, r;
		cin >> l >> r;
		cout << psum[r]-psum[l]+(psum[l]-psum[l-1])*2<< ed;
	}
}
