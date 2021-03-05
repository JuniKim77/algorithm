#include <iostream>
#include "WUF.h"

using namespace std;

int main()
{
	WUF uf(10);

	uf.unionDots(4, 3);
	uf.unionDots(3, 8);
	uf.unionDots(6, 5);
	uf.unionDots(9, 4);
	uf.unionDots(2, 1);
	uf.unionDots(8, 9);
	uf.unionDots(5, 0);
	uf.unionDots(7, 2);
	uf.unionDots(6, 1);
	uf.unionDots(1, 0);
	uf.unionDots(6, 7);

	return 0;
}