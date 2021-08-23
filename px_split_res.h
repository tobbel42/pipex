/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_split_res.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:20:18 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 12:01:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PX_SPLIT_RES_H
# define PX_SPLIT_RES_H

void	quote_skip(char const *s, int *i);
int		find_subs(char const *s, char c);
int		unwind(char **ptr_tab, int n);
int		fill_tab(char **ptr_tab, char *ptr, char c, int n_subs);

#endif