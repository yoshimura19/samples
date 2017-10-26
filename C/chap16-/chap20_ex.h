#ifndef __PEOPLE_H__
#define __PEOPLE_H__

#include <stdio.h>
#include <string.h>

typedef struct {
  char name[256];
  int age;
  int sex;
} People;

/* 個人データを入力する */
extern void InputPeople(People *data);

/* 個人データを表示する */
extern void ShowPeople(People data);

#endif
