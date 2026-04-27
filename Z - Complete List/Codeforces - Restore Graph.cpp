//7 de Abril 2026 22:35
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
	ll n, k;
	cin >> n >> k;
	vector<pll> arr(n);
	map<ll, ll> mp;
	queue<pll> q;
	ff(i, 0, n){
		ll x;
		cin >> x;
		arr[i].fi = x;
		mp[x]++;
		arr[i].se = i;
		if(x == 0) q.push({0, i});
	}
	sort(all(arr));
	ll maxx = arr[n-1].fi;
	if(mp[0] != 1){
		cout << -1;
		return 0;
	}
	ff(i, 1, maxx+1){
		if(mp[i] > mp[i-1]*k){
			cout << -1;
			return 0;
		}
	}
	vector<vl> conexiones(n);
	vector<pll> outt;
	ff(i, 1, n){
		while(!q.empty() && q.front().fi != arr[i].fi-1) q.pop();
		while(!q.empty() && conexiones[q.front().se].size() == k) q.pop();
		if(q.empty()){cout << -1; return 0;}
		conexiones[q.front().se].pb(arr[i].se);
		conexiones[arr[i].se].pb(q.front().se);
		q.push({arr[i].fi, arr[i].se});
		outt.pb({q.front().se, arr[i].se});
	}
	cout << outt.size() << ed;
	for(auto [a, b] : outt) cout << a+1 << ' ' << b+1 << ed;
	
}
