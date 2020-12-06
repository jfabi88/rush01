
int		check(char **matrice, char dati_in[16]);
int		solve(char **matrice, int row, int col, char dati_in[16]);

int		is_safe(char **matrice, int col, int row, char n)
{
	int cont;

	cont = 0;
	while (cont < 4)
	{
		if (matrice[row][cont] == n)
			return (0);
		cont++;
	}
	cont = 0;
	while (cont < 4)
	{
		if (matrice[cont][col] == n)
			return (0);
		cont++;
	}
	return (1);
}

int		solve_1(char **matrice, int row, int col, char dati_in[16])
{
	int i;

	i = '1';
	while (i <= '4')
	{
		if (is_safe(matrice, col, row, i) != 0)
		{
			if (is_safe(matrice, col, row, i) == 1)
				matrice[row][col] = i;
			if (solve(matrice, row, col + 1, dati_in) == 1)
				return (1);
		}
		matrice[row][col] = '0';
		i++;
	}
	return (0);
}

int		solve(char **matrice, int row, int col, char dati_in[16])
{
	if (row == 3 && col == 4)
	{
		if (check(matrice, dati_in) == 0)
			return (0);
		return (1);
	}
	if (col == 4)
	{
		row++;
		col = 0;
	}
	if (matrice[row][col] != '0')
		return (solve(matrice, row, col + 1, dati_in));
	return (solve_1(matrice, row, col, dati_in));
}

