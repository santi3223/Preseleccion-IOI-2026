//24 de Enero 2026 16:36
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
	string str;
	cin >> str;
	sort(all(str));
	ll i = 0;
	ll c = 0;
	bool doble = false;
	ll n = str.size();
	while(i < str.size()){
		if(!doble && i+1 < str.size() && str[i+1] == str[i]){
			c++;
			doble = true;
		}
		ll x = upper_bound(all(str), str[i])-str.begin();
		ll a = x-i, b = n-x;
		c += a*b;
		i = x;
		
	}
	cout << c;

}
