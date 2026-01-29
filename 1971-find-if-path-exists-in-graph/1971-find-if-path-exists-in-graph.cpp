class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        stack<int> st;

        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            if (top == end)
                return true;

            for (int node : graph[top]) {
                if (!visited[node]) {
                    visited[node] = true;
                    st.push(node);
                }
            }
        }
        return false;
    }
};