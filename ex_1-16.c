#include <stdio.h>
#define MAXLINE 10 // longest number string - 2 since '\n' and '\0' fills the two last slots.

int get_line(char line[], int maxline); // renamed to avoid naming conflict from <stdio>
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) // there was a line!
    printf("Length of longest line: %d\nLongest line: %s\n", max, longest);
  return 0;
}

// Q: Necessary to use different name than in declaration above?
// read a line into s, return length
int get_line(char s[], int lim)
{
  int flag = 0;
  int c, i;
  for (i=0; (c = getchar()) != EOF && c!='\n'; ++i)
  {
    if (i < lim - 1)
      s[i] = c;
    else
      flag = 1;
  }
  if (c == '\n')
  {
    if (flag == 1) {
      s[lim - 2] = '\n';
      s[lim - 1] = '\0';
    }
    else {
      s[i] = '\n';
      s[i] = '\0';
    }
    ++i;
  }
  //s[i] = '\0'; // terminates string in C
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
