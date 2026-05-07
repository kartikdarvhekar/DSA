class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(0);
        Node* temp=head;
        Node* tempC=dummy;
        while(temp){
            Node* k= new Node(temp->val);
            tempC->next=k;
            tempC=tempC->next;
            temp=temp->next;
        }
        Node* a=head;
        Node* b=dummy->next;
        unordered_map<Node*,Node*>m;
        while(a){
            m[a]=b;
            a=a->next;
            b=b->next;
        }
        for(auto ele : m){
           if(ele.first->random!=NULL) (ele.second)->random=m[(ele.first)->random];
        }
        return dummy->next;
    }
};