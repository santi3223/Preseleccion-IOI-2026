//17 de Julio 2026 23:41
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

struct ds{
	array<ll, 9> a;
	ll c;
};
vl fac;


ll encode(array<ll, 9> a){
	ll s = 0;
	bool vis[9] = {};
	ff(i, 0, 9){
		vis[a[i]-1] = 1;
		ll c = 0;
		ff(j, 1, a[i]){
			if(!vis[j-1]) c++;
		}
		s += fac[8-i]*c;
	}
	//cout << s << ed;
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fac = vl(10);
	fac[0] = 1;
	ff(i, 1, 10) fac[i] = i*fac[i-1];
	array<ll, 9> arr, ok;
	ff(i, 0, 9) cin >> arr[i];
	queue<ds> pq;
	pq.push({arr, 0});
	ll sz = 9*8*7*6*5*4*3*2;
	vb vis(sz+5, 0);
	ff(i, 0, 9) ok[i] = i+1;
	//cout << "a " << encode(arr);
	vis[encode(arr)] = 1;
	
	while(pq.size()){
		auto [a, c] = pq.front();
		pq.pop();
		if(a == ok){
			cout << c;
			return 0;
		}
		
		swap(a[0], a[1]);
		ll s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[0], a[1]);
		
		swap(a[2], a[1]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[2], a[1]);
		
		swap(a[3], a[4]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[3], a[4]);
		
		swap(a[5], a[4]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[5], a[4]);
		
		swap(a[6], a[7]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[6], a[7]);
		
		swap(a[8], a[7]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[8], a[7]);
		
		
		
		
		swap(a[0], a[3]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[0], a[3]);
		
		swap(a[6], a[3]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[6], a[3]);
		
		swap(a[1], a[4]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[1], a[4]);
		
		swap(a[7], a[4]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[7], a[4]);
		
		swap(a[2], a[5]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[2], a[5]);
		
		swap(a[8], a[5]);
		s = encode(a);
		if(!vis[s]){
			vis[s] = 1;
			pq.push({a, c+1});
		}
		swap(a[8], a[5]);
		
	}
}

/*
0 1 2
3 4 5
6 7 8
*/
