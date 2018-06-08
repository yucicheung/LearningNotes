bug分支
如果在某个版本上发现某bug为issue101，那么就需要开启一个临时分支isuue101做临时分支，那目前你在dev上的工作还没有到可以提交的程度，那自然你应该先将目前的工作存储起来
    git  stash #存储工作现场，等日后恢复
    git stash list # 寻找存储好的工作现场
    # 两种回复现场方式
    git stash apply # 恢复后不删除 
    git stash apply stash@{0} # 更具体的恢复
    git stash drop # 手动删除
    git stash pop # 恢复同时删除
    # 再查看list就看不到内容了
    git stash list
    
多人合作/多地工作
每次clone后，在文件夹中的.git下记录的都是处于master分支，

$ git remote # 查看远程库信息
$ git remote -v # 显示详细信息，如果没有push权限就看不到push地址
$ git push origin master/dev # 推到不同分支上，将提交推到远程库

推送原则，如果是大家一起开发的分支以及主分支，则必须时刻保持和远程一致，如果是自己处理的bug分支等，可以不用推送。

抓取

$ git clone <address> # 抓取分支
$ git branch # 其中只显示主分支

# 那如果是要一起在dev分支上开发，就需要从远程分支创建到本地
git checkout -b dev origin/dev # 此时开发位置就切换到dev分支位置，修改都在此位置

如果几个人都在dev分支上进行开发，par先提交了相应的版本，那你的version就behind该分支的origin(remote)，因此需要先pull，此时如果有提示说要set tracking information用命令git branch --set-upstream-to dev origin/<branch>建立远程和本地的连接，再git pull到最新版本，解决冲突再push就可以。


标签管理

用标签来表示某一版本，或者说将标签作为某一版本的快照，每次取该标签的版本就是将该标签对应的历史版本取出来。（这个其实就可以对应的release版本）

标签创建和查看

简单来理解，标签就是指向某一版本的固定指针，类似于commit吧，但是不是用杂乱数字来表示一个版本，而是将一个有意义的名字和commit绑在一起。

    git branch
    git checkout master # 一般发布新版本在master上，因为这上面为稳定版，但是在dev分支上也可以进行发布
    git tag v1.0 # 在master当前位置（最新位置）进行打tag
    git tag # 显示所有打过的tag
    # 如果要对以前的版本打tag
    git log --pretty=oneline --abbrev-commit
    git tag v0.9 <commit_id>
    git tag # 再查看就可以看到所有tag按字母顺序列出
    git show <tagname> # 查看某一版tag的信息
    
    # 更详细的标签命令
    git tag -a <tagname> -m 'commit' <commit_ID> # 给commit_ID打上名为tagname的标签，并且加上注释
    
    # 用私钥前面一个标签，带`-s`
    git tag -s v0.2 -m 'comment' <commit_id> # 用PGP签名签名一个标签

标签的推送和删除

    git tag -d v0.1 #本地直接删除
    git push origin v1.0 # 一次推送一个tag
    git push origin --tags # 一次性全部推送
    # 删除远程标签
    git tag -d v0.9 #在本地删除
    git push origin :refs/tags/v0.9 # 从远程也删除标签


如果你要修改一个开源的项目，一定要先进行fork到自己的repo，再clone以后才能在本地修改然后push到远程被接受。如果希望开源项目可以接受自己的修改，就发起一个pull request尝试贡献代码。
自定义git
忽略特殊文件，某些文件是不需要上传的，可是每一次都会提示untracked，这时就要设置.gitignore文件，将需要忽略的文件的名字放进去。
忽略文件的原则是：
1. 忽略操作系统自动生成的文件，比如缩略图等；
2. 忽略编译生成的中间文件、可执行文件等，也就是如果一个文件是通过另一个文件自动生成的，那自动生成的文件就没必要放进版本库，比如Java编译产生的.class文件，还有python编译生成的.pyc文件等；
3. 忽略你自己的带有敏感信息的配置文件，比如存放口令的配置文件
把.gitignore文件也提交到Git上就可以，还要放到版本库里面！！！
如果要提交一个包含在.gitignore中的文件请用命令git add -f ex.class
还可以用git check-ignore -v <mistake_file>来检查ignore规则是否书写正确。

配置git

    git config --global alias.st status # global是对当前用户起作用
    git config alias.st status # 就是对当前文件夹有效
    # 一个文件夹下的最终的配置文件放在 .git/config文件中
    # 而一个用户的git配置文件放置在$HOME/.gitconfig中


