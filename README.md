# 哈希表（Hash table）

## 链式哈希表

哈希函数有三种映射方法

- 直接取模 $h(k)=k\mod  m$

  缺点：

  - 如果 $m$ 是2的幂次方，那么 $k\mod  m$ 只取决于 $k$的低位，忽略了高位的信息。
    1. - 假设 k=10（二进制表示为 10101010）。
         - 最低3位是 010，即 2。
         - $10\mod  8=2$，与最低3位的结果一致。
       - 假设 $k=13$（二进制表示为 1101）。
         - 最低3位是 101，即 55。
         - $13\mod  8=5$，与最低3位的结果一致。
    2. **数学解释：**
       - 任何整数 $k$可以表示为 $k=8×q+r$，其中 q是商，r是余数，且 $0≤r<8。$
       - 在二进制中，$8×q$ 相当于将 k的最低3位清零，而 r 就是 k的最低3位。

- $(k\mod2^w)>>(w−r)$，其中$m=2^r$

  通过右移操作，提取键的高位信息，避免只依赖低位信息的问题

  - $键 k=12345（二进制：11000000111001）。$
  - $w=16（即取余 2^{16}=65536）。$
  - $r=8（即哈希表大小 m=2^8=256）。$
  - $右移位数 w−r=16−8=8$

  计算过程：

  1. $取余 2^{16}：$
     $k\mod  2^{16}=12345\mod  65536=12345（因为 12345<65536）。$
  2. 右移 8 位：
     $12345>>8=48（二进制 11000000111001右移8位变成 110000，即 48）。$

  最终哈希值为 48。

  $k\mod2^w $用于得到k的低w位二进制数，因为k可以写成

  $k=b_{n−1}×2^{n−1}+b_{n−2}×2^{n−2}+⋯+b_w×2^w+b_{w−1}×2^{w−1}+⋯+b_0×2^0$

  即$k=高位部分×2^w+低位部分$

  $(高位部分×2^w)\mod2^w=0$

  $低位部分\mod2^w=低位部分$

  $k\mod2^w $结果就是k的低w位二进制数

- 通用哈希（Universal Hashing）

  $h_{a,b}(k)=((a×k+b)\mod p)\mod  m$,其中:

  - p 是一个大于所有可能键值的质数。

  - a和 b是随机选择的整数，且 $1≤a<p，0≤b<p。$

  - m 是哈希表的大小。

    通用哈希函数族的设计保证了 $h(k1) 和 h(k2) $是均匀分布在 {0,1,…,m−1}上的随机变量。彼此独立，因此$h(k1)=h(k2) $的概率是 $1/m。$

  对于每一个$ I_{ij}$，它取值为1的概率是 $1/m$，取值为0的概率是 $1−1/m$。因此，$E[I_{ij}]=1×1/m+0×(1−1/m)=1/m。$

  那么对于n个key值，m个槽孔，每个槽孔的链表的期望长度就是$n×1/m=n/m$

![ede5ea53fb6b119e11bb9a7a60961f2a](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@Hash/202502162202506.png)

## Table doubling和Karp-Rabin算法

### 摊销思想：

1. **插入操作的成本：**

   - 每次插入操作的成本为 O(1)，除非触发表翻倍。
   - 表翻倍的成本为 O(n)，其中 n 是当前表的大小。

2. **分摊表翻倍的成本：**

   - 表翻倍的成本可以分摊到之前的插入操作中。

   - 每次表翻倍的成本 O(n) 可以分摊到 n 次插入操作中，因此每次插入操作的摊销成本为 O(1)。

     也就是说，我们不在乎某个操作的成本有多大，只需要最终的总成本比较小，就是我们所理想的。

### Karp-Rabin与暴力法：

#### 暴力法：

```
def brute_force_search(text, pattern):
    n = len(text)
    m = len(pattern)
    for i in range(n - m + 1):
        j = 0
        while j < m and text[i + j] == pattern[j]:
            j += 1
        if j == m:
            return i  # 返回匹配的起始位置
    return -1  # 未找到
```



- **时间复杂度**：最坏情况下为 **O(n \* m)**（n是文本长度，m是模式长度）。

- **空间复杂度**：**O(1)**，不需要额外空间。

  核心思想是：从文本的第一个字符开始，逐个与目标模式串进行比较，如果发现不匹配，就将文本的起始位置向后移动一位，重新开始比较，直到找到匹配的子串或遍历完整个文本。

#### Karp-Rabin

1. **预处理：**

   - 计算目标模式串 P的哈希值 h(P)。
   - 计算文本串 T的前 m个字符的哈希值 $h(T[0..m−1])$，其中 m是模式串的长度。

2. **滑动窗口匹配：**

   - 从$ i=0$ 开始，滑动窗口遍历文本串 T。
   - 对于每个位置 i，计算当前子串 $T[i..i+m−1] $的哈希值 $h(T[i..i+m−1])$。
   - 如果 $h(T[i..i+m−1])=h(P)$，则进一步验证 $T[i..i+m−1]$ 和 P是否真正匹配。
   - 如果匹配成功，则记录匹配位置 i。

3. **哈希值的快速计算：**

   - 使用滚动哈希（Rolling Hash）技术，快速计算下一个子串的哈希值。

   - 具体来说，假设当前子串的哈希值为 h，则下一个子串的哈希值可以通过以下公式计算：

     $h(T[i+1..i+m])=(h−T[i]×d^{m−1})×d+T[i+m]$

     其中 d是字符集的基数（例如，ASCII 字符集的基数为 256）

     对滚动哈希公式的解释：

     1. **移除 $T[i] $的贡献：**
        当前子串的第一个字符 $T[i]$ 对哈希值的贡献是 $T[i]×d^{m−1}$。因此，我们需要从当前哈希值中减去这个贡献：

        $h_{new}=h(T[i..i+m−1])−T[i]×d^{m−1}$

        2.**乘以基数 d：**
        将剩余部分乘以基数 d，相当于将所有字符的权重提升一位：

        $h_new=(h(T[i..i+m−1])−T[i]×d^{m−1})×d$

        3.**添加 $T[i+m]$ 的贡献：**
        最后，添加下一个子串的最后一个字符 $T[i+m]$ 的贡献：

        $h(T[i+1..i+m])=(h(T[i..i+m−1])−T[i]×d^{m−1})×d+T[i+m]$

时间复杂度为 O(n+m)

# 用哈希的滑动窗口解决考核题：

![image-20250216213727839](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@master/202502162137992.png)

![image-20250216213749980](https://cdn.jsdelivr.net/gh/xixiluyaoyao/Code@master/202502162137135.png)

```
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ALPHABET_SIZE 26

int shortestSequenceLength(int n, char words[n][20]) {
    int count[ALPHABET_SIZE] = {0}; // 记录每个字母的出现次数
    int unique = 0; // 记录当前窗口中有多少个不同的字母
    int min_length = INT_MAX; // 记录满足条件的最短窗口长度
    int left = 0; // 滑动窗口的左边界

    // 遍历单词序列
    for (int right = 0; right < n; right++) {
        // 将当前单词的字母加入窗口
        for (int i = 0; words[right][i] != '\0'; i++) {
            char c = words[right][i];
            if (count[c - 'a'] == 0) {
                unique++; // 如果字母第一次出现，增加 unique
            }
            count[c - 'a']++; // 更新字母计数
        }

        // 当窗口包含所有字母时，尝试缩小窗口
        while (unique == ALPHABET_SIZE) {
            // 计算当前窗口的字母总数
            int current_length = 0;
            for (int i = left; i <= right; i++) {
                current_length += strlen(words[i]);
            }

            // 更新最小长度
            if (current_length < min_length) {
                min_length = current_length;
            }

            // 将左边界单词的字母移出窗口
            for (int i = 0; words[left][i] != '\0'; i++) {
                char c = words[left][i];
                count[c - 'a']--;
                if (count[c - 'a'] == 0) {
                    unique--; // 如果字母不再出现，减少 unique
                }
            }
            left++; // 移动左边界
        }
    }

    return min_length;
}

int main() {
    int n;
    scanf("%d", &n); // 输入单词数量
    char words[n][20]; // 存储单词

    // 输入单词
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // 计算最短子序列的长度
    int result = shortestSequenceLength(n, words);
    printf("%d\n", result); // 输出结果

    return 0;
}
```

