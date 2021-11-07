// Linked special prev symbol to current
// If prev and current match to special pair count it specially
// If not current means just current

class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> romans {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        auto size = s.size();
        vector<vector<char>> specialSymbols {
            {'I', 'V', 'X'}, 
            {'X', 'L', 'C'}, 
            {'C', 'D', 'M'} 
        };
        
        char prev_symbol = '\0';
        int res = 0;
        
        for(int i = 0; i < size; ++i) {
            auto symbol = s[i];
            int value = 0;
            
            bool found = false;
            for(int l = 0; l < 3; ++l) {
                if(prev_symbol == specialSymbols[l][0]) {
                    for(int p = 1; p < 3; ++p) {
                        if(symbol == specialSymbols[l][p]) {
                            value = romans[symbol] - romans[prev_symbol] - romans[prev_symbol];
                            found = true;
                        }
                    }
                }
            }
            
            if(not found)
                value = romans[symbol];
            
            res += value;
           
            prev_symbol = symbol;
        }
        
        return res;
    }
};