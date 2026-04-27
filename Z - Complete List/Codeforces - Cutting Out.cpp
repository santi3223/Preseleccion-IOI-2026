//21 de Marzo 2026 23:29
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

ll n, k;
vl s, t, cc;


bool can(ll x){
	t.clear();
	ff(i, 0, 200001){
		ll need = min(cc[i]/x, k- (ll)(t.size()));
		ff(j, 0, need){
			t.pb(i);
		}
	}
	return t.size() == k;
}

int main(){
	cin >> n >> k;
	s = vl(n);
	cc = vl(200005, 0);
	ff(i, 0, n) cin >> s[i];
	for(auto &x : s) cc[x]++;
	
	ll l = 0, r = n;
	while(r-l > 1){
		ll mid = (l+r)/2;
		if(can(mid)) l = mid;
		else r = mid;
	}
	if(!can(r)) can(l);
	for(auto &x : t) cout << x << " ";
}
