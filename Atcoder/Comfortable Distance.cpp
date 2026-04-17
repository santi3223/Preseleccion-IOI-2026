//14 de Marzo 2026 08:46
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
	ll n, l, r;
	cin >> n >> l >> r;
	string str;
	cin >> str;
	vector<vl> arr(26);
	ll c = 0;
	ff(i, 0, n){
		ll cur = str[i]-'a';
		ll cl = i-r, cr = i-l;
		if(cr >= 0){
			cl = max(0LL, cl);
			auto &x = arr[cur];
			ll lef = lower_bound(all(x), cl) - x.begin();
			ll ri = upper_bound(all(x), cr) - x.begin();
			c += ri-lef;
		}
		arr[cur].pb(i);
	}
	cout << c;
	
}
