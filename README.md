# 洛谷刷题记录 · LiangXi_LuoGu

C++ 算法与数据结构练习。按专题推进，**每 AC 一题一个 commit**。
配套自学课件：[elysia520520.github.io/study](https://elysia520520.github.io/study/)

---

## 环境

| 项 | 值 |
|---|---|
| 编译器 | MSYS2 UCRT64 `g++` 16.2.0 |
| 路径 | `D:\c++\MSYS2\ucrt64\bin\g++.exe` |
| 编译参数 | `-O2 -std=c++17 -Wall -Wextra` |
| 深搜/递归题 | 需要大栈：`-Wl,--stack,268435456`（Windows 上 `ulimit -s` 无效） |

```powershell
# 普通题
g++ -O2 -std=c++17 -Wall -Wextra P3366.cpp -o P3366.exe

# 深搜类（递归深度可能到 2 万层）
g++ -O2 -std=c++17 -Wl,--stack,268435456 P1605.cpp -o P1605.exe
```

> 在 VS Code 里按 `Ctrl+Shift+B` 可直接编译（任务定义在 `D:\c++\.vscode\tasks.json`，产物输出到 `D:\c++\output`）。
> `.exe` 不进仓库（见 `.gitignore`）。

---

## 目录说明

| 文件名 | 内容 |
|---|---|
| `P####.cpp` | 洛谷题号，与题目一一对应 |
| `P####_1.cpp` / `P####_2.cpp` | 同一题的两种写法（如 `P1160_1` 指针版 / `P1160_2` 数组版） |
| `1.cpp` ~ `11.cpp` | 早期无名练习（阶段一语法练习，保留作记录） |

---

## 进度

已收录 **55 个** `.cpp`，覆盖以下专题（按学习顺序）：

| 专题 | 题号 | 备注 |
|---|---|---|
| 高精度 | P1009（高精度阶乘）、P1303（高精度乘法）、P1591（阶乘数码） | ✅ |
| 排序与模拟 | P1177（快排×2）、P1908（逆序对 归并）、P1923（第 k 小）、P1059、P1093、P2676、P1068、P5740、P1781、P1042 | ✅ |
| 链表与队列 | P1160（指针版 + 数组版）、P1996（约瑟夫）、P1739（括号匹配） | ✅ |
| 堆与优先队列 | P3378（堆模板）、P1090（合并果子）、P1168（中位数） | ✅ |
| 递归与搜索 | P1157（组合）、P1706（全排列）、P1305（二叉树遍历）、P5734 | ✅ |
| 图与遍历 | P5318（DFS/BFS）、P1605（迷宫）、P1443（马的遍历） | ✅ |
| 拓扑排序 | P1113、P1347、P1807（最长路）、P4017（食物链计数） | ✅ |
| 并查集 | P3367（模板）、P1551（亲戚）、P3958（奶酪） | ✅ |
| 最短路 | P4779（堆优化 Dijkstra）、P3371（弱化版） | ✅ |
| 负环 | P3385（SPFA 判负环） | ✅ |
| 最小生成树 | P3366（Kruskal） | ✅ |
| 二分 | P2249（查找）、P1182（数列分段）、P2678（跳石头） | ⚠️ P2249 有 n=1 死递归、P1182 有 int 溢出，待修 |
| 前缀和 / 差分 / 单调栈 | P3131、P2367、P5788（下一个更大元素） | ✅ |
| 平衡树 | P5076（普通二叉树，重复值判据略糙） | ✅ |

> 完整清单与逐题状态见课件站的 [刷题清单](https://elysia520520.github.io/study/reference/problem-list.html)。

---

## 已知待改进

- `P2249.cpp`：`Find` 递归在 `l == r` 且查不到时无出口（n = 1 会死循环），建议改 `while (l < r)` 循环版
- `P1182.cpp`：`check()` 里 `int x` 累加会溢出（大数据 WA），应改 `long long`
- `P4779.cpp`、`P3371.cpp`：缺 `ios::sync_with_stdio(false); cin.tie(nullptr);` 两行快读
- `P3371.cpp`：一条 `-Wsign-compare` 警告

---

## 提交约定

```
feat(P3366): 最小生成树 Kruskal AC
fix(P1551): 合并时改成比较集合大小
docs: README 补编译说明
```

- 一题一提交，提交信息写清「哪题 + 做什么」
- 全在 `main` 分支上推进（单人项目不开分支）
- 已推送的提交不改历史，改了东西就再补一条

---

## 相关

- 自学课件站：https://elysia520520.github.io/study/
- 刷题清单：https://elysia520520.github.io/study/reference/problem-list.html
- 算法总结（速查）：https://elysia520520.github.io/study/reference/algorithms-summary.html
