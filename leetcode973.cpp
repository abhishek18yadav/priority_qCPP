#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, vector<int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(auto ele : points){
            int x= ele[0];
            int y= ele[1];
            int distance = x*x + y*y;
            pp p1;
            p1.first= distance;
            p1.second = ele;
            pq.push(p1);
        }
        vector<vector<int>>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
int main(){
    vector<vector<int>>points{{1,3},{-2,2}};
    int k=1;
    vector<vector<int>>res = kClosest(points,k);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}