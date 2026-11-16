# Git 工作流 · 这个仓库怎么用

> 这份文档就是阶段⑥「工程工具链」第 1–3 项的落地说明。
> 目标只有一个：**让提交历史自己会说话** —— 半年后回来看，能一眼看出「哪天学了什么、哪道题卡了多久、哪次改动是修 Bug」。

---

## 一、每道题一个 commit（已经养成，继续保持）

一次提交只做一件事：

```bash
git add P3374.cpp
git commit -m "P3374 树状数组：单点加 + 区间和"
```

提交信息用「**题号 + 主题：这一题的关键点**」三件套：

| 写法 | 评价 |
|---|---|
| `P3374 树状数组：单点加 + 区间和` | ✅ 半年后还看得懂 |
| `更新` / `emm` / `改一下` | ❌ 等于没写 |
| `P3374 过了，用树状数组，lowbit 那个地方卡了半小时` | ✅ 更好：把卡点也写进去 |

一条命令看自己最近都在干什么：

```bash
git log --oneline -20
git log --stat -3        # 连改了哪些文件一起看
git show 5d3701a         # 看某一次改动的完整 diff
```

---

## 二、分支：给「还没想好」的改动开个副本

主线永远保持「能编译、能交题」的状态；拿不准的改动先开分支：

```bash
git switch -c docs/git-workflow      # 新建并切过去（= checkout -b）
# …改文件…
git add docs/git-workflow.md
git commit -m "docs: 补 Git 工作流说明"
git push -u origin docs/git-workflow # 第一次推要 -u，之后直接 git push
```

分支名约定（前缀一眼看出类型）：

| 前缀 | 用途 | 例子 |
|---|---|---|
| `feat/` | 新功能、新题解 | `feat/P3385-spfa-negative-cycle` |
| `fix/` | 修 Bug | `fix/P2249-n1-recursion` |
| `docs/` | 只改文档 | `docs/git-workflow` |
| `exp/` | 试验，随时可弃 | `exp/seg-tree-iterative` |

切回主线、删掉分支：

```bash
git switch main
git branch -d docs/git-workflow        # 本地已合并的分支
git push origin --delete docs/git-workflow
```

**合并**（两种都行，看情况）：

```bash
git merge --no-ff docs/git-workflow    # 保留分支结构，历史上看得出「这里做过一条分支」
git merge --squash docs/git-workflow   # 把分支压成一个提交，主线干净
```

冲突了怎么办（同一行两人改）：

```bash
git status                  # 看哪些文件冲突（both modified）
# 打开文件，找到 <<<<<<< ======= >>>>>>> 三段，手动改成想要的样子，删掉标记
git add 冲突文件
git merge --continue
```

---

## 三、远程：GitHub 上的那一份才是「备份 + 证据」

```bash
git remote -v                       # 看远程地址
git fetch origin                    # 只下载不合并
git pull --rebase origin main       # 拉下来，把自己的提交接到后面
git push                            # 推上去
```

三条铁律：

1. **推之前先 `git status`**：确认没有意外的未跟踪文件（尤其是 `.exe`、测试数据、密码）。
2. **`push` 被拒**（non-fast-forward）：说明远程有你本地没有的提交 → 先 `git pull --rebase`，再 push。
3. **别 `git push -f` 主线**：会覆盖别人的提交。只有自己独占的分支可以强推。

回滚三板斧：

```bash
git restore P3374.cpp              # 丢掉工作区未提交的改动（危险，不可恢复）
git reset --soft HEAD~1            # 撤销最近一次提交，改动留在暂存区
git revert <commit>                # 已经推上去的提交：造一个「反向提交」来抵消它
```

---

## 四、GitHub 协作：Issue 记「要做什么」，PR 记「做了什么」

**Issue（任务单）**：发现一个待修点就开一张，标题写现象，正文写复现方式与期望。

> 例：`P2249 在 n=1 时死递归` —— 正文写「输入 `1 1 / 5 / 1` 会栈溢出」「期望输出 `1`」「猜测是 `mid` 没有前进」。

**PR（合并请求）**：把一条分支「申请合并进 main」，正文写清楚三件事：

1. 这个 PR 解决什么（`Closes #3` 自动关联 Issue）
2. 怎么验证的（编译参数、对拍组数、样例输出）
3. 有没有副作用

合并方式：

| 方式 | 适合 | 效果 |
|---|---|---|
| Merge commit | 一条完整的功能分支 | 保留分支形状，历史最真实 |
| Squash | 一堆「改一下」的碎提交 | 压成一个干净提交 |
| Rebase | 自己独占的小分支 | 线性历史，无合并节点 |

**看懂别人的仓库**（面试里真会问）：按这个顺序读

1. `README.md` —— 这是什么、怎么跑
2. 目录结构 —— `src/` `include/` `tests/` `docs/` 各放什么
3. `Makefile` / `CMakeLists.txt` —— 怎么构建、依赖什么
4. `CONTRIBUTING.md` + `.github/ISSUE_TEMPLATE/` —— 这个项目希望你按什么规矩提东西
5. `git log --oneline -20` —— 最近在忙什么、提交信息风格
6. `git shortlog -sn` —— 谁在维护

---

## 五、这个仓库现在的状态

```
LiangXi_LuoGu/
├── P####.cpp          题解（题号命名，一题一文件；多解用 _1 _2 后缀）
├── README.md          题单与环境说明
├── docs/              文档（本文件、题单索引）
├── .github/           Issue / PR 模板
└── .gitignore         排除 *.exe（编译产物不进仓库）
```

- 远程：`https://github.com/wangxi223/LiangXi_LuoGu`
- 分支：`main`（主线，随时可编译）
- 提交粒度：一题一提交；文档/配置单独提交
