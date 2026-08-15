class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gsize=g.size();
        int ssize=s.size();
        int i=0,j=0;

        int count=0;

        while(i<gsize && j<ssize){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};