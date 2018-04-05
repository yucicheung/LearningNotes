主要记录个人代码版本管理操作。
# 最基础概念
本地文件夹(写代码的地方)是git的工作区，.git叫版本库，其中叫stage的是暂存区，远程仓库，git管理并跟踪的是修改。
## fork，star和watch的作用
**fork：**是指你想向该仓库贡献代码，才fork到自己repo，再clone到本地之后修改。
**watch：**是随时观察到该repo的所有动态，包括issue等。
**star：**是收藏某个repo。
## github基础配置
- 配置全局信息
```bash
$ git config --global user.name yucicheung
$ git config --global user.email 'yucicheung@gmail.com'
```
- 初始化工作区
```bash
$ git init
```
## 基础操作
- 提交
```bash
$ git add .
$ git commit -m "first commit"
$ git push origin master
```
`clone`是在主目录下用的，clone是从无到有。
`pull`是在工作区里用的，从旧到新。

- 查看修改
```bash
$ git status #查看工作区状态
$ git diff #如果status告诉你文件修改过，用此命令查看差别
```
## 暂存区版本回退
```bash
$ git log #到当前head为止的提交
$ git reset --hard HEAD^ # HEAD^表示版本号，--hard表示版本回退且head指针一起回退
$ git reflog #记录你的所有提交
```
## 工作区撤销修改
```bash
$ git rm #首先手动删除后，再用git删除
$ git checkout  --file #撤销file在工作区的修改
$ git reset HEAD file # 按当前HEAD恢复，是把暂存区的修改撤销掉，重新放回工作区。（所以git reset既可以撤销暂存区的修改，也可以回退版本）
```
如果工作区的版本落后于版本库的版本，`push`时要加上`--force`选项。

## 分支
因为需要一直保持`master`主分支是稳定可用，只用于发布新版本，那么在开发时就不能在该分支上修改，而应该新建分支。
所以除主分支以外的分支都是不稳定，大家各自有自己的分支，修改后往dev分支上合并，最后往master分支上合并。

所谓的分支管理我们可以理解为，在保证其他人可以在master下载到正常工作的文件时，我们也可以在分支上进行版本管理。
1. HEAD指向当前分支
2. master指向当前可正常工作版本的最新版本（每次clone或者download的zip文件都是master分支，即主分支）
3. 新分支指针（创建一个新分支，就是新建一个指针，每次提交就将新分支的指针不断往前移，但是master暂时保持不动）
4. 一直到你的分支可以确认正常工作以后，我们再进行master和分支的合并。
###新建分支
```bash
$ git checkout -b dev # 新建dev分支并切换到
# 相当于下面两条命令
$ git branch dev # 创建
$ git checkout dev # 切换
```
用`$ git branch`可查看所有分支及当前所在分支。 
### 分支合并
```bash
$ git checkout master# 切换到master
$ git merge dev # 将指定分支的内容融合到master上，即改变master的指针位置
$ git branch -d dev # 合并后可删除dev分支
```
### 合并冲突
如果只有一条时间线，就可以执行“快速合并”操作，直接改变指针的位置即可。
但时如果创建出不同的时间线，多人对同一文件都进行了修改，就可能产生合并冲突，需手动处理。
`$ git status`会告诉我们冲突文件在哪里。
**分支合并模式:**
- **Fast forward**模式:在合并分支时会丢掉分支信息，也就是都看不见哪一次是分支上merge出来的。禁用Fast forward模式命令为`git merge --no-ff -m "merge with no-ff" dev`。此时可以用`git log`查询到merge历史，否则看不到merge历史。`$ git log --graph`命令可以看到分支合并图。
