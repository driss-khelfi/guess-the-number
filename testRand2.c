#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pick(void) 
{
  srand(time(NULL));
  int randomNum = rand() % 101;
  return randomNum;
}

int select(void) 
{
  int userNum;
  printf("Entrez un nombre compris entre 1 et 100 : ");
  while (!scanf("%d", &userNum)) {
    printf("Saisie invalide. Veuillez entrer un nombre : ");
    fflush(stdin);
  }
  return userNum;
}

int decision(int userNum, int randomNum, int vie) 
{
  if (userNum > randomNum) {
    printf("C'est moins ! Il vous reste %d chances.\n", vie);
    vie--;
  } else if (userNum < randomNum) {
    printf("C'est plus ! Il vous reste %d chances.\n", vie);
    vie--;
  } else {
    printf("Bravo, vous avez gagne !\n");
    return 1;
  }
  return 0;
}

int main(void) 
{
  int vie = 10;
  int randomNum = pick();
  
  while (vie > 0) {
    int userNum = select();
    int result = decision(userNum, randomNum, vie);
    if (result) {
      break;
    }
  }
  
  if (vie == 0) 
  {
    printf("Vous avez perdu toutes vos chances. Le nombre était %d.\n", randomNum);
  }
  
  return 0;
}