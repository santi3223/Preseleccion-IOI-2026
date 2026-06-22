//21 de Junio 2026 23:24
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

vector<vl> a;
vector<map<ll, ll>> mp;
ll c = 0;
ll n, m, k;

void calc(ll x, ll y, ll steps, bool fir, ll val){
	if(x < 0 || y < 0 || n <= x || m <= y || steps == 0) return;
	val ^= a[x][y];
	//cout << x << ' ' << y << ' ' << steps << ' ' << fir << ' ' << val << ed;
	if(steps == 1){
		if(fir) mp[x][val]++;
		else c += mp[x][k^val^a[x][y]];
	}
	
	if(fir){
		calc(x, y+1, steps-1, fir, val);
		calc(x+1, y, steps-1, fir, val);
	}
	else{
		calc(x, y-1, steps-1, fir, val);
		calc(x-1, y, steps-1, fir, val);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	a = vector<vl>(n, vl(m));
	ff(i, 0, n){
		ff(j, 0, m){
			cin >> a[i][j];
		}
	}
	mp = vector<map<ll, ll>>(n);
	ll st = (n+m-1)/2, en = (n+m-1)-st;
	st++;
	//cout << st << ' ' << en << ed;
	
	calc(0, 0, st, 1, 0);
	calc(n-1, m-1, en, 0, 0);
	cout << c;
	
}
