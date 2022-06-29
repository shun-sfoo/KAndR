#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void celsius();
void fahrenheit();
void revert_celsius();
void input();
void judge();
void count_char_v1();

int main(int argc, char* argv[]) {
  celsius();
  fahrenheit();
  revert_celsius();
  /* input(); */
  /* judge(); */
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
  int c;
  while ((c = getchar()) != EOF) putchar(c);
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
