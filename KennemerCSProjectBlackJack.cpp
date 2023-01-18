// This code plays blackjack.

// Kayley Kennemer
// Project 2
// Computer Science 1

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int displayMenu();
double Credit();
double placeYourBets(double);
int cardValue(int);
char FaceCardValue(int);
int AceValue(int);
bool winLose(int, int, int, char, int);
double MoneyWinLose(double, double);
void quitOption(double);
bool validatePlay(int);
bool validateCredit(double);
bool validateBet(double);
bool validateHitOrStay(char);
void gameHistory(ifstream &, ofstream&);
void History(ofstream &, int, char, char, char, char, char, double, int, char, double);

ifstream inputFile;
ofstream outputFile;
string fileName = "KennemerHistory.txt";

const int BLACKJACK = 21;
const double BETMIN = 10.0;
const double BETMAX = 150.0;
double bet = 0;
double betTotal = 0;
char hitStay;
int quit;
int playGame;
int hands = 0;
double credit = 0;
int dealerCard1, dealerCard2, dealerCard3, dealerCard4;
int playerCard1, playerCard2, playerCard3, playerCard4, playerCard5;
char playerCard1Face, playerCard2Face, playerCard3Face, playerCard4Face, playerCard5Face;
char dealerCard1Face, dealerCard2Face, dealerCard3Face, dealerCard4Face;
int Card, aceCard;
char FaceCard;
int cardTotal = 0, dealerCardTotal = 0;

int main()
{
	int Menu;
	int counter = 0;

	cout << "Welcome to BlackJack table!" << endl;
	credit = Credit();
	
	Menu = displayMenu();
	cout << Menu << endl;

	do
	{
		switch(playGame)
		{
			case 1: bet = placeYourBets(credit);
				

				srand(time(NULL));
				Card = rand() % 13 + 1;
				playerCard1 = cardValue(Card);
				Card = rand() % 13 + 1;
				playerCard2 = cardValue(Card);
				cardTotal = playerCard1 + playerCard2;

				playerCard1Face = FaceCardValue(playerCard1);
				playerCard2Face = FaceCardValue(playerCard2);

				cout << "Player first card " << playerCard1Face << endl;
				cout << "Player second card " << playerCard2Face << endl;
				cout << "The player total hand is: " << cardTotal << endl;

				Card = rand() % 13 + 1;
				dealerCard1 = cardValue(Card);
				Card = rand() % 13 + 1;
				dealerCard2 = cardValue(Card);
				dealerCardTotal = dealerCard1 + dealerCard2;

				dealerCard1Face = FaceCardValue(dealerCard1);
				dealerCard2Face = FaceCardValue(dealerCard2);

				cout << "Dealer second card is: " << dealerCard2Face << endl;

				if(cardTotal < BLACKJACK)
				{
					cout << "Would you like to hit (H) or stay (S)?" << endl;
					cin >> hitStay;

					while(!validateHitOrStay(hitStay))
					{
						cout << "That is an invalid answer. Please enter a H for Hit or a S for stay." << endl;
						cin >> hitStay;
					}
			
					if(hitStay == 'h' || hitStay == 'H')
					{
						Card = rand() % 13 + 1;
						playerCard3 = cardValue(Card);
						cardTotal += playerCard3;

						if(cardTotal > BLACKJACK)
						{
							if(playerCard1 == 14)
							{
								aceCard = playerCard1;
								playerCard1 = AceValue(aceCard);
							}
							else if(playerCard2 == 14)
							{
								aceCard = playerCard2;
								playerCard2 = AceValue(aceCard);
							}
							else if(playerCard3 == 14)
							{
								aceCard = playerCard3;
								playerCard3 = AceValue(aceCard);
							}
						}
						cardTotal = playerCard1 + playerCard2 + playerCard3;

						playerCard3Face = FaceCardValue(playerCard3);

						cout << "Player first card " << playerCard1Face << endl;
						cout << "Player second card " << playerCard2Face << endl;
						cout << "Player third card " << playerCard3Face << endl;
						cout << "The player total hand is: " << cardTotal << endl;

						if(cardTotal == BLACKJACK)
						{
							cout << "BLACKJACK!!" << endl;
						}
						else if (cardTotal > BLACKJACK)
						{
							cout << "BUSTED! You Lose" << endl;
						}

						if(cardTotal < BLACKJACK)
						{
							cout << "Would you like to hit (H) or stay (S)?" << endl;
							cin >> hitStay;

							while(!validateHitOrStay(hitStay))
							{
								cout << "That is an invalid answer. Please enter a H for Hit or a S for stay." << endl;
								cin >> hitStay;
							}

							if(hitStay == 'h' || hitStay == 'H')
							{
								Card = rand() % 13 + 1;
								playerCard4 = cardValue(Card);
								cardTotal += playerCard4;

								playerCard4Face = FaceCardValue(playerCard4);

								cout << "Player first card " << playerCard1Face << endl;
								cout << "Player second card " << playerCard2Face << endl;
								cout << "Player third card " << playerCard3Face << endl;
								cout << "Player fourth card " << playerCard4Face << endl;
								cout << "The player total hand is: " << cardTotal << endl;

								if(cardTotal == BLACKJACK)
								{
									cout << "BLACKJACK!!" << endl;
								}
								else if (cardTotal > BLACKJACK)
								{
									cout << "BUSTED! You Lose" << endl;
								}

								if(cardTotal < BLACKJACK)
								{
									cout << "Would you like to hit (H) or stay (S)?" << endl;
									cin >> hitStay;

									while(!validateHitOrStay(hitStay))
									{
										cout << "That is an invalid answer. Please enter a H for Hit or a S for stay." << endl;
										cin >> hitStay;
									}

									if(hitStay == 'h' || hitStay == 'H')
									{
										Card = rand() % 13 + 1;
										playerCard5 = cardValue(Card);
										cardTotal += playerCard5;

										playerCard5Face = FaceCardValue(playerCard5);

										cout << "Player first card " << playerCard1Face << endl;
										cout << "Player second card " << playerCard2Face << endl;
										cout << "Player third card " << playerCard3Face << endl;
										cout << "Player fourth card " << playerCard4Face << endl;
										cout << "Player fifth card " << playerCard5Face << endl;
										cout << "The player total hand is: " << cardTotal << endl;

										if(cardTotal == BLACKJACK)
										{
											cout << "BLACKJACK!!" << endl;
										}
										else if (cardTotal > BLACKJACK)
										{
											cout << "BUSTED! You Lose" << endl;
										}
									}
									else if(hitStay == 's' || hitStay == 'S')
									{
										if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
										{
											Card = rand() % 13 + 1;
											dealerCard3 = cardValue(Card);
											dealerCardTotal += dealerCard3;

											dealerCard3Face = FaceCardValue(dealerCard3);

											cout << "Dealer first card: " << dealerCard1Face << endl;
											cout << "Dealer second card: " << dealerCard2Face << endl;
											cout << "Dealer third card: " << dealerCard3Face << endl;
											cout << "Dealers hand total: " << dealerCardTotal << endl;

											if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
											{
												Card = rand() % 13 + 1;
												dealerCard4 = cardValue(Card);
												dealerCardTotal += dealerCard4;

												dealerCard4Face = FaceCardValue(dealerCard4);

												cout << "Dealer first card: " << dealerCard1Face << endl;
												cout << "Dealer second card: " << dealerCard2Face << endl;
												cout << "Dealer third card: " << dealerCard3Face << endl;
												cout << "Dealer fourth card: " << dealerCard4Face << endl;
												cout << "Dealers hand total: " << dealerCardTotal << endl;
											}
											else
											{
												cout << "Dealer Busted! You Win! " << endl;
											}
										}
										else if (dealerCardTotal < BLACKJACK && dealerCardTotal > 17)
										{
											cout << "Dealer first card: " << dealerCard1Face << endl;
											cout << "Dealer second card: " << dealerCard2Face << endl;
											cout << "Dealer hand total: " << dealerCardTotal << endl;
										}
									}
								}
							}
							else if(hitStay == 's' || hitStay == 'S')
							{
								if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
								{
									Card = rand() % 13 + 1;
									dealerCard3 = cardValue(Card);
									dealerCardTotal += dealerCard3;

									cout << "Dealer first card: " << dealerCard1Face << endl;
									cout << "Dealer second card: " << dealerCard2Face << endl;
									cout << "Dealer third card: " << dealerCard3Face << endl;
									cout << "Dealers hand total: " << dealerCardTotal << endl;

									if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
									{
										Card = rand() % 13 + 1;
										dealerCard4 = cardValue(Card);
										dealerCardTotal += dealerCard4;

										cout << "Dealer first card: " << dealerCard1Face << endl;
										cout << "Dealer second card: " << dealerCard2Face << endl;
										cout << "Dealer third card: " << dealerCard3Face << endl;
										cout << "Dealer fourth card: " << dealerCard4Face << endl;
										cout << "Dealers hand total: " << dealerCardTotal << endl;
									}
								}
								else if (dealerCardTotal < BLACKJACK && dealerCardTotal > 17)
								{
									cout << "Dealer first card: " << dealerCard1Face << endl;
									cout << "Dealer second card: " << dealerCard2Face << endl;
									cout << "Dealer hand total: " << dealerCardTotal << endl;
								}
							}
						}
					}
					else if (hitStay == 's' || hitStay == 'S')
					{
						if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
						{
							Card = rand() % 13 + 1;
							dealerCard3 = cardValue(Card);
							dealerCardTotal += dealerCard3;

							cout << "Dealer first card: " << dealerCard1Face << endl;
							cout << "Dealer second card: " << dealerCard2Face << endl;
							cout << "Dealer third card: " << dealerCard3Face << endl;
							cout << "Dealers hand total: " << dealerCardTotal << endl;

							if(dealerCardTotal < BLACKJACK && dealerCardTotal < 17)
							{
								Card = rand() % 13 + 1;
								dealerCard4 = cardValue(Card);
								dealerCardTotal += dealerCard4;

								cout << "Dealer first card: " << dealerCard1Face << endl;
								cout << "Dealer second card: " << dealerCard2Face << endl;
								cout << "Dealer third card: " << dealerCard3Face << endl;
								cout << "Dealer fourth card: " << dealerCard4Face << endl;
								cout << "Dealers hand total: " << dealerCardTotal << endl;
							}
							else
							{
								cout << "Dealer Busted! You Win! " << endl;
							}
						}
						else if (dealerCardTotal < BLACKJACK && dealerCardTotal > 17)
						{
							cout << "Dealer first card: " << dealerCard1Face << endl;
							cout << "Dealer second card: " << dealerCard2Face << endl;
							cout << "Dealer hand total: " << dealerCardTotal << endl;
						}
						
					}

					winLose(cardTotal, dealerCardTotal, BLACKJACK, hitStay, dealerCard1);
					MoneyWinLose(bet, credit);

				}
			break;
			case 2: if(counter < 1)
					{
						cout << "There is no history to be viewed. You have to play a game for there to be history." << endl;
					}
					gameHistory(inputFile, outputFile);
			break;
			case 3: quitOption(credit);
			break;
		}
	}
	while(playGame != 3);

}

int displayMenu()
{
	cout << "Welcome! Please choose from the menu." << endl;
	cout << "1. Play BackJack " << endl;
	cout << "2. View game history " << endl;
	cout << "3. Quit" << endl;
	cin >> playGame;

	return playGame;
}

bool validatePlay(int playGame)
{
	bool status = true;

	if(playGame < 1 || playGame > 3)
	{
		status = false;
	}

	return status;
}

void History(ofstream & outFile, int handNum, char playerCard1Face, char playerCard2Face, char playerCard3Face, char playerCardVal4, char playerCardVal5, double bet, int dealerCardTotal, char winLose, double balance )
{
  
  outFile << setw(7) << "Hand" << setw(10) << "Card1" << setw(10) << "Card2" << setw(10) << "Card3" << setw(10) << "Card4" << setw(10) << "Card5" << setw(7) << "Bet" << setw(10) << "Dealer" << setw(5) << "W/L" << setw(10) << "Balance" << endl;

  outFile << setw(7) << handNum++ << setw(10) << playerCard1Face << setw(10) << playerCard2Face << setw(10) << playerCard3Face << setw(10) << playerCard4Face << setw(10) << playerCard5Face << setw(7) << bet << setw(10) << dealerCardTotal << setw(5) << winLose << setw(10) << "$" << credit << endl;
  
  
}

double Credit()
{
	cout << "How much credit do you have to play? " << endl;
	cin >> credit;

	return credit;
}

double placeYourBets(double credit)
{
	cout << "How much would you like to bet? Minimum bets are $10 maximum bets are $150 " << endl;
	cin >> bet;	

	betTotal += bet;

	if(betTotal > credit)
	{
		cout << "You have used up your avaliable credit. Please leave the table or go to the ATM!" << endl;
	}

	return bet;
}

bool validateBet(double bet)
{
	while(bet < 10 || bet > 150)
	{
		cout << "That is an invalid bet. Bets should be between 10 and 150 dollars" << endl;
		cin >> bet;
	}
	return bet;
}

int cardValue(int Card)
{
	if(Card == 1)
	{
		Card = 2;
	}
	else if(Card == 2)
	{
		Card = 3;
	}
	else if(Card == 3)
	{
		Card = 4;
	}
	else if(Card == 4)
	{
		Card = 5;
	}
	else if(Card == 5)
	{
		Card = 6;
	}
	else if(Card == 6)
	{
		Card = 7;
	}
	else if(Card == 7)
	{
		Card = 8;
	}
	else if(Card == 8)
	{
		Card = 9;
	}
	else if(Card == 9)
	{
		Card = 10;
	}
	else if(Card == 10)
	{
		Card = 11;
	}
	else if(Card == 11)
	{
		Card = 12;
	}
	else if(Card == 12)
	{
		Card = 13;
	}
	else if(Card == 13)
	{
		Card = 14;
	}

	return Card;
}

char FaceCardValue(int Card)
{
	char FaceCard;
	
	if(Card == 2)
	{
		FaceCard = '2';
	}
	else if(Card == 3)
	{
		FaceCard = '3';
	}
	else if(Card == 4)
	{
		FaceCard = '4';
	}
	else if(Card == 5)
	{
		FaceCard = '5';
	}
	else if(Card == 6)
	{
		FaceCard = '6';
	}
	else if(Card == 7)
	{
		FaceCard = '7';
	}
	else if(Card == 8)
	{
		FaceCard = '8';
	}
	else if(Card == 9)
	{
		FaceCard = '9';
	}
	else if(Card == 10)
	{
		FaceCard = 'T';
	}
	else if(Card == 11)
	{
		FaceCard = 'J';
	}
	else if(Card == 12)
	{
		FaceCard = 'Q';
	}
	else if(Card == 13)
	{
		FaceCard = 'K';
	}
	else if(Card == 14)
	{
		FaceCard = 'A';
	}

	return FaceCard;
}

bool validateHitOrStay(char hitStay)
{
	bool status = true;

	if(hitStay == 'h' || hitStay == 'H' || hitStay == 's' || hitStay == 'S') 
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}

bool winLose(int cardTotal, int dealerCardTotal, const int BLACKJACK, char hitStay, int dealerCard1)
{
	  bool status = true;

	if(dealerCardTotal == BLACKJACK && cardTotal  == BLACKJACK && dealerCardTotal >= 17)
	{
		cout << endl;
		cout << "Dealers first card was " << dealerCard1 << endl;
		cout << "You both have BLACKJACK. It's a push!" << endl;
		status = false;
		return status;
	}
	  
	if(dealerCardTotal == cardTotal)
	{
		cout << endl;
		cout << "Dealers first card was " << dealerCard1 << endl;
		cout << "You both have the same points. It's a push!" << endl;
		status = false;
		return status;
	}

	if(cardTotal > BLACKJACK || dealerCardTotal > BLACKJACK)
	{
		if(cardTotal > BLACKJACK)
		{
			cout << endl;
			cout << "BUSTED. You went over 21. Your total points were: " << cardTotal << endl;
			cout << "Dealers first card was " << dealerCard1 << endl;
			cout << "The dealer's total points were: " << dealerCardTotal << endl;
			cout << "DEALER WINS" << endl;
			status = false;
			return status;
		}

	    if(dealerCardTotal > BLACKJACK)
	    {
		    cout << endl;
		    cout << "The dealer BUSTED." << endl;
		    cout << "The dealer's first card was: " << dealerCard1 << endl;
		    cout << "The dealer's total points were: " << dealerCardTotal << endl;
		    cout << "Your total points were: " << cardTotal << endl;
		    cout << "YOU WIN" << endl;
		    status = false;
		    return status;
	    }
	}
	  
	if(cardTotal == BLACKJACK && dealerCardTotal != BLACKJACK && dealerCardTotal >= 17)
	{
		cout << endl;
		cout << "You hit BLACKJACK! Your total points were: " << cardTotal << endl;
		cout << "Dealers first card was " << dealerCard1 << endl;
		cout << "The dealer's total points were: " << dealerCardTotal << endl;
		cout << "YOU WIN" << endl;
		cout << endl;
		status = false;
	}

	if(dealerCardTotal == BLACKJACK && cardTotal != BLACKJACK)
	{
	    cout << endl;
	    cout << "The dealer hit BLACKJACK." << endl;
	    cout << "Dealers first card was " << dealerCard1 << endl;
	    cout << "The dealer's total points were: " << dealerCardTotal << endl;
	    cout << "Your total points were: " << cardTotal << endl;
	    cout << "YOU LOSE" << endl;
	    status = false;
	}
	if(hitStay == 's' || hitStay == 'S')
	{
	    if(dealerCardTotal > 17 && dealerCardTotal < BLACKJACK)
	    {
	      	if(dealerCardTotal > cardTotal)
	      	{
		        cout << endl;
		        cout << "YOU LOSE" << endl;
		        cout << "Dealers first card was " << dealerCard1 << endl;
		        cout << "The dealer's total points were: " << dealerCardTotal << "\nYour total points were: " << cardTotal << endl;
		        status = false;
	    	}
	      	else
	      	{
		        cout << endl;
		        cout << "YOU WIN" << endl;
		        cout << "Dealers first card was " << dealerCard1 << endl;
		        cout << "Your total points were: " << cardTotal << endl << "The dealer's total points were: " << dealerCardTotal << endl;
		        status = false;
	      	} 
	    }
	}

	return status;

}

int AceValue(int aceCard)
{
	aceCard = 1;

	return aceCard;
}

double MoneyWinLose(double bet, double credit)
{
	if(dealerCardTotal == BLACKJACK && cardTotal  == BLACKJACK && dealerCardTotal >= 17)
	{
		cout << endl;
		cout << "Your avaliable credit is: " << credit << endl;
		return credit;
	}
	  
	if(dealerCardTotal == cardTotal)
	{
		cout << endl;
		cout << "Your avaliable credit is: " << credit << endl;
		return credit;
	}

	if(cardTotal > BLACKJACK || dealerCardTotal > BLACKJACK)
	{
		if(cardTotal > BLACKJACK)
		{
			cout << endl;
			credit -= bet;
			cout << "Your avaliable credit is: " << credit << endl;
			return credit;
		}

	    if(dealerCardTotal > BLACKJACK)
	    {
		    cout << endl;
		    credit = bet + bet;
		    cout << "Your avaliable credit is: " << credit << endl;
		    return credit;
	    }
	}
	  
	if(cardTotal == BLACKJACK && dealerCardTotal != BLACKJACK && dealerCardTotal >= 17)
	{
		cout << endl;
		credit = bet + bet;
		cout << "Your avaliable credit is: " << credit << endl;
		return credit;
	}

	if(dealerCardTotal == BLACKJACK && cardTotal != BLACKJACK)
	{
	    cout << endl;
	    credit -= bet;
	    cout << "Your avaliable credit is: " << credit << endl;
	    return credit;
	}

	if(hitStay == 's' || hitStay == 'S')
	{
	    if(dealerCardTotal > 17 && dealerCardTotal < BLACKJACK)
	    {
	      	if(dealerCardTotal > cardTotal)
	      	{
		        cout << endl;
		        credit -= bet;
		        cout << "Your avlaiable credit is: " << credit << endl;
	    	}
	      	else
	      	{
		        cout << endl;
		        credit = bet + bet;
		        cout << "Your avaliable credit is: " << credit << endl;
		    } 
	    }
	}

	return credit;
}

void gameHistory(ifstream & inFile, ofstream & outFile)
{
  	string playerCard1Face, playerCard2Face, playerCard3Face, playerCard4Face, playerCard5Face, winLose;
  	double bet, credit;
  	int dealerCardTotal;
  	int empty = 0;

  	cout << setw(7) << "Hand" << setw(10) << "Card 1" << setw(10) << "Card 2" << setw(10) << "Card 3" << setw(10) << "Card 4" << setw(10) << "Card 5" << setw(7) << "Bet" << setw(10) << "Dealer" << setw(5) << "W/L" << setw(10) << "Balance" << endl;

  	inFile.open(fileName);

  	while(!inFile.eof())
  	{
    	inFile >> playerCard1Face >> playerCard2Face >> playerCard3Face >> playerCard4Face >> playerCard5Face >> bet >> dealerCardTotal >> winLose >> credit;
    	while(inFile >> empty)
    	{
      		cout << setw(7) << "  " << setw(10) << playerCard1Face << setw(10) << playerCard2Face << setw(10) << playerCard3Face << setw(10) << playerCard4Face << setw(10) << playerCard5Face << setw(7) << bet << setw(10) << dealerCardTotal << setw(5) << winLose << setw(10) << "$" << credit << endl;
    	}
    
  	}

  	inFile.close();


}	

void quitOption(double credit)
{

  	cout << "Thank you for playing!" << endl;
  	if(credit != 0.0)
  	{
    	cout << setprecision(2) << fixed << showpoint << endl;
    	cout << "Your current balanace is: " << "$" << credit << endl;
  	}
}
