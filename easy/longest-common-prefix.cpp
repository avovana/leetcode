// Idea is to traverse all strings many times checking next symbol_number
// How to improve =  check every half
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto str = strs[0];
        
        if(str.size() == 0)
            return "";
        
        if (strs.size() == 1)
            return str;
        
        for(int symbol_number = 0; symbol_number < str.size(); ++symbol_number) {
            cout << "symbol_number: " << symbol_number << endl;
            for(int str_number = 1; str_number < strs.size(); ++str_number) {
                cout << "str_number: " << str_number << endl;
                if (str.size() <= symbol_number)
                    return str.substr(0, symbol_number);

                auto cur_str = strs[str_number];

                if (cur_str.size() <= symbol_number)
                    return str.substr(0, symbol_number);

                if (str[symbol_number] != cur_str[symbol_number])
                    return str.substr(0, symbol_number);

            }
        }
        
        return str;
    }
};

// Looked solutions. Saw compact code. Thought a little bit after it. The idea came up.
// I should check every symbols while I'm working with current string. And find how many symbols are mached.
// Save this counter. And compare with some big value var. If at this time counter less than that var, update it.
// At the end I have the lowest counter.
// So I discarded outer loop thanks to this idea. And became much faster.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto str = strs[0];
        
        if(str.size() == 0)
            return "";
        
        if (strs.size() == 1)
            return str;
        
        int min_idx_comm_prefix = str.size();
        
        for(int str_number = 1; str_number < strs.size(); ++str_number) {
            auto cur_str = strs[str_number];
            int symbol_number = 0;
            
            while(
                  symbol_number < str.size() &&
                  symbol_number < cur_str.size() &&
                  str[symbol_number] == cur_str[symbol_number])
            {
                ++symbol_number;
            }
            
            if (symbol_number < min_idx_comm_prefix) {
                min_idx_comm_prefix = symbol_number;
            }
        }
        
        return str.substr(0, min_idx_comm_prefix );
    }
};
