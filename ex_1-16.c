#include <stdio.h>
#define MAXLINE 5 // longest number string - 2 since '\n' and '\0' fills the two last slots.

int get_line(char line[], int maxline); // renamed to avoid naming conflict from <stdio>
int get_line2(char line[], int maxline); 
void copy(char to[], char from[]);
void copy2(char to[], char from[], int lim);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line2(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) // there was a line!
    printf("Longest line: %s\n", longest);
  return 0;
}

// Q: Necessary to use different name than in declaration above?
// read a line into s, return length
int get_line(char s[], int lim)
{
  int c, i;
  for (i=0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    ++i; // Q: difference between prefix and postfix
  }
  s[i] = '\0'; // terminates string in C
  return i;
}

int get_line2(char s[], int lim)
{
  int c, i;
  for (i=0; (c = getchar()) != EOF && c!='\n'; ++i)
  {
    
    if (i >= lim - 1)
    {
      unsigned new_size = lim + MAXLINE;
      char tmp[new_size];
      copy2(tmp, s, lim);
      lim = lim + MAXLINE; // TODO: works, but greasy
      printf("s: %s, tmp: %s\n", s, tmp);
      s = tmp; // TODO: sketchy step?!
      printf("s: %s, tmp: %s\n", s, tmp);
    }
    
    s[i] = c;
    ++i; 
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

// modified copy function to increase size of array, leaving empty room at the end.
// Remember that arrays are called by reference and not by local copy.
void copy2(char to[], char from[], int lim) {
  int i;

  i = 0;
  
  while (i < lim - 1)
  {
    to[i] = from[i];
    ++i;
  }    
}
