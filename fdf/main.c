#include <stdio.h>
#include <math.h>
#include <stdlib.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

typedef struct s_pos {
  int x;
	int	y;
	int	z;
} t_pos;


void  print_matrix(double matrix_1[4][4], double matrix_2[4])
{
  int i;
  int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
    {
			printf("%f ", matrix_1[i][j++]);
		}
    printf("\n");
    i++;
	}
  i = 0;
  while (i < 4)
    printf("%f", matrix_2[i++]);
  printf("\n");
}

void  print_multiple_matrix(double matrix_1[4][4], double matrix_2[4])
{
  // matrix_2 * matrix_1
  int i;
  int j;
  double *matrix;

  matrix = malloc(4 * sizeof(double));
  i = 0;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      matrix[i] += matrix_2[j] * matrix_1[i][j];
      j++;
    }
    i++;
  }

  i = 0;
  while (i < 4)
    printf("%f", matrix[i++]);
  printf("\n");
  free(matrix);
}

int main()
{
	double	matrix_1[4][4] = {{1/sqrt(2), -1/sqrt(2), 0, 0},
                        {1/sqrt(6), 1/sqrt(6), 2/sqrt(6), 0},
                        {-1/sqrt(3), -1/sqrt(3), 1/sqrt(3), 0},
                        {0, 0, 0, 1}};
	double	matrix_2[4] = {1, 1, 1, 1};

  print_matrix(matrix_1, matrix_2);
  print_multiple_matrix(matrix_1, matrix_2);
}
