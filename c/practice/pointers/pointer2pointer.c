/*

*/

int myNum = 10;       // normal variable
int *ptr = &myNum;    // pointer to int
int **pptr = &ptr;    // pointer to pointer

printf("myNum = %d\n", myNum);
printf("*ptr = %d\n", *ptr);
printf("**pptr = %d\n", **pptr);
/*
Result:
myNum = 10
*ptr = 10
**pptr = 10
*/

/*Changing value */

**pptr = 20; // changes myNum

printf("myNum = %d\n", myNum); // prints 20

/*
Here's what happens step by step:

myNum holds the value 10.
ptr holds the address of myNum.
pptr holds the address of ptr.
*ptr gives the value of myNum.
**pptr also gives the value of myNum, by going through both pointers.
So:

*ptr = value of myNum
**pptr = value of myNum through both levels

Since **pptr accesses the original variable, you can use it to change the value of the variable too!
*/