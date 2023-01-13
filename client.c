/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:41:48 by rkurnava          #+#    #+#             */
/*   Updated: 2023/01/13 19:03:13 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned char	*ostr;
	long			result;

	ostr = (unsigned char *)str;
	i = 0;
	result = 0;
	if (ostr[i] <= '9' && ostr[i] >= '0')
	{
		while (ostr[i] <= '9' && ostr[i] >= '0')
			result = (result * 10) + (ostr[i++] - '0');
	}
	else
	{
		write(1, "Wrong PID format!\n", 18);
		return (-1);
	}
	return (result);
}

static int	ft_sendbite(char *message, int pid)
{
	int	i;
	int	bits;
	int	c;

	i = -1;
	while (message[++i])
	{
		bits = -1;
		c = message[i];
		while (++bits < 8)
		{
			if ((c >> bits) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					return (1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					return (1);
			}
			usleep(100);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
	{
		write(1, "Missing PID or message or both\n", 30);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (0);
	else
	{
		if (ft_sendbite(argv[2], pid) == 1)
		{
			write(1, "Error while sending the message!\n", 32);
			return (0);
		}
		ft_sendbite("\n", pid);
	}
	return (0);
}
