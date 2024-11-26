#include <stdio.h>
#include "ft_printf_bonus/ft_printf_bonus.h"

int main()
{
	printf("int = %+d \n", 45);
	ft_printf("int = %++++d \n", 45);
}