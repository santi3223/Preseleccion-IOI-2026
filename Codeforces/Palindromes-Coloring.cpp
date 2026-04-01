//22 de Febrero 2026
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		string str;
		cin >> n >> k >> str;
		ll par = 0, imp = 0;
		map<char, ll> mp;
		ff(i, 0, n){
			mp[str[i]]++;
		}
		for(auto &x : mp){
			par += x.se/2;
			imp += x.se%2;
		}
		//cout << par << " " << k << " " << imp << ed;
		ll c = 2*(par/k);
		imp += 2*(par%k);
		//cout << imp << ed;
		if(imp >= k) c++;
		cout << c << ed;
	}
}
