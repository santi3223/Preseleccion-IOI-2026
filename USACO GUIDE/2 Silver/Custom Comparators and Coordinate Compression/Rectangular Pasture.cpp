//12 de marzo 2026 17:47
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
vector<vl> pref;

ll calc(ll a, ll b, ll c, ll d){
	ll q1 = 0, q2 = 0, q3 = 0;
	if(a-1 >= 0) q1 = pref[a-1][d];
	if(b-1 >= 0) q2 = pref[c][b-1];
	if(a-1 >= 0 && b-1 >= 0) q3 = pref[a-1][b-1];
	
	return pref[c][d]-q1-q2+q3;
}

int main(){
	ll n;
	cin >> n;
	vector<pll> arr(n);
	ff(i, 0, n){
		cin >> arr[i].fi >> arr[i].se;
	}
	set<ll> xc, yc;
	sort(all(arr));
	ff(i, 0, n){
		xc.insert(arr[i].fi);
		yc.insert(arr[i].se);
	}
	map<ll, ll> tranx, trany;
	ll id = 0;
	for(auto &x : xc){
		tranx[x] = id;
		id++;
	}
	id = 0;
	for(auto &x : yc){
		trany[x] = id;
		id++;
	}
	pref = vector<vl>(n, vl(n, 0));
	ff(i, 0, n){
		arr[i].fi = tranx[arr[i].fi];
		arr[i].se = trany[arr[i].se];
		//cout << arr[i].fi << " " << arr[i].se << ed;
		pref[arr[i].fi][arr[i].se]++;
	}
	ff(j, 0, n){
		ff(i, 1, n){
			pref[i][j] += pref[i-1][j];
		}
	}
	
	ff(i, 0, n){
		ff(j, 1, n){
			pref[i][j] += pref[i][j-1];
		}
	}
	
	/*ff(i, 0, n){
		ff(j, 0, n){
			cout << pref[i][j] << " ";
		}
		cout << ed;
	}*/
	
	ll ans = 0;
	
	ff(i, 0, n){
		ff(j, i+1, n){
			ll a = arr[i].fi, b = arr[i].se;
			ll c = arr[j].fi, d = arr[j].se;
			if(a > c) swap(a, c);
			if(b > d) swap(b, d);
			
			ll q1 = calc(0, b, a, d);
			ll q2 = calc(c, b, n-1, d);
			ans += q1*q2;
			
		}
	}
	
	cout << ans+n+1;
	
	
	
}
