class Solution {
public:
    int firstMissingPositive(vector<int>& n) {
        if(n.size()==0) return 1;
        int i=1;
        while(1)
        {
            if(count(n.begin(),n.end(),i)==0) return i;
            i++;
        }
        return 0;
    }
};
