/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnakamur <fnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:39:23 by fnakamur          #+#    #+#             */
/*   Updated: 2025/05/18 23:08:38 by fnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	print_array(int array[], int arrsize)
{
	int	i;

	i = -1;
	printf("[");
	while (++i < arrsize)
	{
		printf("%d", array[i]);
		if (i < arrsize - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");
	return (i);
}

char	*get_args(int argc, char *argv[])
{
	char	*args;
	char	*args_tmp;
	int		argi;
	int		j;
	char	**strs;

	args = ft_strdup("");
	argi = 0;
	while (++argi < argc)
	{
		strs = ft_split(argv[argi], ' ');
		if (!strs)
			return (exit(1), NULL);
		j = -1;
		while (strs[++j])
		{
			args_tmp = args;
			args = ft_strjoin(args_tmp, strs[j]);
			free(args_tmp);
			if (strs[j + 1])
			{
				args_tmp = args;
				args = ft_strjoin(args_tmp, " ");
				free(args_tmp);
			}
			free(strs[j]);
		}
		if (argi < argc - 1)
		{
			args_tmp = args;
			args = ft_strjoin(args_tmp, " ");
			free(args_tmp);
		}
		free(strs);
	}
	return (args);
}

int	main(int argc, char *argv[])
{
	char	*args;
	int		*intarr;
	int		arrsize;

	if (argc < 1)
	{
		return (EXIT_SUCCESS);
	}
	args = get_args(argc, argv);
	arrsize = parse_int_array(args, &intarr);
	if (arrsize <= 0)
		return (EXIT_FAILURE);
	if (push_swap(intarr, arrsize) != 0)
		return (free(args), free(intarr), EXIT_FAILURE);
	return (free(args), free(intarr), EXIT_SUCCESS);
}
