/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 18:36:58 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 18:36:58 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_buffer_texture(uint32_t **buffer, t_dda *dda, int x, int n, int texX)
{
	double step = 1.0 * (dda->t[n]->height) / dda->line.h;
	double texPos = (dda->line.start - SCR_HEIGHT / 2 + dda->line.h / 2) * step;
	int y = dda->line.start;
	while(y < dda->line.end)
	{
		int texY = ((int)texPos) & ((dda->t[n]->height) - 1);
		texPos += step;
		uint8_t* pixelData = dda->t[n]->pixels;
		uint8_t r = pixelData[(texY * dda->t[n]->width + texX) * 4];
		uint8_t g = pixelData[(texY * dda->t[n]->width + texX) * 4 + 1];
		uint8_t b = pixelData[(texY * dda->t[n]->width + texX) * 4 + 2];
		uint8_t a = pixelData[(texY * dda->t[n]->width + texX) * 4 + 3];
		uint32_t color = pixel_select(r, g, b, a);
		buffer[y][x] = color;
		y++;
	}
}

void	textures(uint32_t **buffer, t_dda *dda, int x)
{
	int n = 0;
	int texX = 0;
	double wallX = 0;
	if (dda->current_side == X_SIDE && dda->ray_dir.x < 0)
		n = W_INDEX;
	if (dda->current_side == X_SIDE && dda->ray_dir.x > 0)
		n = E_INDEX;
	if (dda->current_side == Y_SIDE && dda->ray_dir.y < 0)
		n = N_INDEX;
	if (dda->current_side == Y_SIDE && dda->ray_dir.y > 0)
		n = S_INDEX;
	if (dda->current_side == X_SIDE)
		wallX = dda->player_pos.y + dda->perp_wall_dist * dda->ray_dir.y;
	else
		wallX = dda->player_pos.x + dda->perp_wall_dist * dda->ray_dir.x;
	wallX -= (floor(wallX));
	texX = (int)(wallX * dda->t[n]->width);
	fill_buffer_texture(buffer, dda, x, n, texX);
}
