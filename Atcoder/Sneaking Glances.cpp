//11 de Abril 2026 08:15
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	queue<pair<ll, pair<ll, long double>>> q;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	q.push({-1, {0, 0.5}});
	ll maxx = 0;
	while(!q.empty()){
		ll id = q.front().fi;
		ll tims = q.front().se.fi;
		long double coords = q.front().se.se;
		q.pop();
		maxx= max(maxx, tims);
		if(id+1 >= n) continue;
		long double pos = (long double)coords-arr[id+1];
		if(coords > 0 && coords-arr[id+1] < 0){
			q.push({id+1, {tims+1, pos}});
		}
		else{
			q.push({id+1, {tims, pos}});
		}
		pos = (long double)coords+arr[id+1];
		if(coords < 0 && coords+arr[id+1] > 0){
			q.push({id+1, {tims+1, pos}});
		}
		else{
			q.push({id+1, {tims, pos}});
		}
	}
	cout << maxx;
}
