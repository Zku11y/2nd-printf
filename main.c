#include <stdio.h>
#include "ft_printf/ft_printf.h"

int main()
{
	printf("int = %+d \n", -45);
	ft_printf("int = %+d \n", -45);
}