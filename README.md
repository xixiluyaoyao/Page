# 堆栈

关于指针的一些问题：

首先是困扰我很久很久的问题，这段代码让我的程序一直崩溃：

- ```
  int pop(Stack* p) {
      if (p->top == NULL) {
          printf("It is an empty stack");
          return -1;
      }
      Node* pfront = p->top;
      int pop_num = p->top->data;
      p->top = p->top->next;
      free(pfront);
      return pop_num;
  }
  
  void Print_stack(Stack p) {
      int a;
      Stack temp = p;  // 创建栈的副本
      while (temp.top != NULL) {
          a = pop(&temp);  // 通过副本执行 pop 操作，原栈不受影响
          printf("%d ", a);
      }
      printf("\n");
  }
  ```

  从注释里可以看出我原本是以为创建栈的副本的话，此时对temp进行操作，不会对原栈造成影响，但事实上：

  虽然创建了 `temp` 来作为栈的副本，但在调用 `pop(&temp)` 时，`temp` 栈的内容会被修改。所以**原栈 `p` 也会被修改**，因为 `pop` 操作是通过 `&temp` 传递指针的，指向的仍然是 `temp` 栈的原始内存。

  所以正确的做法是这样的：

  ```
  void Print_stack(Stack* p) {
  	if (p->top == NULL) {
  		printf("Error because stack is empty");
  		return;
  	}
  	Node* current = p->top;
  	while (current != NULL) {
  		printf("%d ", current->data);
  		current = current->next;
  	}
  	printf("\n");
  }
  ```

  **千万不要调用该死的pop函数。**之前不信邪，想着只要弄一个栈的副本，这样就能直接用pop函数直接把栈的数据全打印出来，并且原栈不会因为弹栈而发生改变。事实上只要调用了pop，无论怎样都会对原栈造成影响，因为在 `pop` 函数中传递的是栈的指针 (`Stack*`)，**所以通过这个指针操作栈会直接修改原栈的内容**。当调用 `pop(&temp)` 时，`temp` 的栈指针会直接修改原栈的 `top`，即 `temp.top` 和 `p.top` 指向的**内存是同一块**。`pop(&temp)` 会删除栈的顶部元素，并更新栈的指针。

  所以只能弄一个临时栈：

  ```
  void Print_stack(Stack* p) {
      Stack temp;  // 创建一个新的栈作为副本
      temp.top = NULL;  // 初始化临时栈为空栈
      Node* current = p->top;  // 使用原栈的数据，暂时不修改原栈
      
      // 使用一个临时栈来存储原栈元素
      while (current != NULL) {
          push(&temp, current->data);  // 将元素压入临时栈
          current = current->next;
      }
  
      // 打印临时栈
      while (temp.top != NULL) {
          int val = pop(&temp);
          printf("%d ", val);
      }
      printf("\n");
  }
  
  ```

  但是何必呢？这不是自找麻烦，直接不用pop函数就没这么多事情了。

- .用法与->用法的区别在于该结构体本身是一个变量还是一个指针，如果是一个结构体变量，那么无论其成员是否是指针类型，都是用.来访问。

- 在 C 语言中，`Stack *s` 和 `Stack s` 这两种传参方式有明显的区别，主要体现在它们的传递方式和内存管理上。

  **`Stack *s：`**

  - `Stack *s` 表示传递的是 `Stack` 类型的指针。这意味着在函数内部你可以修改传入的栈结构，因为你操作的是原始的栈对象，而不是它的副本。
  - 这种方式通常用于需要在函数中修改数据的情况，因为指针传递的是内存地址，函数可以直接访问和修改该地址处的内容。

- bool类型函数的用法：

```
#include <stdbool.h> // 引入标准布尔类型宏定义
bool isEmpty(const char* str) {
    return strlen(str) == 0; // 如果字符串长度为0，返回true
}
```

- exit（1）：


​	`exit(1)` 表示程序正常结束，但以一个非零的状态码（1）返回。通常，非零的状态码用于表示程	序发生了某种错误或者异常情况。

​	`exit(0)` 通常表示程序正常退出，且没有发生错误。



