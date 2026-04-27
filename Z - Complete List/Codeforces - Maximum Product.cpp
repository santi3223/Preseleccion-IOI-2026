//25 de Marzo 2026 23:13
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

ll digp(ll x){
	if(x == 0) return 0;
	ll prod = 1;
	while(x != 0){
		prod *= (x%10);
		x /= 10;
	}
	return prod;
}

int main(){
	ll a, b;
	cin >> a >> b;
	string s = to_string(b);
	ll n = s.size();
	
	ll best = b;
	ll bestp = digp(b);
	
	ff(i, 0, n){
		if(s[i] == '0') continue;
		string t = s;
		t[i]--;
		ff(j, i+1, n){
			t[j] = '9';
		}
		ll num = stoll(t);
		if(num < a) continue;
		ll prod = digp(num);
		if(prod > bestp){
			bestp = prod;
			best = num;
		}
	}
	cout << best;
	
}
