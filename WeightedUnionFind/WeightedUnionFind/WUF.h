class WUF
{
public:
	WUF(int size);
	~WUF();

	bool isConnected(int p, int q);
	int find(int p);
	void unionDots(int p, int q);

private:
	int mCount;
	int* pParent;
	int* pWeight;
};