#include <stdio.h>
#include <string.h>

typedef struct {
  char name[256];
  int age;
  int sex;
} People;

void InputPeople(People *data);
void ShowPeople(People data);

int main(void)
{
  People data[3];
  int i;

  for (i = 0;i < 3;i++) {
    InputPeople(&data[i]);
  }

  for (i = 0;i < 3;i++){
    ShowPeople(data[i]);
  }

  return 0;
}

void InputPeople(People *data)
{
  printf("input name:");
  scanf("%s", data->name);
  printf("input age:");
  scanf("%d", &data->age);
  printf("sex(1-male, 2-female):");
  scanf("%d", &data->sex);
  printf("\n");
}

void ShowPeople(People data)
{
  char sex[16];

  printf("name:%s\n", data.name);
  printf("age:%d\n", data.age);

  if (data.sex == 1) {
    strcpy(sex, "male");
  } else {
    strcpy(sex, "female");
  }

  printf("sex:%s\n", sex);
  printf("\n");
}
