
void	ft_dati_certi_col_up(char **matrice, char *dati_in, int row)
{
	int col;

	col = 0;
	if (dati_in[row] == '1')
		matrice[0][row] = '4';
	else if (dati_in[row] == '4')
	{
		while (col < 4)
		{
			matrice[col][row] = col + 1 + '0';
			col++;
		}
	}
	else if (dati_in[row] == '2' && dati_in[row + 4] == '1')
		matrice[0][row] = '3';
	else if (dati_in[row] == '3' && dati_in[row + 4] == '2')
		matrice[2][row] = '4';
}

void	ft_dati_certi_col_down(char **matrice, char *dati_in, int row)
{
	int col;

	col = 0;
	if (dati_in[row] == '1')
		matrice[3][row - 4] = '4';
	else if (dati_in[row] == '4')
	{
		while (col < 4)
		{
			matrice[col][row - 4] = 4 - col + '0';
			col++;
		}
	}
	else if (dati_in[row] == '2' && dati_in[row - 4] == '1')
		matrice[3][row - 4] = '3';
	else if (dati_in[row] == '3' && dati_in[row - 4] == '2')
		matrice[1][row - 4] = '4';
}

void	ft_dati_certi_row_left(char **matrice, char *dati_in, int row)
{
	int col;

	col = 0;
	if (dati_in[row] == '1')
		matrice[row - 8][0] = '4';
	else if (dati_in[row] == '4')
	{
		while (col < 4)
		{
			matrice[row - 8][col] = col + 1 + '0';
			col++;
		}
	}
	else if (dati_in[row] == '2' && dati_in[row + 4] == '1')
		matrice[row - 8][0] = '3';
	else if (dati_in[row] == '3' && dati_in[row + 4] == '2')
		matrice[row - 8][2] = '4';
}

void	ft_dati_certi_row_right(char **matrice, char *dati_in, int row)
{
	int col;

	col = 0;
	if (dati_in[row] == '1')
		matrice[row - 12][3] = '4';
	else if (dati_in[row] == '4')
	{
		while (col < 4)
		{
			matrice[row - 12][col] = 4 - col + '0';
			col++;
		}
	}
	else if (dati_in[row] == '2' && dati_in[row - 4] == '1')
		matrice[row - 12][3] = '3';
	else if (dati_in[row] == '3' && dati_in[row - 4] == '2')
		matrice[row - 12][1] = '4';
}

void	ft_dati_certi(char **matrice, char *dati_in)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			ft_dati_certi_col_up(matrice, dati_in, i);
		else if (i >= 4 && i < 8)
			ft_dati_certi_col_down(matrice, dati_in, i);
		else if (i >= 8 && i < 12)
			ft_dati_certi_row_left(matrice, dati_in, i);
		else
			ft_dati_certi_row_right(matrice, dati_in, i);
		i++;
	}
}
