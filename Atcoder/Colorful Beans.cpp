//23 de Enero 2026 11:00
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll n;
	cin >> n;
	map<ll, ll> mp;
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		if(mp[b] == 0) mp[b] = a;
		else mp[b] = min(mp[b], a);
	}
	ll maxx = 0;
	for(auto &x : mp){
		maxx = max(maxx, x.se);
	}
	cout << maxx;
	
	
}

