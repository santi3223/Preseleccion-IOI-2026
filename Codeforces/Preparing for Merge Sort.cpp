//24 de Junio 2026 23:14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<vl> ans;
	ff(i, 0, n){
		ll a;
		cin >> a;
		ll l = 0, r = ans.size()-1;
		ll pos = -1;
		//cout << ed << "I " << i << ed;
		while(l <= r){
			ll mid = l+(r-l)/2;
			//cout << l << ' ' << r << ' ' << mid << ' ' << ans[mid].back() << ' ' << a << ed;
			if(ans[mid].back() < a){
				pos = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		if(pos == -1) ans.pb({a});
		else ans[pos].pb(a);
	}
	for(auto x : ans){
		for(auto y : x) cout << y << ' ';
		cout << ed;
	}
}
