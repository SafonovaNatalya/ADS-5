// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char ch) {
  switch (ch) {
  case '(':
  return 0;
  case ')':
  return 1;
  case '+':
  case '-':
  return 2;
  case '*':
  case '/':
  return 3;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack1;
  int helper = -1;
  std::string postvir = "";
  for (int i = 0; i < strlen(inf); i++) {
  if ((inf[i] = '0') || (inf[i] = '1') || (inf[i] = '2') || (inf[i] = '3') ||
     (inf[i] = '4') || (inf[i] = '5') || (inf[i] = '6') || (inf[i] = '7') ||
     (inf[i] = '8') || (inf[i] = '9'))
  postvir = postvir + inf[i] + " ";
  else {
  if (inf[i] == '(') {
    stack1.push(inf[i]);
    helper += 1;
  } else {
    if ((inf[i] == '+') || (inf[i] == '-') || (inf[i] == '*') || (inf[i] == '/')) {
     if (getPrior(inf[i]) > getPrior(stack1[helper]) || (isEmpty())) {
      stack1.push(inf[i]);
      helper += 1;
     }
     else {
      postvir = postvir + stack1.pop(stack[helper]) + " ";
      stack1.push(inf[i]);
     }
    }
  }
  }
    else if (inf[i] == ')') {
     while (stack1[helper] != '(') {
      postvir = postvir + stack1.pop(stack[helper]) + " ";
      helper--;
     }
     if (stack1[helper] == '(') {
      stack1.pop(stack[helper]);
      helper--;
     }
    }
    if (i == (strlen(inf) - 1))
     while (helper > -1) {
      postvir = postvir + stack1.pop(stack[helper]) + " ";
      helper--;
     }
    }
  return std::string(postvir);
}

int counting(int i, int j, char ch) {
  switch (ch) {
  case '+':
  return i + j;
  case '-':
  return i-j;
  case '*':
  return i * j;
  case '/':
  return i/j;
  }
  return -1;
}

int eval(std::string pref) {
  TStack<int, 100> stack2;
  int size = -1;
  int result = 0;
  int j = 0;
  std::string helper = pref;
  while (j < strlen(helper)) {
  if ((helper[i] = '0') || (helper[i] = '1') || (helper[i] = '2') || (helper[i] = '3') ||
     (helper[i] = '4') || (helper[i] = '5') || (helper[i] = '6') || (helper[i] = '7') ||
     (helper[i] = '8') || (helper[i] = '9')) {
  stack2.push(helper.substr(0, helper->IndexOf(" "));
  size += 1;
  helper = helper.substr((helper->IndexOf(" ")) + 1, (strlen(helper) - 1));
  }
  else if ((helper[i] = '+') || (helper[i] = '-') || (helper[i] = '*') || (helper[i] = '/')) {
  stack2.push(counting(stack2.pop(stack2[size - 1]), 
                       stack2.pop(stack2[size]), helper[i]);
  helper = helper.substr((helper->IndexOf(" ")) + 1, (strlen(helper) - 1));
  size--;
              }
  }
  }
  return stack[size];
}
