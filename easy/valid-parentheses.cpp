class Solution {
public:
    bool isPaired(char o, char c) {
        cout << o << " " << c << endl;
        if((o == '(' && c == ')') ||
           (o == '{' && c == '}') ||
           (o == '[' && c == ']')) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isValid(string s) {
        if(s.size() == 1)
            return false;

        vector<int> seq;

        for(int i = 0; i < s.size(); i++) {
            cout << "i=" << i << endl;
            if(s[i] == '(' ||
               s[i] == '{' ||
               s[i] == '[')
                seq.push_back(s[i]);
            else { // ) } ]
                if(seq.size() == 0)
                    return false;

                if(isPaired(seq.back(),s[i])) {
                    seq.pop_back();
                } else {
                    return false;
                }
            }
        }

        if(seq.size() != 0)
            return false;
        else
            return true;
    }
};
