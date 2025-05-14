#include <stdio.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int x = 10;
  int y = 20;
  
  int *ptr = &x;
  printf("x的值：%d\n", x);
  printf("x的地址：%p\n", &x);
  printf("ptr存储的地址：%p\n", ptr);
  printf("ptr指向的值：%d\n\n", *ptr);

  // 通过指针修改值
  *ptr = 100;
  printf("x的值：%d\n", x);
  printf("x的地址：%p\n", &x);
  printf("ptr存储的地址：%p\n", ptr);
  printf("ptr指向的值：%d\n\n", *ptr);
  
  // 使用指针交换两个变量的值
  swap(&x, &y);
  printf("交换后的x值：%d\n", x);
  printf("交换后的y值：%d\n", y);

  return 0;
}