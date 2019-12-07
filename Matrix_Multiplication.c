#include <stdio.h>
#include <stdlib.h>

int **mas1;
int **mas2;
int **mas3;
int i,j,n,m;
int a,b;

int main()
{
	printf("\n Enter n, m: \n");
	scanf("%d%d", &n, &m);

	mas1 = (int**)calloc(n, sizeof(int*)); //выделение памяти под первый двумерный массив
	for(i = 0; i < n; i++)
		mas1[i] = (int*)calloc(m, sizeof(int));
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++){
			printf("arr[%i %i]: ", i, j);
			scanf("%d", &mas1[i][j]);
		}

	printf("\n Enter a, b: \n");
	scanf("%d%d", &a, &b);

	mas2 = (int**)calloc(a, sizeof(int*)); //выделение памяти под второй двумерный массив
	for(i = 0; i < a; i++)
		mas2[i] = (int*)calloc(b, sizeof(int));
	for(i = 0; i < a; i++)
		for(j = 0; j < b; j++){
			printf("arr[%i %i]: ", i, j);
			scanf("%d", &mas2[i][j]);
		}



	if (m == a){
 		mas3 = (int**)calloc(n, sizeof(int*)); //выделение памяти под будущую перемноженную матрицу
 		for(i = 0; i < n; i++)
 			mas3[i] = (int*)calloc(b, sizeof(int));
		for (i = 0; i < n; i++){
			for (j = 0; j < b; j++){
				for (m = 0; m < a; m++){
					mas3[i][j] += mas1[i][m] * mas2[m][j];//вот здесь происходит перемножение
      			}
			}
		};
		printf("\n Massiv:\n");
		for(i = 0; i < n; i++){
			for(j = 0; j < b; j++)
				printf("%5d", mas3[i][j]);
			printf("\n");
		}
		printf("\n---— END —---\n");

		for (i = 0; i < n; i++)
			free(mas3[i]);
		free(mas3);
	} else {printf("Нельзя умножить эти 2 матрицы ;(\n");}; //по правилу матрица размером m на n можно умножить только на матрицу размером n на что-то


	for (i = 0; i < n; i++) //чистим память
		free(mas1[i]);
	free(mas1);
	for (i = 0; i < n; i++)
		free(mas2[i]);
	free(mas2);

	getchar();

	return 0;
}