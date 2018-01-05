/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:12:35 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/11 18:03:11 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c >= 65 && 90 >= c) || (c >= 97 && c <= 122) || (c >= 48 && 57 >= c))
		return (1);
	return (0);
}
