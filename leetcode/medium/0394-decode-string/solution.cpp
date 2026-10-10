class Solution {
public:
    string decodeString(string s) {
        stack<string>mainstack;
        stack<int>numberst;
        
        
        for(int i=0; i<s.length(); i++) {
            char ch=s[i];
            if(ch>='0'  && ch<='9') {
                int ans=0;
                while(i<s.length() && s[i]>='0'  && s[i]<='9') {
                    ans=ans*10 + (s[i] - '0');
                    i++;

                }
                numberst.push(ans);
                i--;
            }
            else if(ch!=']'){
                mainstack.push(string(1,ch));

            }
            else{//closing
                string ans="";
                

                while(!mainstack.empty() && mainstack.top() != "["){
                    ans=mainstack.top() + ans;
                    mainstack.pop();
                }
                mainstack.pop();
                

                int number=numberst.top();
                numberst.pop();
                string repatedstring="";
                while(number>0) {
                    repatedstring=repatedstring + ans;
                    number--;
                }
                mainstack.push(repatedstring);

                
                
                
            }

        }

        string res="";
        while(!mainstack.empty()) {
            res= mainstack.top() + res;
            mainstack.pop();
        }
        return res;
        
    }
};