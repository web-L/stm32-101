#include <stdio.h>

int main() { 
  // 声明并初始化一维数组
  int arr[5] = {1, 2, 3, 4, 5};

  // 打印数组元素
  for (int i = 0; i < 5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  char greeting[] = "Hello, World!";
  printf("greeting: %s\n", greeting);

  return 0;
}