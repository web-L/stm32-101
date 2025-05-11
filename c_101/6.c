#include <stdio.h>

int add(int a, int b);
void greet(char namep[]);
int factorial(int n);

int main() {
  // 调用函数
  int sum = add(5, 3);
  greet("Alice");
  int fact = factorial(15);

  // 打印结果
  printf("Sum: %d\n", sum);
  printf("Factorial: %d\n", fact);
}

// 函数定义
int add(int a, int b) {
  return a + b;
}

void greet(char namep[]) {
  printf("Hello, %s!\n", namep);
}

// 递归计算阶乘
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}