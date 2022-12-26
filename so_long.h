/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:37:11 by ale-cont          #+#    #+#             */
/*   Updated: 2022/12/26 19:16:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# if defined(__APPLE__) && defined(__MACH__)
#  include "mlx/mlx.h"
# else
#  include "mlx_linux/mlx.h"
# endif

# include "libft/libft.h"

#endif