/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputri-a <aputri-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:13:13 by aputri-a          #+#    #+#             */
/*   Updated: 2024/10/25 16:11:33 by aputri-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	setup(t_display *dsp)
{
	dsp->window = mlx_new_window(dsp->mlx, SIZE * dsp->map.cols,
			SIZE * dsp->map.rows, "so_long_bonus");
	if (!dsp->window)
		exit_program(dsp, 1);
	dsp->block = load_img(dsp, "./textures/xpm/block.xpm");
	dsp->gate = load_img(dsp, "./textures/xpm/gate.xpm");
	dsp->key = load_img(dsp, "./textures/xpm/key.xpm");
	dsp->bg = load_img(dsp, "./textures/xpm/bg.xpm");
	dsp->lightkey = load_img(dsp, "./textures/xpm/lightkey.xpm");
	dsp->camo = load_img(dsp, "./textures/xpm/camo.xpm");
	dsp->camolight = load_img(dsp, "./textures/xpm/camolight.xpm");
	dsp->light = load_img(dsp, "./textures/xpm/light.xpm");
	setup_char_idle(dsp);
	setup_char_move(dsp);
}

void	setup_char_idle(t_display *dsp)
{
	dsp->cat[0][0] = load_img(dsp, "./textures/xpm/char/idle/idle1.xpm");
	dsp->cat[0][1] = load_img(dsp, "./textures/xpm/char/idle/idle2.xpm");
	dsp->cat[0][2] = load_img(dsp, "./textures/xpm/char/idle/idle3.xpm");
	dsp->cat[0][3] = load_img(dsp, "./textures/xpm/char/idle/idle4.xpm");
	dsp->cat[0][4] = load_img(dsp, "./textures/xpm/char/idle/idle5.xpm");
	dsp->cat[0][5] = load_img(dsp, "./textures/xpm/char/idle/idle6.xpm");
	dsp->cat[0][6] = load_img(dsp, "./textures/xpm/char/idle/idle7.xpm");
	dsp->cat[0][7] = load_img(dsp, "./textures/xpm/char/idle/idle8.xpm");
}

void	setup_char_move(t_display *dsp)
{
	dsp->cat[1][0] = load_img(dsp, "./textures/xpm/char/right/right1.xpm");
	dsp->cat[1][1] = load_img(dsp, "./textures/xpm/char/right/right2.xpm");
	dsp->cat[1][2] = load_img(dsp, "./textures/xpm/char/right/right3.xpm");
	dsp->cat[1][3] = load_img(dsp, "./textures/xpm/char/right/right4.xpm");
	dsp->cat[1][4] = load_img(dsp, "./textures/xpm/char/right/right5.xpm");
	dsp->cat[2][0] = load_img(dsp, "./textures/xpm/char/left/left1.xpm");
	dsp->cat[2][1] = load_img(dsp, "./textures/xpm/char/left/left2.xpm");
	dsp->cat[2][2] = load_img(dsp, "./textures/xpm/char/left/left3.xpm");
	dsp->cat[2][3] = load_img(dsp, "./textures/xpm/char/left/left4.xpm");
	dsp->cat[2][4] = load_img(dsp, "./textures/xpm/char/left/left5.xpm");
	dsp->cat[3][0] = load_img(dsp, "./textures/xpm/char/up/up1.xpm");
	dsp->cat[3][1] = load_img(dsp, "./textures/xpm/char/up/up2.xpm");
	dsp->cat[3][2] = load_img(dsp, "./textures/xpm/char/up/up3.xpm");
	dsp->cat[3][3] = load_img(dsp, "./textures/xpm/char/up/up4.xpm");
	dsp->cat[4][0] = load_img(dsp, "./textures/xpm/char/down/down1.xpm");
	dsp->cat[4][1] = load_img(dsp, "./textures/xpm/char/down/down2.xpm");
	dsp->cat[4][2] = load_img(dsp, "./textures/xpm/char/down/down3.xpm");
	dsp->cat[4][3] = load_img(dsp, "./textures/xpm/char/down/down4.xpm");
}
