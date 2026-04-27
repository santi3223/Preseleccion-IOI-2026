//14 de Marzo 2026 08:48
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

int main(){
	
	ll l, r, d, u;
	cin >> l >> r >> d >> u;
	ll c = 0;
	ff(i, l, r+1){
		if(i % 2 != 0) continue;
		ll dwn = max(d, -abs(i)+1);
		ll up = min(u, abs(i)-1);
		c += max(0LL, up-dwn+1);
	}
	ff(i, d, u+1){
		if(i % 2 != 0) continue;
		ll lef = max(l, -abs(i));
		ll rig = min(r, abs(i));
		c += max(0LL, rig-lef+1);
	}
	
	cout << c;
	
	
}
