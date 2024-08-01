---
title: ft_printf
tags:
  - "42"
  - programming
  - common_core
use: README, Documentation
languages: C
dependences:
---

<p align="center">
  <picture>
	<img alt="List_logo" src="https://drive.google.com/uc?export=view&id=1rFqWh4miOnHABWGa2X7KTe2geXDhuD2S">
  </picture>
</p>

# <p align="center">**ft_printf**</p>
<p align="center">Because ft_putnbr() and ft_putstr() aren’t enough</p>
</br>
<p align="center"> <i>Summary:</br>
	The goal of this project is pretty straightforward. You will recode `printf()`.</br>
	You will mainly learn about using a variable number of arguments. How cool is that??</br>
	It is actually pretty cool</i> 🙂</br>
	Version: 9.2</br>
</p>

</br>

> [!INFO] 
> If you spot something that isn't right, please open an [Issue](https://github.com/the-8-bits/42-libft/issues/new)

</br>

<details><summary>Table of Contents 🔖</summary>

- [**ft\_printf**](#ft_printf)
	- [Important Concepts](#important-concepts)
		- [Variadic Functions](#variadic-functions)
		- [`ar` commands](#ar-commands)
	- [Requirements](#requirements)
		- [Don’t implement the buffer management of the original `printf()`](#dont-implement-the-buffer-management-of-the-original-printf)
		- [Your function has to handle the following conversions: `cspdiuxX%`](#your-function-has-to-handle-the-following-conversions-cspdiuxx)
		- [Your function will be compared against the original `printf()`](#your-function-will-be-compared-against-the-original-printf)
		- [You must use the command `ar` to create your library](#you-must-use-the-command-ar-to-create-your-library)
		- [Using the `libtool` command is forbidden](#using-the-libtool-command-is-forbidden)
		- [Your `libftprintf.a` has to be created at the root of your repository](#your-libftprintfa-has-to-be-created-at-the-root-of-your-repository)
	- [Mandatory Part](#mandatory-part)
		- [Possible improvements and considerations](#possible-improvements-and-considerations)
	- [Bonus Part](#bonus-part)
		- [Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions](#manage-any-combination-of-the-following-flags--0-and-the-field-minimum-width-under-all-conversions)
		- [Manage all the following flags: `#`, `+`, *`(space)`*](#manage-all-the-following-flags---space)
		- [Main changes](#main-changes)
	- [Usage examples](#usage-examples)

</details>

---

## Important Concepts

### [Variadic Functions](../../../../Languages/C/README.md#variadic-functions)

They provide a versatile way to define functions that **can accept a variable number of arguments**. These functions allow developers to create flexible and efficient code by accommodating different argument counts at runtime. Unlike regular functions, which have a fixed parameter list, variadic functions use the ellipsis notation (`...`) to indicate that they can accept a variable number of arguments of varying types.

Here's a brief example of a variadic function that calculates the sum of its arguments:

```c
#include <stdarg.h>

int sum(int num, ...) {
	va_list args;
	va_start(args, num);
	
	int total = 0;
	for (int i = 0; i < num; i++) {
		total += va_arg(args, int);
	}
	
	va_end(args);
	return total;
}
```

The main used elements, that are essential when working with variadic functions in C, enable you to access and manipulate variable arguments in a safe and controlled manner, making it possible to write functions that accept a variable number of arguments.

- `va_list args`
- `va_start(args, num)
- `va_arg(args, type)`
- `va_end(args)`

### [`ar` commands]((../../../../Languages/C/README.md#ar-commands))

Is typically used for creating and manipulating static libraries in Unix-like operating systems, including Linux. A static library is a collection of object files (compiled code) bundled together into a single file that can be linked with a program at compile time.

---

## Requirements

### Don’t implement the buffer management of the original `printf()`

It means that you should focus on reproducing the formatting and output functionality of the `printf()` function without dealing with the internal buffering mechanisms that `printf()` uses to optimize I/O operations. These mechanisms are designed to reduce the number of system calls or actual writes to the output device (e.g., console, file), which can be slow and inefficient. Instead of writing each character individually, `printf()` collects a block of data in a buffer and then writes this buffer to the output device in larger chunks, reducing the overhead of system calls.

Here's how `printf()` typically uses internal buffering and how you can avoid it:

1. **Buffer Allocation**: `printf()` allocates an internal buffer (usually a character array) to store the formatted output before writing it to the output device. The size of this buffer can vary depending on the implementation but is often a reasonable size, like a few kilobytes.

2. **Partial Writes**: As you call `printf()` with various format specifiers and arguments, it formats the data and places it into this internal buffer. It doesn't immediately write to the output device for each call to `printf()`. Instead, it accumulates data in the buffer.

3. **Flush Operation**: When the internal buffer is full or when a newline character (`'\n'`) is encountered (for line buffering), or when you explicitly call `fflush(stdout)` or `fprintf(file, ...)` functions, `printf()` flushes the buffer. This means it writes the entire contents of the buffer to the output device in one go.

To avoid these internal buffering mechanisms, and write data directly without buffering, you have a few options:

- **Output Formatting**: You should implement the logic to parse the format string and handle the various format specifiers (e.g., `%d`, `%s`, `%f`) correctly. Your custom `printf` function should format the output as specified in the format string.

- **Writing to Output**: After formatting the output, your custom `printf` function should write the formatted data directly to the output stream (usually the console or a file) without worrying about buffering.

- **No Internal Buffer**: Unlike the original `printf()`, which often uses an internal buffer to collect formatted output before writing it to the output stream, your custom implementation should skip this buffering step. In other words, the output should be sent immediately to the output stream as soon as it's formatted.
	> You can use the `write()` system call to write data directly to the output file descriptor (e.g., `stdout`, a file). This bypasses any internal buffering mechanisms entirely. However, this approach requires manual formatting and lacks the convenience of format specifiers.

- **I/O Efficiency**: While you won't implement buffering, you should still aim for I/O efficiency. Writing one character at a time to the output stream can be inefficient. So, you may want to use system calls or library functions that offer efficient I/O operations for writing data.

By omitting the buffer management aspect, you simplify your custom `printf` implementation, but it may be less efficient in terms of I/O compared to the original `printf()` which buffers data before sending it to the output stream. However, this trade-off can be acceptable in some situations where simplicity and clarity of code are more important than optimal performance.

> Make cleaner not faster code...

### Your function has to handle the following conversions: `cspdiuxX%`

It means that your custom `printf` function should be capable of formatting and displaying values of various data types corresponding to these conversion characters. Here's what each of these conversion characters represents:

- **`c`**: Character conversion.
   - `%c` in the format string is used to display a single character.

- **`s`**: String conversion.
   - `%s` is used to display a null-terminated character array (string).

- **`p`**: Pointer conversion.
   - `%p` is used to display a pointer's value, typically representing a memory address, in hexadecimal format.

- **`d` and `i`**: Decimal and integer conversion.
   - `%d` and `%i` are used to display signed decimal integers in base 10.

- **`u`**: Unsigned integer conversion.
   - `%u` is used to display unsigned (base 10) decimal integers.

- **`x` and `X`**: Hexadecimal conversion.
   - `%x` is used to display unsigned hexadecimal (base 16) integers in lowercase.
   - `%X` is used to display unsigned hexadecimal (base 16) integers in uppercase.

- **`%`**: Percent character itself.
   - `%%` is used to display a literal percent character in the output.

### Your function will be compared against the original `printf()`

> Okay.

### You must use the command `ar` to create your library

Allows you to create a static library that can be linked with multiple C programs. Static libraries are linked at compile time, which means the code from the library is copied into the executable, making it self-contained and independent of the library's presence on the system where the program is run.

### Using the `libtool` command is forbidden

It means that you should not use the GNU Libtool utility for building libraries in your project. Libtool is a powerful tool that simplifies the creation of shared libraries (dynamic libraries) on various Unix-like systems. It provides a higher level of abstraction for handling the complexities of shared libraries, including platform-specific differences.

Here's why you might be forbidden from using `libtool`:

1. **Simplicity**: In some cases, the use of `libtool` might be considered overkill for a project that only requires static libraries or has simple library needs. `libtool` can introduce additional complexity and dependencies that are unnecessary for such projects.

2. **Project Constraints**: Your project or assignment instructions may specify that you should not use `libtool` to ensure that you learn and demonstrate an understanding of the lower-level library creation and linking process using tools like `ar` and `gcc` directly.

3. **Compatibility**: `libtool` is primarily designed for creating shared libraries. If your project or platform doesn't require shared libraries and static libraries are sufficient, using `ar` and `gcc` directly can be more straightforward and compatible.

### Your `libftprintf.a` has to be created at the root of your repository

When you're instructed that your `libftprintf.a` has to be created at the root of your repository, it means that the static library you are building (in this case, `libftprintf.a`) should be placed in the top-level directory of your project's repository.

1. **Static Library Name**: `libftprintf.a` is the name of the static library you are building. Static libraries typically have the `.a` file extension on Unix-like systems.

2. **Root of Your Repository**: The "root" or "top-level" directory of your repository is the main directory that contains all the project's source code, files, and directories. It's the directory where your project's version control system (e.g., Git) is initialized.

Placing the library in the root of your repository makes it easily accessible to other parts of your project. This is typically done to ensure that other source files and build scripts can reference and link with `libftprintf.a` without specifying a complex or relative path.

Your project structure should look like this:

```
/ft_printf
	├── src
	│   ├── ft_printf.c
	│   ├── ...
	├── include
	│   ├── ft_printf.h
	│   ├── ...
	├── Makefile
	├── libftprintf.a   <-- This is where you should place it
	├── ...
```

---

## `va_start()`, `va_arg()`, and `va_end()`

Typically used when you want to create functions that can accept a variable number of arguments, like `printf` and `scanf` in C. These functions are part of the `<stdarg.h>` header.

1. `va_start()`:
   - is used to initialize a `va_list` object, which is a data structure that allows you to access the variable arguments passed to a function.
   - It takes two arguments: the first argument is the `va_list` object you want to initialize, and the second argument is the last named parameter before the variable arguments. This helps `va_start()` determine where the variable arguments begin.

   Example:
   ```c
   #include <stdarg.h>

   void example_function(int fixed_arg, ...) {
       va_list args;
       va_start(args, fixed_arg);
       // Now you can use va_arg() to access variable arguments.
   }
   ```

2. `va_arg()`:
   - is used to access the individual variable arguments within the function.
   - It takes a `va_list` object and the type of the argument you want to access.
   - You should use `va_arg()` in a loop or repeatedly to access all the variable arguments.

   Example:
   ```c
   int sum_of_integers(int count, ...) {
       va_list args;
       va_start(args, count);
       int sum = 0;
       for (int i = 0; i < count; i++) {
           int num = va_arg(args, int);
           sum += num;
       }
       va_end(args);
       return sum;
   }
   ```

3. `va_end()`:
   - `va_end()` is used to clean up and release the resources associated with the `va_list` object.
   - It should be called at the end of the function that uses variable arguments to free up any resources and prevent memory leaks.

   Example:
   ```c
   int sum_of_integers(int count, ...) {
       va_list args;
       va_start(args, count);
       int sum = 0;
       for (int i = 0; i < count; i++) {
           int num = va_arg(args, int);
           sum += num;
       }
       va_end(args); // Cleanup va_list
       return sum;
   }
   ```

---

|Mandatory|#|Bonus|#|
|-|-|-|-|
|%c|✔️|’-0.’|❌|
|%s|✔️|’#`space`+’|❌|
|%p|✔️|
|%d|✔️|
|%i|✔️|
|%u|✔️|
|%x|✔️|
|%X|✔️|
|%%|✔️|

## Mandatory Part

This function takes a format string and a variable number of arguments and prints formatted output to the standard output (`stdout`). It handles format specifiers such as characters, strings, signed integers and unsigned integers, hexadecimal integers, and printing a literal '%' character. The code uses `va_list` and `va_arg` to process the variable arguments.

```c
// ft_printf.c
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_start(args, format); // starts the argument list
	while (*format)
	{
		if (*format != '%') //will print everything if not a placeholder
			count += write(1, format, 1);
		else
		{
			format++; // move past the placeholder
         // sends the format value and the argument list to the handler
			count += ft_handle_format_specifier(*format, args);
		}
		format++; // move past the null element printed by the handler
	}
	va_end(args); // close the argument list
	return (count);
}
```


## Bonus Part

> Skiped


## Possible improvements and considerations

- Error handling: 
   - The code does not handle invalid format specifiers gracefully. It should include error checking and report any invalid format specifiers or missing arguments.
   - It might be helpful to return an error code or use a separate mechanism to report errors or failures during printing.

- MAKE THE BONUS PART: Precision and width: The code does not handle precision or width modifiers (e.g., `%10s`, `%.2f`) commonly found in `printf`.

- Portability: The code assumes that `write` is available and writes to standard output. You may want to make it more portable or allow specifying the output stream. Some sort of `ft_printf_fd(int fd, const char *format, ...)`

- Buffering (NOT ALLOWED): Instead of using `write` for every character, you can consider buffering the output and writing in larger chunks for better performance.


## Usage examples

Certainly, here are usage examples for each of the scenarios you've listed based on the format specifiers and conditions:

1. **`%c`: Character**

```c
char ch = 'A';
ft_printf("Character: %c\n", ch);
```

2. **`%s`: String**

```c
char *str = "Hello, World!";
ft_printf("String: %s\n", str);
```

3. **`%p`: Pointer**

```c
void *ptr = &ch;
ft_printf("Pointer: %p\n", ptr);
```

4. **`%d` and `%i`: Signed Decimal Integer**

```c
int num = 42;
ft_printf("Integer: %d\n", num);
```

5. **`%u`: Unsigned Decimal Integer**

```c
unsigned int num = 42;
ft_printf("Unsigned Integer: %u\n", num);
```

6. **`%x` and `%X`: Hexadecimal Integer (lowercase and uppercase)**

```c
int hex_num = 255;
ft_printf("Hexadecimal (lowercase): %x\n", hex_num);
ft_printf("Hexadecimal (uppercase): %X\n", hex_num);
```

7. **`%%`: Percentage Sign**

```c
ft_printf("This is a literal %% character.\n");
```

In the `./tests/` folder there're some shell scripts implementing these scenarios.


> Malebolge