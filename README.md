# getfun.h

**getfun** is a lightweight, zero-dependency C library designed to safely read, validate, and store user input (`char`, `int`, `long`, `float`, `double`, and dynamically allocated `string`s) without buffer overflows or infinite input loops.

## Why getfun?

In standard C, reading user input with `scanf()` can easily leave invalid characters stuck in the input buffer, causing infinite loops, while reading strings safely requires manual memory management. **getfun** wraps input acquisition, buffer cleanup, and dynamic memory allocation into clean, self-documenting `store_*` primitives.

## Features

* **Zero Dependencies:** Uses only standard C libraries (`<stdio.h>` and `<stdlib.h>`).
* **Safe Input Validation:** Automatically clears invalid input from `stdin` and re-prompts the user until valid data is entered.
* **Dynamic Strings:** `store_string()` dynamically expands memory via `realloc()` to accept strings of arbitrary length, paired with a convenient `string` (`char *`) typedef.
* **Memory-Leak Tested:** Verified with Valgrind (`0 errors from 0 contexts`).

## Note

This library was created as a learning project while studying C and CS50, exploring input buffers, dynamic memory allocation (`malloc`/`realloc`), and clean library design.

## Installation

### Option 1: System-Wide Installation (Linux)

Install `getfun.h` and `libgetfun.so` into `/usr/local` so you can include `<getfun.h>` from any project:

```bash
git clone https://github.com
cd getfun
sudo make install
```

Compile your programs linking `-lgetfun`:

```bash
gcc your_program.c -lgetfun -o your_program
```

To uninstall:

```bash
sudo make uninstall
```

### Option 2: Local Project Include

Copy `getfun.h` and `getfun.c` into your project folder, include `#include "getfun.h"`, and compile them together:

```bash
gcc your_program.c getfun.c -o your_program
```

## Quick Example (visible in `examples/example.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <getfun.h>

int main(void)
{
    char letter = store_char("Enter a character: ");
    int number = store_int("Enter an integer: ");
    long big_num = store_long("Enter a large integer: ");
    float decimal = store_float("Enter a float: ");
    double precise = store_double("Enter a double: ");
    string text = store_string("Enter a string: ");

    printf("\n--- Summary ---\n");
    printf("Char: %c | Int: %d | Long: %ld\n", letter, number, big_num);
    printf("Float: %f | Double: %.10lf\n", decimal, precise);
    printf("String: %s\n", text);

    free(text);
    return 0;
}
```

## License

This project is licensed under the MIT License.
