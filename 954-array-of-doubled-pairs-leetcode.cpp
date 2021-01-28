class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        map<int,int> m;
        for(int x:a) m[x]++;
        for(auto i:m)
        {
            int x=i.first;
            if(m[x])
            {
                if(x<0){
                    if(x&1) return false;
                    if(m[x/2]<m[x]) return false;
                    m[x/2]-=m[x];
                }
                else{
                    if(m[2*x]<m[x]) return false;
                    m[2*x]-=m[x];
                }
            }
        }
        return true;
    }
};
