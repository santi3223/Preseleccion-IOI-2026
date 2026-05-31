//29 de Mayo 2026 11:44
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a0 = 0, cur = 0, c = 0, minus = 0;
		ff(i, 0, n){
			if(i == 0){
				cin >> a0;
			}
			else{
				cin >> cur;
				cur -= minus;
				if(a0 > cur){
					c += a0-cur;
					a0 = cur;
				}
				else{
					c += cur-a0;
					minus += cur - a0;
				}
			}
			//cout << i << ' ' << cur << ed;
		}
		cout << c+abs(a0) << ed;
	}
	
}
