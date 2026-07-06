//4 de Julio 2026 15:19
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ll n, m;
	cin >> n >> m;
	vl pos(n), arr(n);
	ff(i, 0, n){
		ll a;
		cin >> a;
		arr[i] = a-1;
		pos[a-1] = i;
	}
	ll c = 1;
	ff(i, 0, n-1){
		if(pos[i] > pos[i+1]) c++;
	}
	//cout << c << ed;
	while(m--){
		ll a, b;
		cin >> a >> b;
		ll va = arr[a-1], vb = arr[b-1];
		set<ll> st;
		st.insert(va-1);
		st.insert(va);
		st.insert(vb-1);
		st.insert(vb);
		
		for(auto x : st) if(x+1 < n && 0 <= x && pos[x] > pos[x+1]) c--;
		
		swap(pos[va], pos[vb]);
		swap(arr[a-1], arr[b-1]);
		
		for(auto x : st) if(x+1 < n && 0 <= x && pos[x] > pos[x+1]) c++;
		cout << c << ed;
	}
}
