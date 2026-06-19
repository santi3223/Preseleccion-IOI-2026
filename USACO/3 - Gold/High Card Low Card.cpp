//18 de Junio 2026 19:41
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
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	
	ll n;
	cin >> n;
	vl arr(n);
	set<ll> tod;
	ff(i, 0, 2*n) tod.insert(i+1);
	ff(i, 0, n){
		cin >> arr[i];
		tod.erase(arr[i]);
	}
	set<ll> st, may, men;
	for(auto x : tod){
		if(men.size() == n/2) may.insert(x);
		else men.insert(x);
	}
	st = may;
	//for(auto x : st) cout << x << ' ';
	//cout << ed;
	
	ll c = 0;
	ff(i, 0, n/2){
		ll cur = arr[i];
		if(cur > *st.rbegin()){
			st.erase(st.begin());
		}
		else{
			auto it = st.lower_bound(cur);
			st.erase(it);
			c++;
		}
	}
	
	st = men;
	
	//for(auto x : st) cout << x << ' ';
	//cout << ed;
	ff(i, n/2, n){
		ll cur = arr[i];
		if(cur < *st.begin()){
			st.erase(prev(st.end()));
		}
		else{
			auto it = st.lower_bound(cur);
			it--;
			st.erase(it);
			c++;
		}
	}
	cout << c;
	
	
	
}
