#include "raycasting.h"

void textures_set(t_game *game)
{
    int endian;
    game->tex_width = 64;
    game->tex_height = 64;
    game->tex_so = mlx_xpm_file_to_image(game->mlx_ptr, "textures/SO.xpm",
                                         &game->tex_width, &game->tex_height);
    game->tex_no = mlx_xpm_file_to_image(game->mlx_ptr, "textures/NO.xpm",
                                         &game->tex_width, &game->tex_height);
    game->tex_ea = mlx_xpm_file_to_image(game->mlx_ptr, "textures/EA.xpm",
                                         &game->tex_width, &game->tex_height);
    game->tex_we = mlx_xpm_file_to_image(game->mlx_ptr, "textures/WE.xpm",
                                         &game->tex_width, &game->tex_height);
    
    game->tex_so_addr = mlx_get_data_addr(game->tex_so, &game->tex_bpp,
                                          &game->tex_line_len, &endian);
    game->tex_no_addr = mlx_get_data_addr(game->tex_no, &game->tex_bpp,
                                          &game->tex_line_len, &endian);
    game->tex_ea_addr = mlx_get_data_addr(game->tex_ea, &game->tex_bpp,
                                          &game->tex_line_len, &endian);
    game->tex_we_addr = mlx_get_data_addr(game->tex_we, &game->tex_bpp,
                                          &game->tex_line_len, &endian);
}
