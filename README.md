# 写在最初

原计划是把所有的学习记录放在Note仓库中，但实际执行发现仅仅两天就已经很长了，不方便阅读。所以专门开一个仓库用于记录代码学习

这是关于数据结构的学习

# 链表

完成了链表的初始化和遍历，实现的功能大概如下

![image-20250122223733492](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222237761.png)

![image-20250122222659450](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222226621.png)

![image-20250122222540705](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222225950.png)

其实链表的实现并没有花我很多的时间，一些坑点我都写在注释里了，我本来想在readme中细细描述，但现在我有一个更想说的东西：

==和Git不得不说的故事（已红温）==

------

  我在去年暑假的时候就初步接触过git，当时用的是Gitbash直接敲命令行上传代码到gitee，过程非常简单，只需要把廖雪峰老师给的命令复制粘贴，就能轻松提交（当然最开始我没看懂git到底在干嘛，还是我哥给我演示了一遍，主打一个依葫芦画瓢）

  但是今年，我学会了 ~~魔法~~ 科学上网，所以决定用某hub存代码，其实操作大差不差，但是我这次非常作死地没用gitbash，而是改用vs2022的Git功能，然后噩梦开始了：

  我非常顺利地初始化了本地的仓库，然后点击推送的时候意外却发生了：vs显示未能推送到远程仓库，请检查输出，但我的输出最开始是这样的：![image-20250122224007048](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222240084.png)

根本啥也没有啊？

于是我觉得是我初始化本地仓库的问题，我以为是我本地文件的位置有问题（因为vs会自动生成code，debug，x64等等一堆文件），于是我文件位置换了又换，但是毫无作用，差点把vs玩坏了（因为疯狂点推送，拉取，然后变得我也看不懂了）。后面发生，原来![image-20250122224303983](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222243009.png)这个调试是可以展开的，我终于发现了fail的原因
==fatal: unable to access ‘https://github.com/.../.git‘: Failed to connect to github.com port 443 after 21035 ms: Could not connect to server==

  但是咱也不知道到底发生了什么，于是又去搜索，然后发现：原来不是本地仓库的原因，而是因为我挂了梯子？？好吧，然后按照教程换了代理端口![image-20250122224707831](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222247077.png)

总算是提交成功了，皆大欢喜是不是？然后又冒出了新的问题：我的代码没有交到main，而是交到了一个莫名奇妙出现的新分支master。本来也可以不管的，但是一想到如果要看代码的话，还要切换分支，那多不方便？于是强迫症又犯了，开始找怎么合并分支，于是新的噩梦开始了：

我在vs里面点击合并分支，结果给我弹出来一个这个：

==refusing to merge unrelated histories==

搜了一下，说是在命令行加上--allow-unrelated-histories就可以了，但问题是：我用的是vs啊，哪来的命令行？我是直接在C盘git pull origin master --allow-unrelated-histories还是cd到我的放代码的文件里去？总之试了一下，然后给我弹出来了这个![image-20250122225215065](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222252115.png)

？合着我还要给你explain一下我为啥要干这个？怎么explain咱也不知道，最后我想出了一个绝妙的点子：

直接在vs里再推送一次代码，把远程仓库的master改成main，这样就能交到main里，再把github里的master分支删掉，是不是很聪明？

交代码过程非常顺利，但是删分支就不一样了，网上说能直接在github里点击删除，但我找了很久都没找到他们说的删除选项，于是最后又回归到了万能的命令行：![image-20250122225741794](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222257973.png)

从图里可以看出本人所经历的坎坷。

![image-20250122230035017](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222300146.png)

==真是磕磕又绊绊，如履薄冰==

总结：~~能用命令行就用命令行，vs是什么勾石，感觉不如vs code一根~~

vs是一款我的问题

