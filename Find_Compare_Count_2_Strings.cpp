class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int length = J.length();
        int LengthIndex = 0;
        int Count = 0;
        
        while(LengthIndex < length){
            Count = FindMember(S, (J.substr(LengthIndex, 1)).c_str()) + Count;
            LengthIndex++;
        }
        
        return Count;
        
    }
    int FindMember(string address, const char* ToFind);
};

int Solution::FindMember(string address, const char* ToFind) {
    std::size_t pos = 0;
    int index = 0;
    while(address.find(ToFind, pos, 1) != -1){
        pos = address.find(ToFind, pos, 1);
        pos = pos + 1;
        index++;
    }
    return index;
}
