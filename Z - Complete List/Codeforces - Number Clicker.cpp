//20 de Mayo 2026 22:53
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

ll binexp(ll b, ll e, ll mod){
	if(e == 0) return 1;
	if(e == 1) return b%mod;
	ll mid = binexp(b, e/2, mod)%mod;
	if(e % 2 == 0) return mid*mid%mod;
	return (mid*mid%mod)*b%mod;
}

ll inv(ll x, ll p){
	return binexp(x, p-2, p)%p;
}

int main(){
	ll u, v, p;
	cin >> u >> v >> p;
	map<ll, ll> vis1, vis2, par1, par2;
	queue<pll> q;
	q.push({u, 1});
	q.push({v, 2});
	vis1[u] = -1;
	vis2[v] = -1;
	
	ll mid = -1;
	while(!q.empty()){
		ll cur = q.front().fi, id = q.front().se;
		q.pop();
		if(vis1[cur] != 0 && vis2[cur] != 0){
			mid = cur;
			break;
		}
		if(id==1){
			ll nxt = (cur+1)%p;
			if(vis1[nxt] == 0){
				par1[nxt] = cur;
				vis1[nxt] = 1;
				q.push({nxt, id});
			}
			nxt = (cur+p-1)%p;
			if(vis1[nxt] == 0){
				par1[nxt] = cur;
				vis1[nxt] = 2;
				q.push({nxt, id});
			}
			if(cur != 0){
				ll i = inv(cur, p);
				if(vis1[i] == 0){
					par1[i] = cur;
					vis1[i] = 3;
					q.push({i, id});
				}
			}
		}
		else{
			ll nxt = (cur+1)%p;
			if(vis2[nxt] == 0){
				par2[nxt] = cur;
				vis2[nxt] = 1;
				q.push({nxt, id});
			}
			nxt = (cur+p-1)%p;
			if(vis2[nxt] == 0){
				par2[nxt] = cur;
				vis2[nxt] = 2;
				q.push({nxt, id});
			}
			if(cur != 0){
				ll i = inv(cur, p);
				if(vis2[i] == 0){
					par2[i] = cur;
					vis2[i] = 3;
					q.push({i, id});
				}
			}
		}
	}
	vl ord;
	ll cur = mid;
	while(cur != u){
		ll parent = par1[cur];
		if((parent+1)%p == cur){
			ord.pb(1);
		}
		else if((parent+p-1)%p == cur){
			ord.pb(2);
		}
		else{
			ord.pb(3);
		}
		cur = par1[cur];
	}
	reverse(all(ord));
	cur = mid;
	while(cur != v){
		ll parent = par2[cur];
		if((cur+1)%p == parent){
			ord.pb(1);
		}
		else if((cur+p-1)%p == parent){
			ord.pb(2);
		}
		else{
			ord.pb(3);
		}
		cur = par2[cur];
	}
	cout << ord.size() << ed;
	for(auto x : ord) cout << x << ' ';
	
}
