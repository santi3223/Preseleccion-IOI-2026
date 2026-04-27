//23 de Enero 2026 18:08
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
	ll cur = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(cur+x <= 0) cur = 0;
		else cur += x;
		//cout << cur << " " << x << ed;
	}
	cout << cur;
}
