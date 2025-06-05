#include "../includes/cub3d.h"

int error_check_playerdup(t_game *game)
{
    if (check_playerdup(game))
    {
        free_map(game);
        return (1);
    }
    return (0);
}

int is_mapline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != 'N' && line[i] != 'W' && line[i] != 'E' && line[i] != 'S' && line[i] != '1' && line[i] != '0' && line[i] != '\r')
            return (0);
        i++;
    }
    return (1);
}
int is_mapber(char *filename)
{
    int len;

    if (!filename)
    {
        ft_printf("Filename is NULL\n");
        return (0);
    }
    len = ft_strlen(filename);
    if (filename[len - 3] == 'c' &&
        filename[len - 2] == 'u' &&
        filename[len - 1] == 'b')
    {
        return (1);
    }
    ft_printf("Filename does not have .cub extension\n");
    return (0);
}

void free_map(t_game *game)
{
    int i;

    i = 0;

    if (!game || !game->map)
        return;
    while (game->map[i])
    {
        free(game->map[i]);
        game->map[i] = NULL;
        i++;
    }
    free(game->map);
}
int check_playerdup(t_game *game)
{
    int i = 0;
    int j;
    int player_count = 0;

    while (game->map[i] && !is_mapline(game->map[i]))
        i++;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (ft_strchr("NESW", game->map[i][j]))
                player_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1)
        return (ft_printf("Error: Player Count must be 1\n"), 1);
    return (0);
}
