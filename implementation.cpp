#include<bits/stdc++.h>
using namespace std;
// https://github.com/singhsanket143/CppCompetitiveRepository/blob/master/heap_lectures/maxheap.cpp
class maxheap{
    public:
    vector<int>hp;
    maxheap(){

    }
    void upheapify(){
        int ci= hp.size()-1; // ci - child idx and pi - parent idx
        if(ci==0)return;
        while(ci>0){
            int pi = (ci-1)/2;
            if(hp[ci]>hp[pi]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }
            else break;
        }
    }

    void downheapify(){
        int pi = 0;
        while(pi<hp.size()){
            int lc = 2*pi+1;
            int rc = 2*pi+2;
            if(lc>=hp.size())return ; // as left child is filled fst and if its not in size then pi is leaf node
            int mxidx = pi;
            if(hp[mxidx]<hp[lc])mxidx=lc;
            if(rc < hp.size() and hp[mxidx]<hp[rc])mxidx=rc;
            if(mxidx!=pi){
                swap(hp[mxidx],hp[pi]);
                pi=mxidx;
            }else break;
        }
        
    }
    void push(int val){
        hp.push_back(val);
        upheapify();
    }
    void pop(){
        // removes front or highest priority element
        if(hp.size()==0)return ;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        downheapify();
    }
    void peek(){
        if(hp.size()==0)cout<<"insert first"<<endl;
        else cout<<hp[0]<<endl; 
    }
    bool isempty(){
        return hp.size()==0;
    }

    void display()
    {
        for(int i=0; i<hp.size(); i++){
            cout<<hp[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    maxheap hp;
    hp.push(3);
    cout<<hp.isempty()<<endl;
    hp.push(1);
    hp.push(2);
    hp.push(8);
    hp.push(3);
    hp.display();
    hp.pop();
    hp.display();
    return 0;
}