class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) {
            return true;
        }
        int count=0;
        int j=0;
        int k=0;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i]!=s2[i]) {
                count++;


                if(count>2){
                  return false;
                }
              else if(count==1){
                 j=i; 
                }

              else{
                 k=i;
               }


            }
        
            
        }
        return (s1[j]==s2[k] && s2[j]==s1[k]);
    }
};