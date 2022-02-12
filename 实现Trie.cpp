class Node {
public:
    Node* ptr[26];
    bool terminal;  // 该节点是否可组成单词

    Node() {
        terminal = false;
        for (int i = 0; i < 26; i += 1) {
            ptr[i] = nullptr;
        }
    }
};

// 26叉树
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Node* search_prefix(string word) {
    //     int len = word.length();
    //     Node* p = root;
    //     for (int i = 0; i < len; i += 1) {
    //         int id = word[i] - 'a';
    //         if (p.ptr[id] == nullptr) {
    //             p.ptr[id] = new Node();
    //         }
    //         p = p.ptr[id];
    //     }
    // }
    
    void insert(string word) {
        int len = word.length();
        Node* p = root;
        for (int i = 0; i < len; i += 1) {
            int id = word[i] - 'a';
            if (p -> ptr[id] == nullptr) {
                p -> ptr[id] = new Node();
            }
            p = p -> ptr[id];
        }
        p -> terminal = true;
    }
    
    bool search(string word) {
        int len = word.length();
        Node* p = root;
        for (int i = 0; i < len; i += 1) {
            int id = word[i] - 'a';
            if (p -> ptr[id] == nullptr) {
                return false;
            }
            p = p -> ptr[id];
        }
        return p -> terminal;
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length();
        Node* p = root;
        for (int i = 0; i < len; i += 1) {
            int id = prefix[i] - 'a';
            if (p -> ptr[id] == nullptr) {
                return false;
            }
            p = p -> ptr[id];
        }
        return true;   
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
