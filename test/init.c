#include <stdlib.h>

void	ft_zero(char **matrice)
{
	int i;
	int j;

	i = 0;
	j = 0;
	matrice[0] = malloc(5 * sizeof(char));
	matrice[1] = malloc(5 * sizeof(char));
	matrice[2] = malloc(5 * sizeof(char));
	matrice[3] = malloc(5 * sizeof(char));
	while (i < 4)
	{
		while (j < 4)
		{
			matrice[i][j] = '0';
			j++;
		}
		matrice[i][j] = '\0';
		j = 0;
		i++;
	}
}

int		ft_pulizia_dati(char *dati_in, char *dati_out, char **out)
{
	int i;
	int i_2;

	i = 0;
	i_2 = 0;
	ft_zero(out);
	while (dati_in[i])
	{
		if (i % 2 == 0 && (dati_in[i] < '1' || dati_in[i] > '4'))
			return (0);
		else if (dati_in[i] == ' ')
			i++;
		else if (dati_in[i] < '1' || dati_in[i] > '4')
			return (0);
		else
		{
			dati_out[i_2] = dati_in[i];
			i++;
			i_2++;
		}
	}
	if (i != 31)
		return (0);
	else
		return (1);
}

