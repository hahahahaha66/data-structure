### 回溯算法
回溯算法（backtracking algorithm）是一种通过穷举来解决问题的办法，他的核心思想是从一个初始状态出发，暴力搜索所有的可能的解决方案，当遇到正确的解则将其记录，直到找到解或尝试了所有的可能的选择都无法找到解为止
之所以称为回溯算法，是因为该算法在搜索解空间时会采用尝试与回退的策略，当算法在搜索过程中遇到某个状态无法继续前进或无法得到满足条件的解时，他会撤销上一步的选择，退回到之前的状态，并尝试其他可能的选择

    /* 回溯算法框架 */
    void backtrack(State *state, vector<Choice *> &choices, vector<State *> &res) {
        // 判断是否为解
        if (isSolution(state)) {
            // 记录解
            recordSolution(state, res);
            // 不再继续搜索
            return;
        }
        // 遍历所有选择
        for (Choice choice : choices) {
            // 剪枝：判断选择是否合法
            if (isValid(state, choice)) {
                // 尝试：做出选择，更新状态
                makeChoice(state, choice);
                backtrack(state, choices, res);
                // 回退：撤销选择，恢复到之前的状态
                undoChoice(state, choice);
            }   
        }
        return ;
    }

##### 常用术语
+ 解  满足问题的特定条件的答案，可能有一个或多个
+ 约束条件  问题中限制解的可行性的条件，通常用于剪枝
+ 状态  表示问题在某一时刻的情况，包括已做出的的选择
+ 尝试  根据可用选择来探索解空间的过程，包括做出选择，更新状态，检查是否为解
+ 回退  指遇到不满足约束条件的状态时，撤销前面做出的选择，回到上一个状态
+ 减枝  根据问题特性和约束条件避免无意义的搜索路径的方法，可以提高搜索效率
