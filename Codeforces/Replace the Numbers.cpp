#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

int main(){
	ll q, n = 0;
	cin >> q;
	vector<vl> pos(5e5+5);
	while(q--){
		ll t, x, y;
		cin >> t;
		if(t == 1){
			cin >> x;
			pos[x].pb(n++);
		}
		else{
			cin >> x >> y;
			if(x == y) continue;
			if(pos[x].size() > pos[y].size()) swap(pos[x], pos[y]);
			for(auto &p : pos[x]) pos[y].pb(p);
			pos[x].clear();
		}
	}
	vl ans(n);
	ff(i, 0, 5e5+5){
		for(auto &p : pos[i]){
			ans[p] = i;
		}
	}
	ff(i, 0, n) cout << ans[i] << ' ';
}

