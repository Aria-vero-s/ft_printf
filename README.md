# **ft_printf** - 42 Project

## **Table of Contents**
- [Introduction](#introduction)
- [Subject](#subject)
- [Format Specifiers](#format-specifiers)
- [Main()](#main)
- [Code Explanation](#code-explanation)
- [Example with ft_printi](#example-with-ft_printi)

---

## **Introduction**
**ft_printf** is a project in the 42 curriculum that aims to recreate the C library function `printf`. The function `printf` allows us to print variables to the console in various formats.

## **Subject**
Project guide:
- [ft_printf.subject.pdf](en.subject.pdf)

## **Format Specifiers**
Here are the format specifiers `ft_printf` must support:

| Specifier | Description                           |
| --------- | ------------------------------------- |
| `%c`      | Prints a single character             |
| `%s`      | Prints a string (null-terminated)     |
| `%p`      | Prints a pointer address              |
| `%d/%i`   | Prints a signed decimal integer       |
| `%u`      | Prints an unsigned decimal integer    |
| `%x`      | Prints an unsigned hexadecimal (lowercase) |
| `%X`      | Prints an unsigned hexadecimal (uppercase) |
| `%%`      | Prints a percent sign                 |

## **Main()**

1. Compile and run your program:
   ```bash
   gcc main.c libftprintf.a
   ./a.out
   ```

After compiling, you can include `ft_printf` in your C programs:

2. Use `ft_printf` as you would use the standard `printf` function:
   ```c
   int main(void)
   {
	   int value = 42;
	   ft_printf("The value is: %d\n", value);
	   return 0;
   }
   ```

## **Code Explanation**

### **ft_printf.h**

`#include "ft_printf.h"`
This line includes the custom header file `ft_printf.h`, which contains function prototypes and necessary includes for the `ft_printf` implementation. This header file will typically declare the functions like `ft_printf`, `ft_printc`, `ft_prints`, etc., and ensure that everything is correctly linked.

### **flags(va_list arg, char s)**

This function is responsible for **identifying** the format specifier (like `%d`, `%s`, etc.) and **calling** the appropriate function handling the data type. And although `ft_printf()` writes variables to the console using `write()`, we also need to give it a return value like the original `printf()`, which is the number of characters printed.

The function works by checking which specifier is provided (e.g., `%d`, `%s`, `%x`, etc.) and then calling the respective function to print that type.
For each case, the number of characters printed is added to the `count` variable.

### **va_list arg, va_start, va_arg, va_end ...**

- `va_list arg`: This is the list of arguments passed to `ft_printf` that need to be processed based on the format specifiers. It is used with `...` to create functions that accept an unkown quantity of arguments of unknown types.
- `va_start` : Initializes `va_list` to access arguments.
- `va_arg` : Accesses an argument specific in the list.
- `va_end` : Cleans up memory once finished using `va_list`.

### **ft_printf(const char *str, ...)**

The `ft_printf` function is the main function that mimics the behavior of the standard `printf`. Here's how it works:

1. **Processing the Format String**
   - The function loops through the format string (`str`), character by character.
   - When a `'%‘` character is found, it indicates the start of a format specifier. The `flags()` function is then called to process the corresponding format specifier (like `%d`, `%s`, etc.).
   - If the current character is not a `'%‘`, it is treated as a regular character and printed directly using `write(1, &str[i], 1)`.

2. **Counting Characters**
   - Every time a character (or multiple characters) is printed, the number of characters printed is tracked using the `count` variable.

3. **Finalizing**
   - After processing the entire string, `va_end(arg)` is called to clean up the memory used by `va_list`.
   - The total number of characters printed is returned by `ft_printf`.

### **Example with ft_printi**
`ft_printi` is used to print integers (both positive and negative). Which can causes a problem: the string representation of an integer can vary in length. For example, the integer 42 is two characters long, while -42 is three characters long. In the function, `ft_itoa()` is used to convert an integer to string. Which is a useful fix for this problem.

1. First, we call the main function:
   ```c
	int	main(void)
	{
		int	i;

		i = -42;
		ft_printf("%i", i);
		return (0);
	}
   ```

2. `ft_printf` is then called:
   ```c
	#include "ft_printf.h"

	int	flags(va_list arg, char s)
	{
		int	count;

		count = 0;
		if (s == 'c')
			count = count + ft_printc(va_arg(arg, int));
		else if (s == 's')
			count = count + ft_prints(va_arg(arg, char *));
		else if (s == 'p')
			count = count + ft_printp(va_arg(arg, void *));
		else if (s == 'd')
			count = count + ft_printd(va_arg(arg, int));
		else if (s == 'i')
			count = count + ft_printi(va_arg(arg, int));
		else if (s == 'u')
			count = count + ft_printu(va_arg(arg, unsigned int));
		else if (s == 'x')
			count = count + ft_printx(va_arg(arg, unsigned int));
		else if (s == 'X')
			count = count + ft_print88(va_arg(arg, unsigned int));
		else if (s == '%')
			count = count + ft_printc('%');
		else
			return (-1);
		return (count);
	}

	int	ft_printf(const char *str, ...)
	{
		int	i;
		int	count;

		va_list(arg);
		va_start(arg, str);
		i = 0;
		count = 0;
		if (!str)
			return (-1);
		while (str[i] != '\0')
		{
			if (str[i] == '%')
			{
				i++;
				count = count + flags(arg, str[i]);
			}
			else
			{
				write(1, &str[i], 1);
				count++;
			}
			i++;
		}
		va_end(arg);
		return (count);
	}
   ```

3. Then, flags() identified which function to call:
   ```c
	#include "ft_printf.h"

	int	ft_printi(int a)
	{
		int		i;
		char	*str;
		int		len;

		i = 0;
		str = ft_itoa(a);
		len = ft_strlen(str);
		if (str != NULL)
		{
			while (str[i] != '\0')
			{
				write(1, &str[i], 1);
				i++;
			}
			free(str);
		}
		return (len);
	}
   ```

4. In ft_printi, we call ft_itoa and ft_strlen:
   ```c
	#include "ft_printf.h"

	int	temp_n(int n)
	{
		int	num_digits;

		if (n == 0)
			return (1);
		num_digits = 0;
		while (n != 0)
		{
			n /= 10;
			num_digits++;
		}
		return (num_digits);
	}

	char	*ft_itoa(int n)
	{
		int		num_digits;
		int		is_negative;
		int		i;
		char	*str;

		num_digits = temp_n(n);
		is_negative = (n < 0);
		i = num_digits + is_negative;
		str = (char *)malloc((i + 1) * sizeof(char));
		if (!str)
			return (NULL);
		if (n == 0)
			return (str[0] = '0', str[1] = '\0', str);
		if (is_negative)
			str[0] = '-';
		str[i] = '\0';
		while (n != 0)
		{
			if (is_negative)
				str[--i] = -(n % 10) + '0';
			else
				str[--i] = (n % 10) + '0';
			n /= 10;
		}
		return (str);
	}
   ```

5. The output is -42
