//17 de Junio 2026 15:34
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	
	ll n;
	cin >> n;
	//arrival senior, sample time
	vector<pair<ll, pll>> arr(n);
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		arr[i] = {a, {n-i, b}};
	}
	sort(all(arr));
	//senior, arrival, sample
	ll id = 0;
	priority_queue<pair<ll, pll>> pq;
	pq.push({arr[id].se.fi, {arr[id].fi, arr[id].se.se}});
	ll maxx = 0, cur = arr[id].fi;
	id++;
	while(id < n || pq.size()){
		if(pq.empty() && id < n){
			//cout << "FILL" << ed;
			cur = arr[id].fi;
			while(cur >= arr[id].fi && id < n){
				pq.push({arr[id].se.fi, {arr[id].fi, arr[id].se.se}});
				id++;
			}
		}
		while(pq.size()){
			ll arriv = pq.top().se.fi, samp = pq.top().se.se;
			//cout << pq.top().fi+1 << ed << arriv << ' ' << samp << "  " << cur << ' ' << maxx << ed;
			pq.pop();
			maxx = max(maxx, cur-arriv);
			cur += samp; 
			//cout << cur << ' ' << maxx << ed << ed;
			while(cur >= arr[id].fi && id < n){
				pq.push({arr[id].se.fi, {arr[id].fi, arr[id].se.se}});
				id++;
			}
		}
	}
	cout << maxx;
}
