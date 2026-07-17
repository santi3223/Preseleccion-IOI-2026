//10 de Julio 2026 18:41
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
	ll t;
	cin >> t;
	while(t--){
		ll n, a, b;
		cin >> n >> a >> b;
		if(a+b > n || (n == 1 && a+b != 0) || (n == 2 && a+b == 1) || a == n || b == n || (max(a, b) != 0 && min(a, b) == 0)){
			cout << "NO" << ed;
			continue;
		}
		cout << "YES" << ed;
		ff(i, 0, n) cout << i+1 << ' ';
		cout << ed;
		ff(i, 0, b){
			cout << i+a+1 << ' ';
		}
		ff(i, 0, a) cout << i+1 << ' ';
		ff(i, a+b, n) cout << i+1 << ' ';
		cout << ed;
	}
}
