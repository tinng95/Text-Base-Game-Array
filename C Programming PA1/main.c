#include <stdio.h>
#include <stdlib.h>

//Property of Daniel and Tin

double calculateHealAmount(double *playerCritChance, double *playerCritDamage, double *playerPhysicalResistance, double *attack)
{
	double healAmount;
	double random;
	random = rand() % 100 + 1;

	if (random <= *playerCritChance)
	{
		healAmount = (((*attack * 0.4) * (*playerCritDamage)) * (*playerPhysicalResistance + 1));
	}
	else
	{
		healAmount = ((*attack * 0.4) *(*playerPhysicalResistance + 1));
	}
	return healAmount;
};

double calculateDamageAmount(double *attackerAttack, double *attackerCritChance, double *attackerCritDamage, double *targetPhysicalResistance)
{
	double random;
	double damageDealt;
	random = (rand() % 100 + 1) / 100;

	if (random <= *attackerCritChance)
	{
		damageDealt = (double)(((double)*attackerAttack * (*attackerCritDamage)) * (*targetPhysicalResistance));
	}
	else
	{
		damageDealt = (double)((double)*attackerAttack *(*targetPhysicalResistance));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, double *playerHealth, double *playerMaxHealth, double *playerAttack, double *playerPhysicalResistance, double *playerCritChance, double *playerCritDamage)
{
	switch (roleNumber)
	{
	case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
		*playerHealth = 10000; //Set *playersHealth to 10000;
		*playerMaxHealth = 10000; //Set *playerMaxHealth to 10000;
		*playerAttack = 300; //Set *playerAttack to 300;
		*playerPhysicalResistance = 0.80; //Set *playerPhysicalResistance to 0.80;
		*playerCritChance = 0.20; //Set *playerCritChance to 0.20;
		*playerCritDamage = 8.00; //Set *playerCritDamage to 8.00;
								  /*END of your solution*/
		break;
	case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
		*playerHealth = 4000; //Set *playersHealth to 4000;
		*playerMaxHealth = 4000; //Set *playerMaxHealth to 4000;
		*playerAttack = 1000; //Set *playerAttack to 1000;
		*playerPhysicalResistance = 0.30; //Set *playerPhysicalResistance to 0.30;
		*playerCritChance = 0.40; //Set *playerCritChance to 0.40;
		*playerCritDamage = 4.00; //Set *playerCritDamage to 4.00;
								  /*END of your solution*/
		break;
	case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
		   /*BEGINNING of your solution*/
		*playerHealth = 6000; //Set *playersHealth to 6000;
		*playerMaxHealth = 6000; //Set **playerMaxHealth to 6000;
		*playerAttack = 600; //Set *playerAttack to 600;
		*playerPhysicalResistance = 0.50; //Set *playerPhysicalResistance to0.50;
		*playerCritChance = 0.80; //Set *playerCritChance to 0.80;
		*playerCritDamage = 6.00; //Set *playerCritDamage to 6.00;
								  /*END of your solution*/
		break;
	}
};

void createBoss(double *bossHealth, double *bossAttack, double *bossPhysicalResistance, double *bossCritChance, double *bossCritDamage)
{
	/*BEGINNING of your solution*/
	*bossHealth = 50000; //Set *bossHealth to 50000
	*bossAttack = 50000;//(rand() % 600 + 400.0); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
	*bossPhysicalResistance = (rand() % 60 + 30.0) / 100; //Set *bossPhysicalResistance to a randomized number in the range between 30 to 60 inclusively
	*bossCritChance = (rand() % 20 + 10.0) / 100; //Set *bossCritChance to a randomized number in the range between 10 to 20 inclusively
	*bossCritDamage = (rand() % 250 + 100.0) / 100; //Set *bossCritDamage to a randomized number in the range between 100 to 250 inclusively
													/*END of your solution*/
};

void introduction() {
	printf("Welcome to your Programming Assignment 1!\n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva.\n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer.\n ");
	printf("1. Warrior\n ");
	printf("2. Mage\n ");
	printf("3. Archer\n");
	printf("Please select your class with the coresponding numbers. ");
	printf("Selection: ");
}

int getUserInput(int numOfChoices) {
	int number;
	while (1 == 1) // Always true, C is stupid
	{
		scanf("%d", &number);
		for (int i = 1; i <= numOfChoices; i++) // Loops through the possible choices
		{
			if (number == i)
			{
				printf("\n");
				return i;
			}
		}
		//Error Message
		fseek(stdin, 0, SEEK_END); //Flush input buffer
		printf("<----------------------------------------------------------------------------->\n");
		printf("Invalid Input Error: Please enter a one of the number above!\n");

	}

	return number;
}

void applyHealAmount(double *targetHealth, double *targetMaxHealth, double healAmount)
{
	if (*targetHealth + healAmount > *targetMaxHealth)
	{
		*targetHealth = *targetMaxHealth;
	}
	else
	{
		*targetHealth += healAmount;
	}
}

//GAME ENGINE:

int processInput(int opCode)
{
	int temp;
	switch (opCode)
	{
	case 0: //Class Selection
		temp = getUserInput(3);
		if (temp == 1)
		{
			return 1;
		}
		else if (temp == 2)
		{
			return 2;
		}
		else if (temp == 3)
		{
			return 3;
		}
		break;
	case 1: //Action Selection
		temp = getUserInput(2);
		if (temp == 1)
		{
			return 2;
		}
		else if (temp == 2)
		{
			return 3;
		}
		break;
	}

}



void render(int opCode, double *renderArgument1, double *renderArgument2)
{
	switch (opCode)
	{
	case 0:
		introduction();
		break;
	case 1: //Display Player Menu
		printf("<--------------------------------------------------------->\n");
		printf("1. Attack\n");
		printf("2. Heal\n");
		printf("Selection: ");
		break;
	case 2:
		printf("<--------------------------------------------------------->\n");
		printf("You deal %d damage to the boss!\n", (int)*renderArgument1);
		break;
	case 3:
		printf("<--------------------------------------------------------->\n");
		printf("You heal %d health!\n", (int)*renderArgument1);
		break;
	case 4:
		printf("<--------------------------------------------------------->\n");
		printf("Boss deals %d damage to you!\n", (int)*renderArgument1);
		break;
	case 5:
		printf("Boss heals %d health!\n", (int)*renderArgument1);
		break;
	case 6:
		printf("<--------------------------------------------------------->\n");
		printf("Player's Health %d\n", (int)*renderArgument1);
		printf("Boss Health: %d\n", (int)*renderArgument2);
		break;
	case 7:
		printf("<--------------------------------------------------------->\n");
		printf("Congratulations! You Defeated the Boss!\n");
		break;
	case 8:
		printf("<--------------------------------------------------------->\n");
		printf("YOU DIED!!! Well at least you got the game running XD");
		break;
	}
}



int updateGame(int opCode, double *updateGameParameters[])
{

	/*
	0: playerHealth;
	1: playerMaxHealth;
	2: playerAttack;
	3: playerPhysicalResistance
	4: playerCritChance;
	5: playerCritDamage;
	6: bossHealth;
	7: bossAttack;
	8: bossPhysicalResistance;
	9: bossCritChance;
	10: bossCritDamage;
	*/
	//FUNCTION
	int renderOpCode = -1;
	double *renderArgument1 = NULL;
	double *renderArgument2 = NULL;
	renderArgument1 = malloc(sizeof(double));
	renderArgument2 = malloc(sizeof(double));

	switch (opCode)
	{
	case 0: //Create Warrrior
		createPlayerCharacter(processInput(0), updateGameParameters[0], updateGameParameters[1], updateGameParameters[2], updateGameParameters[3], updateGameParameters[4], updateGameParameters[5]);
		break;
	case 1: //Create Boss
		createBoss(updateGameParameters[6], updateGameParameters[7], updateGameParameters[8], updateGameParameters[9], updateGameParameters[10]);
		break;
	case 2: //Player Attacks
		*renderArgument1 = calculateDamageAmount(updateGameParameters[2], updateGameParameters[4], updateGameParameters[5], updateGameParameters[8]);
		*updateGameParameters[6] -= *renderArgument1; //Subtract damage from boss health
		renderArgument2 = updateGameParameters[6];
		render(2, renderArgument1, renderArgument2);
		if (*updateGameParameters[6] <= 0)
		{
			render(7, NULL, NULL);
			return 0;
			break;
		}
		render(6, updateGameParameters[0], updateGameParameters[6]);
		break;
	case 3: //Player Heals
		*renderArgument1 = calculateHealAmount(updateGameParameters[4], updateGameParameters[5], updateGameParameters[3], updateGameParameters[2]);
		applyHealAmount(updateGameParameters[0], updateGameParameters[1], *renderArgument1);
		render(3, renderArgument1, NULL);
		render(6, updateGameParameters[0], updateGameParameters[6]);
		break;
	case 4: //Boss Attacks
		*renderArgument1 = calculateDamageAmount(updateGameParameters[7], updateGameParameters[9], updateGameParameters[10], updateGameParameters[3]);
		*updateGameParameters[0] -= *renderArgument1;
		render(4, renderArgument1, NULL);
		if (*updateGameParameters[0] <= 0)
		{
			render(8, NULL, NULL);
			return 0;
			break;
		}
		render(6, updateGameParameters[0], updateGameParameters[6]);
		break;
	case 5: // Boss Heals
		*renderArgument1 = calculateHealAmount(updateGameParameters[9], updateGameParameters[10], updateGameParameters[8], updateGameParameters[7]);
		*renderArgument2 = 50000.0;
		applyHealAmount(updateGameParameters[6], renderArgument2, *renderArgument1);
		render(5, renderArgument1, NULL);
		break;
	}
	return 1;
}

int AI(double *updateGameParameters[])
{
	if (*updateGameParameters[6] > 15000)
	{
		return 4;
	}
	else
	{
		return 5;
	}
}


int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	//const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	//const char roleName2[10] = { 'M','a','g','e' };
	//const char roleName3[10] = { 'A','r','c','h','e','r' };
	double playerHealth;
	double playerAttack;
	double playerMaxHealth;
	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;


	//BOSS STATS
	char bossName[10] = { 'S', 'i', 'l', 'v', 'a' };
	int bossHealth;
	int bossAttack;
	double bossPhysicalResistance;
	double bossCritChance;
	double bossCritDamage;

	double *updateGameParameters[11];

	int isGameRunning = 1;




	updateGameParameters[0] = &playerHealth;
	updateGameParameters[1] = &playerMaxHealth;
	updateGameParameters[2] = &playerAttack;
	updateGameParameters[3] = &playerPhysicalResistance;
	updateGameParameters[4] = &playerCritChance;
	updateGameParameters[5] = &playerCritDamage;


	updateGameParameters[6] = &bossHealth;
	updateGameParameters[7] = &bossAttack;
	updateGameParameters[8] = &bossPhysicalResistance;
	updateGameParameters[9] = &bossCritChance;
	updateGameParameters[10] = &bossCritDamage;


	render(0, NULL, NULL);
	updateGame(0, updateGameParameters);
	updateGame(1, updateGameParameters);
	while (isGameRunning == 1)
	{
		render(1, NULL, NULL);
		isGameRunning = updateGame(processInput(1), updateGameParameters);
		if (isGameRunning != 1)
		{
			break;
		}
		isGameRunning = updateGame(AI(updateGameParameters), updateGameParameters);
	}
	return 0;
};