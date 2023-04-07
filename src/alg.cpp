// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char ch) {
  switch (ch) {
  case ('('):
  return 0;
  break;
  case (')'):
  return 1;
  break;
  case ('+'):
  return 2;
  break;
  case ('-'):
  return 2;
  break;
  case ('*'):
  return 3;
  break;
  case ('/'):
  return 3;
  break;
  default:
  return -1;
  break;
  }
}

std::string workspace(const std::string& stroka) {
  if (2 >= stroka.length()) return stroka;
  int k = 2 - stroka.length() % 2;;
  std::string result(stroka, 0, k);
  for (auto it = stroka.begin() + k; it != stroka.end();) {
    result += ' '; result += *it++;;
    }
    return result;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack1;
  std::string postvir;
  for (auto& i : inf) {
    int prior = getPrior(i);
    if (prior == -1) {
      postvir += i;
    } else {
      if (prior == 0 || stack1.get() < prior || stack1.isEmpty()) {
        stack1.push(i);
      } else if (i == ')') {
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
        stack1.push(i);
      }
    }
  }
  while (!stack1.isEmpty()) {
        postvir += stack1.get();
        stack1.pop();
    }
  postvir = workspace(postvir);
  return postvir;
}

int counting(const int& i, const int& j, const int& ch) {
  switch (ch) {
  case ('+'):
  return i+j;
  case ('-'):
  return i-j;
  case ('*'):
  return i*j;
  case ('/'):
  return i/j;
  default:
  break;
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
      } else if (isdigit(pref[i+1])) {
        helper += pref[i];
        continue;
      } else {
        helper += pref[i];
        stack2.push(atoi(helper.c_str()));
        helper = "";
      }
    } else {
      int j = stack2.get();
      stack2.pop();
      int k = stack2.get();
      stack2.pop();
      stack2.push(counting(j, k, pref[i]));
    }
  }
  return stack2.get();
}
