#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

pll gt(ll a, ll b){
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	return {a, b};
}


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		string str;
		cin >> n >> str;
		ll d = 0, k = 0;
		map<pll, ll> mp;
		for(auto &c : str){
			if(c == 'D') d++;
			else k++;
			mp[gt(d, k)]++;
			cout << mp[gt(d, k)] << ' ';
		}
		cout << ed;
	}
}

