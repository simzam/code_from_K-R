#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

int get_line(char line[], int maxline); // avoid naming conflict from <stdio>
void copy(char to[], char from[]);
int remove_trailing(char to[], int index, int max_index); 
void reverse(char to_reverse[], char reverse[], int nul_idx);
void detab(char line[], char line_detab[], int len);

int main() {
  int len;
  char line[MAXLINE];
  char reverse_line[MAXLINE];
  
  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, reverse_line, len);
    printf("%s\n", reverse_line);
  }

  return 0;
}

// the out length will be longer than the inline if tabs are encountered
// might be a good idea to do some checks on length.

// Can consider to redo getline in order, but there is a catch in messing with working function. 
void detab(char line[], char line_detab[], int len) {
  int i, j;
  while (line[i] != EOF && i + TABSTOP < len) {
    if (line[i] == '\t') {
      for (j = 0; j < TABSTOP; ++j) {
        line_detab[i] = ' ';
      }
    }
    else {
      line_detab[i] = line[i];
    }
    ++i;
  }
}


/* void entab(char line[], char line_entab[], int len) { */
/*   int i, j; */
/*   int space_counter = 0; */
/*   while (line[i] != EOF && i + TABSTOP < len) { */
/*     if (line[i] == ' ') { */
/* w      ++space_counter; */
/*       space_flag = 1; */
/*       if (space_counter */
/*       } */
/*     } */
/*   } */
/* } */


void set_delimiters(char s[], int idx) {
  s[idx] = '\n';
}

// read a line into s, return length

// whats the logic in not ++ after adding EOF. Is EOF not a char in the string??
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
  int idx;
  if (c == '\n' || i != 0)
  {
    if (flag == 1) {
      idx = lim - 2;
    }
    else {
      idx = i;
    }
    s[idx] = '\n';    
  }
  else {
    
  }
  return i;
}

// copies string "from" to string "to", depends on EOF at the end of string
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
