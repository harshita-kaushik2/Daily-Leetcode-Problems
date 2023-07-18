/*Intuition
We store the values in Unordered Map as {key,address} pair.

Initial coniguration of Doubly Linked List
The nodes of DLL store {key,value} pair
It has two dummy nodes head and tail
Inititally, the dummy nodes have value (-1,-1).
The head points to tail and tail points to head.
The most recently used key will be placed right after the head. That means, if we put() a {key,value} pair to the DLL, it has to be right after the head.

Note : When you call get() for a key, that key becomes the most recently used cache. Thus, we have to delete that key and insert it again right after the head.
This means that, the Least Recently Used (LRU) Cache will obviously be right before tail of the DLL. In case the put() function is called and the capacity of 
the cache is full, it is the key immediately before tail that has to be deleted.*/

class LRUCache {
public:
  class Node {
  public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
      key = _key;
      val = _val;
    }
  };

  Node* head = new Node(-1, -1);
  Node* tail = new Node(-1, -1);

  int capacity;
  unordered_map<int, Node*> cache;

  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }

  void addNode(Node* newNode) {
    Node* temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
  }

  void deleteNode(Node* delNode) {
    Node* prevNode = delNode->prev;
    Node* nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node* resNode = cache[key];
      int res = resNode->val;
      cache.erase(key);
      deleteNode(resNode);
      addNode(resNode);
      cache[key] = head->next;
      return res;
    }

    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      Node* existingNode = cache[key];
      cache.erase(key);
      deleteNode(existingNode);
    }
    if (cache.size() == capacity) {
      cache.erase(tail->prev->key);
      deleteNode(tail->prev);
    }

    addNode(new Node(key, value));
    cache[key] = head->next;
  }
};