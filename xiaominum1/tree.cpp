class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        // n,表示节点个数
        int n = matrix.size();
        // ge,用于存储与每个节点存在链接关系的节点的index，由于每个节点可以都
        // 多个子节点（多叉树），所以用vector<vector<int> >的结构
        // 存储
        vector<vector<int> > ge(n);
        // dep,用于存储n个节点的深度,初始化为-1
        vector<int> dep(n, -1);
        // fa,用于存储n个节点对应的父节点的index，初始化为-1，
        // 由于每个节点只有一个父节点，所以用vector<int>的形式表示
        vector<int> fa(n, -1);
        //初始化邻接矩阵
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    ge[i].push_back(j);
                    ge[j].push_back(i);
                }
            }
        }
        // 用于广度遍历此多叉树,这里是类似栈的结构
        vector<int> stk;
        // 存入根节点
        stk.push_back(0);
        // 根节点的深度置为0
        dep[0] = 0;
        // 类似广度遍历此多叉树
        while (not stk.empty()) {
            // 取栈顶元素
            int u = stk.back();
            // 删除栈顶元素
            stk.pop_back();
            // 遍历所有与u相邻的点
            for (int k = 0; k < ge[u].size(); k++) {
                int v = ge[u][k];
                // 表示v已经访问过了
                if (fa[v] != -1) {
                    continue;
                }
                // v的父节点是u
                fa[v] = u;
                // v的深度为其父节点深度+1
                dep[v] = dep[u] + 1;
                // 将v入栈
                stk.push_back(v);
            }
        }
        // 寻找a和b的最近分割点
        int a = indexA, b = indexB;
        // 将a和b回溯到相同高度
        while(dep[a] > dep[b]) {
            a = fa[a];
        }
        while(dep[a] < dep[b]) {
            b = fa[b];
        }
        // 寻找最近分割点
        while(a != b) {
            a = fa[a];
            b = fa[b];
        }
        return a;
    }
};