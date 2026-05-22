//21 de Mayo 2026 23:44
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<ll, pll> mp;
		ff(i, 0, n){
			ll x;
			cin >> x;
			if(x % 2 == 0) mp[-(x-1)/2].se++;
			else mp[-(x-1)/2].fi++;
		}
		ll ans = 0;
		while(mp.size() > 1){
			ll id = mp.begin()->fi;
			ll &imp = mp[id].fi, &pr = mp[id].se;
			ans += imp;
			pr += imp;
			ans += pr;
			ll nw = -id;
			nw++;
			//cout << nw-1 << " to " << (nw-1)/2 << ed;
			if(nw % 2 == 0) mp[-(nw-1)/2].se += pr;
			else mp[-(nw-1)/2].fi += pr;
			mp.erase(id);
		}
		//cout << mp.size() << ' ' << ans << ed;
		ll id = mp.begin()->fi;
		//cout << id << ' ';
		//cout << id << ' ' << mp[id].fi << ' ' << mp[id].se << ed;
		if(mp[id].se){
			if(id == 0) ans += min(mp[id].fi, mp[id].se);
			else ans += mp[id].fi;
		}
		
		cout << ans << ed;
	}

}
