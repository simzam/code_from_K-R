#include <stdio.h>
#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    if (max > 0) // there was a line!
      printf("%s\n", longest);
  }
  return 0;
}

// Q: Necessary to use different name than in declaration above?
// read a line into s, return length
int getline(char s[], int lim)
{
  int c, i;
  for (i=0; i < lim - 1 &&(c = getchar()) != EOF && c!='\n'; ++i)
  {
    /*
    if (i >= lim - 1)
    {
      unsigned new_size = lim + MAXLINE;
      char tmp[new_size];
      copy(tmp, s, new_size - MAXLINE);
      s = tmp;
    }
    */
    s[i] = c;
    ++i; // Q: difference between prefix and postfix
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }
  s[i] = '\0'; // terminates string in C
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
  
 
void copy2(char to[], char from[], int lim) {
  int i;

  i = 0;
  
  while (i < lim - 1)
  {
    to[i] = from[i];
    ++i;
  }    
}
