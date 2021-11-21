#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>

class square
{
private:
	int x = 0;
	int y = 0;
	char pawn = ' ';

public:

	square()
	{
	}
	square(int inputX, int inputY)
	{
		x = inputX;
		y = inputY;

		if ((x + y) % 2 == 0)
		{
			if (y < 3)
			{
				pawn = 'W';
			}
			else if (y > 4)
			{
				pawn = 'B';
			}
		}
		else
		{
			pawn = ' ';
		}
	}

	void printDebug()
	{
		//std::cout << "x: " << x + 1 << " y: " << y + 1 << " pawn: " << pawn << "\t";
		//std::cout << x + 1 << "/" << y + 1 << "-" << pawn << "\t";
		std::cout << pawn << "\t";
	}
	char getX()
	{
		switch (x)
		{
		case 0:
			return 'a';
		case 1:
			return 'b';
		case 2:
			return 'c';
		case 3:
			return 'd';
		case 4:
			return 'e';
		case 5:
			return 'f';
		case 6:
			return 'g';
		case 7:
			return 'h';
		default:
			exit(1);
		}
	}
	char getY()
	{
		return y + 1 + '0';
	}
	char getPawn()
	{
		return pawn;
	}
	void destroyPawn()
	{
		pawn = ' ';
	}
};

void start();
void switchPlayer(char& player);

int main()
{
	start();
	system("pause>0");
}

void start()
{
	square field[8][8];

	char currentPlayer = 'W';

	std::string select, target;
	int selectX, selectY, targetX, targetY;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			field[x][y] = square(x, y);
		}
	}

	do
	{
		system("cls");
		//////////print field
		for (int height = 7; height >= 0; height--)
		{
			std::cout << height + 1 << "\t";

			for (int length = 0; length < 8; length++)
			{
				field[length][height].printDebug();
			}
			std::cout << "\n\n\n\n";
		}

		std::cout << "\t";
		for (int length = 0; length < 8; length++)
		{
			std::cout << (char)(length + 97) << "\t";
		}
		std::cout << "\n";

		std::cout << "\nCurrent player: " << currentPlayer << "\n";

		//////////////select
		do
		{
			std::cout << "\nSelect pawn: ";
			getline(std::cin, select);
			select[0] = tolower(select[0]);

			if ((select[1] > '0' && select[1] <= '8') && (select[0] >= 'a' && select[0] <= 'h'))
			{
				selectX = select[0] - 96 - 1;
				selectY = select[1] - 48 - 1;

				if (field[selectX][selectY].getPawn() == currentPlayer)
				{
					break;
				}
				else
				{
					std::cout << "No " << currentPlayer << " pawns in this area.\n";
					field[selectX][selectY].printDebug();
				}
			}
			else
			{
				std::cout << "Invalid input.\n";
			}
		} while (true);

		///////////target
		do
		{
			std::cout << "\nSelect target: ";
			getline(std::cin, target);
			if ((target[1] > '0' && target[1] <= '8') && (target[0] >= 'a' && target[0] <= 'h'))//validates input
			{
				std::cout << "Valid\n";
				targetX = target[0] - 96 - 1;
				targetY = target[1] - 48 - 1;

				if ((targetX + targetY) % 2 == 0 && field[targetX][targetY].getPawn() == ' ')////check if trying to move on correct field and if its empty
				{
					if ((targetX - selectX == 1 || targetX - selectX == -1) && (targetY - selectY == 1 || targetY - selectY == -1))//check if trying to move once
					{
						std::cout << "JUMP!";
						std::swap(field[selectX][selectY], field[targetX][targetY]);
						break;
					}
					else if ((targetX - selectX == 2 || targetX - selectX == -2) && (targetY - selectY == 2 || targetY - selectY == -2))//check if trying to move twice
					{
						if (field[(selectX + targetX) / 2][(selectY + targetY) / 2].getPawn() != ' ' && field[(selectX + targetX) / 2][(selectY + targetY) / 2].getPawn() != currentPlayer)//check if there is pawn to destroy
						{
							std::cout << "ATTACK!";
							field[(selectX + targetX) / 2][(selectY + targetY) / 2].destroyPawn();
							std::swap(field[selectX][selectY], field[targetX][targetY]);
							break;
						}
						else
						{
							std::cout << "No pawn to destroy.\n";
						}
					}
					else
					{
						std::cout << "Invalid move.\n";
					}
				}
				else
				{
					std::cout << "Field not empty.\n";
				}
			}
			else
			{
				std::cout << "Invalid input.\n";
			}
		} while (true);
		switchPlayer(currentPlayer);
	} while (true);
}

void switchPlayer(char& player)
{
	switch (player)
	{
	case 'W':
		player = 'B';
		break;
	case 'B':
		player = 'W';
		break;
	default:
		exit(2);
	}
}

//void initBoard(int boardSize)
//{
//	for (int height = 0; height <= boardSize * 4; height++)
//	{
//		if (height % 4 == 0)
//		{
//			for (int width = 0; width <= boardSize * 4; width++)
//			{
//				if (width % 4 == 2 && height == boardSize * 4)
//				{
//					std::cout << " 1 ";
//				}
//				else if (width % 4 == 0)
//				{
//					std::cout << "|";
//				}
//				else
//				{
//					std::cout << "---";
//				}
//			}
//		}
//		else if (height % 4 == 2)
//		{
//			for (int width = 0; width <= boardSize * 4; width++)
//			{
//				if (width == 0)
//				{
//					std::cout << "a";
//				}
//				else if (width % 4 == 0)
//				{
//					std::cout << "|";
//				}
//				else
//				{
//					std::cout << "   ";
//				}
//			}
//		}
//		else
//		{
//			for (int width = 0; width <= boardSize * 4; width++)
//			{
//				if (width % 4 == 0)
//				{
//					std::cout << "|";
//				}
//				else
//				{
//					std::cout << "   ";
//				}
//			}
//		}
//
//		std::cout << "\n";
//	}
//}