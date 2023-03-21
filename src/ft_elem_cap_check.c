/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem_cap_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:01:28 by lreille           #+#    #+#             */
/*   Updated: 2023/03/21 22:14:50 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minirt.h"

int	ft_check_a(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 3)
		ft_error(data, A1001);
	if (check_double(tab[1]) == 0 || \
		(ft_atod(tab[1]) < 0 || ft_atod(tab[1]) > 1))
		ft_error(data, A1002);
	else if (check_rgb(tab[2]) == 0)
		ft_error(data, A1003);
	if (data->parsing.a == 1)
		ft_error(data, A1004);
	return (AMB);
}

int	ft_check_l(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 3)
		ft_error(data, L1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, L1002);
	else if (check_double(tab[2]) == 0 || \
			(ft_atod(tab[2]) < 0 || ft_atod(tab[2]) > 1))
		ft_error(data, L1003);
	return (LIG);
}

int	ft_check_c(t_item *data, char **tab)
{
	if (ft_dbltablen(tab) != 4)
		ft_error(data, C1001);
	if (check_pos(tab[1]) == 0)
		ft_error(data, C1002);
	else if (check_vec_ort(tab[2]) == 0)
		ft_error(data, C1003);
	else if (check_double(tab[3]) == 0 || \
			(ft_atod(tab[3]) < 0 || ft_atod(tab[3]) > 180))
		ft_error(data, C1004);
	return (CAM);
}
