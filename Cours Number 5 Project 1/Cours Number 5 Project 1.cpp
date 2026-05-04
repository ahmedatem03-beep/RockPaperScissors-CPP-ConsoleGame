#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum enGame { Stone = 1, Peper = 2, Scissors = 3 };
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int ComputerChoice()
{
	return RandomNumber(1, 3);
}
int ReadLength()
{
	int length = 0;
	do
	{
		cout << "How Many Rounds 1 To 10? ";
		cin >> length;
	} while (length < 1 || length>10);
	return length;
}

int ReadPlayerNumber()
{
	int NumOfPlayer = 0;
	do
	{
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissorse ? ";
		cin >> NumOfPlayer;
	} while (NumOfPlayer > 3 || NumOfPlayer < 1);
	return NumOfPlayer;
}
string ChoiceReadPlayer(enGame Game)
{
	if (Game == enGame::Stone)
		return "Stone";
	else if (Game == enGame::Peper)
		return "Paper";
	else if (Game == enGame::Scissors)
		return"Scissorse";
}

string ChoiceTheGame(int Player,int Computer)
{
	

	if (Player == Computer)
		return "[No Winner]";

	else if ((Player == enGame::Stone && Computer == enGame::Scissors) ||
		(Player == enGame::Scissors && Computer == enGame::Peper) ||
		(Player == enGame::Peper && Computer == enGame::Stone))
		return "[Player]";

	else
	return "[Computer]";
		
}
void Color(string Game)
{
	if (Game == "[No Winner]")
		system("color 6F");
	else if (Game == "[Player]")
		system("color 2F");
	else if (Game == "[Computer]")
	{
		system("color 4F");
		cout << "\a";
	}
}
string FinalWinner(int WinnerPlayer, int WinnerComputer)
{
	if (WinnerPlayer > WinnerComputer)
		return "Player";
	else if (WinnerComputer > WinnerPlayer)
		return "Computer";
	else
		return "No Winner";
}
void ResetScreen()
{
	system("cls");
	system("color 0F");
}
void PrintFinalGame()
{
	int length = ReadLength();
	int NumOfPlayer = 0;
	int Computer = 0;
	int Counter = 0, WinnerPlayer = 0, WinnerComputer = 0, NoWinner = 0;
	char PlayeAgain;
	do
	{
		
		for (int i = 1; i <= length; i++)
		{
			cout << "\nRound [" << i << "] bengins:\n\n";
			NumOfPlayer = ReadPlayerNumber();
			Computer = ComputerChoice();
			cout << "\n_______________Round [" << i << "] _______________\n\n";
			cout << "Player1 Choice: " << ChoiceReadPlayer((enGame)NumOfPlayer) << endl;;
			cout << "Computer Choice: " << ChoiceReadPlayer((enGame)Computer) << endl;
			cout << "Round Winner: " << ChoiceTheGame(NumOfPlayer, Computer) << endl;
			Color(ChoiceTheGame(NumOfPlayer, Computer));
			cout << "________________________________________\n\n";
			Counter++;
			if (ChoiceTheGame(NumOfPlayer, Computer) == "[No Winner]")
				NoWinner++;
			else if (ChoiceTheGame(NumOfPlayer, Computer) == "[Player]")
				WinnerPlayer++;
			else if (ChoiceTheGame(NumOfPlayer, Computer) == "[Computer]")
				WinnerComputer++;
		}
		cout << "\t\t\t__________________________________________________\n\n";
		cout << "\t\t\t\t\t+++Game Over+++\n\n";
		cout << "\t\t\t__________________________________________________\n\n";
		cout << "\t\t\t__________________[Game Results]__________________\n\n";
		cout << "\t\t\tGame Rounds        :" << Counter << endl;
		cout << "\t\t\tPlayer1 Won Times  :" << WinnerPlayer << endl;
		cout << "\t\t\tComputer Won Times :" << WinnerComputer << endl;
		cout << "\t\t\tDraw Times         :" << NoWinner << endl;
		cout << "\t\t\tFinal Winner       :" << FinalWinner(WinnerPlayer, WinnerComputer) << endl;
		cout << "\t\t\t__________________________________________________\n\n";

		cout << "\t\t\tDo Tou Want To Playe Again? Y/N?";
		cin >> PlayeAgain;
		ResetScreen();
	} while (PlayeAgain == 'Y'||PlayeAgain=='y');
	
}
int main()
{
	srand((unsigned)time(NULL));
	PrintFinalGame();
	
}