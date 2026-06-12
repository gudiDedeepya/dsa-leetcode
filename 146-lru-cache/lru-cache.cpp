class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }

    void addnode(node* newnode){
        node* temp=head->next;
        
        newnode->next=temp;
         newnode->prev=head;
         head->next=newnode;
        temp->prev=newnode;
       
    }


    void deletenode(node* todel){
        node* delprev=todel->prev;
        node* nexnode=todel->next;
        delprev->next=nexnode;
        nexnode->prev=delprev;
        //delete todel;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node *resnode=mpp[key];
            int res=resnode->val;
            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* exist=mpp[key];
            mpp.erase(key);
            deletenode(exist);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */