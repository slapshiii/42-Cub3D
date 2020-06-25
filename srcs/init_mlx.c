
#include "parser_param.h"
#include "get_next_line.h"
#include "cub3d.h"
#include <mlx.h>

int init_mlx(game_t *g)
{
    if ((g->mlx_ptr = mlx_init()) == NULL)
        return (1);
    return (0);
}
