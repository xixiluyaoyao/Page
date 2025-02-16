#include <stdio.h>
#include <string.h>
#include <limits.h>

#define ALPHABET_SIZE 26

int shortestSequenceLength(int n, char words[n][20]) {
    int count[ALPHABET_SIZE] = { 0 }; // ��¼ÿ����ĸ�ĳ��ִ���
    int unique = 0; // ��¼��ǰ�������ж��ٸ���ͬ����ĸ
    int min_length = INT_MAX; // ��¼������������̴��ڳ���
    int left = 0; // �������ڵ���߽�

    // ������������
    for (int right = 0; right < n; right++) {
        // ����ǰ���ʵ���ĸ���봰��
        for (int i = 0; words[right][i] != '\0'; i++) {
            char c = words[right][i];
            if (count[c - 'a'] == 0) {
                unique++; // �����ĸ��һ�γ��֣����� unique
            }
            count[c - 'a']++; // ������ĸ����
        }

        // �����ڰ���������ĸʱ��������С����
        while (unique == ALPHABET_SIZE) {
            // ���㵱ǰ���ڵ���ĸ����
            int current_length = 0;
            for (int i = left; i <= right; i++) {
                current_length += strlen(words[i]);
            }

            // ������С����
            if (current_length < min_length) {
                min_length = current_length;
            }

            // ����߽絥�ʵ���ĸ�Ƴ�����
            for (int i = 0; words[left][i] != '\0'; i++) {
                char c = words[left][i];
                count[c - 'a']--;
                if (count[c - 'a'] == 0) {
                    unique--; // �����ĸ���ٳ��֣����� unique
                }
            }
            left++; // �ƶ���߽�
        }
    }

    return min_length;
}

int main() {
    int n;
    scanf("%d", &n); // ���뵥������
    char words[n][20]; // �洢����

    // ���뵥��
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // ������������еĳ���
    int result = shortestSequenceLength(n, words);
    printf("%d\n", result); // ������

    return 0;
}