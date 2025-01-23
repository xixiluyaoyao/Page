# 第一次扩展（链表）

增加了插入功能以及清空链表功能。

关于链表的清空功能：之前的代码没有free部分，一直malloc但是不free的话可能导致内存泄漏什么的。还好写的项目不算大，不然可能真把电脑搞坏了hhh。

值得一提的是，在调试的过程中，偶然在直接输入-1时编译器直接标红警告了，原因是Clear这个部分![571483936d750f984bea8b102bd4ca20](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501230207464.png)

**如果`pointnode本身就是NULL的话（比如你scanf的时候直接输入-1就会这样，链表只有一个头节点）这个时候pointnode->next相当于在访问空指针，会出bug，程序会崩溃。`**

所以要在循环的时候加个条件，这样就ok：`while (pointnode！=NULL && pointnode->next != NULL)`![image-20250123021754029](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230221721.png)



还有一个地方想说的是，之前的注释有过这样一段话：![image-20250123022510181](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230225309.png)

现在知道为什么了。能找到原因是因为写扩展的时候是从GitHub的仓库里直接Clone原代码到vs里的，然后在运行的时候发现终端的输出结果中，关于中文的部分是一片乱码，大概是这个样子：![image-20250123022757480](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230227509.png)

后面一搜发现是GitHub用的是UTF-8编码，但vs默认的编码不是，![image-20250123023052124](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230230183.png)

![image-20250123023131468](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230231552.png)

![image-20250123023153075](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230231314.png)

![image-20250123023207553](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230232622.png)

于是按照上图的方式，现在传入GitHub的代码的中文部分就不会出现乱码了![image-20250123023304976](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230233019.png)





------

又到了例行吐槽vs的git的环节：

是的，在上一章节中，我学会了怎么用vs推送到github仓库，以及解决代理端口的问题，就在我欢欣鼓舞以为以后的git环节畅通无阻的时候，新的风暴出现了：

我要给原来的代码增加新的功能（也就是实现插入和清空），于是我通过搜索得出，我可以：

1. 将GitHub的代码Clone到本地的vs上
2. 在vs上给代码增加新的功能
3. 创建一个分支然后提交更改



前两点非常简单，我顺利地写完了代码，然后就被vs折磨了。。。

首先那个推送功能为什么老是喜欢自动创立一个master分支然后把各种东西交到master这件事我就不吐槽了（上一次已经吐槽过了，解决办法就是在cmd里手动敲命令把那个分支删掉）

其次就是为什么我写好的项目为什么不能直接提交，而是要先创建一个新的本地git仓库，我最开始忘记了这点，然后在我的develop分支和master分支（这个是vs自己创的）同时提交了我最初没扩展的原始代码（就是相当于把main的东西复制粘贴到了develop分支）

然后在我解决了上述的问题之后，最噩梦的来了：

我不能从本地拉取代码，因为提示我有未解决的冲突，，我研究了半天也没搞懂要怎么在vs里解决这个冲突，还在输出端里看见了![image-20250123025010947](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230250094.png)

诸如这样的报错，于是我又去搜怎么在windows里更改文件夹所有权，按照网上的方案走了一遍但是无事发生，但是我在解决冲突的时候！！

我发现我写的扩展代码没了？？？

我也不知道我点到了什么，反正就是有啥点啥，弹出是否就选是（我在想或许是我点了一个叫重置的东西），我到现在也没弄明白，但总之就是我写好的代码全都不见了（只有扩展前的代码），然后我只能把整个放扩展代码的文件夹删掉，从头开始重新Clone，然后重新敲扩展代码

当然，拉取的时候还是失败了，我到现在也没弄清楚要怎么解决冲突文件，因为vs根本没给我解决的方法，它只给我列了一堆文件，也没说冲没冲突，最后我顺从了，我决定选择使用命令行

其实我最开始就想用命令行的，但是最开始教程是这样![image-20250123030201533](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230302754.png)

我也完成得很顺利，但是后面它变成了这样![image-20250123030225327](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230302701.png)

我最开始是抗拒的，但是后面的用命令行直接add的部分人家直接用IDEA完成了，我也没辙，只能老实按他说的用vs交代码，然后就悲剧了。。

最后我方案是：用vs初始化本地的Git仓库，然后接下来：

`git checkout -b [branch name]`创建本地分支

`git push origin [branch name]`把新分支推送到Github

`git branch`查看本地分支

`git branch -r`查看远程分支

`git add .`

`git commit -m "注释"`提交当前代码

`git merge <当前分支名称>`合并分支

`git push origin <目标分支名称>`推送到远程仓库



`git push origin :[branch name]`当然，删除远程分支也是大有用处的



现在是凌晨3：16，谢谢你vs

vs是一款我的问题

本来明天是打算学习堆栈的，现在决定先去廖雪峰老师那里再进修一下Git，vs的Git真是一坨

![image](https://github.com/user-attachments/assets/67ed183f-b604-49fd-9f93-e58d9366d062)

这是受害者的证明

------

# 写在最初

原本是打算把所有的笔记放在Note仓的，但是很快发现只过了几天日志就已经很长了，所以专门新建了一个代码仓，用于记录代码的学习

这是一个记录数据结构的学习的仓库

------

关于仓库功能的补充：除了学习数据结构外，这也是我学习Git的记录

# 链表（最初的）

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
