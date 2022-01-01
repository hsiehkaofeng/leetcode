class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        int i1 = 0, i2 = 0;
        int total_size = nums1.size() + nums2.size();
        while(i1 < nums1.size() || i2 < nums2.size()) {
            
            if (i2 < nums2.size() && (i1 == nums1.size() || nums2[i2] < nums1[i1])) {
                res += nums2[i2];
                i2 ++;
            } else {
                res += nums1[i1];
                i1 ++;
            }
            
            // check median
            if (total_size % 2 == 1) {
                // odd
                if (i1 + i2 == ((total_size + 1) / 2 )) {
                    return res;
                }
                res = 0;
            } else {
                //even
                if (i1 + i2 == (total_size / 2 )) {
                    // keep res, first pass
                } else if (i1 + i2 == (total_size / 2 ) + 1) {
                    // second pass
                    return res / 2;
                } else {
                    res = 0;
                }
            }
        }
        return res;
    }
};