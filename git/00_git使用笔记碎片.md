# git使用笔记碎片
- More tips on [gist](https://gist.github.com/yucicheung/cda2d4ed5aa70102c94644fdc1423010).
## 其他概念
- `Gist`：用于方便地和其他人分享一些短的代码片和短的笔记等;
- `Wiki`：用于添加一些与项目相关的文件和信息等(对于README已经写的很完善的情况，可能写一个wiki不是很有必要)，有一个特性是，可以使所有人都获得其编写权限。
上述描述的每一个概念，都是一个单独的git仓库，即可以进行clone,fork，版本回退等操作。

- `Release`和`tag`
  - `tag`准确的就仅仅是打标签而已，对于某个特定版本的仓库快照打上标记;
  - `Release`功能是对一个特定版本打上标签，并且添加更多详尽的说明,如'Release Notes'等。

- `git reflog`和`git log`
  - `git reflog`记录从你clone到本地以后，你在本地的所有HEAD变化操作;
  - `git log`记录该仓库从创建开始到现在的所有commit记录。
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
$ git pull origin master # 将远程的对应分支的代码拉取到本地并与本地代码合并，相当于先做git fetch再做git merge.
```


- 查看远程分支
  - `git remote -v`
- 查看远程分支和本地分支的关联关系。

- 切换远程分支`git checkout origin`

## 仓库的tag管理
- `git tag`查看所有tag
- `git tag -m ''`打标签同时增加注释。 
