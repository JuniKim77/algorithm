#include "WUF.h"

WUF::WUF(int size)
	: mCount(size)
{
	pParent = new int[size];
	pWeight = new int[size];
	for (int i = 0; i < size; ++i)
	{
		pParent[i] = i;
		pWeight[i] = 1;
	}
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

	while (idx != pParent[idx])
	{
		idx = pParent[idx];
	}

	return idx; // »Ñ¸® ¹ÝÈ¯
}

void WUF::unionDots(int p, int q)
{
	int rootP = find(p);
	int rootQ = find(q);

	if (rootP == rootQ) return;

	if (pWeight[rootP] < pWeight[rootQ])
	{
		pParent[rootP] = rootQ;
		pWeight[rootQ] += pWeight[rootP];
	}
	else
	{
		pParent[rootQ] = rootP;
		pWeight[rootP] += pWeight[rootQ];
	}

	--mCount;
}
