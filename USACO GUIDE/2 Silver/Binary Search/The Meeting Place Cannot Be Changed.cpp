//24 de Abril 2026 23:09
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

ll n;
vector<pair<long double, long double>> arr;
bool rig, lef;

long double chec(long double mid){
	long double maxx = 0.0;
	ff(i, 0, n){
		if(arr[i].fi == mid) continue;
		long double cur = abs(arr[i].fi-mid)/arr[i].se;
		if(cur > maxx){
			lef = 0;
			rig = 0;
			maxx = cur;
			if(arr[i].fi < mid) lef = 1;
			else rig = 1;
		}
		else if(cur == maxx){
			if(arr[i].fi < mid) lef = 1;
			else rig = 1;
		}
	}
	return maxx;
}

int main(){
	cin >> n;
	arr = vector<pair<long double, long double>>(n);
	ff(i, 0, n) cin >> arr[i].fi;
	ff(i, 0, n) cin >> arr[i].se;
	sort(all(arr));
	long double minn = arr[n-1].fi, l = 0.0, r = minn, MAXX = 10e-7;
	while(r-l > MAXX){
		long double mid = l+(r-l)/2;
		lef = 0;
		rig = 0;
		long double cur = chec(mid);
		minn = min(minn, cur);
		if(lef && rig) break;
		if(lef) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(10) << minn;
}
