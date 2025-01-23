# 第二次扩展与修复（链表）

这次对链表增加了删除与销毁功能，并对老代码的一些bug进行了修复

## 增加功能

- 新增两个删除功能，分别用于删除链表中的第一个目标数据和删除链表中的所有目标数据
- 新增销毁功能（就是把头节点也一起删掉）

## 修复与改进

- 修复访问权限冲突问题，避免可能导致的悬空指针问题，增加了代码的安全性

  

​        我看的是黑马教的链表，他的销毁链表代码如下：

![image-20250123201254318](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232012456.png)

我觉得销毁链表的代码有很大一部分与清空链表的代码重复，所以我对销毁代码稍微做了一些改进：

![image-20250123202242393](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232022536.png)

但是在实际运行的时候，

```
Destroy(header);//销毁链表

Printnode(header);//再次调用链表
```

这样编译器会告诉你Printnode函数出现访问权限冲突的问题，而按理来说此时的header节点应该是NULL，此时Printnode函数应该会打印“这是一个空节点”的结果![image-20250123202015822](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232020871.png)

后面得知，不论是我的代码，还是黑马的代码，虽然传参数很方便，但是如果在销毁链表后，主函数中若再次访问header（比如调用了Printnode），程序会崩溃。这是一个悬空指针的问题

至于为什么我在我的销毁代码中手动让`header=NULL`，还是会出现程序崩溃的情况，这是因为如果传入函数的参数是header，仅仅只传入了指针的值，相当于是指针的一个副本（即 `Destroy` 中的 `header` 是主函数中 `header` 的拷贝），此时在函数中对header进行修改，对主函数中的header没有任何影响。所以正确的做法是：

```
void Destroy(struct Linknode** header) {
    Clear(*header);
    free(*header);
    *header = NULL; // 修改主函数中的 header
}
```

这样，即使被销毁的链表在后续又被调用了，也不会导致程序崩溃。

在C语言中，函数参数的传递始终是**值传递**。

当你传递一个普通变量（比如 `int a`）时，函数接收到的是这个变量的**值的副本**，修改副本不会影响原变量。

当你传递一个指针的地址（即 `struct LinkNode**`），本质上是将**指针变量本身的地址**传递给了函数。这样，函数接收到的是主函数中指针变量的地址，可以通过这个地址直接修改主函数中的指针。

当你传递一个指针（比如 `int* ptr`）时，函数接收到的是这个指针的**副本**。

通过这个指针副本可以修改它指向的内存内容，但不能修改主函数中的指针本身。



- 对输出格式进行了改进：![image-20250123203945337](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232039389.png)

相比以往的输出一个值换行一次，现在的输出结果更加美观，也更容易看出函数功能是否正常实现：![image-20250123204403357](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232044426.png)

![image-20250123204210388](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232042438.png)

- 对Clear函数进行了改进

  原先的Clear是这样的：![image-20250123215240311](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232152648.png)

  这里有一个bug：

  如果链表只有头节点的话，此时`pointnode->next`相当于对空指针进行访问，可能会导致程序崩溃，且这部分的判断其实是多余的，所以删掉了这部分的判断：

  ![image-20250123213145659](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232131714.png)

------



# 关于Git与Github

最开始把这一栏放在二级目录里，但感觉这一栏的实用性非常强，所以把它放进了一级目录

本人在经历了整整两天除了吃饭和睡觉外都坐在电脑前被vs和git折磨以后，总算是总结出了一些便捷之法

------

vs的自动创建master分支大概是为了方便后续的分支合并，但我仍然感觉vs的Git功能不好用，以下我将归总以命令行的方式提交代码到仓库/分支，后续如果忘记了只需要把以下代码复制粘贴即可：

提交代码到main：

```
Git 的全局配置：
git config --global user.name "你的用户名"
git config --global user.email "你的邮箱地址"
git config --global --list//查看当前的全局配置
全局配置适用于所有的 Git 仓库，只需要设置一次即可。

如果本地文件在D盘，首先需要： D://进入D盘
cd [文件名]//进入放代码的文件夹（也就是你要上传的项目文件）
git init//初始化仓库
git add .
git commit -m "注释（用英文）"//提交代码。第一次会让输入git的邮箱、用户名
git pull --rebase origin master//拉取代码
git push -u origin master//push到远程仓库

```

提交代码到分支：

```
如果本地文件在D盘，首先需要： D://进入D盘
cd [文件名]//进入放代码的文件夹
git checkout -b [branch name]//创建+切换分支
git push origin [branch name]//将新分支推送到github
git checkout [branch name]//切换到新的分支（如果git checkout -b [branch name]了可以不需要这一步）
git add .
git commit -m "注释（用英文写）"//添加并提交本地需要提交的代码（最好要写 -m""那部分，不然cmd可能会报错）
git push origin [branch name]//push 到git仓库
```

这时候你的Github中就会出现一个新分支，并且里面会有你提交的文件。一些人喜欢用命令行合并分支，但我觉得直接在Github里面合并分支会方便得多，方式如下：

在你的仓库中点击Pull requests

![image-20250123210900978](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232109410.png)

点击New pull request，如果你提交了分支，这时候Create pull request就是亮的![image-20250123211026691](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232110770.png)

点击即可创建合并分支的请求。如果你的分支和主分支没有冲突，就能直接合并，如果有冲突，这时候Github会把冲突的地方标出来，大概是这样：

<<< [branch name]

............(你的代码)

............(这时候显示的代码一般来说就是你最新提交上去的那个)

<<<< main

验证此时的代码就是你要交的代码后，你只需要把<<< [branch name]和<<<< main手动删掉就行，然后再点击 “**Mark as resolved**“（我已解决冲突），解决完所有标记出来的冲突后，就能提交你的变更，然后点击**”Merge pull request“**（合并分支）来合并你的Pull Request。最后它会提示你可以放心地删除这条分支，然后你就点击删除分支就行，当然，如果想保留分支的话也可以不删。（个人觉得没必要保留，直接删掉就行）

补充一些可能用到的分支管理代码：

```
git branch -r//查看远程分支
git branch//查看本地分支
git branch -d [branch name]//删除本地分支
git push origin :[branch name]//删除github远程分支
```



------



# 第一次扩展（链表）

增加了插入功能以及清空链表功能。

关于链表的清空功能：之前的代码没有free部分，一直malloc但是不free的话可能导致内存泄漏什么的。还好写的项目不大，不然可能真把电脑搞坏了hhh。

- 值得一提的是，在调试的过程中，偶然在直接输入-1时编译器直接标红警告了，原因是Clear这个部分![571483936d750f984bea8b102bd4ca20](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501230207464.png)


**如果`pointnode本身就是NULL的话（比如你scanf的时候直接输入-1就会这样，链表只有一个头节点）这个时候pointnode->next相当于在访问空指针，会出bug，程序会崩溃。`**

所以要在循环的时候加个条件，这样就ok：`while (pointnode！=NULL && pointnode->next != NULL)`![image-20250123021754029](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230221721.png)



- 还有一个地方想说的是，之前的注释有过这样一段话：![image-20250123022510181](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230225309.png)


现在知道为什么了。能找到原因是因为写扩展的时候是从GitHub的仓库里直接Clone原代码到vs里的，然后在运行的时候发现终端的输出结果中，关于中文的部分是一片乱码，大概是这个样子：![image-20250123022757480](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230227509.png)

后面一搜发现是GitHub用的是UTF-8编码，但vs默认的编码不是，![image-20250123023052124](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230230183.png)

![image-20250123023131468](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230231552.png)

![image-20250123023153075](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230231314.png)

![image-20250123023207553](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230232622.png)

于是按照上图的方式，现在传入GitHub的代码的中文部分就不会出现乱码了![image-20250123023304976](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@develop/202501230233019.png)





------

## 关于vs

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

### 解决办法：

最后我的方案是：~~用vs初始化本地的Git仓库，然后接下来：~~

直接：

`git checkout -b [branch name]`创建本地分支

`git push origin [branch name]`把新分支推送到Github

`git branch`查看本地分支

`git branch -r`查看远程分支

`git add .`

`git commit -m "注释"`提交当前代码

注意：如果直接git commit会出现这种情况，建议还是加上后面的注释部分![image-20250123200645085](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code/202501232007681.png)

~~`git merge <当前分支名称>`合并分支~~

**（感觉`git merge`不好用，建议还是在GitHub上直接处理冲突然后合并分支，非常方便）**

`git push origin <目标分支名称>`推送到远程仓库



`git push origin :[branch name]`当然，删除远程分支也是大有用处的



现在是凌晨4：06，谢谢你vs

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

------

## 和Git不得不说的故事（已红温）

  我在去年暑假的时候就初步接触过git，当时用的是Gitbash直接敲命令行上传代码到gitee，过程非常简单，只需要把廖雪峰老师给的命令复制粘贴，就能轻松提交（当然最开始我没看懂git到底在干嘛，还是我哥给我演示了一遍，主打一个依葫芦画瓢）

  但是今年，我学会了 ~~魔法~~ 科学上网，所以决定用某hub存代码，其实操作大差不差，但是我这次非常作死地没用gitbash，而是改用vs2022的Git功能，然后噩梦开始了：

- 网络代理端口

  我非常顺利地初始化了本地的仓库，然后点击推送的时候意外却发生了：vs显示未能推送到远程仓库，请检查输出，但我的输出最开始是这样的：![image-20250122224007048](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222240084.png)

根本啥也没有啊？

于是我觉得是我初始化本地仓库的问题，我以为是我本地文件的位置有问题（因为vs会自动生成code，debug，x64等等一堆文件），于是我文件位置换了又换，但是毫无作用，差点把vs玩坏了（因为疯狂点推送，拉取，然后变得我也看不懂了）。后面发生，原来![image-20250122224303983](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222243009.png)这个调试是可以展开的，我终于发现了fail的原因

==fatal: unable to access ‘https://github.com/.../.git‘: Failed to connect to github.com port 443 after 21035 ms: Could not connect to server==

  但是咱也不知道到底发生了什么，于是又去搜索，然后发现：原来不是本地仓库的原因，而是因为我挂了梯子？？好吧，然后按照教程换了代理端口![image-20250122224707831](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Note/202501222247077.png)

总算是提交成功了，皆大欢喜是不是？然后又冒出了新的问题：

- 合并与删除分支

我的代码没有交到main，而是交到了一个莫名奇妙出现的新分支master。本来也可以不管的，但是一想到如果要看代码的话，还要切换分支，那多不方便？于是强迫症又犯了，开始找怎么合并分支，于是新的噩梦开始了：

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
