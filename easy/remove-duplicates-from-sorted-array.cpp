// Idea is to have 2 indexes. First points to first dublicate that was found(slow movement)
// Second to next value that is new/non-dublicate(fast movement)

//    idx  idx2
//[0,  0,  1,  1,  1,  2,  2,  3,  3,  4]
//         idx        idx2
//[0,  1,  1,  1,  1,  2,  2,  3,  3,  4]

//There is special case:
//[1,  2]
//or
//[1,  2,  2]
// else if() for it

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // idx to place for insert next non dublicate
        // idx2 to find this non dublicate
        if(nums.size() == 0)
            return 0;

        if(nums.size() == 1)
            return 1;

        int prev = nums[0];
        int to_insert = 0;
        bool first_dublicate = true;
        for(int i = 1; i < nums.size(); ++i) {
            if(prev == nums[i]) {
                if(first_dublicate) {
                    to_insert = i;
                    first_dublicate = false;
                }
            } else if(first_dublicate) {
                prev = nums[i];
                to_insert = i + 1;
            } else {
                int first_non_dublicate = nums[i];
                nums[to_insert] = first_non_dublicate;
                to_insert++;
                prev = first_non_dublicate;
            }
        }

        return to_insert;
    }
};
