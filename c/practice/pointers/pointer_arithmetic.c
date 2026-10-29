/*
Increment & Decrement
*/
int myNumbers[3] = {10, 20, 30};
int *p = myNumbers;  // myNumbers[0]

printf("%d\n", *p); // 10
p++;           // move to myNumbers[1]
printf("%d\n", *p); // 20
p--;           // back to myNumbers[0]
printf("%d\n", *p); // 10

p += 2;        // jump to myNumbers[2]
printf("%d\n", *p); // 30

/*
Subtraction
*/
int myNumbers[5] = {10, 20, 30, 40, 50};
int *start = &myNumbers[1]; // points to 20
int *end = &myNumbers[4];   // points to 50

printf("%ld\n", end - start); // 3 elements apart

/*
Pointer Arithmetic Depends on Type
Not all pointers move the same way.

When you add 1 to a pointer, it moves forward by the size of the thing it points to - not just by 1 byte.

For example:

An int* pointer moves by the size of an integer (usually 4 bytes).
A char* pointer moves by the size of a character (1 byte).
So if both pointers start at memory address 1000:

int* → p + 1 would move to address 1004
char* → p + 1 would move to address 1001
This shows that pointer movement depends on the data type it points to - not on the number you add:
*/

int myNumbers[2] = {1, 2};
char letters[] = "Hi"; // 'H', 'i', '\0'

int *pi = myNumbers; // int pointer
char *pc = letters; // char pointer

printf("%p\n", (void*)pi);
printf("%p\n", (void*)(pi + 1)); // moves by sizeof(int) (4 bytes)
printf("%p\n", (void*)(pi + 2)); // moves by sizeof(int) (4 bytes)

printf("%p\n", (void*)pc);
printf("%p\n", (void*)(pc + 1)); // moves by 1 byte