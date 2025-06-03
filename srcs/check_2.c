#include "../includes/cub3d.h"

void free_mapcopy(char **map)
{
    int i;

    i = 0;

    if (!map)
        return ;
    while (map[i])
    {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
}

int find_playerpos(char **map, double *px, double *py)
{

	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				*px = j + 0.5;
				*py = i + 0.5;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
static int is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'L' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_surronded_by_valid(char **map, int y, int x)
{
	return (is_valid_map_char(map[y - 1][x])
		&& is_valid_map_char(map[y + 1][x])
		&& is_valid_map_char(map[y][x - 1])
		&& is_valid_map_char(map[y][x + 1]));
}

int flood_fill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '\n' || map[y][x] == '1' || map[y][x] == 'L')
		return (0);
	if ((map[y][x] == '0' || map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'N') 
			&& (y < 1 // ha 0 na primeira linha
			|| !map[y + 1] // ha 0 na ultima linha
			|| x < 1 // ha 0 na primeira coluna
			|| (!map[y][x + 1] || map[y][x + 1] == '\n') // ha 0 na ultima coluna
			|| !is_surronded_by_valid(map, y, x))) // o 0 nao esta rodeado de 0, F ou 1
		return (ft_printf("y: %d,x: %d\n", y, x), 1);
	map[y][x] = 'L';
	if (flood_fill(map, y + 1, x))
		return (1);
	if (flood_fill(map, y - 1, x))
		return (1);
	if (flood_fill(map, y, x + 1))
		return (1);
	if (flood_fill(map,y,x - 1))
		return (1);
	return (0);
} 