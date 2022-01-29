#include <bits/stdc++.h>
using namespace std;

// 定义双向链表节点
class Node {
public:
    int key;
    int data;
    Node* pre;
    Node* post;

    Node(int _key = 0, int _data = 0, Node* _pre = nullptr, Node* _post = nullptr): key(_key), data(_data), pre(_pre), post(_post) {}
};

// 定义双向链表
class DoubleList {
private:
    Node* head;
    Node* tail;

public:
    DoubleList() {
        head = tail = nullptr;
    }

    // 头插法
    Node* insert_front(int key, int data) {
        if (head == nullptr) {
            head = new Node(key, data);
            tail = head;
        }
        else {
            Node* np = new Node(key, data);
            np -> post = head;
            head -> pre = np;
            head = np;
        }
        return head;
    }

    // 删除节点
    int delete_node(Node* np) {
        Node* pre = np -> pre;
        Node* post = np -> post;
        if (pre) {
            pre -> post = post;
        }
        if (post) {
            post -> pre = pre;
        }
        if (np == tail) {
            tail = pre;
        }
        if (np == head) {
            head = post;
        }
        int key = np -> key;
        delete np;
        np = pre = post = nullptr;
        return key;
    }

    // 删除尾部节点
    int delete_tail() {
        if (tail) {
            return delete_node(tail);
        }
        return -1;
    }

    void debug() {
        if (head) {
            Node* p = head;
            while (p) {
                cout << p -> data << " ";
                p = p -> post;
            }
            cout << endl;
            cout << "head is " << head -> data << endl;
            cout << "tail is " << tail -> data << endl;
        }
        cout << "============" << endl;
        return;
    }

};

class LRUCache {
private:
    int cap;
    int size;
    DoubleList cache;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity): cap(capacity), size(0) {
        mp.clear();
    }

    int get(int key) {
        int val;
        // cout << "get " << key << " count: " << mp.count(key) <<endl;
        if (mp.count(key) == 0) {
            val = -1;
        }
        else {
            Node* np = mp[key];
            val = np -> data;
            cache.delete_node(np);
            // cout << "before crash...." << endl;
            np = cache.insert_front(key, val);
            mp[key] = np;
        }
        return val;
    }

    void put(int key, int value) {
        if (mp.count(key) == 0) {
            if (size == cap) {
                int key = cache.delete_tail();
                mp.erase(key);
            }
            size = min(size + 1, cap);
            Node* np = cache.insert_front(key, value);
            mp[key] = np;
        }
        else {
            Node* np = mp[key];
            cache.delete_node(np);
            np = cache.insert_front(key, value);
            mp[key] = np;
        }
        return;
    }

    void debug() {
        cache.debug();
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    LRUCache cache(n);
    string op;
    while (cin >> op) {
        cout << op << " ";
        if (op == "put") {
            int k, v;
            cin >> k >> v;
            cout << k << " " << v << endl;
            cache.put(k, v);
            cache.debug();
        }
        else if (op == "get") {
            int k;
            cin >> k;
            cout << k << endl;
            cout << cache.get(k) << endl;
            cache.debug();
        }
    }
    return 0;
}
