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

static uint32_t	get_pixel_value(int tex_x, int tex_y, t_dda *dda, int tex_num)
{
	uint8_t	*pixel_data;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	pixel_data = dda->t[tex_num]->pixels;
	r = pixel_data[(tex_y * dda->t[tex_num]->width + tex_x) * 4];
	g = pixel_data[(tex_y * dda->t[tex_num]->width + tex_x) * 4 + 1];
	b = pixel_data[(tex_y * dda->t[tex_num]->width + tex_x) * 4 + 2];
	a = pixel_data[(tex_y * dda->t[tex_num]->width + tex_x) * 4 + 3];
	return (pixel_select(r, g, b, a));
}

static t_coors_int	get_tex_x(t_dda *dda, int tex_num)
{
	double		wall_x;
	t_coors_int	tex;

	if (dda->current_side == X_SIDE)
		wall_x = dda->player_pos.y + dda->perp_wall_dist * dda->ray_dir.y;
	else
		wall_x = dda->player_pos.x + dda->perp_wall_dist * dda->ray_dir.x;
	wall_x -= (floor(wall_x));
	tex.x = (int)(wall_x * dda->t[tex_num]->width);
	if (tex_num == S_INDEX || tex_num == W_INDEX)
		tex.x = dda->t[tex_num]->width - tex.x - 1;
	return (tex);
}

static void	fill_buffer_texture(uint32_t **buffer, t_dda *dda, int x, int tex_num)
{
	t_coors_int	tex;
	double		step;
	double		tex_pos;
	int			y;

	tex = get_tex_x(dda, tex_num);
	step = 1.0 * (dda->t[tex_num]->height) / dda->line.h;
	tex_pos = 0;
	y = dda->line.start;
	while (y < 0)
	{
		tex_pos += step;
		y++;
	}
	while (y < SCR_HEIGHT && y <= dda->line.end)
	{
		tex.y = ((int)tex_pos) & ((dda->t[tex_num]->height) - 1);
		tex_pos += step;
		buffer[y][x] = get_pixel_value(tex.x, tex.y, dda, tex_num);
		y++;
	}
}

static int	get_tex_num(t_dda *dda)
{
	if (dda->current_side == X_SIDE && dda->ray_dir.x < 0)
		return (W_INDEX);
	else if (dda->current_side == X_SIDE && dda->ray_dir.x > 0)
		return (E_INDEX);
	else if (dda->current_side == Y_SIDE && dda->ray_dir.y < 0)
		return (N_INDEX);
	else
		return (S_INDEX);
}

void	textures(uint32_t **buffer, t_dda *dda, int x)
{
	int		tex_num;

	tex_num = get_tex_num(dda);
	fill_buffer_texture(buffer, dda, x, tex_num);
}
