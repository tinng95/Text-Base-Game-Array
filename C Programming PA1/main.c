#include <stdio.h>
#include <stdlib.h>

/*
double attackCaculator(float critChance, double critDamage, double attack, float physicalResistance) 
{
	double random;
	random = rand() % 100, 1;

	if (random <= critChance) {
		attack = (attack * ((critDamage/100)+1)) * (physicalResistance / 100);}
		//attack is INT, CritDamage is Float, physicalResistance is DOUBLE
	else {
		attack = attack *(physicalResistance / 100);
	}
	return attack;
};*/


void createPlayerCharacter(char *roleName, int *playerHealth, int *playerAttack, double *playerResistance, double *playerCritChance, double *playerCritDamage)
{
	switch(*roleName)
	{
		case 1:
			break;
	}
}


int main() {
	char name[50];
	int  ID;

	int health = 500;
	int attack= 40;
	
	double physicalResistance;
	//physicalResistance = rand() % 100, 1;
	double critChance;
	//critChance = rand() % 100 + 1;

	float critDamage;
	//critDamage = rand() % 500 + 100;
	
	long lumion; // Currency;
	double temp = (double)rand();

	printf("%lf", random);

	return 0;
};