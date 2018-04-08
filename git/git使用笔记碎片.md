# git使用笔记碎片
## 其他概念
Gist用于管理和发布一些没必要保存在仓库中的代码。
## TaskList语法
- [ ]
- [x]
## 撤销本地修改
- 使用如下命令替换掉本地改动：
git checkout -- <filename>
此命令会使用 HEAD 中的最新内容替换掉你的工作目录中的文件。已添加到缓存区的改动，以及新文件，都不受影响。

- 假如你想要丢弃你所有的本地改动与提交
可以到服务器上获取最新的版本并将你本地主分支指向到它：
git fetch origin
git reset --hard origin/master

## 分支新建和管理
### 新建分支
```bash
$ git checkout -b dev
$ git branch #可见所在分支
```

```bash
$ git push origin dev
```
### 查看新分支
```bash
$ git branch -r # 查看远程repo
$ git checkout origin/hexo
```
git reset之间区别：http://www.cnblogs.com/kidsitcn/p/4513297.html
### 新分支合并到主分支
对远程新分支，合并到主分支master
```
$ git checkout master
$ git merge --no-ff dev
$ git log --graph
```

## 提交和记录管理
### 一次性提交
`git add .`和`git commit -m message`
```bash
$ git commit -am message
```

### 修改
修改上一条提交信息。
```bash
$ git commit --ammend
```
### 压缩
将当前HEAD位置在内的四条提交合并为一条。
```bash
$ git rebase -i HEAD~4 #用squash再修改commit message
$ git push --force origin master
```
## 保存现场
```bash
$ git stash
$ git stash list
$ git stash apply
或
$ git stash apply stash@{0}
```
## 与远程同步
```bash
$ git remote #查看远程仓库
$ git fetch origin master #从远程获取最新代码到本地
$ git log -p master origin/master #比较本地和远程的差别
$ git merge origin/master # 将下载好的远程代码与本地仓库合并
```
