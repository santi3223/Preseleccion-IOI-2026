//9 de Julio 2026 23:39
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

int main(){
	ll n, k;
	cin >> n >> k;
	vl a(n), b(n);
	ff(i, 0, n) cin >> a[i];
	ff(i, 0, n) cin >> b[i];
	ll c1 = 1e9;
	ff(i, 0, n){
		c1 = min(c1, b[i]/a[i]);
	}
	ff(i, 0, n) b[i] -= c1*a[i];
	ll c = 0;
	ll l = 0, r = 1e9+5;
	while(l <= r){
		ll mid = l+(r-l)/2;
		ll q = 0;
		ff(i, 0, n){
			q += a[i]*mid-min(a[i]*mid, b[i]);
			if(q > k){
				q = -1;
				break;
			}
		}
		if(q == -1) r = mid-1;
		else{
			c = mid;
			l = mid+1;
		}
	}
	cout << c1+c;
}
