#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
struct light{
    long long x,y;
};
int main() {
    long long l,n,k;
    scanf("%lld%lld%lld",&l,&n,&k);
    long long a[n];
    queue <light> q;
    vector <long long> v;
    set <long long> visit;
    // long long visit[l+1]={};

    int k1=k; //

    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        light r;
        r.x=a[i];
        r.y=0;
        q.push(r);
        v.push_back(0);
        visit.insert(a[i]);
        // visit[a[i]]=1;
        k--; //
    }
    while(!q.empty()){
        light t=q.front();
        q.pop();
        long long left=t.x-1;  //
        long long right=t.x+1; //
        // cout << left << " " << right << endl;
        if(left>=0){
            if(visit.count(left)==0){
                k--;
                visit.insert(left);
                light p;
                p.x=left;
                p.y=t.y+1;
                q.push(p);
                v.push_back(t.y+1);
                if(k<0){
                    break;
                }
            }
        }
        if(right<=l){ //
            if(visit.count(right) == 0){
                k--;
                // visit[right]=1;
                visit.insert(right);
                light p;
                p.x=right;
                p.y=t.y+1;
                q.push(p);
                v.push_back(t.y+1);
                if(k<0){
                    break;
                }
            }
        }
    }
    for(int i=0;i<k1;i++){
        printf("%lld\n",v[i]);
    }
    return 0;
}