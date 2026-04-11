class Solution {
public:
    int solve(string op,stack<int> &st){

        int second = st.top();
        st.pop();

        int first = st.top();
        st.pop();

        if(op == "+"){
            return (first + second);
        }
        else if(op == "-"){
            return (first - second);
        }
        else if(op == "*"){
            return (first * second);
        }
        
        return (first / second);
        
    }
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int> st;

        for(int i = 0; i < n; i++){

            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){

                int res = solve(tokens[i],st);

                st.push(res);
            }
            else{

                int temp = stoi(tokens[i]);
                st.push(temp);
            }
        }

        return st.top();
    }
};
