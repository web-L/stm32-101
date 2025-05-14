#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[50];
  int age;
  char sex;
};

void updateAge(struct Person *person, int newAge);

int main() {
  struct Person person1;
  strcpy(person1.name, "张三");
  person1.age = 25;
  person1.sex = 'M';

  printf("姓名：%s\n", person1.name);
  printf("年龄：%d\n", person1.age);
  printf("性别：%c\n", person1.sex);

  struct Person person2 = { "李四", 30, 'F' };
  printf("姓名：%s\n", person2.name);
  printf("年龄：%d\n", person2.age);
  printf("性别：%c\n", person2.sex);

  updateAge(&person1, 35);
  printf("更新后的年龄：%d\n", person1.age);

  return 0;
}

void updateAge(struct Person *person, int newAge) {
  person->age = newAge;
}