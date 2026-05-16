//15 de Mayo 2026 23:13
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

vector<unordered_set<ll>> conexiones;
set<ll> unvis;
vl sz;
ll cur = 0;

void dfs(ll x){
	sz[cur]++;
	auto it = unvis.begin();
	while(it != unvis.end()){
		if(conexiones[x].count(*it)){
			it++;
		}
		else{
			ll last = *it;
			unvis.erase(it);
			dfs(last);
			it = unvis.upper_bound(last);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	conexiones = vector<unordered_set<ll>>(n);
	sz = vl(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].insert(--b);
		conexiones[b].insert(a);
	}
	ff(i, 0, n) unvis.insert(i);
	ff(i, 0, n){
		auto it = unvis.find(i);
		if(it != unvis.end()){
			unvis.erase(it);
			dfs(i);
			cur++;
		}
	}
	cout << cur << ed;
	sort(sz.begin(), sz.begin()+cur);
	ff(i, 0, cur) cout << sz[i] << ' ';
	
}
