#include "chap20_ex.h"

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

  printf("名前:%s\n", data.name);
  printf("年齢:%d\n", data.age);
  if (data.sex == 1) {
    strcpy(sex, "male");
  } else {
    strcpy(sex, "female");
  }

  printf("sex:%s\n", sex);
  printf("\n");
}
