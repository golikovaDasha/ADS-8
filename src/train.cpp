// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :countOp(0), first(nullptr), last(nullptr) {}

int Train::getOpCount() {
  return countOp;
}
void Train::addCage(bool light) {
if (first && last) {
  Cage* temporary = new Cage;
  temporary->light = light;
  temporary->next = nullptr;
  temporary->prev = nullptr;
  last->next = temporary;
  last->next->prev = last;
  last = last->next;
  if (!first->prev) {
    first->prev = last;
  }
  if (!last->next) {
    last->next = first;
  }
  } else {
  Cage* temporary = new Cage;
  temporary->light = light;
  temporary->next = nullptr;
  temporary->prev = nullptr;  
  first = temporary;
  last = first;
  }
}
int Train::getLength() {
  first->light = true;
  Cage* temporary = first;
  int tCount = 0, len = 0;
  while (true) {
  countOp+=1;
  tCount+=1;
  temporary = temporary->next;
  if (temporary->light) {
  int temp = tCount;
  temporary->light = false; //выключили
  for (int i = tCount; tCount; tCount-1, countOp+1) {
    temporary = temporary->prev;
  }
  if (!temporary->light) {
    len = temp;
    break;
    }
  }
}
return len;
}
