class Node
{   
    public:

    int key, value;
    Node *next, *prev;
    
    Node(int key, int val)
    {   
        this->key = key;
        this->value = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
public:

    unordered_map<int,Node*>umap;
    int cnt;
    int size;
    Node *head, *tail;

    LRUCache(int capacity) {
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
        
        cnt =  0;
        size = capacity;
    }

    void deleteNode(Node *node)
    {
        if(node==nullptr)
            return;

        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        cnt-=1;   
    }

    void addNode(Node *node)
    {
        if(node==nullptr)
            return;

        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;

        cnt+=1; 
    }
    
    int get(int key) {

        if(umap.find(key)==umap.end())
            return -1;

        Node *node = umap[key];
        int value = node->value;

        deleteNode(node);

        //Node *newNode = new Node(value);
        addNode(node);
        umap[key] = node;

        return value;
    }
    
    void put(int key, int value) {
        
        if(umap.find(key)!=umap.end())
        {
            Node *node = umap[key];
            node->value = value;

            deleteNode(node);
            addNode(node);
            umap[key] = node;
            return;
        }

        if(cnt==size)
        {
            Node *nodeToBeDeleted = tail->prev;
            deleteNode(nodeToBeDeleted);
            umap.erase(nodeToBeDeleted->key);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        umap[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */