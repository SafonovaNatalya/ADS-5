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
  std::string postvir = "";
  for (int i = 0; i < strlen(inf); i++) {
    int prior = getPrior(inf[i]);
    if (prior == -1) {
      postvir += inf[i];
    } else {
      if (stack1.get() < prior || prior == 0 || stack1.isEmpty()) {
        stack1.push(inf[i]);
      } else if (inf[i] == ')') {
        char helper = stack1.get();
        while (getPrior(helper) >= prior) {
          postvir += helper;
          stack1.pop();
          helper = stack1.get();
        }
        stack1.pop();
      } else {
        char helper = stack1.get();
        while (getPrior(helper) >= prior) {
          postvir += helper;
          stack1.pop();
          helper = stack1.get();
        }
        stack1.push(inf[i]);
      }
    }
  }
  while (!stack1.isEmpty()) {
        postvir += stack1.get();
        stack1.pop();
    }
  if (2 >= postvir.length()) {
    return postvir;
  };
    int k = 2 - postvir.length() % 2;
    std::string otvet(postvir, 0, k);
    for (auto it = postvir.begin() + k; it != postvir.end();) {
        otvet += ' '; otvet += *it++;;
    }
    return otvet;
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
  return 0;
}
  
int eval(std::string pref) {
  TStack<int, 100> stack2;
  std::string helper = "";
  for (int i = 0; i < pref.size(); i++) {
    if (getPrior(pref[i]) == -1) {
      if (pref[i] == ' ') {
        continue;
      } else if (isdigit(post[i+1])) {
        helper += pref[i];
        continue;
      } else {
        helper += pref[i];
        stack2.push(atoi(helper.c_str()));
        helper = "";
      }
    } else {
      int j = stack2.pop();
      int k = stack2.pop();
      stack2.push(counting(j, k, pref[i]));
    }
  }
  return stack2.get();
}
