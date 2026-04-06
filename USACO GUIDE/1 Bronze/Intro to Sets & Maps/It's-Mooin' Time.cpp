//16 de Febrero 2026 23:26
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

int main(){
	ll n, f;
	cin >> n >> f;
	string arr;
	cin >> arr;
	map<string, ll> mp;
	map<string, vl> coords;
	ff(i, 2, n){
		string cur = "";
		cur += arr[i-2];
		cur += arr[i-1];
		cur += arr[i];
		mp[cur]++;
		coords[cur].pb(i-2);
		coords[cur].pb(i-1);
		coords[cur].pb(i);
	}
	vector<char> list = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
	vector<string> ans;
	for(auto &x : mp){
		string cur = x.fi;
		if(cur[0] != cur[1] && cur[2] == cur[1]){
			
		}
		else{
			continue;
		}
		if(x.se >= f){
			ans.pb(cur);
			continue;
		}
		if(x.se == f-1){
			string nw = cur;
			bool ok = false;
			ff(i, 0, list.size()){
				nw[0] = list[i];
				if(nw != cur && mp[nw] != 0){
					ll id = 0;
					bool ot = false;
					while(id < coords[nw].size()){
						bool notn = false;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+1] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+2] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ot = true;
						break;
					}
					if(ot){
						ans.pb(cur);
						ok = true;
						break;
					}
				}
			}
			if(ok) continue;
			nw = cur;
			ff(i, 0, list.size()){
				nw[1] = list[i];
				if(nw != cur && mp[nw] != 0){
					ll id = 0;
					bool ot = false;
					while(id < coords[nw].size()){
						bool notn = false;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+1] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+2] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ot = true;
						break;
					}
					if(ot){
						ans.pb(cur);
						ok = true;
						break;
					}
				}
			}
			if(ok) continue;
			nw = cur;
			ff(i, 0, list.size()){
				nw[2] = list[i];
				if(nw != cur && mp[nw] != 0){
					ll id = 0;
					bool ot = false;
					while(id < coords[nw].size()){
						bool notn = false;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+1] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ff(jd, 0, coords[cur].size()){
							if(coords[nw][id+2] == coords[cur][jd]){
								id += 3;
								notn = true;
								break;
							}
						}
						if(notn) continue;
						ot = true;
						break;
					}
					if(ot){
						ans.pb(cur);
						ok = true;
						break;
					}
				}
			}
			if(ok) continue;
		}
	}
	if(f == 1){
		for(auto &x : mp){
			string cur = x.fi, nw = cur;
			ff(i, 0, list.size()){
				nw[0] = list[i];
				if(nw != cur && nw[0] != nw[1] && nw[1] == nw[2]) ans.pb(nw);
			}
			nw = cur;
			ff(i, 0, list.size()){
				nw[1] = list[i];
				if(nw != cur && nw[0] != nw[1] && nw[1] == nw[2]) ans.pb(nw);
			}
			nw = cur;
			ff(i, 0, list.size()){
				nw[2] = list[i];
				if(nw != cur && nw[0] != nw[1] && nw[1] == nw[2]) ans.pb(nw);
			}
		}
	}
	cout << ans.size() << ed;
	sort(all(ans));
	ff(i, 0, ans.size()) cout << ans[i] << ed;
	
}
