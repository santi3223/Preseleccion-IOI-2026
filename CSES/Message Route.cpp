//28 de Mayo 2026 17:33
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
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	queue<ll> q;
	vb vis(n, 0);
	q.push(0);
	vl par(n, -1);
	vis[0] = 1;
	par[0] = 0;
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		for(auto &x : conexiones[cur]){
			if(vis[x]) continue;
			vis[x] = 1;
			par[x] = cur;
			q.push(x);
		}
	}
	if(!vis[n-1]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	vl ans;
	ll cur = n-1;
	par[0] = -1;
	while(cur != -1){
		ans.pb(cur);
		cur = par[cur];
	}
	reverse(all(ans));
	cout << ans.size() << ed;
	ff(i, 0, ans.size()){
		cout << ans[i]+1 << ' ';
	}

}
