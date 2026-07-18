class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int normal=0,n=grumpy.size();
    
        for(int i=0;i<n;i++){
            // FIX: normal customers are those with grumpy == 0
            normal+=(1-grumpy[i])*customers[i];
        }

        int curr=0,maxi=0,idx=0;

        for(int i=0;i<minutes;i++){
            // FIX: count only extra customers that can be satisfied
            curr+=grumpy[i]*customers[i];
        }

        maxi=curr;

        for(int i=minutes;i<n;i++){
            // FIX: slide over grumpy customers only
            curr=curr+grumpy[i]*customers[i]
                     -grumpy[i-minutes]*customers[i-minutes];

            if(curr>maxi){
                maxi=curr;
                idx=i-minutes;
            }
        }

        // FIX: delete this entire loop.
        // 'maxi' already represents the maximum extra satisfied customers.
        // No need to modify normal using idx.
        /*
        for(int i=idx;i<minutes;i++){
            normal-=grumpy[i]*customers[i];
        }
        */

        return normal+maxi;
    }
};