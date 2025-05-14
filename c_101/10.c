#include <stdio.h>

int main() {
  FILE *file;
  char buf[100];
  
  // 写入文件
  file = fopen("test.txt", "w");
  if (file == NULL) {
    printf("文件打开失败\n");
    return 1;
  }

  fprintf(file, "Hello, World! \n");
  fprintf(file, "Hello, C!");

  fclose(file);

  //读取文件
  file = fopen("test.txt", "r");
  if (file == NULL) {
    printf("文件打开失败\n");
    return 1;
  }
  printf("文件内容：\n");
  while (fgets(buf, sizeof(buf), file) != NULL) {
    printf("%s", buf);
  }
  fclose(file);
  

  return 0;
}

// 文件操作
// 1. 打开文件
// 2. 读取文件
// 3. 写入文件
// 4. 关闭文件
