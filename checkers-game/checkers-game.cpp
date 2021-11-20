#include <iostream>
#include <iomanip>
#include <vector>

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

		if (((x + y) % 2 == 0) && y < 3)
		{
			pawn = 'W';
		}
		else if (((x + y) % 2 == 1) && y > 4)
		{
			pawn = 'B';
		}
		else
		{
			pawn = ' ';
		}
	}
	void printData()
	{
		std::cout << "x: " << x + 1 << " y: " << y + 1 << " pawn: " << pawn << "\n";
	}
};

void start();

int main()
{
	start();
}

void start()
{
	square field[8][8];

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			field[x][y] = square(x, y);
		}
	}

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			field[x][y].printData();
		}
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