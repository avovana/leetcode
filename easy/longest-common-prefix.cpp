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