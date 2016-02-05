#include <stdio.h>
#include <stdlib.h>

//Property of Daniel and Tin

double calculateHealAmount(double playerCritChance, double playerCritDamage, double playerPhysicalResistance, int attack)
{
	double healAmount;
	double random;
	random = rand() % 100 + 1;

	if (random <= playerCritChance) 
	{
		healAmount = (int)((((double)attack * 0.4) * (playerCritDamage)) * (playerPhysicalResistance + 1));
	}
	else 
	{
		healAmount = (int)(((double)attack * 0.4) *(playerPhysicalResistance + 1));
	}
	return healAmount;
};

double calculateDamageAmount(int attackerAttack, double attackerCritChance, double attackerCritDamage, double targetPhysicalResistance)
{
	double random;
	double damageDealt;
	random = (rand() % 100 + 1) / 100;

	if (random <= attackerCritChance) 
	{
		damageDealt = (int)(((double)attackerAttack * (attackerCritDamage)) * (targetPhysicalResistance));
	}
	else 
	{
		damageDealt = (int)((double)attackerAttack *(targetPhysicalResistance));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, int *playerHealth, int *playerAttack, double *playerPhysicalResistance, double *playerCritChance, double *playerCritDamage)
{
	switch(roleNumber)
{
		case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 10000; //Set *playersHealth to 10000;
			*playerAttack = 300; //Set *playerAttack to 300;
			*playerPhysicalResistance = 0.80; //Set *playerPhysicalResistance to 0.80;
			*playerCritChance = 0.20; //Set *playerCritChance to 0.20;
			*playerCritDamage = 8.00; //Set *playerCritDamage to 8.00;
			/*END of your solution*/
			break;
		case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
			*playerHealth = 4000; //Set *playersHealth to 4000
			*playerAttack = 1000; //Set *playerAttack to 1000;
			*playerPhysicalResistance = 0.30; //Set *playerPhysicalResistance to 0.30;
			*playerCritChance = 0.40; //Set *playerCritChance to 0.40;
			*playerCritDamage = 4.00; //Set *playerCritDamage to 4.00;
			/*END of your solution*/
			break;
		case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 6000; //Set *playersHealth to 6000
			*playerAttack = 600; //Set *playerAttack to 600;
			*playerPhysicalResistance = 0.50; //Set *playerPhysicalResistance to0.50;
			*playerCritChance = 0.80; //Set *playerCritChance to 0.80;
			*playerCritDamage = 6.00; //Set *playerCritDamage to 6.00;
			/*END of your solution*/
			break ;
	}
};

void createBoss(int *bossHealth, int *bossAttack, double *bossPhysicalResistance, double *bossCritChance, double *bossCritDamage)
{
	/*BEGINNING of your solution*/
	*bossHealth = 50000; //Set *bossHealth to 50000
	*bossAttack = (rand() % 600 + 400.0); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
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
	printf("Please select your class with the coresponding numbers: ");
}

int playerMove()
{
	int choice;
	printf("1. Attack\n");
	printf("2. Heal\n");
	choice = getUserInput(2);
	return choice;
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
				return i;
			}
		}
		//Error Message
		//fflush(stdin); //Flush input buffer
		fflush(stdin);
		printf("<----------------------------------------------------------------------------->\n");
		printf("Invalid Input Error: Please enter a one of the number above!\n");
		
	}

	return number;
}

int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	const char roleName2[10] = { 'M','a','g','e' };
	const char roleName3[10] = { 'A','r','c','h','e','r' };
	int playerHealth;
	int playerAttack;

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
	
	//FUNCTION
	introduction();
	createPlayerCharacter(getUserInput(3), &playerHealth, &playerAttack, &playerPhysicalResistance, &playerCritChance, &playerCritDamage);
	createBoss(&bossHealth, &bossAttack, &bossPhysicalResistance, &bossCritChance, &bossCritDamage);
	
	while (bossHealth > 0)
	{
		switch (playerMove()) 
		{
			case 1:
				bossHealth = bossHealth - calculateDamageAmount(playerAttack, playerCritChance, playerCritDamage, playerPhysicalResistance);
				playerHealth = playerHealth - calculateDamageAmount(bossAttack, bossCritChance, bossCritDamage, bossPhysicalResistance);
				break;
			case 2:
				playerHealth = playerHealth + calculateHealAmount(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack);
				playerHealth = playerHealth + calculateDamageAmount(bossAttack, bossCritChance, bossCritDamage, bossPhysicalResistance);
				break;
		}
		if (playerHealth <= 0)
		{
			printf("<----------------------------------------------------------------------------->\n");
			printf("You Died!, but hey at least you got the game working. XD\n");
		}
		else if (bossHealth <= 0)
		{
			printf("<----------------------------------------------------------------------------->\n");
			printf("Congrationlation you beat the boss, now go back to writing code.\n");
		}
		else
		{
			printf("<----------------------------------------------------------------------------->\n");
			printf("Player Health: %d\n", playerHealth);
			printf("Boss Healt: %d\n", bossHealth);
		}
	}
return 0;
};