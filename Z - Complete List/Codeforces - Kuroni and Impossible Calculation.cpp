//12 de Julio 2026 23:04
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
 
int main(){
	ll n, m;
	cin >> n >> m;
	vl a(n);
	ff(i, 0, n){
		cin >> a[i];
		//a[i] %= m;
		//cout << a[i] << ' ';
	}
	//cout << ed;
	ll ans = -1;
	if(n <= m){
		ff(i, 0, n){
			ff(j, i+1, n){
				if(ans == -1) ans = abs(a[i]-a[j]);
				else ans *= abs(a[i]-a[j]);
				//cout << abs(a[i]-a[j]) << ed;
				ans %= m;
			}
		}
	}
	else ans = 0;
	cout << ans;
	
}
