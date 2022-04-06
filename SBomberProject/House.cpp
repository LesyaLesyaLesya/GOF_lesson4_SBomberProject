
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

House::House()
{
	for (size_t i = 0; i < 14; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			look[j][i] = ' ';
		}
	}
}
bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	GotoXY(x, y - 13);
	//cout << "  @@@@@@@  ";
	for (size_t j = 0; j < 14; j++)
	{	
		for (size_t i = 0; i < 7; i++)	
		{
			std::cout << look[j][i];
				
		}
		GotoXY(x, y - (12-j));
		//std::cout << std::endl;
	}


	/*
	MyTools::SetColor(CC_Yellow);
	GotoXY(x, y - 5);
	cout << "  ########  ";
	GotoXY(x, y - 4);
	cout << "##        ##";
	GotoXY(x, y - 3);
	cout << "############";
	GotoXY(x, y - 2);
	cout << "#          #";
	GotoXY(x, y - 1);
	cout << "#          #";
	GotoXY(x, y);
	cout << "############";*/
}

void HouseBuilderA::buildFoundation()
{
	for (int i = 0; i < 7; i++)
	{
		p->look[13][i] = '@';
	}
}

void HouseBuilderA::buildWall()
{
	for (int j = 7; j < 13; j++)
	{
		p->look[j][0] = '@';
		p->look[j][6] = '@';
	}
}

void HouseBuilderA::buildCeiling()
{
	for (int i = 0; i < 7; i++)
	{
		p->look[7][i] = '@';
	}
}

void HouseBuilderA::buildRoof()
{
	for (int i = 1; i < 6; i++) { p->look[6][i] = '@'; }
	for (int i = 2; i < 5; i++) { p->look[5][i] = '@'; }

}

void HouseBuilderB::buildFoundation()
{
	for (int i = 0; i < 7; i++)
	{
		p->look[13][i] = '@';
	}
}

void HouseBuilderB::buildWall()
{
	for (int j = 7; j < 13; j++)
	{
		p->look[j][0] = '@';
		p->look[j][6] = '@';
	}
}

void HouseBuilderB::buildCeiling()
{
	for (int i = 0; i < 7; i++)
	{
		p->look[7][i] = '@';
	}
}

void HouseBuilderB::buildRoof()
{
	for (int i = 1; i < 6; i++) { p->look[6][i] = '@'; }
	for (int i = 2; i < 5; i++) { p->look[5][i] = '@'; }

}

void HouseBuilderB::buildPipe()
{
	for (int j = 0; j < 5; j++)
	{
		p->look[j][3] = '@';
	}
}