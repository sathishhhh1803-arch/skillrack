#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& seg,int node,int nl,int nr,int ql,int qr){
    if(nr<ql || nl>qr) return 1e9+1;
    if(nr<=qr && nl>=ql) return seg[node];
    int mid=(nl+nr)/2;
    int lc=find(seg,2*node,nl,mid,ql,qr);
    int rc=find(seg,2*node+1,mid+1,nr,ql,qr);
    return min(lc,rc);
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    int newn=1;
    while(newn<n) newn=newn<<1;
    vector<int> seg(newn*2,1e9+1);
    for(int i=newn;i<newn+n;i++) cin>>seg[i];
    for(int i=newn-1;i>0;i--)
     seg[i]=min(seg[i+i],seg[i+i+1]);
    
    n=newn;
    while(q--){
        int lt,rt; cin>>lt>>rt;
        cout<<find(seg,1,1,n,lt,rt)<<endl;
    }
}