#include "ft_printf.h"
#include "stdio.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int	main()
{
	char			*name;
	void			*pointer;
	int				number;
	int				negative_number;
	unsigned int	unsigned_number;
	unsigned int	hexalower;
	int				charac;


	pointer = "dahora";
	name = "Eduardo";
	number = 20;
	negative_number = -89;
	unsigned_number = 8516000;
	hexalower = 2133213;
	charac = 69;

	ft_printf(ANSI_COLOR_RED "TYPE CHAR\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: a inicial do meu nome é o %c \n", charac);
	printf("printf: a inicial do meu nome é o %c \n", charac);

	ft_printf(ANSI_COLOR_RED "TYPE STRING\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: meu nome é %s \n", name);
	printf(" printf: meu nome é %s \n", name);

	ft_printf(ANSI_COLOR_RED "TYPE POINTER\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: o endereco é %p \n", pointer);
	printf(" printf: o endereco é %p \n", pointer);

	ft_printf(ANSI_COLOR_RED "TYPE DECIMAL\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: tenho %d anos de idade\n", number);
	printf(" printf: tenho %d anos de idade \n", number);

	ft_printf(ANSI_COLOR_RED "TYPE INTEGER\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: tenho %i de QI\n", negative_number);
	printf("printf: tenho %i de QI \n", negative_number);

	ft_printf(ANSI_COLOR_RED "TYPE UNSIGNED DECIMAL\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: o brasil tem %u km2\n", unsigned_number);
	printf("printf: o brasil tem %u km2\n", unsigned_number);

	ft_printf(ANSI_COLOR_RED "TYPE HEXA LOWERCASE\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: o hexa em lowercase é %x \n", hexalower);
	printf("printf: o hexa em lowercase é %x \n", hexalower);

	ft_printf(ANSI_COLOR_RED "TYPE HEXA UPPERCASE\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: o hexa em uppercase é %X \n", hexalower);
	printf("printf: o hexa em uppercase é %X \n", hexalower);

	ft_printf(ANSI_COLOR_RED "TYPE PERCENT SIGN\n" ANSI_COLOR_RESET);
	ft_printf("ft_printf: %% \n");
	printf("printf: %% \n");
	return(0);
}
