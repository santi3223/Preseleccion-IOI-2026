//22 de Julio 2026 12:59
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
	vl in(n, 0);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--b].pb(--a);
		in[a]++;
	}
	vb vis(n, 0);
	priority_queue<ll> pq;
	ff(i, 0, n){
		if(in[i] == 0){
			pq.push(i);
			vis[i] = 1;
		}
	}
	vl ans;
	while(pq.size()){
		ll cur = pq.top();
		pq.pop();
		ans.pb(cur+1);
		for(auto x : conexiones[cur]){
			in[x]--;
			if(!in[x]){
				vis[x] = 1;
				pq.push(x);
			}
		}
	}
	reverse(all(ans));
	for(auto x : ans) cout << x << ' ';
}
