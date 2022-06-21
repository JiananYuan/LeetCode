class Solution {
public:
    string defangIPaddr(string address) {
        int pos = -2;
        while ((pos = address.find('.', pos + 2)) != -1) {
            address.insert(pos + 1, "]");
            address.insert(pos, "[");
        }
        return address;
    }
};
