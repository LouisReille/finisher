/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_min_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:50:18 by cdescour          #+#    #+#             */
/*   Updated: 2023/03/21 22:07:09 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	ft_check_sp(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 4)
		ft_error(data, SP1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, SP1002);
	else if (check_double(tab[2]) == 0 || ft_atod(tab[2]) < 0)
		ft_error(data, SP1003);
	else if (check_rgb(tab[3]) == 0)
		ft_error(data, SP1004);
	return (SPH);
}

int	ft_check_pl(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 4)
		ft_error(data, PL1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, PL1002);
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, PL1003);
	else if (check_rgb(tab[3]) == 0)
		ft_error(data, PL1004);
	return (PLA);
}

int	ft_check_cy(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 6)
		ft_error(data, CY1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, CY1002);
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, CY1003);
	else if (check_double(tab[3]) == 0 || ft_atod(tab[3]) < 0)
		ft_error(data, CY1004);
	else if (check_double(tab[4]) == 0 || ft_atod(tab[4]) < 0)
		ft_error(data, CY1005);
	else if (check_rgb(tab[5]) == 0)
		ft_error(data, CY1006);
	return (CYL);
}
