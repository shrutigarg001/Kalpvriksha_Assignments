#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int ValidParenthesis(char * str, int len) {
  int index = 0, openBracket = 0, squareBracket = 0, curlyBrace = 0;
  char * string2;
  string2 = (char * ) malloc(len);

  while (*str != 0) {
    if (*str == '(') {
      openBracket++;
      string2[++index] = 1;
    }

    if (*str == '[') {
      squareBracket++;
      string2[++index] = 2;
    }

    if (*str == '{') {
      curlyBrace++;
      string2[++index] = 3;
    }

    if (*str == ')') {
      if (string2[index] == 1) {
        openBracket--;
        index--;

      } 
      else 
        return 0;
    }
    if (*str == ']') {
      if (string2[index] == 2) {
        squareBracket--;
        index--;
      } 
      else 
        return 0;

    }
    if (*str == '}') {
      if (string2[index] == 3) {
        curlyBrace--;
        index--;
      } 
      else 
        return 0;
    }

    str++;
  }

  if (openBracket > 0 || squareBracket > 0 || 
    curlyBrace > 0)
    return 0;
  return 1;
}

int main() {
  char string1[50];
  int n, i, x;
  printf("Input a string: ");
  scanf("%s", string1);
  n = strlen(string1);
  printf("Check bracket in the said string is valid or not? %d", ValidParenthesis(string1, n));
}
