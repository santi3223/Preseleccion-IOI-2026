//7 de Marzo 2026 08:01
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, x;
	cin >> n >> x;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
		if(arr[i] < x){
			cout << 1 <<ed;
			x = arr[i];
		}
		else cout << 0 << ed;
	}
	
}
