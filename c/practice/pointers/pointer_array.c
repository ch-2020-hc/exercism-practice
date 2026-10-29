int myNumbers[4] = {25, 50, 75, 100};
int i;

// print out array value
for (i = 0; i < 4; i++) {
  printf("%d\n", myNumbers[i]);
}

// print out array element address
for (i = 0; i < 4; i++) {
  printf("%p\n", &myNumbers[i]);
}

/*
Relation btw array and pointer:
In C, the name of an array, is actually a pointer to the first element of the array.

The memory address of the first element is the same as the name of the array:
*/
int myNumbers[4] = {25, 50, 75, 100};

// Get the memory address of the myNumbers array
printf("%p\n", myNumbers);

// Get the memory address of the first array element
printf("%p\n", &myNumbers[0]);

/*
Result:
0x7ffe70f9d8f0
0x7ffe70f9d8f0
*/

int myNumbers[4] = {25, 50, 75, 100};

// Get the value of the second element in myNumbers
printf("%d\n", *(myNumbers + 1));

// Get the value of the third element in myNumbers
printf("%d", *(myNumbers + 2));

/*
Change the value
*/
int myNumbers[4] = {25, 50, 75, 100};

// Change the value of the first element to 13
*myNumbers = 13;

// Change the value of the second element to 17
*(myNumbers +1) = 17;

// Get the value of the first element
printf("%d\n", *myNumbers);

// Get the value of the second element
printf("%d\n", *(myNumbers + 1));