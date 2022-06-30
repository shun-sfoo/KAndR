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
  print_line();
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

void print_histogram_vertical() {}
