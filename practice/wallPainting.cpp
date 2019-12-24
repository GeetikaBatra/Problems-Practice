#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Worker{
	ll T, c,s;
};

bool cmp(Worker w1, Worker w2){
	if(w1.T==w2.T){
		if(w1.s==w2.s){
			return w1.c < w2.c;
		}
		return w1.s>w2.s;
	}
	return w1.T<w2.T;
}
void WallPainting(Worker *works, ll N, ll D){
	sort(works, works+N, cmp);
	ll total_cost=0;
	ll time=0;
	ll i=0;
	while(i<N){
		if(D<works[i].s){
			break;
		}
		D=D-works[i].s;
		total_cost+=works[i].c;
	}
	if(D!=0){
		total_cost+=works[i].c;
	}
	
	cout << total_cost << endl;
}

int main(){
	ll N,D;
	cin>>N>>D;
	// freopen("input.txt", "r", stdin);
	Worker works[N];
	for(int i=0; i<N;i++){
	    ll T;
		ll c;
		ll s;
		cin>>T>>c>>s;
		Worker newW;
		newW.T=T;
		newW.c=c;
		newW.s=s;

		works[i] = newW;
	}
	WallPainting(works, N, D);
}