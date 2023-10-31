class Solution {
public:
    bool isOperator(string st){
        if(st=="+" || st=="-" || st=="*" || st=="/")return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it:tokens){
            if(isOperator(it)){
                int a=st.top();st.pop();
                int b=st.top();st.pop();
                if(it=="+")st.push(a+b);
                else if(it=="-")st.push(b-a);
                else if(it=="*")st.push(a*b);
                else if(it=="/")st.push(b/a);
            }else{
               int num=stoi(it); 
                st.push(num);
            }
        }
        return st.top();
        
    }
};