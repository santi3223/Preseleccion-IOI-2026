//7 de Mayo 2026 18:52
//this problem is absolute cinema
//There's no word in English that ends with the letter j aah problem (U+1F62D)
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
	ll n, m, o;
	cin >> n >> m >> o;
	vector<pll> rooms(n), offers(m);
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		rooms[i] = {b, a};
	}
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		offers[i] = {b, a};
	}
	sort(all(rooms));
	sort(all(offers));
	priority_queue<ll> pq;
	ll id = 0;
	vl lis;
	for(auto &[p, c] : rooms){ //people cost
		while(id < m && offers[id].fi <= p){
			pq.push(offers[id].se);
			id++;
		}
		if(!pq.empty()){
			ll cur = pq.top();
			pq.pop();
			ll prof = cur-c;
			if(prof > 0) lis.pb(prof);
		}
	}
	sort(rall(lis));
	ll sz = lis.size();
	ll s = 0;
	ff(i, 0, min(sz, o)){
		s += lis[i];
	}
	cout << s;
}
