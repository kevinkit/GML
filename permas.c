#include <stdlib.h>
#include <stdio.h>


int main()
{

//seeed
	time_t t;
	srand((unsigned) time(&t));
	

	printf("At least the compiler worked....\n");

	int i,j,zeile,spalte;
	/* Matrix ist zeiger auf int-Zeiger*/

	int **matrix;
/*	printf("Anzahl der Zeilen: ?\n");
	scanf("%d", &zeile);
	printf("Anzahl der spalten: ?\n");
	scanf("%d",&spalte);
*/

	zeile = 10;
	spalte = zeile;

	matrix = (int**) malloc(zeile*sizeof(int*));

	if(NULL == matrix)
	{
		printf("Nicht ausreichend Speicher verfügbar \n");
		exit(0);
	}

	//Speicher reservien
	for(i=0;i < zeile;i++)
	{
		matrix[i] = (int*) malloc(spalte*sizeof(int));
		if(NULL == matrix[i])
		{
			printf("nicht ausreichend Speicher vorhanden!\n");
			exit(0);
		}
	}

	//mit werten füllen
	for(i=0; i < zeile; i++)
	{
		for(j = 0; j < spalte; j++)
		{
			matrix[i][j] = rand() %100;
		}

	}

	printf("\n");
	//werte ausgeben
	for(i=0; i < zeile; i++)
	{
		for(j = 0; j < spalte; j++)
		{
			printf("%d\t",matrix[i][j]);
	
		}
		printf("\n");
	}
		

	int sum = 0;
	printf("Diagonale ausgeben: \n");
	//nur die diagonale ausgeben
	for(i=0; i < zeile; i++)
	{
//		printf("%d.Zeile",i);
		//in jeder zeile muss ein wert in der spalte weiter gesprungen werden
		printf("%d\t",matrix[i][i]);
		sum += matrix[i][i];
	
	}

	printf("\n Die Summe der Diagonale ist %d\n",sum);



	//ohne permute funktion erstmal..
	int first_permute[10]  = {0,1,2,3,4,5,6,7,8,9};
	int second_permute[10] = {0,2,1,3,5,6,9,8,7,4};
	int third_permute[10]  = {8,5,4,3,1,2,9,7,6,9};
	int sum_vec[3]         = {0,0,0};
	
	//sollte gleich sein wie die obere ausgabe
	//first permute
	printf("sollte gleich aussehen wie oben\n");
	for(i=0; i < zeile; i++)
	{
		printf("\n");
		for(j=0;j < spalte;j++)
		{
			
			printf("%d \t",matrix[first_permute[i]][j]);
			sum_vec[0] += matrix[first_permute[i]][first_permute[i]]; 
		}


	}
	printf("SUMME = %d\n", sum_vec[0]);

	//second permute
	for(i=0;i < zeile;i++)
	{
		printf("\n");
		for(j=0;j < spalte;j++)
		{
			printf("%d \t",matrix[second_permute[i]][j]);
			sum_vec[1] += matrix[second_permute[i]][second_permute[i]];

		}

	}

	printf("SUMME = %d\n",sum_vec[1]);
	//third permute
	for(i=0;i<zeile;i++)
	{
		printf("\n");
		for(j=0;j < spalte;j++)
		{		
			printf("%d \t",matrix[third_permute[i]][j]);
			sum_vec[2] += matrix[third_permute[i]][third_permute[i]];
		}


	}
	printf("SUMME = %d\n", sum_vec[2]);


	int tmp = 0;
	int tmp_loc = 0;
	for(i=0;i<3;i++)
	{
		printf("SUM[%d]  = %d\n",i,sum_vec[i]);
		if(sum_vec[i] > tmp)
		{
			tmp = sum_vec[i];
			printf("Größter Wert = %d\n",tmp);
			tmp_loc = i;
		}



	}

	int g = 0;
	printf("Die Permutation %d, ist die beste \n",tmp_loc);
	printf("Permutationsreihenfolge: \n");

	switch(tmp_loc)
	{
		case 0:
			for(g=0;g < 10;g++)
			{
				printf("%d\t",first_permute[g]);
			}
			break;
		case 1:
			for(g=0;g < 10;g++)
			{
				printf("%d\t",second_permute[g]);

			}
			break;
		case 2: for(g=0;g < 10;g++)
			{
				printf("%d\t",third_permute[g]);
			}
			break;
	}



	//Speicher wieder freigeben
	for(i=0; i < zeile;i++)
	{
		free(matrix[i]);
	}

	free(matrix);



	return 0;

}
