/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:49 by rkurnava          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:19 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_binary(int b)
{
	static int	bits;
	static int	bitnum;

	if (SIGUSR2 == b)
		bitnum |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		write(1, &bitnum, 1);
		bitnum = 0;
		bits = 0;
	}
}

static void	ft_nbr(int pid)
{
	char	c;

	if (pid < 10)
	{
		c = pid + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_nbr(pid / 10);
		ft_nbr(pid % 10);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_nbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_binary);
		signal(SIGUSR2, ft_binary);
		pause();
	}
}
