//23 de Mayo 2026 09:09
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
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll n = s.size();
		map<char, ll> mp;
		ll maxx = 0;
		ff(i, 0, n){
			mp[s[i]]++;
			maxx = max(maxx, mp[s[i]]);
		}
		if(maxx-1 > n-maxx){
			cout << "No" << ed;
			continue;
		}
		cout << "Yes" << ed;
		
		priority_queue<pair<ll, char>> pq;
		for(char c = 'a'; c <= 'z'; c++){
			if(mp[c]){
				pq.push({mp[c], c});
			}
		}
		string ans = "";
		while(pq.size() >= 2){
			auto [a, b] = pq.top();
			pq.pop();
			auto [a2, b2] = pq.top();
			pq.pop();
			ans += b;
			ans += b2;
			a--;
			a2--;
			if(a) pq.push({a, b});
			if(a2) pq.push({a2, b2});
		}
		while(!pq.empty()){
			ans += pq.top().se;
			pq.pop();
		}
		cout << ans << ed;
		
	}
}
