//27 de Enero 2026 20:07
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
	ll n, q;
	cin >> n >> q;
	vl arr(n, 1);
	ff(i, 0, q){
		ll x;
		cin >> x;
		x--;
		arr[x] = (arr[x]+1) % 2;
	}
	ll c = 0;
	ff(i, 0, n){
		c += arr[i];
	}
	cout << c;
	
}
