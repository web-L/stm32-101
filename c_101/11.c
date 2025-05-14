#include <stdio.h>
#include <stdlib.h> // 包含malloc函数, free函数

int main() {
  int n, i, *ptr, sum = 0;

  printf("请输入一个整数：");
  scanf("%d", &n);

  printf("int类型占用的字节数：%zu\n", sizeof(int));

  // 动态分配内存
  ptr = (int*)malloc(n * sizeof(int));
  if (ptr == NULL) {
    printf("内存分配失败\n");
    return 1;
  }

  printf("成功分配内存\n");

  // 释放内存
  free(ptr);
  printf("内存释放成功\n");

}