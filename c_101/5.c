#include <stdio.h>

int main() {
  int i = 0;
  // for 循环
  for (i = 0; i < 10; i++) {
    printf("i: %d\n", i);
  }

  // while 循环
  while (i < 10) {
    printf("i: %d\n", i);
    i++;
  }

  // do while 循环
  do {
    printf("i: %d\n", i);
    i++;
  } while (i < 10);

  // 嵌套循环
  for (i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("i: %d, j: %d\n", i, j);
    }
  }

  // 跳转语句
  for (i = 0; i < 10; i++) {
    if (i == 5) {
      break;
    }
    printf("i: %d\n", i);
  }

  // 使用 continue 跳过当前循环
  for (i = 0; i < 10; i++) {
    if (i == 5) {
      continue;
    }
    printf("i: %d\n", i);
  }
}