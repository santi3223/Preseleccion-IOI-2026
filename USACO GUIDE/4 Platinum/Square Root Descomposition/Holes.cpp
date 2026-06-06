//5 de Junio 2026 15:46
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

ll n, blocks;
vl arr, cnt, nxt, last;

void build(ll i){
	ll l = blocks*i, r = min(n, blocks*(i+1))-1;
	//cout << "L R " << l << ' ' << r << ed;
	for(ll i = r; i >= l; i--){
		ll to = arr[i]+i;
		if(to >= n){
			nxt[i] = n;
			cnt[i] = 1;
			last[i] = i;
		}
		else if((i/blocks) != (to/blocks)){
			nxt[i] = to;
			cnt[i] = 1;
			last[i] = i;
		}
		else{
			nxt[i] = nxt[to];
			cnt[i] = cnt[to]+1;
			last[i] = last[to];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> n >> q;
	arr = vl(n);
	cnt = nxt = last = arr;
	ff(i, 0, n) cin >> arr[i];
	blocks = sqrt(n);
	ll B = (n+blocks-1)/blocks;
	ff(i, 0, B) build(i);
	while(q--){
		ll o, a;
		cin >> o >> a;
		a--;
		if(o == 0){
			ll b;
			cin >> b;
			arr[a] = b;
			build(a/blocks);
		}
		else{
			ll cur = a;
			ll c = 0, ult = a;
			while(cur < n){
				c += cnt[cur];
				ult = last[cur];
				cur = nxt[cur];
			}
			cout << ult+1 << ' ' << c << ed;
		}
	}
}
