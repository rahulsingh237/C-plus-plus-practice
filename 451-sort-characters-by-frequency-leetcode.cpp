class Solution {
public:
    string getString(char x) 
    { 
        string l(1, x); 
        return l;    
    } 
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++) m[s[i]]++;
        pair<int,char> p;
        vector<pair<int,char>> v;
        for(auto x:m)
        {
            p.first=x.second;
            p.second=x.first;
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        string r="";
        for(int i=v.size()-1;i>=0;i--)
        {
            for(int j=0;j<v[i].first;j++) r+=getString(v[i].second);
        }
        return r;
    }
};
