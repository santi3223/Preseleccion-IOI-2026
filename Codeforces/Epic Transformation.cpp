//13 de Julio 2026 23:59
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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<ll, ll> v;
		ff(i, 0, n){
			ll x;
			cin >> x;
			v[x]++;
		}
		priority_queue<pll> q;
		for(auto [x, y] : v){
			q.push({y, x});
		}
		ll sz = n;
		while(q.size() >= 2){
			auto [cnt1, x1] = q.top();
			q.pop();
			auto [cnt2, x2] = q.top();
			q.pop();
			cnt1--;
			cnt2--;
			sz -= 2;
			if(cnt1){
				q.push({cnt1, x1});
			}
			if(cnt2){
				q.push({cnt2, x2});
			}
		}
		cout << sz << ed;
	}
}
