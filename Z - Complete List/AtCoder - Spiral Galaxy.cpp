//25 de Abril 2026 8:13
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

vector<string> arr;

bool chec(ll i1, ll j1, ll i2, ll j2){
	ff(i, i1, i2+1){
		ff(j, j1, j2+1){
			ll ni = i1+i2-i;
			ll nj = j1+j2-j;
			if(arr[i][j] != arr[ni][nj]) return false;
		}
	}
	return true;
}

int main(){
	ll n, m;
	cin >> n >> m;
	arr = vector<string>(n);
	ff(i, 0, n) cin >> arr[i];
	ll c = n*m;
	ff(i, 0, n){
		ff(j, 0, m){
			ff(id, i, n){
				ff(jd, j, m){
					if(id == i && jd == j) continue;
					c += chec(i, j, id, jd);
				}
			}
		}
	}
	cout << c;
}
