// App1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"
#include "Control.h"
#include "headers.h"
#include <future>

int main()
{
	Control mainGameObj;
	char x;

	cout << "Press s to start \n";
	cin >> x;

	if (x == 's' || x == 'S')
	{
		mainGameObj.gameLoop();
	}
		
		
	cout << "Good Bye! " << endl;

	system("pause");
    return 0;
}

