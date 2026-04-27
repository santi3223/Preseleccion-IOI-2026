//26 de Febrero 2026 19:02
#include <bits/stdc++.h>
#include "light.h"
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
//C1
ll q;
bool l;

void prepare(){
	q = 1;
	l = false;
}

pair<ll, vl> join(ll p){
	q += p;
	vl a;
	if(l){
		a = {q};
		return {p, a};
	}
	ll x = 1;
	while(true){
		if(x > q) break;
		a.pb(q-(x-1));
		x *= 2;
	}
	if(a[a.size()-1] != 1) a.pb(1);
	reverse(all(a));
	return {p, a};
}

pair<ll, vl> leave(ll p){
	l = true;
	q -= p;
	vl a = {1, q};
	if(q == 1) a = {1};
	return {p, a};
}
/*
int main(){
	ll Q;
	cin >> Q;
	prepare();
	while(Q--){
		ll P;
		cin >> P;
		pair<ll, vl> ans;
		if(P > 0){
			ans = join(P);
		}
		else ans = leave(abs(P));
		cout << ans.fi << "  ";
		ff(i, 0, ans.se.size()){
			cout << ans.se[i] << " ";
		}
		cout << ed;
	}
}
*/
