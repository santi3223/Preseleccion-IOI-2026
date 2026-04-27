//25 de Enero 2026 19:00
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
	vector<string> arr(n, string(n, '#'));
	for(ll i = 1; i < n/2; i += 2){
		ff(j, i, n-i){
			arr[i][j] = '.';
			arr[j][i] = '.';
			arr[n-1-i][n-1-j] = '.';
			arr[n-1-j][n-1-i] = '.';
		}
	}
	ll x = n-1;
	if(x % 4 == 2){
		arr[x/2][x/2] = '.';
	}
	
	ff(i, 0, n){
		cout << arr[i] << ed;
	}
	
}
