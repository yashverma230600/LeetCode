class LRUCache {

    class Node{
        int key;
        int val;
        Node prev;
        Node next;

        Node(int key, int val){
            this.key=key;
            this.val=val;
        }
    }

    Node head = new Node(-1,-1);
    Node tail = new Node(-1,-1);
    // Capacity of cache
    int cap;
        // Hash map to store key-node mapping
    HashMap<Integer,Node> m = new HashMap<>();

    public LRUCache(int capacity) {
        cap=capacity;
        head.next=tail;
        tail.prev=head;
        
    }

    // Function to remove a given node from list
    private void deleteNode(Node delNode){
        Node delPrev = delNode.prev;
        Node delNext = delNode.next;
        delPrev.next = delNext;
        delNext.prev = delPrev; 
    }

    private void addNode(Node newNode){
        Node temp=head.next;
        newNode.next=temp;
        newNode.prev=head;
        head.next=newNode;
        temp.prev=newNode;
    }
    // Function to get value from cache
    public int get(int key) {
        //If key exist(Check map)
        if(m.containsKey(key)){
            Node resNode = m.get(key);
            int res = resNode.val;

            //remove old mapping
            // m.remove(key);

            deleteNode(resNode);
            addNode(resNode);

            return res;
        }
        return -1;
        
    }
    
    public void put(int key, int value) {
        //If key already exists
        if(m.containsKey(key)){
            Node existingNode = m.get(key);
            m.remove(key);
            deleteNode(existingNode);
        }
        //If cap reached
        if(m.size() == cap){
            m.remove(tail.prev.key);
            deleteNode(tail.prev);
        }
        //insert new node at front
        addNode(new Node(key,value));
        m.put(key,head.next);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */