//2 de Julio 2026 22:49
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		vl arr(n), b(n, 0);
		ff(i, 0, n){
			cin >> arr[i];
		}
		ff(i, 0, n-1) b[i] = (arr[i] < 2*arr[i+1]);
		ll c = 0, cur = 0;
		ll l = 0, r = k-1;
		ff(i, 0, k) cur += b[i];
		while(r+1 < n){	
			if(cur == k) c++;
			cur -= b[l];
			l++;
			r++;
			cur += b[r];
		}
		if(cur == k) c++;
		cout << c << ed;
	}
}
