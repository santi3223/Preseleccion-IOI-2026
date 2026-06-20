//19 de Junio 2026 23:13
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
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl a(n), pref(n), suf(n+1);
		ff(i, 0, n) cin >> a[i];
		pref[0] = abs(a[0]);
		ff(i, 1, n){
			pref[i] = pref[i-1]+abs(a[i]);
		}
		suf[n-1] = a[n-1];
		for(ll i = n-2; i >= 0; i--){
			suf[i] = suf[i+1]+a[i];
		}
		ll maxx = suf[0], id = -1;
		ff(i, 1, n){
			if(a[i] > 0){
				ll cur = pref[i-1]+suf[i+1]-a[i];
				if(cur > maxx){
					maxx = cur;
					id = i;
				}
			}
		}
		if(id == -1){
			cout << 0 << ed << ed;
			continue;
		}
		vl ans;
		for(ll i = id-1; i >= 0; i--){
			if(ans.size() & 1){
				a[i] = -a[i];
			}
			if(a[i] > 0) ans.pb(i);
		}
		ans.pb(id);
		cout << ans.size() << ed;
		for(auto x : ans) cout << x+1 << ' ';
		cout << ed;
	}
}
