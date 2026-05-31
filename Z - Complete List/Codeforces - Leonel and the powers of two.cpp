//29 de Mayo 2026 16:08
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

const long double PI = acos(-1.0);

string bin(ll p){
	//cout << p << ed;
	if(p == 1){
		return "2";
	}
	if(p % 2 == 0){
		return "("+bin(p/2)+")^2";
	}
	return "(2*"+bin(p-1)+")";
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll x;
		cin >> x;
		cout << bin(x) << ed;
	}
	
}
