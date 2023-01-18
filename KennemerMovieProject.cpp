// This program displays the seating of a movie theater for two different movies
// and the their show times. 

// Kayley Kennemer
// July 18, 2021
// Project 3
// Computer Science 1

#include <iostream>
#include <iomanip>
using namespace std;

const int COL = 8;
const int ROW = 7;
const double MATINEEADULTPRICE = 6.00;
const double MATINEECHILDPRICE = 4.00;
const double EVENINGADULT = 8.00;
const double EVENINGCHILD = 6.00;
int totalATickets;
int totalCTickets;
double totalATSales = 0.0;
double totalCTSales = 0.0;

void movieShowTimes();
void TicketsWPices();
void seatingChart(char [][COL], char [][COL], char [][COL], char [][COL], int);
void displaySeating(char [][COL], int);
void SeatSelection(char [][COL], int, int);
bool validateSeatRow(int);
bool validateSeatChoice(int);
bool validateMovie(int);
bool validateTickets(int);
int AdultTickets();
int ChildTickets();
void salesResults(int, int, int, double, double);

int main()
{
	char entertainment;
	int movieChoice;
	int movieTime;
	int adultTicket;
	int childTicket;
	int salesview;
	int ticketsBought;

	char seatingFB1[ROW][COL];
	char seatingFB2[ROW][COL];
	char seatingB1[ROW][COL];
	char seatingB2[ROW][COL];

	seatingChart(seatingFB1, seatingFB2, seatingB1, seatingB2, ROW);

	do
	{
		cout << "Welcome to the movies! Would you like to be entertained? (Y) for yes or (N) for No " << endl;
		cin >> entertainment;

		while (entertainment == 'y' || entertainment == 'Y')
		{
			movieShowTimes();
			cout << "Which movie would you like to see?" << endl << "Enter 1 for Free Birds" << endl << "Enter 2 for Bethooven" << endl;
			cin >> movieChoice;

			switch(movieChoice)
			{
				case 1: cout << "What time would you like to see Free Birds?" << endl;
					cout << "Enter 1 for 3:30 or 2 for 6:00" << endl;
					cin >> movieTime;

					while(!validateMovie(movieTime))
					{
						cout << "That is an invalid entry please enter 1 for 3:30 or 2 for 6:00" << endl;
						cin >> movieTime;
					}

					if(movieTime == 1)
					{
						adultTicket = AdultTickets();
						totalATickets += adultTicket;
						totalATSales += adultTicket * MATINEEADULTPRICE;
						childTicket = ChildTickets();
						totalCTickets += childTicket;
						totalCTSales += childTicket * MATINEECHILDPRICE;
						ticketsBought = adultTicket + childTicket;

						SeatSelection(seatingFB1, ROW, ticketsBought);

						displaySeating(seatingFB1, ROW);
					}
					else if(movieTime == 2)
					{
						adultTicket = AdultTickets();
						totalATickets += adultTicket;
						totalATSales += adultTicket * EVENINGADULT;
						childTicket = ChildTickets();
						totalCTickets += childTicket;
						totalCTSales += childTicket * EVENINGCHILD;
						ticketsBought = adultTicket + childTicket;

						SeatSelection(seatingFB2, ROW, ticketsBought);

						displaySeating(seatingFB2, ROW);
					}
				break;

				case 2: cout << "What time would you like to see Bethooven?" << endl;
					cout << "Enter 1 for 5:30 or 2 for 7:30" << endl;
					cin >> movieTime;

					while(!validateMovie(movieTime))
					{
						cout << "That is an invalid entry please enter 1 for 5:30 or 2 for 7:30" << endl;
						cin >> movieTime;
					}

					if(movieTime == 1)
					{
						adultTicket = AdultTickets();
						totalATickets += adultTicket;
						totalATSales += adultTicket * MATINEEADULTPRICE;
						childTicket = ChildTickets();
						totalCTickets += childTicket;
						totalCTSales += childTicket * MATINEECHILDPRICE;
						ticketsBought = adultTicket + childTicket;

						SeatSelection(seatingB1, ROW, ticketsBought);

						displaySeating(seatingB1, ROW);
					}	
					else if(movieTime == 2)
					{
						adultTicket = AdultTickets();
						totalATickets += adultTicket;
						totalATSales += adultTicket * EVENINGADULT;
						childTicket = ChildTickets();
						totalCTickets += childTicket;
						totalCTSales += childTicket * EVENINGCHILD;
						ticketsBought = adultTicket + childTicket;

						SeatSelection(seatingB2, ROW, ticketsBought);

						displaySeating(seatingB2, ROW);
					}
				break;
				case -99: salesResults(salesview, totalATickets, totalCTickets, totalATSales, totalCTSales);
				return 0;
			}
		}
	}while(entertainment == 'y' || entertainment == 'Y');
	



	return 0;
}

bool validateMovie(int movie)
{
	bool status = true;

	if(movie < 1 || movie > 2)
	{
		status = false;
	}

	if(movie == -99)
	{
		status = true;
	}

	return status;
}

bool validateTickets(int tickets)
{
	bool status = true;

	if(tickets < 0)
	{
		status = false;
	}

	return status;
}

void movieShowTimes()
{
	cout << "Free Birds" << setw(9) << "3:30" << setw(10) << "6:00" << endl;
	cout << "Bethooven" << setw(10) << "5:30" << setw(10) << "7:30" << endl;
}

void TicketsWPices()
{
	cout << "Adult Tickets are: $6.00 (matinee before 6:00pm) " << setw(20) << "$8.00 (evening)" << endl;
	cout << "Child Tickets are: $4.00 (matinee before 6:00pm) " << setw(20) << "$6.00 (evening)" << endl;
}

int AdultTickets()
{
	int ATickets;
	cout << "How many adult tickets would you like?" << endl;
	cin >> ATickets;

	while(!validateTickets(ATickets))
	{
		cout << "That is an invalid entry tickets must be zero or greater" << endl;
		cin >> ATickets;
	}

	return ATickets;
}

int ChildTickets()
{
	int CTickets;

	cout << "How many child tickets would you like? " << endl;
	cin >> CTickets;

	while(!validateTickets(CTickets))
	{
		cout << "That is an invalid entry tickets must be zero or greater" << endl;
		cin >> CTickets;
	}

	return CTickets;
}

void seatingChart(char seatingFB1[][COL], char seatingFB2[][COL], char seatingB1[][COL], char seatingB2[][COL], int ROW)
{

  	for(int i1 = 1; i1 <= ROW; i1++)
  	{
    	for(int i2 = 1; i2 <= COL; i2++)
    	{
      		seatingFB1[i1][i2] = '*';
      		seatingFB2[i1][i2] = '*';
      		seatingB1[i1][i2] = '*';
      		seatingB2[i1][i2] = '*';
    	}
  	}
}

void SeatSelection(char chart[][COL], int ROW, int tickets)
{

  	const char TAKEN = '#';
  	const char BLOCK = 'X';
  	const char OPEN = '*';
  	int row;
  	int seat;
  	cout << tickets << endl;

  	while(tickets > 0)
  	{
    	cout << "Enter the row you would like to sit in: " << endl;
    	cin >> row;
    
    	while(!validateSeatRow(row))
    	{
      		cout << "You have entered an invalid row number. Please enter a row number 1 through 7: " << endl;
     		cin >> row;
    	}
    	cout << "Enter the seat number: " << endl;
    	cin >> seat;

    	while(!validateSeatChoice(seat))
    	{
      		cout << "You have entered an invalid seat number. Please enter a seat number 1 through 8: " << endl;
      		cin >> seat;
    	}
    	while(chart[row][seat] == BLOCK || chart[row][seat] == TAKEN)
    	{
      		cout << "You have select an unavailable seat. This seat is either blocked due to Covid Restrictions shown by X or already taken shown by #. Please enter a different row and seat number." << endl << "Row number: " << endl;
      		cin >> row;
      		cout << "Seat number: " << endl;
      		cin >> seat;
    	}
    	chart[row - 1][seat] = BLOCK;
    	chart[row][seat] = TAKEN;
    	chart[row + 1][seat] = BLOCK;
    	tickets--;
  	}

  	for(int i1 = 1; i1 <= ROW; i1++)
  	{

    	for(int i2 = 1; i2 <= COL; i2++)
    	{

      		if(chart[i1][i2] == TAKEN)
      		{
        
        		if(chart[i1][i2-1] != BLOCK || chart[i1][i2-1] != TAKEN || chart[i1][i2+1] != BLOCK || chart[i1][i2+1] != TAKEN)
        		{

          			if(chart[i1][i2-1] == OPEN)
          			{
            			if(i2!=1)
            			{
            				chart[i1][i2-1] = BLOCK;
            			}
          			}
        
          			if(chart[i1][i2+1] == OPEN)
          			{
            			if(i2 != 8)
            			{
            				chart[i1][i2+1] = BLOCK;
            			}
          			}
        		}
      		}
    	}
  	}
}

bool validateSeatRow(int row)
{
	bool status = true;

	if(row > 7 || row <= 0)
	{
		status = false;
	}

	return status;
}

bool validateSeatChoice(int seat)
{
	bool status = true;

	if(seat > 8 || seat <= 0)
	{
		status = false;
	}

	return status;
}

void displaySeating(char chart[][COL], int ROW)
{ 
  	cout << "Seat#";
  	for(int i =1; i <= COL; i++)
  	{
        cout << setw(2) << right << i;     
  	}
  	cout << endl;
  
  	for(int i1 = 1; i1 <= ROW; i1++)
  	{
    	if(i1 != 0)
    	{
    		cout << "Row " << i1;
    	}
    
    	for(int i2 = 1; i2 <= COL; i2++)
    	{
      		cout << setw(2) << chart[i1][i2];
    	}
    	cout << endl;
    }

}

void salesResults(int salesview, int totalATickets, int totalCTickets, double totalATSales, double totalCTSales)
{
	cout << "Would you like to view ticket sales by type or total? Enter (1) for Type, (2) for Total" << endl;
	cin >> salesview;

	if(salesview == 1)
	{
		cout << "The number of Adult tickets sold today: " << totalATickets << endl;
		cout << "The number of Child tickets sold today: " << totalCTickets << endl;
		cout << setprecision(2) << fixed << showpoint;
		cout << "The profit of Adult tickets: " << totalATSales << endl;
		cout << "The profit of Child tickets: " << totalCTSales << endl;
	}
	else if(salesview == 2)
	{
		cout << "The total number of tickets sold: " << totalATickets + totalCTickets << endl;
		cout << setprecision(2) << fixed << showpoint;
		cout << "The total profit made today: " << totalATSales + totalCTSales << endl;
	}
}