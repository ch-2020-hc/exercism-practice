# C, C++ and ARM64-Assembly practice

Solutions from the Exercism C track, two Exercism C++ exercises, and short embedded-style snippets I wrote while practicing (ring buffer, motor state machine, PI controller, register bit macros).

## Layout

- `arm64/exercism` — Exercism ARM64 solutions.
- `c/exercism` — Exercism C solutions. Each have a small `main.c` driver
- `c/practice` — my own snippets: ring buffer, FSM, PI control, bitwise macros, pointers, strings, structs
- `cpp/exercism` — Exercism C++ solutions.

## Build

C: from an exercise folder that has `main.c` and a solution file of the same name. Checked in `c/exercism/two_fer`:

```
gcc -std=c11 -Wall -Wextra -o two_fer main.c two_fer.c
./two_fer
```

The name after `-o` is the program name, and it matches the solution file (`two_fer.c`). On Windows, gcc writes `two_fer.exe`; 


