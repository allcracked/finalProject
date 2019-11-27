//#include <iostream>
//#include <time.h>
//#include <stdlib.h>
//
//using namespace std;
//
//int main(int argc, char** argv) {
//	srand(time(NULL));
//	
//	char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//	string words[] = {"HOLA", "JOSE", "CASA", "DADO"};
//	string remainingWords[4];
//	string usingWords[4];
//	
//	char alphabetSoup[8][8];
//	
//	for (int i = 0; i < sizeof(alphabetSoup)/sizeof(alphabetSoup[0]); i++) {
//		for (int j = 0; j < sizeof(alphabetSoup[0]); j++) {
//			alphabetSoup[i][j] = letters[rand() % sizeof(letters)];
//		}
//	}
//	
//	for (int i = 0; i < sizeof(alphabetSoup)/sizeof(alphabetSoup[0]); i++) {
//		for (int j = 0; j < sizeof(alphabetSoup[0]); j++) {
//			cout << alphabetSoup[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	int randomRow, randomColumn, randomWord;
//	
//	randomWord = rand() % (sizeof(words)/sizeof(string));
//	randomRow = rand() % (sizeof(alphabetSoup)/sizeof(alphabetSoup[0]));
//	randomColumn = rand() % words[randomWord].length();
//	
//	cout << randomWord << " " << randomRow << " " << randomColumn << " " << words[randomWord] << endl;
//	
//	
//	
//	
//	return 0;
//}

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int const ROWS = 10;
int const COLUMNS = 10;
bool searchLocation(char (&board)[ROWS][COLUMNS], string, int, int, int, bool, int);
int main() {
    srand(time(NULL));
    char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string words[] = {"HOLA", "CASA", "NADA", "PAPA", "MAMA", "MEME"};
    char board[ROWS][COLUMNS] = {0};
    
    for (int i = 0; i < (sizeof(board)/sizeof(board[0])); i++) {
        for (int j = 0; j < sizeof(board[0]); j++) {
            if (!board[i][j]) {
                cout << "* ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    int currentWord = rand() % (sizeof(words)/sizeof(string));
    int orientation = (rand() % 3)+1; // 1 horizontal, 2 vertical, 3 descending, 4 ascending
    int currentRow = rand() % ((sizeof(board)/sizeof(board[0]))-(words[currentWord].length()-1));
    int currentColumn = rand() % (sizeof(board[0])-(words[currentWord].length()-1));
    int reverve = rand() % 2;
    cout << currentWord << ": " << words[currentWord] << ":" << words[currentWord].length() << " " << orientation << " [" << currentRow << "][" << currentColumn << "]: " << board[currentRow][currentColumn] << endl;
    
    if (!searchLocation(board, words[currentWord], orientation, currentRow, currentColumn, false, 0)) {
        cout << "We need another location for the word." << endl;
    } else {
        cout << "Spot was free." << endl;
    }
    
    searchLocation(board, words[currentWord], orientation, currentRow, currentColumn, true, reverve);
    for (int i = 0; i < (sizeof(board)/sizeof(board[0])); i++) {
        for (int j = 0; j < sizeof(board[0]); j++) {
            if (!board[i][j]) {
                cout << "* ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
/*
 * Busca
 */
bool searchLocation(char (&board)[ROWS][COLUMNS], string currentWord, int orientation, int currentRow, int currentColumn, bool saveLocation, int reverse) {
    int searchRow = currentRow;
    int searchColumn = currentColumn;
    int wordIndex = 0;
    if(reverse) {
        wordIndex = currentWord.length()-1;
    }
    while (true) {
        // Comprueba si la posicion actual tiene valores
        if (board[searchRow][searchColumn]) {
            if (board[searchRow][searchColumn] != currentWord[wordIndex]) {
                return false;
            }
        }
        if (saveLocation) {
            board[searchRow][searchColumn] = currentWord[wordIndex];
        }
        if (orientation == 1 && searchColumn < (searchColumn+currentWord.length()-1) && searchColumn < sizeof(board[0])-1) {
            searchColumn++;
        } else if (orientation == 2 && searchRow < (searchRow+currentWord.length()-1) && searchRow < (sizeof(board)/sizeof(board[0]))-1) {
            searchRow++;
        } else if(orientation == 3 && searchRow < (searchRow+currentWord.length()-1) && searchRow < (sizeof(board)/sizeof(board[0]))-1 && searchColumn < (searchColumn+currentWord.length()-1) && searchColumn < sizeof(board[0])-1) {
            searchRow++;
            searchColumn++;
        } else {
            return true;
        }
        if (reverse) {
            if (wordIndex > 0) {
                wordIndex--;
            } else {
                return true;
            }
        } else {
            if (wordIndex < currentWord.length()-1) {
                wordIndex++;
            } else {
                return true;
            }
        }
    }
}
