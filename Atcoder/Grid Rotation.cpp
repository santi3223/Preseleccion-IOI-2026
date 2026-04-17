//26 de Enero 2026 10:03
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
ll MOD = 1e9;

int main(){
	ll minn = LLONG_MAX;
	ll n;
	cin>> n;
	vector<string> a(n), b(n);
	ff(i, 0, n){
		cin >> a[i];
	}
	ff(i, 0, n){
		cin >> b[i];
	}
	ll c;
	c = 0;
	ff(i, 0, n){
		ff(j, 0, n){
			if(a[i][j] != b[i][j]) c++;
		}
	}
	minn = min(minn, c);
	c = 0;
	ll id = 0, jd = 0;
	for(ll j = n-1; j >= 0; j--){
		ff(i, 0, n){
			if(a[i][j] != b[id][jd]){
				c++;
			}
			jd++;
		}
		jd = 0;
		id++;
	}
	minn = min(minn, c+3);
	c = 0;
	id = 0;
	jd = 0;
	for(ll i = n-1; i >= 0; i--){
		for(ll j = n-1; j >= 0; j--){
			if(a[i][j] != b[id][jd]) c++;
			jd++;
		}
		jd = 0;
		id++;
	}
	minn = min(minn, c+2);
	c = 0;
	id = 0; 
	jd = 0;
	ff(j, 0, n){
		for(ll i = n-1; i >= 0; i--){
			if(a[i][j] != b[id][jd]) c++;
			jd++;
		}
		jd = 0;
		id++;
	}
	minn = min(minn, c+1);
	cout << minn;
	
}
