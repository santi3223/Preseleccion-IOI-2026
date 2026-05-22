//21 de Mayo 2026 10:49
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

ll binexp(ll b, ll e, ll mod){
	if(e == 0) return 1;
	if(e == 1) return b%mod;
	ll mid = binexp(b, e/2, mod)%mod;
	if(e % 2 == 0) return mid*mid%mod;
	return (mid*mid%mod)*b%mod;
}

ll inv(ll x, ll p){
	return binexp(x, p-2, p)%p;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vb visited(4*n+5, 0);
		ll prev = -1;
		ff(i, 0, n){
			ff(j, 1, 2*n+1){
				if(!visited[j]){
					cout << j << ' ';
					visited[j] = 1;
					if(prev != -1){
						visited[j+prev] = 1;
					}
					prev = j;
					break;
				}
			}
		}
		cout << ed;
	}
	
}
