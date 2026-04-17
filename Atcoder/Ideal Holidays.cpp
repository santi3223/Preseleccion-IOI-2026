//23 de Enero 2026 10:42
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
	ll n, a, b;
	cin >> n >> a >> b;
	vl arr(n);
	ll mod = a+b;
	ff(i, 0, n){
		cin >> arr[i];
		arr[i] %= mod;
	}
	sort(all(arr));
	if(arr[n-1]-arr[0]+1 <= a){
		cout << "Yes";
		return 0;
	}
	ff(i, 1, n){
		if(arr[i]-arr[i-1]-1 >= b){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	
	
}
