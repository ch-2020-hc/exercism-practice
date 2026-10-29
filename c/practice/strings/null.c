/*
In C and C++, the "negation" of a char pointer (char *) usually means evaluating 
whether the pointer is valid or checking if the character it references is the null terminator.
The behavior depends entirely on the operator you use.

1. Logical Negation (!)Using the logical NOT operator !ptr checks where the pointer is pointing.

Syntax: if (!ptr)What it does: Returns true (or 1) if ptr is NULL (points to address 0),
 meaning it points nowhere.Opposite: if (ptr) returns true if it is a valid, non-null memory address.
 
2. Logical Negation of the Dereferenced Value (!*)Using the logical NOT on the dereferenced pointer 
!*ptr checks the actual character the pointer references.

Syntax: if (!*ptr)What it does: Returns true if the first character of the string is the null terminator \0 
(equivalent to an empty string).
Opposite: if (*ptr) returns true if the character at the given memory address is not zero.

3. Bitwise Negation (~)If you meant the bitwise NOT operator ~ptr, it performs a bitwise inversion of the memory address rather than a logical check.Syntax: ~ptrWhat it does: Flips all the bits of the memory address (e.g., 0 becomes all 1s). This results in a completely different, likely invalid, memory address.
*/