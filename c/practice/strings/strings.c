char carName[] = "Volvo";
int length = sizeof(carName) / sizeof(carName[0]);
int i;

for (i = 0; i < length; ++i) {
  printf("%c\n", carName[i]);
}

char message[] = "Good to see you,";
char fname[] = "John";

printf("%s %s!", message, fname);

