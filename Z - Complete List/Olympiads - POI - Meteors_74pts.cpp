//8 de Marzo 2026 19:26
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, m;
	cin >> n >> m;
	vl stat(m);
	ff(i, 0, m){
		cin >> stat[i];
		stat[i]--;
	}
	vl ex(n);
	ff(i, 0, n){
		cin >> ex[i];
	}
	ll q;
	cin >> q;
	vector<pair<pll, ll>> up;
	ff(i, 0, q){
		ll l, r, c;
		cin >> l >> r >> c;
		l--;
		r--;
		up.pb({{l, r}, c});
	}
	vl ans(n, -1), count(n, 0);
	ff(i, 0, q){
		ll id = up[i].fi.fi;
		while(true){
			if(id >= m) id = 0;
			//cout << id << " ";
			count[stat[id]] += up[i].se;
			if(count[stat[id]] >= ex[stat[id]] && ans[stat[id]] == -1) ans[stat[id]] = i; 
			if(id == up[i].fi.se) break;
			id++;
		}
		/*cout << ed;
		ff(j, 0, n){
			cout << count[j] << " ";
		}
		cout << ed;*/
	}
	ff(i, 0, n){
		if(ans[i] == -1) cout << "NIE";
		else cout << ans[i]+1;
		cout << ed;
	}
	
	
}
