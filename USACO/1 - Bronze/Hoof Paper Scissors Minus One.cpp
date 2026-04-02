//20 de Febrero 2026 16:48
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"


int main(){
	ll n, q;
	cin >> n >> q;
	vector<string> str(n);
	ff(i, 0, n){
		cin >> str[i];
	}
	while(q--){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		ll c = 0, oth = 0;
		ff(i, 0, n){
			ll x = i, y = a;
			bool v1 = false, v2 = false;
			if(x < y){ swap(x, y); v1 = true;}
			ll xx = i, yy = b;
			if(xx < yy){ swap(xx, yy); v2 = true;}
			if(((str[x][y] == 'W' && !v1) || (str[x][y] == 'L' && v1)) && ((str[xx][yy] == 'W' && !v2) || (str[xx][yy] == 'L' && v2))){
				c += n*2-1-oth;
				oth += 2;
			}
		}
		cout << c << ed;
	}
}
