#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
#define IN 1
#define OUT 0

void celsius();
void fahrenheit();
void revert_celsius();
void input();
void judge();
void count_char_v1();
void count_unvisible();
void output();
void output_unvisible();
void print_line();

void print_histogram_vertical();

void print_char_histogram();

int power(int m, int n);

int getline1(char[], int);
void copy(char[], char[]);

void squeeze(char* s1, char* s2);
int any(char* s1, char* s2);

int main(int argc, char* argv[]) {
  celsius();
  fahrenheit();
  revert_celsius();
  /* output(); */
  /* input(); */
  /* judge(); */
  /* count_unvisible(); */
  /* count_char_v1(); */
  /* output_unvisible(); */
  /* print_line(); */
  /* print_histogram_vertical(); */
  /* print_char_histogram(); */
  int res = power(2, 5);
  printf("%d\n", res);

  char s1[] = "hello";
  char s2[] = "world";

  /* squeeze(s1, s2); */

  int r = any(s1, s2);

  printf("%d", r);
}

void celsius() {
  printf("%4s %6s\n", "fahr", "cel");

  float fahr, celsius;
  float lower, upper, step;
  lower = 0;
  upper = 300;
  step = 30;

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf(" %3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

void fahrenheit() {
  printf(" %3s %6s\n", "cel", "fahr");
  float celsius;

  for (celsius = 0; celsius <= UPPER; celsius = celsius + STEP)
    printf(" %3.0f %6.1f\n", celsius, (9.0 / 5.0) * celsius + 32);
}

void revert_celsius() {
  printf("revert\n");

  printf("%4s %6s\n", "fahr", "cel");

  float fahr;
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}

void input() {
  int c, count = 0;
  while ((c = getchar()) != EOF) {
    putchar(c);
    ++count;
  }
  printf("count %d", count);
}

void judge() {
  /* 1.6 */
  /* 1.7 */
  printf("getchar() != EOF is %d\n", getchar() != EOF);  // 1
  printf("EOF is  %d\n", EOF);                           // -1
}

void count_char_v1() {
  long nc;
  nc = 0;
  while (getchar() != EOF) ++nc;
  printf("%ld\n", nc);
}

void count_char_v2() {
  double nc;
  for (nc = 0; getchar() != EOF; ++nc)
    ;

  printf("%.0f", nc);
}

void count_line() {
  int nl, c;
  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n') ++nl;
  printf("%d\n", nl);
}

void count_unvisible() {
  int ns, nt, nl, c;
  ns = nt = nl = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++ns;
    } else if (c == '\t') {
      ++nt;
    } else if (c == '\n') {
      ++nl;
    }
  }

  printf("space %d, tab %d, line %d\n", ns, nt, nl);
}

void output() {
  /* 1.9 */
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      while ((c = getchar()) == ' ')
        ;
      putchar(' ');
      if (c == EOF) break;
    }
    putchar(c);
  }
}

void output_unvisible() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == ' ') {
      putchar('\\');
      putchar('b');

    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');

    } else
      putchar(c);
  }
}

void count_word() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') ++nl;

    if (c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}

void print_line() {
  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      printf("\n");
    } else {
      putchar(c);
    }
  }
}

void count_number() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' || c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }

  printf("digits = ");
  for (i = 0; i < 10; ++i) printf(" %d", ndigit[i]);

  printf(",white space = %d, other = %d\n", nwhite, nother);
}

void print_histogram_vertical() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\n' && c != ' ' && c != '\t') {
      putchar('*');
    } else {
      printf("\n");
    }
  }
}

void print_char_histogram() {
  int i, c, n;
  int cdigit[26];

  for (i = 0; i < 26; ++i) { cdigit[i] = 0; }

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') { ++cdigit[c - 'a']; }
  }

  for (i = 0; i < 26; ++i) {
    putchar(i + 'a');
    putchar(':');
    putchar(' ');
    for (n = 0; n < cdigit[i]; n++) { putchar('*'); }
    putchar('\n');
  }
}

int power(int base, int n) {
  int p;

  for (p = 1; n > 0; --n) { p = base * p; }
  return p;
}

int getline1(char s[], int lim) {
  int i, c;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char from[], char to[]) {
  int i;
  for (i = 0; (from[i] = to[i]) != '\0'; ++i)
    ;
}

void squeeze(char s1[], char s2[]) {
  char i, j;

  for (i = 0; s2[i] != '\0'; i++) {
    for (j = 0; s1[j] != '\0'; j++) {
      if (s1[j] == s2[i]) { s1[j] = '\0'; }
    }
  }
}

int any(char s1[], char s2[]) {
  char i, j;
  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s2[j] == s1[i]) { return j; }
    }
  }
  return -1;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x | ((y & ~(~0 << n)) << (p + 1 - n));
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) { mid = low + (high - low) / 2; }
}
