#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
class HouseBuilder;
class HouseBuilderA;
class HouseBuilderB;

class House : public DestroyableGroundObject
{
public:
	House();
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
	friend HouseBuilder;
	friend HouseBuilderA;
	friend HouseBuilderB;
private:
	char look[14][7];
	const uint16_t score = 40;
};

class HouseBuilder
{
protected:
	House* p;
public:
	HouseBuilder() : p(0) {};
	virtual ~HouseBuilder() {};

	virtual void createHouse() {}

	virtual void buildFoundation() {}
	virtual void buildWall() {}
	virtual void buildCeiling() {}
	virtual void buildRoof() {}
	virtual void buildPipe() {}

	virtual House* getHouse() { return p; }
};
// ��� � - ���������� ��� � ������ ��� �����
class HouseBuilderA : public HouseBuilder
{
public:
	void createHouse() { p = new House; }
	void buildFoundation();
	void buildWall();
	void buildCeiling();
	void buildRoof();

	/*void buildInfantryman() { p->vi.push_back(Infantryman()); }
	void buildArcher() { p->va.push_back(Archer()); }
	void buildHorseman() { p->vh.push_back(Horseman()); }
	void buildCatapult() { p->vc.push_back(Catapult()); }*/
};

//��� B - ���������� ��� � ������ c ������
class HouseBuilderB : public HouseBuilder
{
public:
	void createHouse() { p = new House; }
	void buildFoundation();
	void buildWall();
	void buildCeiling();
	void buildRoof();
	void buildPipe();
};

// �����-�������������, �������� ��������� ����
// ������ ����� ��������� �������� ���������� �����.
class Director
{
public:
	House* createHouse(HouseBuilder& builder)
	{
		builder.createHouse();
		builder.buildFoundation();
		builder.buildWall();
		builder.buildCeiling();
		builder.buildRoof();
		builder.buildPipe();
		return (builder.getHouse());
	}
};
/*� ��� � ���� ���� ������� ������ House:
class House : public DestroyableGroundObject
������� � ���� ������� ������:
char look[7][14];

������ ����� ��������� ���������� ����������� ���� � ���������� �����������
�������� Draw ����� std::cout. 

�������� � ������ House ������������� ����� HouseBuilderA � 
�� ����� �������������� ��� ��� (��������� ������) �� ������: 
�����, �����, �����,����. 

����� HouseBuilderA ����� ����������� HouseBuilder.
��� ������� ����� ������� � ����� HouseDirector, ������� ����� ����� ��������� ������� Construct, �
������� ������� ����� �����, ��������, ������� ��� � ������ ��� ��� �����,
� ��������� ��� ������� �����. 
� ������������ SBomber �������� � ������������, ����� ��������� ��� ��� �����, 
� ������������ ���� ��� � ������� HouseDirector. �� ��������
�������� ��������� ��� � ������ ����������� ��������.*/

