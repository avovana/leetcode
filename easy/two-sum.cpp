// Runtime: 32 ms, faster than 39.38% of C++ online submissions for Two Sum.
// Memory Usage: 10.1 MB, less than 93.11% of C++ online submissions for Two Sum.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum;
        for(int r = nums.size() - 1; 0 < r; --r) {
            // if(nums[r] > target)
            //     continue;
            
            for(int l = 0; l < r; ++l) {
                // if(nums[l] > target)
                //     continue;
                
                //cout << "l = " << l << " r = " << r << endl;
                //cout << "nums[l] = " << nums[l] << " nums[r] = " << nums[r] << endl;
                sum = nums[l] + nums[r];
                //cout << "sum = " << sum << endl;
                if(sum > target)
                    continue;
                else if(sum == target) {
                    return {l,r};
                }
            }
        }
        
        return {0,0};
    };
};

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort whole array ---------------- (!) idx changing
        // find  idx of value < targert
        // start checking sum from that value and minimum. iterate from minimum to that value. If exceded take prev_value
        // check again
        
        vector<int> res;
        
        sort(begin(nums), end(nums));
        //cout << "sorted" << endl;
        auto target_it = upper_bound(begin(nums), end(nums), target);
        target_it--;
        cout << "target_it= " << *target_it << endl;
        for(auto i : nums) {
            cout << i << " ";
        }

        for(; begin(nums) < target_it; --target_it) {
            for(auto lowest = begin(nums); lowest != target_it; lowest++) {
                auto sum = *lowest + *target_it;
                cout << "sum=" << sum;

                if(sum == target) {
                    res.push_back(distance(begin(nums), lowest));
                    res.push_back(distance(begin(nums), target_it));
                    
                    return res;
                } else if (sum > target) {
                    break;
                }
            }
        }
        
        return res;
    }
};
*/
