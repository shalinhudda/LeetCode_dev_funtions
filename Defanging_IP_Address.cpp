class Solution {
public:
    string defangIPaddr(string address) {
        return FindAndReplace(address);
    }
    string FindAndReplace(string address);
};

string Solution::FindAndReplace(string address) {
    std::size_t pos = 0;
    while(address.find(".", pos, 1) != -1){
        pos = address.find(".", pos, 1);
        address.replace(pos, 1, "[.]");
        pos = pos + 3;
    }
    return address;
}