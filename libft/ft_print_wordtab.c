/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wordtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:31:00 by wrhett            #+#    #+#             */
/*   Updated: 2020/06/09 23:14:23 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_wordtab(char **argv)
{
	int n;

	n = 0;
	while (*(argv + n) != NULL)
	{
		ft_putstr(*(argv + n));
		ft_putchar('\n');
		n += 1;
	}
}
