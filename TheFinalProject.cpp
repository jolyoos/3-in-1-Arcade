#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>    
#include <string.h>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include<cstdlib>
#include<chrono>
#include<thread>
// 3 in 1 Arcade
/* Made by 
Julius Formilles
Mico Laraccas
Daniel Lachica
Aaronn Advincula 
*/


//Functions for typing slowly the string.
//************************************************************************************************************************************************************


int typedelayfast(const std::string& str, bool flag) { //Short Sleep Time
    int typespeed = 50; // Sets the typing speed
    
    for (size_t i = 0; i < str.length(); i++) {
        Sleep(typespeed); // Gets time slept from typespeed
        std::cout << str[i];
    }
    std::cout << std::endl;
    
    if (flag) {
    Sleep(1000);
    system("cls"); //Clears the line after flag is true which is after typing the whole line
    }
    
    return 0;
}

int typedelayslow(const std::string& str, bool flag) { //Longer Sleep Time
    int typespeed = 50; // Sets the typing speed
    
    for (size_t i = 0; i < str.length(); i++) {
        Sleep(typespeed); // Gets time slept from typespeed
        std::cout << str[i];
    }
    std::cout << std::endl;
    
    if (flag) {
    Sleep(2000);
    system("cls"); //Clears the line after flag is true which is after typing the whole line
    }
    
    return 0;
}
 
 int typedelayxtraslow(const std::string& str, bool flag) { //Longer Sleep Time
    int typespeed = 120; // Sets the typing speed
    
    for (size_t i = 0; i < str.length(); i++) {
        Sleep(typespeed); // Gets time slept from typespeed
        std::cout << str[i];
    }
    std::cout << std::endl;
    
    if (flag) {
    Sleep(2000);
    system("cls"); //Clears the line after flag is true which is after typing the whole line
    }
    
    return 0;
}
//*************************************************************************************************************************************************************


//**********************
//Word Bomb            *
//Made by Nixie Lachica*
//**********************
 const int TIMER_DURATION = 5; 

	std::string randomword() {
	const std::string words[] = { "transgress", "obeisance", "characteristic", "misanthrope", "preponderance", "articulation", "forbearance", "quintessential", "legislation", "parsimonious", "convalescent", "predecessor", "representative", "irrefragable", "gullibility", "nonagenarian", "adulation", "electrolysis", "installation", "onomatopoeia", "malignant"
,"centrifugal", "neurological.", "idiosyncratic", "xylophonist", "surreptitiously", "indomitable", "sacrilegious", "absenteeism", "pertinacious" };

	int index = rand() % (sizeof(words) / sizeof(words[0]));
	return words[index];
}

bool Iscorrect(const std::string& generatedWord, const std::string& playerWord) {

	return generatedWord == playerWord;
}

void wordbomb() {
    system("Color 0D");
	srand(static_cast<unsigned>(time(0)));
while (true){

        system("cls");

std::cout<<"__    __ ____ _____  ____    _____  ____  __  __ _____ "<<std::endl;
std::cout<<"\\ \\/\\/ // () \\| () )| _) \\   | () )/ () \\|  \\/  || () )"<<std::endl;
std::cout<<" \\_/\\_/ \\____/|_|\\_\\|____/   |_()_)\\____/|_|\\/|_||_()_)"<<std::endl;
		std::cout << std::endl;
        typedelayslow("Welcome to the Word Ticking Game!!", true);
        typedelayslow("Enter 'exit' to exit at any point during the game.", false);
        Sleep(1000);
		typedelayslow("You have exactly " + std::to_string(TIMER_DURATION) + " seconds to type the word shown ", false);
        typedelayslow("If you get a spelling mistake, the game will end.", false);
        Sleep(1000);
        system("cls");
        while (true) {
		std::string generatedWord = randomword();
		std::cout << "Given Word: " << generatedWord << std::endl;

		auto start = std::chrono::steady_clock::now();
		std::string playerWord;
		std::cout << "Type the word shown: ";
		std::cin >> playerWord;
        if(playerWord=="exit"||playerWord=="Exit")
        return;

		auto end = std::chrono::steady_clock::now();
		auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

		if (elapsedSeconds <= TIMER_DURATION && Iscorrect(generatedWord, playerWord)) {
            system("cls");
			std::cout << "Correct! Next word: " << std::endl;
            Sleep(500);
		}
		else {
			std::cout << "Time is up! Try again by typing anything!  Type Exit to exit the game." << std::endl;
			std::cin >> playerWord;
            if(playerWord=="exit"||playerWord=="Exit" || playerWord == "EXIT")
            return;
            break;

			if (playerWord == "Exit" || playerWord == "exit" || playerWord == "EXIT") {
				std::cout << "Try again soon!" << std::endl;
                return;
			}
		}
	}

	}
}

//*****************************
//Wordle                      *
//Made by Aaron Advincula     *
//*****************************
// Function to randomly choose a word from the word bank
const int wordLength = 5;

std::string getRandomWord() {
    const std::string words[] = {"apple", "happy", "grape", "cloud", "music", "beach", "robot", "smile", "alert", "guess", "bread", "chair", "crown", "breed", "broad", "chase", "brief", "cycle", "cheap", "curve", "daily", "acute", "actor", "abuse", "admit", "craft", "miner", "minor", "heavy", "drama", "fault", "flash", "local", "enjoy", "fluid", "known", "label", "logic", "loose", "might", "never", "radio", "paper", "north", "novel", "noise", "occur", "ocean", "offer", "pride", "price", "print", "spare", "speed", "split", "spent", "table", "taken", "track", "teeth", "theme", "upset", "upper", "wound", "waste", "write", "whole", "worth", "vital", "visit", "value", "virus", "valid"};
    int index = rand() % (sizeof(words) / sizeof(words[0]));
    return words[index];
}

bool IsCorrect(const std::string& generatedWord, const std::string& playerWord) {
    return generatedWord == playerWord;
}

void displayFeedback(const std::string& hiddenWord, const std::string& guess) {
    for (int i = 0; i < hiddenWord.length(); ++i) {
        if (guess[i] == hiddenWord[i]) {
            std::cout << 'O';  // Correct letter in correct position
        } else if (find(hiddenWord.begin(), hiddenWord.end(), guess[i]) != hiddenWord.end()) {
            std::cout << 'X';  // Correct letter in the wrong position
        } else {
            std::cout << '-';  // Incorrect letter
        }
    }
    std::cout << std::endl;
}

void wordle() {
    
    // Seed the random number generator with the current time
    system("Color 0C");
    while(true){
    srand(static_cast<unsigned int>(time(0)));
    std::string hiddenWord = getRandomWord();
    int maxAttempts = 8;
 std::cout << " ____ ____ ____ ____ ____ ____ "<<std::endl;
 std::cout << "||W |||o |||r |||d |||l |||e ||"<<std::endl;
 std::cout << "||__|||__|||__|||__|||__|||__||"<<std::endl;
 std::cout << "|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|"<<std::endl;
    typedelayslow("Welcome to Wordle! Try to guess the " + std::to_string(wordLength) + "-letter word.", false); 
    typedelayslow("The hidden word has " + std::to_string(wordLength) + " letters.", false);
   typedelayslow("Enter exit at any point during the game to exit.", false);
   typedelayslow("Press Enter to start.", false);
    std::cin.ignore();
    system("cls");
    for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
        std::string guess;

        std::cout << "\nAttempt " << attempt << "/" << maxAttempts << ": ";
        std::getline(std::cin, guess);
        if(guess=="exit"||guess=="Exit"||guess=="EXIT")
        return;

        if (guess.length() != wordLength) {
            std::cout << "Invalid guess. Please enter a " << wordLength << "-letter word." << std::endl;
            --attempt;
            continue;
        }

        if (IsCorrect(hiddenWord, guess)) {
            std::cout << "You guessed the word in " << attempt << " attempts. Well done!" << std::endl;
            Sleep(3000);
            break;
        } else {
            std::cout << "Incorrect guess. Here is the feedback:" << std::endl;
            displayFeedback(hiddenWord, guess);
            // You can add additional logic or messages here as needed
            Sleep(500);
        }
    }

    if (maxAttempts == 8) {
        std::cout << "Sorry, you've run out of attempts. The correct word was: " << hiddenWord << std::endl;
    }
    }
    return;
}

//*************************************
//*Rock Paper Scissors Game           *
//*Made by Julius Andrei Formilles    *
//*************************************

void janken(){
system("Color 0B");
std::string userinputstring;
while (userinputstring != "exit"&& userinputstring != "Exit"){

    int userinputint = 0;
    int computerinputint = 0;
    std::string computerinputstring;
    userinputstring.clear(); // Clears userinputstringdata so that the program doesn't read the data from the last iteration.

std::cout<<"                  _                                             _                       "<<std::endl; 
std::cout<<"                 | |                                           (_)                       "<<std::endl;
std::cout<<"   _ __ ___   ___| | __  _ __   __ _ _ __   ___ _ __   ___  ___ _ ___ ___  ___  _ __ ___ "<<std::endl;
std::cout<<"  | '__/ _ \\ / __| |/ / | '_ \\ / _` | '_ \\ / _ \\ '__| / __|/ __| / __/ __|/ _ \\| '__/ __|"<<std::endl;
std::cout<<"  | | | (_) | (__|   <  | |_) | (_| | |_) |  __/ |    \\__ \\ (__| \\__ \\__ \\ (_) | |  \\__ \\"<<std::endl;
std::cout<<"  |_|  \\___/ \\___|_|\\_\\ | .__/ \\__,_| .__/ \\___|_|    |___/\\___|_|___/___/\\___/|_|  |___/"<<std::endl;
std::cout<<"                        | |         | |                                                  "<<std::endl;
std::cout<<"                        |_|         |_|                                                  "<<std::endl;
Sleep(2350);


    std::cout<<std::endl <<std::endl<<"Press enter to start the game.";

    std::cin.ignore();
    system("cls");
    typedelayfast("Enter 'exit' at any point during the game to exit.",false);
    Sleep(3000);
    system("cls");


    while(userinputstring != "Rock"&& userinputstring != "rock" && userinputstring != "Paper" && userinputstring != "paper"&& userinputstring != "Scissors"&& userinputstring !=  "scissors" && userinputstring != "exit" && userinputstring != "Exit"){ 
        // Loops until the correct input has been made
        // Coded in a way so that it isnt case sensitive


    typedelayfast("Rock Paper or Scissors?", false);
    std::cout<<std::endl;
    std::getline (std::cin, userinputstring);
    system("cls");


    if(userinputstring != "Rock"&& userinputstring != "rock" && userinputstring !=  "Paper"&& userinputstring !=  "paper"&& userinputstring !=  "Scissors"&& userinputstring !=  "scissors" && userinputstring != "exit" && userinputstring != "Exit"){
    typedelayfast("Input a correct choice", true);
    }
        else{

         if (userinputstring=="Rock"|| userinputstring=="rock")
            userinputint=1;
         else if(userinputstring=="Paper"|| userinputstring == "paper")
            userinputint=2;
         else if(userinputstring=="Scissors"|| userinputstring== "scissors")
            userinputint=3;
         else if (userinputstring == "Exit" || userinputstring == "exit"|| userinputstring=="EXIT")
            userinputint=4;
    }
    }

switch (userinputint){
case 1: 
std::cout<<"     _______"<<std::endl;
std::cout<<" ---'   ____)  "<<std::endl;
std::cout<<"       (_____)  "<<std::endl;
std::cout<<"       (_____)  "<<std::endl;
std::cout<<"       (____)"<<std::endl;
std::cout<<" ---.__(___)  "<<std::endl;
std::cout<<" '''  "<<std::endl;
break;

case 2:
std::cout<<"    _______"<<std::endl;
std::cout<<"---'   ____)____"<<std::endl;
std::cout<<"          ______)"<<std::endl;  
std::cout<<"          _______)"<<std::endl;  
std::cout<<"         _______)"<<std::endl;
std::cout<<"---.__________)"<<std::endl;  
std::cout<<"'''"<<std::endl;
break;

case 3:
std::cout<<"    _______"<<std::endl;
std::cout<<"---'   ____)____"<<std::endl; 
std::cout<<"          ______)"<<std::endl;  
std::cout<<"       __________)"<<std::endl;  
std::cout<<"      (____)"<<std::endl;
std::cout<<"---.__(___)"<<std::endl;  
std::cout<<"'''"<<std::endl;  
break;

case 4:
return; //Goes back to main(); on the line after the function was called.
                }

typedelayslow("You have chosen " + userinputstring + ".", true); //Types what the user has chosen
typedelayfast("Rock! Paper! Scissors! Shoot!", true); 
    
    
    
            srand(time(NULL));                 //Initializes RNG. By initializing, you set the starting point to the current time which ensures that the
                                               //the number is different every time you run it.
            computerinputint = rand() % (3 - 1 + 1) + 1; // RNG. 3 is the upper limit and 1 is the lower limit 
                                                         // (upperLimit - lowerLimit + 1) + lowerLimit;
            switch (computerinputint){
            case 1: 
            computerinputstring = "Rock";
std::cout<<"    _______"<<std::endl;
std::cout<<" ---'   ____)  "<<std::endl;
std::cout<<"       (_____)  "<<std::endl;
std::cout<<"       (_____)  "<<std::endl;
std::cout<<"       (____)"<<std::endl;
std::cout<<" ---.__(___)  "<<std::endl;
std::cout<<" '''  "<<std::endl;
            break;

            case 2:
            computerinputstring = "Paper";
std::cout<<"    _______"<<std::endl;
std::cout<<"---'   ____)____"<<std::endl;
std::cout<<"          ______)"<<std::endl;  
std::cout<<"          _______)"<<std::endl;  
std::cout<<"         _______)"<<std::endl;
std::cout<<"---.__________)"<<std::endl;  
std::cout<<"'''"<<std::endl;
            break;

            case 3:
            computerinputstring = "Scissors";
std::cout<<"    _______"<<std::endl;
std::cout<<"---'   ____)____"<<std::endl; 
std::cout<<"          ______)"<<std::endl;  
std::cout<<"       __________)"<<std::endl;  
std::cout<<"      (____)"<<std::endl;
std::cout<<"---.__(___)"<<std::endl;  
std::cout<<"'''"<<std::endl;  
            break;

            default: 
            std::cout<<"something went work xd";
            break;
            }
  
    typedelayfast("The computer has chosen " + computerinputstring + ".",true);




if(userinputint == computerinputint) //Result of the game Determiner
typedelayslow("It is a tie. Go again.", true);

else if(userinputint == 1){
    if (computerinputint==2)
    typedelayfast("Paper beats Rock. You have lost.", true);
    else if (computerinputint==3)
    typedelayslow("Rock beats Scissors. You have won!", true);
    Sleep(2000);
}

else if(userinputint == 2){
    if (computerinputint==1)
    typedelayfast("Paper beats Rock. You have won!", true);
    else if (computerinputint==3)
    typedelayslow("Scissors beats Paper . You have lost.", true);   
    Sleep(2000);
}

else if(userinputint == 3){
    if (computerinputint==2)
    typedelayslow("Scissors beats Paper. You have won!", true);
    else if (computerinputint==1)
    typedelayslow("Rock beats Scissors. You have lost.", true);
    Sleep(2000);
}


}   
    }
//Credits***************************************************************************************************************************************************************************
void credits(){
    system("Color 0E");
std::string userinputstring;
std::cout<<"                         _ _ _       "<<std::endl;
std::cout<<"                        | (_) |      "<<std::endl;
std::cout<<"        ___ _ __ ___  __| |_| |_ ___ "<<std::endl;
std::cout<<"       / __| '__/ _ \\/ _` | | __/ __|"<<std::endl;
std::cout<<"      | (__| | |  __/ (_| | | |_\\__ \\"<<std::endl;
std::cout<<"       \\___|_|  \\___|\\__,_|_|\\__|___/"<<std::endl;

std::cout<<std::endl<<std::endl;

typedelayxtraslow("Made by:", false);
typedelayxtraslow("Julius Formilles", false);
typedelayxtraslow("Aaron Advincula", false);
typedelayxtraslow("Danielle Lachica", false);
typedelayxtraslow("Mico Larracas", false);
std::cout<<std::endl<<std::endl;
typedelayxtraslow("Special Mentions:", false);
typedelayxtraslow("Linus (Waffle) Pitargue ", false);
typedelayxtraslow("Karl Stephen Delos Santos Mangahas", false);
typedelayxtraslow("Troy Ronquillo", false);
std::cout<<std::endl<<std::endl;
typedelayxtraslow("Enter 'exit' to return to menu or exit the program.", false);

while(userinputstring != "exit" && userinputstring != "Exit" && userinputstring != "EXIT"){
std::cin>>userinputstring;
if(userinputstring == "exit" || userinputstring == "Exit" || userinputstring == "EXIT"){
return;
}                               
}
}



//Main Menu Function*************************************************************************************************************************************************************

int userinputint;
char userinputchar;

void menu(){
if (std::cin.fail()) { // Checks if previous input operation failed. (If the input was not the correct type)
std::cin.clear(); // Clear error state
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
}

std::cout<<"   _____    _          ___   ___                        __   "<<std::endl;
std::cout<<"  |__  /   (_)___     <  /  /   |  ______________ _____/ /__ "<<std::endl;
std::cout<<"   /_ <   / / __ \\    / /  / /| | / ___/ ___/ __ `/ __  / _ \\"<<std::endl;
std::cout<<" ___/ /  / / / / /   / /  / ___ |/ /  / /__/ /_/ / /_/ /  __/"<<std::endl;
std::cout<<"/____/  /_/_/ /_/   /_/  /_/  |_/_/   \\___/\\__,_/\\__,_/\\___/ "<<std::endl;
                                                             
                                                                                
std::cout<<std::endl;
std::cout<<"Enter the number of the game that you want to play:"<<std::endl;
std::cout<<"(1) Rock Paper Scissors"<<std::endl;
std::cout<<"(2) Wordle"<<std::endl;
std::cout<<"(3) Word Bomb"<<std::endl;
std::cout<<"(4) Credits" << std::endl;
std::cout<<"(5) Exit" << std::endl;
std::cin>>userinputint;

std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

switch(userinputint){
case 1:
system("cls");
janken();
break;

case 2:
system("cls");
wordle();
break;

case 3:
system("cls");
wordbomb();
break;

case 4: 
system("cls");
credits();
break;

case 5:
system("cls");
return;

default:
menu();
}
return; //Goes back to main(); on the line after the function was called.
}

//Main Function
int main(){
   system("Color 0A");
   while(true){
    std::cout<<"Press enter to continue."<<std::endl;
    std::cin.ignore();

    system("cls");
    menu();

    std::cout<<"Do you want to close the program? (Y/N)";
    std::cin>>userinputchar;
    if(userinputchar == 'Y' || userinputchar == 'y')
    break;
    else
    continue;

}
system("cls");
typedelayslow("Thank you for playing :)", true);
return 0;
}

