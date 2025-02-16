#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ALPHABET_SIZE 26

int shortestSequenceLength(int n, char words[n][20]) {
    int count[ALPHABET_SIZE] = { 0 }; // 记录每个字母的出现次数
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