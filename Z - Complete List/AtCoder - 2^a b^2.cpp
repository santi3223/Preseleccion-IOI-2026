//9 de Abril 2026 14:21
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
#define ed "\n"
#define vs vector<string>
 
int main(){
	ll n;
	cin >> n;
	ll c = 0;
	ff(i, 1, 3){
		ll k = (1ll<<i);
		if(k > n) break;
		if(k == n) c++;
		else{
			ll l = 1, r = n, best = 0;
			while(l <= r){
				ll mid = l + (r-l)/2;
				__int128 val = (__int128)k*mid*mid;
				if(val <= n) best = mid, l = mid+1;
				else r = mid-1;
			}
			c += best;
		}
	}
	cout << c;
}
