// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :countOp(0), first(nullptr), last(nullptr) {}

int Train::getOpCount() {
  return countOp;
}
Train::Cage* Train::add(bool light) {
  Cage* NewC = new Cage;
  NewC->light = light;
  NewC->next = nullptr;
  NewC->prev = nullptr;
  return NewC;
}
void Train::addCage(bool light) {
  if (first && last) {
    last->next = add(light);
    last->next->prev = last;
    last = last->next;
  if (!first->prev) {
    first->prev = last;
  }
  if (!last->next) {
    last->next = first;
  }
  } else {
    first = add(light);
    last = first;
  }
}
int Train::getLength() {
  first->light = true;
  Cage* temporary = first;
  int tCount = 0, len = 0;
  while (true) {
  ++countOp;
  ++tCount;
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
