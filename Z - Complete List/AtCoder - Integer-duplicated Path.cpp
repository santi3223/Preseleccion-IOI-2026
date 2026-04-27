//7 de Marzo 2026 08:41
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

vl ans, arr;
vector<vl> conexiones;
map<ll, ll> mp;
bool rep;
ll id;

void dfs(ll cur, ll par){
	mp[arr[cur]]++;
	if(mp[arr[cur]] >= 2 && !rep){
		id = cur;
		rep = true;
	}
	if(rep) ans[cur] = 1;
	for(auto &x : conexiones[cur]){
		if(x != par){
			dfs(x, cur);
		}
	}
	mp[arr[cur]]--;
	if(rep && cur == id) rep = false;
}


int main(){
	ll n;
	cin >> n;
	arr = vl(n);
	ans = vl(n, 0);
	ff(i, 0, n){
		cin>> arr[i];
	}
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	rep = false;
	dfs(0, -1);
	ff(i, 0, n){
		if(ans[i] == 1) cout << "Yes";
		else cout << "No";
		cout << ed;
	}
}
