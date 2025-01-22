# 第一次扩展

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
