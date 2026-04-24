#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	node*l,*r;int tl,tr,mx,add,st,sv;bool hst;
	int len(){return tr-tl+1;}
	void apply_add(int x){
		mx+=x;
		st+=x*len();
		if(hst)sv+=x;
		else add+=x;
	}
	void apply_set(int x){
		mx=x;
		st=x*len();
		sv=x;
		add=0;
		hst=1;
	}
	void ext(){
		if(tl==tr)return;
		int tm=(tl+tr)/2;
		if(!l)l=new node{0,0,tl,tm,0,0,0,0,0};
		if(!r)r=new node{0,0,tm+1,tr,0,0,0,0,0};
	}
	void push(){
		if(tl==tr)return;
		ext();
		if(hst){
			l->apply_set(sv);
			r->apply_set(sv);
			hst=0;
		}
		if(add){
			l->apply_add(add);
			r->apply_add(add);
			add=0;
		}
	}
	void pull(){
		mx=max(l?l->mx:-(1LL<<60),r?r->mx:-(1LL<<60));
		st=(l?l->st:0)+(r?r->st:0);
	}
	void range_add(int ql,int qr,int x){
		if(qr<tl||tr<ql)return;
		if(ql<=tl&&tr<=qr){
			apply_add(x);
			return;
		}
		push();
		l->range_add(ql,qr,x);
		r->range_add(ql,qr,x);
		pull();
	}
	void range_set(int ql,int qr,int x){
		if(qr<tl||tr<ql)return;
		if(ql<=tl&&tr<=qr){
			apply_set(x);
			return;
		}
		push();
		l->range_set(ql,qr,x);
		r->range_set(ql,qr,x);
		pull();
	}
	int query_max(int ql,int qr){
		if(qr<tl||tr<ql)return -(1LL<<60);
		if(ql<=tl&&tr<=qr)return mx;
		push();
		return max(l->query_max(ql,qr),r->query_max(ql,qr));
	}
	int query_sum(int ql,int qr){
		if(qr<tl||tr<ql)return 0;
		if(ql<=tl&&tr<=qr)return st;
		push();
		return l->query_sum(ql,qr)+r->query_sum(ql,qr);
	}
};
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int N,Q;cin>>N>>Q;
 
	node*st=new node{0,0,0,N,0,0,0,0,0};
	for(int i=1;i<=Q;i++){
		string t;cin>>t;
		if(t=="A"){
			int l,r,v;cin>>l>>r>>v;
			st->range_add(l,r,v);
		}else if(t=="S"){
			int l,r,v;cin>>l>>r>>v;
			st->range_set(l,r,v);
		}else if(t=="T"){
			int l,r;cin>>l>>r;
			cout<<st->query_sum(l,r)<<endl;
		}else if(t=="M"){
			int l,r;cin>>l>>r;
			cout<<st->query_max(l,r)<<endl;
		}
	}
}
