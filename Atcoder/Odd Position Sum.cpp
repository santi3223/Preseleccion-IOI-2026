//26 de Enero 2026 09:18
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
	ll n;
	cin >> n;
	ll c = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(i % 2 == 0) c += x;
	}
	cout << c;
}
