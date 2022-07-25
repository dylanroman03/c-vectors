#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdbool.h>
#include <string.h>

using namespace std;

// A = 1; B = 2; C = 3;
vector<int> builds{2, 3, 1, 1, 2};  
vector<int> numbers{14, 7, 2, 24, 8};  
vector<int> seats{42, 65, 45, 64, 38};  
vector<float> area{52.50, 70.00, 30.25, 55.00, 42.25};  


void showTable()
{
	printf("Edificio\tNumero\tPuestos\tArea");
	for (std::size_t i = 0; i < builds.size(); i++) {
		int build = builds[i];
		int number = numbers[i];
		int seat = seats[i];
		float thisArea = area[i];

		switch (build)
		{
		case 1:
			printf("\nA\t\t%d\t%d\t%0.2lf", number, seat, thisArea);
			break;
		
		case 2:
			printf("\nB\t\t%d\t%d\t%0.2lf", number, seat, thisArea);
			break;
		
		case 3:
			printf("\nC\t\t%d\t%d\t%0.2lf", number, seat, thisArea);
			break;
		}
	}
	printf("\n");
}

void capacity() {
	int seatsA = 0;
	int seatsB = 0;
	int seatsC = 0;

	for (std::size_t i = 0; i < builds.size(); i++) {
		int build = builds[i];

		switch (build)
		{
		case 1:
			seatsA = seatsA + seats[i];

			break;
		
		case 2:
			seatsB = seatsB + seats[i];
			break;
		
		case 3:
			seatsC = seatsC + seats[i];
			break;
		}
	}

	printf("Capacidad total en A: %d\n", seatsA);
	printf("Capacidad total en B: %d\n", seatsB);
	printf("Capacidad total en C: %d\n", seatsC);
}

void showRelation() {
	vector<float> realation;

	for (std::size_t i = 0; i < builds.size(); i++) {
		float calc = area[i] / seats[i];
		realation.push_back(calc);
	}

	printf("Edificio\tNumero\tPuestos\tArea\tRelacion metro cuadrado");
	for (std::size_t i = 0; i < builds.size(); i++) {
		int build = builds[i];
		int number = numbers[i];
		int seat = seats[i];
		float thisArea = area[i];

		switch (build)
		{
		case 1:
			printf("\nA\t\t%d\t%d\t%0.2lf\t%0.2lf", number, seat, thisArea, realation[i]);
			break;
		
		case 2:
			printf("\nB\t\t%d\t%d\t%0.2lf\t%0.2lf", number, seat, thisArea, realation[i]);
			break;
		
		case 3:
			printf("\nC\t\t%d\t%d\t%0.2lf\t%0.2lf", number, seat, thisArea, realation[i]);
			break;
		}
	}
	printf("\n");
}

void maxCapacity() {
	int maxCapacity = 0;
	int maxCapacityNumb = 0;
	char maxCapacitybuild[2];
		
	for (std::size_t i = 0; i < builds.size(); i++) {
		int build = builds[i];
		bool changeCapacity = false;

		if (seats[i] > maxCapacity)
		{
			maxCapacity = seats[i];
			maxCapacityNumb = numbers[i];
			changeCapacity = true;
		}

		switch (build)
		{
		case 1:
			if (changeCapacity)
			{
				strcpy(maxCapacitybuild, "A");
			}
			
			break;
		
		case 2:
			if (changeCapacity)
			{
				strcpy(maxCapacitybuild, "B");
			}

			break;
		
		case 3:
			if (changeCapacity)
			{
				strcpy(maxCapacitybuild, "C");
			}

			break;
		}
	}
	printf("El aula con mayor capacidad es el %d del %s, con %d\n", maxCapacityNumb, maxCapacitybuild, maxCapacity);
}

int main()
{
	int option;

	while (option != 5)
	{
		printf("seleccion una option\n1)Mostar tabla\t2)Capacidad en cada edificio\t3)Relacion metro cuadrado\t4)Aula con mayor capacidad de puestos\n");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			showTable();
			break;

		case 2:
			capacity();
			break;
		
		case 3:
			showRelation();
			break;

		case 4:
			maxCapacity();
			break;

		case 5:
			printf("Adios...\n");
			break;

		default:
			printf("Seleccione una opcion valida");
			break;
		}
	}

	return 0;
}
