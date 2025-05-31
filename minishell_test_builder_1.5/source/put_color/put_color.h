#ifndef PUT_COLOR_H
# define PUT_COLOR_H
# include <stdbool.h>

# define RED "31"
# define RED_BG "41"

# define GRN "32"
# define GRN_BG "42"

# define PUR "35"
# define PUR_BG "45"

# define BLU "34"
# define BLU_BG "44"

# define WHITE_BG "47"

# define END "\e[0m"

# define TURQ "36"
# define TURQ_BG "46"

void	put_color(char *color, bool bold, char *str);
#endif
