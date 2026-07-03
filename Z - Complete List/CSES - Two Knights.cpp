//2 de Julio 2026 17:10
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
 
void f(ll n){
	cout <<  (n-1)*(n+4)*(n*n-3*n+4)/2 << ed;
}
 
int main(){
	ll n;
	cin >> n;
	ff(i, 1, n+1){
		f(i);
	}
}
