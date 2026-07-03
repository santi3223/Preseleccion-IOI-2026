//2 de Julio 2026 14:45
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
		ll x, y;
		cin >> y >> x;
		if(y <= x){
			if(x & 1){
				cout << x*x-(y-1);
			}
			else{
				cout << (x-1)*(x-1)+y;
			}
		}
		else{
			swap(x, y);
			if(x & 1){
				cout << (x-1)*(x-1)+y;
			}
			else{
				cout << x*x-(y-1);
			}
		}
		cout << ed;
	}
}
