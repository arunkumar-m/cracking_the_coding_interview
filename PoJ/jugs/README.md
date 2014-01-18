# Jugs

[http://poj.org/problem?id=1606](http://poj.org/problem?id=1606)

## Solution

BFS + 状态记忆

用BFS对所有状态进行遍历。（状态是一个节点！最开始我想成每种操作是一个节点没救了。。)

```c++
struct State {
    int ca, cb;
    int action;
    State *prev;
    State() { prev = NULL; }
    State(int x, int y, int z) : ca(x), cb(y), action(z), prev(NULL) {}
} states[MAX][MAX];
```

用上面这样一个结构体记录到达过的状态。```states[i][j]```表示水箱A水量为i，B水量为j的情况。prev指针记录到达这条状态的上一条状态是哪个（方便输出）。

```c++
void output(State s) {
    if (s.prev == NULL) {
        return;
    }
    output(*s.prev);
    cout << operation[s.action] << endl;
}
```

递归打印避免使用栈。
