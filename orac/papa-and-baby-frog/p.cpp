#include <bits/stdc++.h>
using namespace std;
struct segtree{
    struct Y{
        Y*lc=nullptr,*rc=nullptr;
        int l,r,sum=0;
        Y(int l,int r):l(l),r(r){}
        void update_y(int p,int a){
            sum+=a;
            if(l==r)return;
            int mid=(l+r)/2;
            if(p<=mid){
                if(lc==nullptr)lc=new Y(l,mid);
                lc->update_y(p,a);
            }else{
                if(rc==nullptr)rc=new Y(mid+1,r);
                rc->update_y(p,a);
            }
        }
        int query_y(int ql,int qr){
            if(qr<l||r<ql)return 0;
            if(ql<=l&&r<=qr)return sum;
            int ans=0;
            if(lc!=nullptr)ans+=lc->query_y(ql,qr);
            if(rc!=nullptr)ans+=rc->query_y(ql,qr);
            return ans;
        }
    };
    struct X{
        X*lc=nullptr,*rc=nullptr;
        Y*yt=nullptr;
        int l,r,yl,yr;
        X(int l,int r,int yl,int yr):l(l),r(r),yl(yl),yr(yr){
            yt=new Y(yl,yr);
        }
        void update_x(int x,int y,int a){
            yt->update_y(y,a);
            if(l==r)return;
            int mid=(l+r)/2;
            if(x<=mid){
                if(lc==nullptr)lc=new X(l,mid,yl,yr);
                lc->update_x(x,y,a);
            }else{
                if(rc==nullptr)rc=new X(mid+1,r,yl,yr);
                rc->update_x(x,y,a);
            }
        }
        int query_x(int x1,int x2,int y1,int y2){
            if(x2<l||r<x1)return 0;
            if(x1<=l&&r<=x2)return yt->query_y(y1,y2);

            int ans=0;
            if(lc!=nullptr)ans+=lc->query_x(x1,x2,y1,y2);
            if(rc!=nullptr)ans+=rc->query_x(x1,x2,y1,y2);
            return ans;
        }
    };
    X*root=nullptr;
    map<pair<int,int>,int>A;
    segtree(int xl,int xr,int yl,int yr){
        root=new X(xl,xr,yl,yr);
    }
    void set(int x,int y,int a){
        int d=a-A[{x,y}];
        A[{x,y}]=a;
        root->update_x(x,y,d);
    }
    int query(int x1,int y1,int x2,int y2){
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        return root->query_x(x1,x2,y1,y2);
    }
};
int main() {
    int N,K;cin>>N>>K;
    
}
