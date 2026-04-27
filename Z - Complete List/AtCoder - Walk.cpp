//20 de Marzo 2026 18:10
//DP contest
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
#define ed endl
#define vs vector<string>
const ll MOD = 1e9+7;

ll n;

vector<vl> mult(vector<vl> &a, vector<vl> &b){
	vector<vl> res(n, vl(n, 0));
	ff(i, 0, n){
		ff(k, 0, n){
			if(a[i][k] == 0) continue;
			ff(j, 0, n){
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return res;
}

vector<vl> mat(vector<vl> arr, ll k){
	vector<vl> res(n, vl(n, 0));
	ff(i, 0, n) res[i][i] = 1;
	while(k){
		if(k % 2 != 0) res = mult(res, arr);
		arr = mult(arr, arr);
		k/=2;
	}
	return res;
}

int main(){
	ll k;
	cin >> n >> k;
	
	vector<vl> arr(n, vl(n));
	ff(i, 0, n) ff(j, 0, n) cin >> arr[i][j];
	vector<vl> b = mat(arr, k);
	ll c = 0;
	ff(i, 0, n) ff(j, 0, n) c = (c+b[i][j])%MOD;
	cout << c;
}
