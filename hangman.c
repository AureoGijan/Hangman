/*
 * This program is for hangman DUH!
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void guess(char, char [], char []);
void showFigure(int );
void guessWord(char []);
void renderWord(char []);
bool letterExist(char, char []);
bool wordComplete(char [], char []);

int main()
{
	bool gameOver = false;
	char playerName[40];
	char word[40];
	char anoWord[40];
	char guessLetter;
	int i = 0;
	int wordLength;
	
	printf("please enter your name: ");
	scanf("%s", playerName);
	
	printf("\nplease enter a word: ");
	scanf("%s", word);
	
	strcpy(anoWord, word);
	
	guessWord(anoWord);
	
	
	while (gameOver != true) {
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		showFigure(i);
		printf("\n");
		renderWord(anoWord);
		
		printf("\nenter a letter: ");
		fflush(stdin); //flush the buffer
		scanf("%c", &guessLetter);
		
		if(letterExist(guessLetter, word)) {
			printf("\nYou are correct!");
			guess(guessLetter, anoWord, word);
		} else {
			printf("\nThere is no letter %c in the word", guessLetter);
			i++;
		}
		
		if (i == 7) {
			printf("\nGame Over");
			gameOver = true;
		} else if (wordComplete(anoWord, word)) {
			printf("\nCongratulations! You guessed the word.");
			gameOver = true;
		}
			
		
		
	}
	
	
	return 0;
}

void showFigure(int phase) //shows the hanging figure
{
	switch(phase)
	{
		case 0:
			printf("\n___________"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 1:
			printf("\n___________"
				   "\n     |    |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 2:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 3:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n    /     |"
				   "\n   /      |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 4:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n    / \\   |"
				   "\n   /   \\  |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 5:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n    /|\\   |"
				   "\n   / | \\  |"
				   "\n          |"
				   "\n          |"
				   "\n          |"
				   "\n          |");
			break;
		case 6:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n    /|\\   |"
				   "\n   / | \\  |"
				   "\n      \\   |"
				   "\n      /   |"
				   "\n          |"
				   "\n          |");
			break;
		case 7:
			printf("\n___________"
				   "\n     |    |"
				   "\n     O    |"
				   "\n    /|\\   |"
				   "\n   / | \\  |"
				   "\n    / \\   |"
				   "\n    \\ /   |"
				   "\n          |"
				   "\n          |");
			break;
		default:
		printf("wrong!");
	}
}

void guessWord(char wvord[])
{
	int i = 0;
	while (wvord[i] != 0) {
		wvord[i] = '_';
		i++;
	}
}

void renderWord(char vword[])
{
	int i = 0;
	while (vword[i] != 0) {
		printf("%c ", vword[i]);
		i++;
	}
}

void guess(char letra, char word[], char originalWord[])
{
	int i = 0;
	while (originalWord[i] != 0){
		if (letra == originalWord[i]) {
			word[i] = letra;
		}
		i++;
	}
}

bool letterExist(char letra, char originalWord[])
{
	int i = 0;
	while(originalWord[i] != 0) {
		if(letra == originalWord[i])
			return true;
		i++;
	}
	return false;
}

bool wordComplete(char word[],char originalWord[])
{
	int i = 0;
	int counter = 0;
	int length = strlen(originalWord);
	while (originalWord[i] != 0) {
		if(word[i] == originalWord[i]){
			counter++;
		}
		i++;
	}
	
	if (counter == length)
		return true;
	else
		return false;
}




