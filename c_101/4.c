#include <stdio.h>

int main() {
  float age;

  printf("请输入你的年龄：");
  scanf("%f", &age);

  if (age < 18) {
    printf("你还未成年\n");
  } else if (age >= 18 && age < 60) {
    printf("你已经成年了\n");
  } else {
    printf("你已经老年了\n");
  }

  printf("age / 10: %f\n", age / 10);

  switch ((int)age / 10) {
    case 0:
    case 1:
      printf("您是儿童\n");
      break;
    case 2:
    case 3:
      printf("您是青少年\n");
      break;
    case 4:
    case 5:
      printf("您是中年人\n");
      break;
    default:
      printf("您是老年人\n");
  }
}