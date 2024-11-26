#include <stdio.h>
// #include <limits.h>
#include "ft_printf.h"
// int main()
// {
// 	int integer = 42;
// 	unsigned int unsigned_integer = 42;
// 	char character = 'A';
// 	char *string = "Hello, World!";
// 	int *ptr = NULL;
// 	unsigned int hex_number = 255;
// 	int negative_integer = -42;
// 	unsigned int large_unsigned_integer = UINT_MAX;
// 	int large_integer = INT_MAX;
// 	int small_integer = INT_MIN;

// 	// Testing integer
// 	ft_printf("Integer: %d\n", integer);
// 	ft_printf("Integer: %i\n", integer);
// 	ft_printf("Negative Integer: %d\n", negative_integer);
// 	ft_printf("Large Integer: %d\n", large_integer);
// 	ft_printf("Small Integer: %d\n", small_integer);

// 	// Testing character
// 	ft_printf("Character: %c\n", character);

// 	// Testing string
// 	ft_printf("String: %s\n", string);
// 	ft_printf("Empty String: %s\n", "");

// 	// Testing hexadecimal (lowercase)
// 	ft_printf("Hexadecimal (lowercase): %x\n", hex_number);
// 	ft_printf("Large Hexadecimal (lowercase): %x\n", large_unsigned_integer);

// 	// Testing hexadecimal (uppercase)
// 	ft_printf("Hexadecimal (uppercase): %X\n", hex_number);
// 	ft_printf("Large Hexadecimal (uppercase): %X\n", large_unsigned_integer);

// 	// Testing pointer address
// 	ft_printf("Pointer address: %p\n", (void *)ptr);
// 	ft_printf("Pointer address: %p\n", (void *)&integer);

// 	// Testing unsigned integer
// 	ft_printf("Unsigned Integer: %u\n", unsigned_integer);
// 	ft_printf("Large Unsigned Integer: %u\n", large_unsigned_integer);

// 	// Testing percent sign
// 	ft_printf("Percent: %%\n");

// 	// Testing mixed formats
// 	ft_printf("Mixed formats: %d %c %s %x %X %p %u %%\n", integer, character, string, hex_number, hex_number, (void *)ptr, unsigned_integer);

// 	// Testing edge cases
// 	ft_printf("Edge case - Zero: %d\n", 0);
// 	ft_printf("Edge case - Zero Hex: %x\n", 0);
// 	ft_printf("Edge case - Zero Pointer: %p\n", (void *)0);

// 	return 0;
// }

//=========output============
// Integer: 42
// Integer: 42
// Negative Integer: -42
// Large Integer: 2147483647
// Small Integer: -2147483648
// Character: A
// String: Hello, World!
// Empty String:
// Hexadecimal (lowercase): ff
// Large Hexadecimal (lowercase): ffffffff
// Hexadecimal (uppercase): FF
// Large Hexadecimal (uppercase): FFFFFFFF
// Pointer address: 0x0
// Pointer address: 0x<address_of_integer>
// Unsigned Integer: 42
// Large Unsigned Integer: 4294967295
// Percent: %
// Mixed formats: 42 A Hello, World! ff FF 0x0 42 %
// Edge case - Zero: 0
// Edge case - Zero Hex: 0
// Edge case - Zero Pointer: 0x0

#include <stdio.h>
int main()
{
	ft_printf("%\n");
}