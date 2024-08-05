#include<bits/stdc++.h>
using namespace std;

struct cmp {
        bool operator()(const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };


 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp >pq;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!= NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(100);
        ListNode* ptr =  dummy;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr->next)pq.push(curr->next);
            ptr->next = curr;
            ptr= ptr->next;
        }
        return dummy->next;
    }

int main(){
    return 0;
}