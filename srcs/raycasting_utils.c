/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:10 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/27 14:09:10 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	drawline(t_ptr *ptr, int x, int drawstart, int drawend, int color)
{
	/* drawing the line*/
	int	i;

	i = 0;
	while (i < drawstart)
	{
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x)] = (ptr->ceiling_color / RGB_RED);
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1] = (ptr->ceiling_color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2] = (ptr->ceiling_color % RGB_RED) % RGB_GREEN;
		i++;
	}
	while (i < drawend)
	{
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x)] = (color / RGB_RED);
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1] = (color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2] = (color % RGB_RED) % RGB_GREEN;
		i++;
	}



      //calculate value of wallX
    // double wallX; //where exactly the wall was hit
    // if (ptr->ray->side == 0)
	// 	wallX = ptr->player->posY + ptr->ray->perpWallDist * ptr->ray->raydirY;
    // else
	// 	wallX = ptr->player->posX + ptr->ray->perpWallDist * ptr->ray->raydirX;
    // wallX -= floor((wallX));

    //   //x coordinate on the texture
    // int texX = (int)(wallX * (double)(64));
    // if(ptr->ray->side == 0 && ptr->ray->raydirX > 0)
	// 	texX = 64 - texX - 1;
    // if(ptr->ray->side == 1 && ptr->ray->raydirY < 0)
	// 	texX = 64 - texX - 1;

    // // How much to increase the texture coordinate per screen pixel
	// int lineheight = (int)(WIN_WIDTH / ptr->ray->perpWallDist);
    // double step = 1.0 * 64 / lineheight;
    //   // Starting texture coordinate
    // double texPos = (drawstart - WIN_HEIGHT / 2 + lineheight / 2) * step;
	// int	y;
	// y = drawstart;
    // while (y < drawend)
    // {
    //     // Cast the texture coordinate to integer, and mask with (64 - 1) in case of overflow
    // 	int texY = (int)texPos & (64 - 1);
    //     texPos += step;
	// 	printf("bite = %d\n", 64 * texY + texX);
    //     int colour = ptr->dply.textures[0].data[64 * (texY + texX)];
    //     //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
    //     // if(side == 1)
	// 	// 	color = (color >> 1) & 8355711;
	// 	ptr->dply.screen->data[4 * (y * WIN_WIDTH + x)] = (colour / RGB_RED);
	// 	ptr->dply.screen->data[4 * (y * WIN_WIDTH + x) + 1] = (colour % RGB_RED) / RGB_GREEN;
	// 	ptr->dply.screen->data[4 * (y * WIN_WIDTH + x) + 2] = (colour % RGB_RED) % RGB_GREEN;
	// 	y++;
	// }
	/* printing the image, can be moved. used for debug purpose */
}
