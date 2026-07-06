//5 de Julio 2026 22:56
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
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
	cin >> n >> m;
	vector<vl> conexiones(n);
	set<pll> st;
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		if(a == b) continue;
		if(st.find({a, b}) != st.end()) continue;
		st.insert({a, b});
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	vb visited(n, 0);
	priority_queue<ll, vl, greater<ll>> pq;
	pq.push(0);
	vl ans;
	while(pq.size()){
		ll cur = pq.top();
		pq.pop();
		if(visited[cur]) continue;
		visited[cur] = 1;
		ans.pb(cur);
		for(auto x : conexiones[cur]){
			if(!visited[x]) pq.push(x);
		}
	}
	for(auto x : ans) cout << x+1 << ' ';
}
