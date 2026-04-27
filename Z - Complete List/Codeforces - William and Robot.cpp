//2 de Marzo 2026 21:12
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
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	priority_queue<ll, vl, greater<ll>> pq;
	ff(i, 0, n){
		pq.push(arr[i]);
		if(i % 2 != 0) pq.pop();
		//cout << pq.top() << ed;
	}
	ll c = 0;
	while(!pq.empty()){
		c += pq.top();
		pq.pop();
	}
	cout << c;
}
