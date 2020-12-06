
int		check_1(char **matrice, char dati_in[16], int i)
{
	char	max;
	char	view;
	int		j;

	view = '0';
	max = '0';
	j = 0;
	while (j < 4)
	{
		if (matrice[j][i] > max)
		{
			view++;
			max = matrice[j][i];
		}
		j++;
	}
	if (view == dati_in[i])
		return (1);
	return (0);
}

int		check_2(char **matrice, char dati_in[16], int i)
{
	char	max;
	char	view;
	int		j;

	view = '0';
	max = '0';
	j = 3;
	while (j > -1)
	{
		if (matrice[j][i - 4] > max)
		{
			view++;
			max = matrice[j][i - 4];
		}
		j--;
	}
	if (view == dati_in[i])
		return (1);
	return (0);
}

int		check_3(char **matrice, char dati_in[16], int i)
{
	char	max;
	char	view;
	int		j;

	view = '0';
	max = '0';
	j = 0;
	while (j < 4)
	{
		if (matrice[i - 8][j] > max)
		{
			view++;
			max = matrice[i - 8][j];
		}
		j++;
	}
	if (view == dati_in[i])
		return (1);
	return (0);
}

int		check_4(char **matrice, char dati_in[16], int i)
{
	char	max;
	char	view;
	int		j;

	max = '0';
	j = 3;
	view = '0';
	while (j > -1)
	{
		if (matrice[i - 12][j] > max)
		{
			view++;
			max = matrice[i - 12][j];
		}
		j--;
	}
	if (view == dati_in[i])
		return (1);
	return (0);
}

int		check(char **matrice, char dati_in[16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			if (check_1(matrice, dati_in, i) == 0)
				return (0);
		if (i >= 4 && i < 8)
			if (check_2(matrice, dati_in, i) == 0)
				return (0);
		if (i >= 8 && i < 12)
			if (check_3(matrice, dati_in, i) == 0)
				return (0);
		if (i >= 12 && i < 16)
			if (check_4(matrice, dati_in, i) == 0)
				return (0);
		i++;
	}
	return (1);
}
