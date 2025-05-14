#include <stdio.h>
#include <stdbool.h>

int main() {

  // 整数类型
  int integer = 10; // 整数类型
  char character = 'A'; // 字符类型
  printf("整数类型: %d\n", integer);
  printf("字符类型: %c\n", character);

  // 浮点类型
  float float_num = 10.123456; // 浮点类型
  printf("浮点类型: %f\n", float_num);

  // 浮点类型
  float decimal = 10.123456; // 浮点类型
  double precise = 3.14159265358979323846; // 双精度浮点类型
  printf("浮点类型: %f\n", decimal);
  printf("双精度浮点类型: %f\n", precise);

  // 字符串类型
  char string[] = "Hello, World!"; // 字符串类型
  printf("字符串类型: %s\n", string);
  
  bool isTrue = true;
  printf("布尔类型: %d\n", isTrue);

  // 枚举类型
  enum Color {
    RED,
    GREEN,
    BLUE
  };

  enum Color color = GREEN;
  printf("枚举类型: %d\n", color);

  // 结构体类型
  struct Person {
    char name[50];
    int age;
  };

  struct Person person = {"张三", 20};
  printf("结构体类型: %s, %d\n", person.name, person.age);

  // 联合类型
  union Data {
    int i;
    double f;
  };

  union Data data;
  data.i = 10;
  printf("联合类型: %d\n", data.i);
  data.f = 3.14;
  printf("联合类型: %f\n", data.f);

  return 0;
}

