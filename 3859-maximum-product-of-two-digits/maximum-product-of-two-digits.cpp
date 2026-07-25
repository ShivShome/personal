class Solution {
public:
    int maxProduct(int n) {
        int larg=0,slarg=0;
        while(n){
            int temp=n%10;
            if(larg<temp){
                slarg=larg;
                larg=temp; 
            }
            else
                slarg=max(slarg,temp);
            
            n/=10;
        }
        return larg*slarg;
    }
};