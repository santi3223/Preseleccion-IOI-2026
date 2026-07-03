//2 de Julio 2026 20:41
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
		ll a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		if((a+b)%3 == 0 && min(a,b)*2 >= max(a,b)) cout << "YES" << ed;
		else cout << "NO" << ed;
	}
	
}
