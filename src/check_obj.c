/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:37:56 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 22:10:59 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	check_element(t_item *data, char **tab, int check)
{
	if (check == AMB)
	{
		if (data->nb_amb++ != 0)
			ft_error(data, E1007);
		return (ft_check_a(data, tab));
	}
	else if (check == CAM)
	{
		if (data->nb_cam++ != 0)
			ft_error(data, E1006);
		return (ft_check_c(data, tab));
	}
	else if (check == LIG)
	{
		if (data->nb_spt++ != 0)
			ft_error(data, E1008);
		return (ft_check_l(data, tab));
	}
	else if (check == SPH)
		return (ft_check_sp(data, tab));
	else if (check == PLA)
		return (ft_check_pl(data, tab));
	else if (check == CYL)
		return (ft_check_cy(data, tab));
	return (0);
}

void	ft_input(t_item *data, int indice, char *str)
{
	if (indice == AMB)
		ft_a_input(data, str);
	else if (indice == CAM)
		ft_c_input(data, str);
	else if (indice == LIG)
		ft_l_input(data, str);
	else if (indice == SPH)
		ft_sp_input(data, str);
	else if (indice == PLA)
		ft_pl_input(data, str);
	else if (indice == CYL)
		ft_cy_input(data, str);
}

void	check_data(t_item *data, char **tab)
{
	if (ft_strnstr("A", tab[0], 2))
		data->parsing.check = AMB;
	else if (ft_strnstr("C", tab[0], 2))
		data->parsing.check = CAM;
	else if (ft_strnstr("L", tab[0], 2))
		data->parsing.check = LIG;
	else if (ft_strnstr("sp", tab[0], 3))
		data->parsing.check = SPH;
	else if (ft_strnstr("pl", tab[0], 3))
		data->parsing.check = PLA;
	else if (ft_strnstr("cy", tab[0], 3))
		data->parsing.check = CYL;
	else
		data->parsing.check = 0;
}
