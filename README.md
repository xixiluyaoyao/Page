# 队列

![image-20250207211055864](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@master/202502072110049.png)

![image-20250207212228390](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@master/202502072122673.png)

- 传入用*q而不是用q：

```
void initQueue(Queue *q)
```

在C语言中，函数参数传递默认是**按值传递**（pass by value），这意味着如果你直接传递一个结构体（如 `Queue q`），函数会创建该结构体的一个副本。对于较大的结构体，复制数据会浪费时间和内存。

通过传递指针（如 `Queue *q`），函数只需要复制指针的值（即内存地址），而不是整个结构体。这样可以显著提高性能。

- 循环队列：

  假设队列的容量是 5 (`MAX_SIZE = 5`)，队列元素的索引范围是 0 到 4。

  - 初始时，`q->front = 0`（队列的前端指针指向第一个元素）。

  - 当执行 

    ```
    q->front = (q->front + 1) % 5;
    ```

     时：

    - 如果 `q->front` 是 0，执行 `q->front = (0 + 1) % 5 = 1`，前端指针向后移动一位。
    - 如果 `q->front` 是 1，执行 `q->front = (1 + 1) % 5 = 2`，前端指针继续向后移动一位。
    - 如果 `q->front` 是 4，执行 `q->front = (4 + 1) % 5 = 0`，前端指针将回到队列的起始位置，实现了循环。
