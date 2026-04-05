// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
//703. Kth Largest Element in a Stream
class KthLargest {
public:
    int K;
    vector<int>v;
    set<int>st;
    KthLargest(int k, vector<int>& nums) {
        v=nums;
        K=k;
        sort(v.begin(),v.end());
        for(int a:v)
        {
            st.insert(a);
        }
    }
    
    int add(int val) {
       
        int index=upper_bound(v.begin(),v.end(),val)-v.begin();
           v.insert(v.begin()+index,val);
           st.insert(val);
        return v[v.size()-K];

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */