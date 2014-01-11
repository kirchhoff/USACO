#include <stdio.h>

int main ()
 {
   char letter;
   float percent;

   for (letter = 'A'; letter <= 'Z'; letter++)
     putchar(letter);

   for (letter = 'z'; letter >= 'a'; letter--)
     putchar(letter);

   putchar('\n');

   for (percent = 0.0; percent < 1.0; percent += 0.1)
     printf("%3.2f\n", percent);
   return 0;
 }
