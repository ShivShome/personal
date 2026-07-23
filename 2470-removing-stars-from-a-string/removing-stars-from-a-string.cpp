class Solution {
public:
    string removeStars(string s) {
        deque<char>st;
        for(char c:s){
            if(c!='*')st.push_back(c);
            else{
                st.pop_back();
            }
        }
        string ans="";
        while(!st.empty()){
            char temp=st.front();
            ans+=temp;
            st.pop_front();
        }
        return ans;
    }
};