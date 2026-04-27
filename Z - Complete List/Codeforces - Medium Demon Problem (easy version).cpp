//23 de Marzo 2026 22:14
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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl r(n+1), d(n+5);
		ff(i, 1, n+1){
			cin >> r[i];
			d[r[i]]++;
		}
		set<pll> s;
		ff(i, 1, n+1) s.insert({d[i], i});
		ll c = 2;
		queue<ll> q;
		while(!s.empty() && (*s.begin()).fi == 0){
			while(!s.empty() && (*s.begin()).fi == 0){
				ll k = (*s.begin()).se;
				auto it = s.find({d[r[k]], r[k]});
				d[r[k]]--;
				if(it!=s.end()){
					s.erase(it);
					q.push(r[k]);
				}
				s.erase(s.begin());
				
			}
			while(!q.empty()) s.insert({d[q.front()], q.front()}), q.pop();
			c++;
		}
		cout << c << ed;
	}
}
