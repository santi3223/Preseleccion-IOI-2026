//22 de Enero 2026 23:08
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
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll n;
	cin >> n;
	ff(i, 0, n+1){
		ff(j, 0, n-i+1){
			ff(k, 0, n-i-j+1){
				cout << i << " " << j << " " << k << ed;
			}
		}
	}
}
