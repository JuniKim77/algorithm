#include "WUF.h"

WUF::WUF(int size)
	: mCount(size)
{
	pParent = new int[size];
	pWeight = new int[size];
}

WUF::~WUF()
{
	delete[] pParent;
	delete[] pWeight;
}

bool WUF::isConnected(int p, int q)
{
	return find(p) == find(q);
}

int WUF::find(int p)
{
	int idx = p;

	while (p != pParent[idx])
	{
		idx = pParent[idx];
	}

	return idx; // »Ñ¸® ¹ÝÈ¯
}

void WUF::unionDots(int p, int q)
{

}
