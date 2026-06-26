//25 de Junio 2026 22:54
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
	ll n, m;
	cin >> n;
	vl a(n);
	ff(i, 0, n) cin >> a[i];
	cin >> m;
	vl b(m);
	ff(i, 0, m) cin >> b[i];
	vl dp(m, 0);
	map<ll, ll> parent;
	ff(i, 0, m) parent[i] = -1;
	
	ff(i, 0, n){
		pll cur = {0, -1};
		ff(j, 0, m){
			if(a[i] == b[j]){
				dp[j] = cur.fi+1;
				parent[j] = cur.se;
			}
			else if(a[i] > b[j]){
				if(dp[j] > cur.fi){
					cur = {dp[j], j};
				}
			}
		}
	}
	ll maxx = 0, id = -1;
	ff(i, 0, m){
		if(dp[i] > maxx) maxx = dp[i], id = i;
	}
	//ff(i, 0, m) cout << dp[i] << ' ';
	//cout << ed;
	vl ans;
	while(id != -1){
		ans.pb(id);
		id = parent[id];
	}
	reverse(all(ans));
	cout << ans.size() << ed;
	for(auto x : ans) cout << b[x] << ' ';
}
