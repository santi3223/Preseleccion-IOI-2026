//23 de Junio 2026 22:39
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

string dir = "UDLR";
ll dx[] = {0, 0, -1, 1};
ll dy[] = {1, -1, 0, 0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll stx, sty, enx, eny;
	cin >> stx >> sty >> enx >> eny;
	ll n;
	cin >> n;
	string in;
	cin >> in;
	vector<pll> arr(n+1, {0, 0});
	ff(i, 0, n){
		char c = in[i];
		ll x = arr[i].fi;
		ll y = arr[i].se;
		ff(j, 0, 4){
			if(dir[j] == c){
				x += dx[j];
				y += dy[j];
			}
		}
		arr[i+1] = {x, y};
	}
	ll l = 0, r = 1e18;
	while(r-l > 1){
		ll mid = l+(r-l)/2;
		ll q = mid/n, rem = mid%n;
		ll x = stx+arr[rem].fi+q*arr[n].fi;
		ll y = sty+arr[rem].se+q*arr[n].se;
		ll dist = abs(x-enx)+abs(y-eny);
		//cout << l << ' ' << r << ' ' << mid << ed;
		//cout << dist << ' ' << mid << ed;
		if(dist <= mid) r = mid;
		else l = mid;
	}
	if(r > 2e14) r = -1;
	cout << r;
	
}
