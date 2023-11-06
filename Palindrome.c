#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100  // 定义栈的最大容量

// 定义栈的结构体
typedef struct {
    char data[MAXSIZE];
    int top;
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 入栈操作
void Push(Stack *s, char c) {
    if (s->top < MAXSIZE - 1) {
        s->data[++s->top] = c;
    }
}

// 出栈操作
char Pop(Stack *s) {
    if (s->top != -1) {
        return s->data[s->top--];
    }
    return '\0';  // 返回一个空字符表示栈空
}

// 判断字符串是否为回文
int IsPalindrome(char *str) {
    int len = strlen(str);
    int mid = len / 2;
    Stack s;
    InitStack(&s);

    // 将字符串的前半部分入栈
    for (int i = 0; i < mid; i++) {
        Push(&s, str[i]);
    }

    // 如果字符串长度为奇数，则中间的字符不需要比较
    if (len % 2 != 0) {
        mid++;
    }

    // 逐个字符与栈顶元素比较
    for (int i = mid; i < len; i++) {
        if (Pop(&s) != str[i]) {
            return 0;  // 一旦发现不匹配，返回0
        }
    }

    return 1;  // 全部匹配，返回1
}

int main() {
    char str[MAXSIZE];

    printf("input here:");
    scanf("%s", str);

    if (IsPalindrome(str)) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
