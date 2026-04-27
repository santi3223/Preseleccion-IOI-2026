//18 de Enero 2026 11:08
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


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, h;
		cin >> n >> m >> h;
		vl a(n);
		ff(i, 0, n){
			cin >> a[i];
		}
		vl original = a;
		vector<bool> check(n, false);
		ff(i, 0, m){
			ll b, c;
			cin >> b >> c;
			b--;
			if(check[b]){
				check[b] = false;
				a[b] = original[b];
			}
			a[b] += c;
			if(a[b] > h) check = vector<bool>(n, true);
		}
		ff(i, 0, n){
			if(check[i] == true){
				a[i] = original[i];
			}
		}
		ff(i, 0, n){
			cout << a[i] << " ";
		}
		cout << ed;
	}
}
