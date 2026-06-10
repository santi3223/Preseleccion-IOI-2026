//6 de Junio 2026 08:03
#include <bits/stdc++.h>
using namespace std;
#define ll int
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(arr[x-1] != i+1){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
