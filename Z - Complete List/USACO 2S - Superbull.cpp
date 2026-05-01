//30 de Abril 2026 15:13
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
#define ed endl
#define vs vector<string>

int main(){
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	priority_queue<pll> pq;
	pq.push({0, 0}); //val, idx
	vb vis(n, 0);
	ll ans = 0;
	while(!pq.empty()){
		pll cur = pq.top();
		pq.pop();
		if(vis[cur.se]) continue;
		vis[cur.se] = true;
		ans += cur.fi;
		ff(i, 0, n){
			if(vis[i]) continue;
			pq.push({arr[i]^arr[cur.se], i});
		}
	}
	cout << ans;
	
}
