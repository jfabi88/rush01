#include <unistd.h>
#include <stdlib.h>

int		ft_pulizia_dati(char *dati_in, char *dati_out, char **out);
void	ft_dati_certi(char **matrice, char *dati_in);
int		solve(char **matrice, int row, int col, char dati_in[16]);
void	ft_print(char **matrice);

int		main(int argc, char **argv)
{
	char	dati_ok[16];
	char	**out;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	out = (char **)malloc(4 * sizeof(char *));
	if (ft_pulizia_dati(argv[1], dati_ok, out))
	{
		ft_dati_certi(out, dati_ok);
		if (solve(out, 0, 0, dati_ok) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_print(out);
}