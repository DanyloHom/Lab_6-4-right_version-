#include <iostream>
#include "Vector.h"

using namespace std;
int main()
{
	try
	{
		Vector<double> V(4), U(4), Z(4), T(4);
		cin >> V;
		cin >> U;
		T = V + U;
		cout << "summa of vectors:" << endl;
		cout << T;
		Z += V;
		Z += U;
		cout << "summa of vectors:" << endl;
		cout << Z;
		cout << "min element = " << Z.ext("min") << endl;
		Z.sort("up");
		cout << "sorted:" << endl;
		cout << Z;
		cout << "norma = " << Z.norma() << endl;
		bool ok = Z.Dublikat();
		if (ok)
			cout << "there is a copy " << endl;
		if (!ok)
			cout << "there aren`t copies " << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}

	system("pause");
	return 0;
}