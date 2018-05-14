struct account
{
	int number;
	char lastname [15];
	char firstname [15];
	float balance;
	struct account * next;
};

typedef struct account * firsta, * currenta, * newa, * previousa;
