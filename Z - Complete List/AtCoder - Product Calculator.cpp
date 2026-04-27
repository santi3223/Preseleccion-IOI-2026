//26 de Enero 2026 13:37
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
ll MOD = 1e9;

int main(){
	ll cur = 1;
	ll n, k;
	cin >> n >> k;
	ll lim = pow(10, k);
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(cur > (lim-1)/x) cur = 1;
		else cur *= x;
	}
	cout << cur;
	
}
