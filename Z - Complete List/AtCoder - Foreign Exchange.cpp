//25 de Enero 2026 12:40
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
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		ll x = arr[i]/a;
		arr[i] -= a*x;
		arr[i+1] += b*x;
	}
	cout << arr[n-1];
	
	
}

