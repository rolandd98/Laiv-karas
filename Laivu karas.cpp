#include <iostream>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

//DARYTA su REPL.it

void Botskaic(int &x, int &y, char &krypt)
{
	int k;

	x = rand() % 10;
	y = rand() % 10;
	k = rand() % 2;
	if (k == 1)krypt = 'h';
	else krypt = 'v';

}

class laivai
{
private:
	char A[10][10];
	int a = 1;
	bool apsuk;
	int i = 0;
	int Xm[4], Ym[4];
public:

	void uzpildyt()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				A[i][j] = '-';
			}
		}
	}

	void iterpti(char krypt, int x, int y, int d)
	{

		if (krypt == 'h')
		{
			while (d)
			{
				A[y][x] = '@';
				d--;
				x++;
			}
		}
		else
			while (d)
			{
				A[y][x] = '@';
				d--;
				y++;
			}

	}

	void rodyti()
	{
		cout << "   " << "A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (i < 9)
				cout << " " << i + 1 << " ";
			else
				cout << i + 1 << " ";
			for (int j = 0; j < 10; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}

	void rodytieil(int i)
	{
		for (int j = 0; j < 10; j++)
			cout << A[i][j] << " ";
	}

	void tikrinimas(char krypt, int x, int y, int d, bool &test)
	{
		int x1, y1, x2, y2;

		x1 = x - 1;
		y1 = y - 1;

		//ribu nustatymas

		if (krypt == 'h')
		{
			x2 = x1 + d + 1;
			y2 = y1 + 2;
		}
		else
		{
			x2 = x1 + 2;
			y2 = y1 + d + 1;
		}

		if (x2 > 10)test = false;
		if (y2 > 10)test = false;


		if (x1 < 0)x1 = 0;
		if (y1 < 0)y1 = 0;
		if (x2 > 9)x2 = 9;
		if (y2 > 9)y2 = 9;

		/*
			cout << "x " << x << endl;
			cout << "y " << y << endl;
			cout << "x1 " << x1 << endl;
			cout << "y1 " << y1 << endl;
			cout << "x2 " << x2 << endl;
			cout << "y2 " << y2 << endl;
		*/
		//testas


		if (x < 0 || y < 0 || x>9 || y>9)
			test = false;
		else
		{
			for (int i = y1; i <= y2; i++)
				for (int j = x1; j <= x2; j++)
				{
					if (A[i][j] == '@')
						test = false;
				}
		}



	}

	void sauti1(int x, int y, bool &test)
	{
		if (A[y][x] == '@')
			test = true;
		else
			test = false;
	}

	void sauti2(int x, int y, char s)
	{
		A[y][x] = s;
	}

	void apvedimas(int x, int y, bool apvesti)
	{
		int minx, miny, maxx, maxy;
		bool test1 = true, test2 = true, test3 = true, test4 = true;

		if (apvesti == false)
		{
			Xm[i] = x;
			Ym[i] = y;
			i++;
		}
		else
		{
			// cout<<"VYGDOMAS APVEDIMAS"<<endl;
			minx = Xm[0];
			miny = Ym[0];
			maxx = Xm[0];
			maxy = Ym[0];
			for (int j = 1; j < i; j++)
			{
				if (Xm[j] < minx || Ym[j] < miny)
				{
					minx = Xm[j];
					miny = Ym[j];
				}
				if (Xm[j] > maxx || Ym[j] > maxy)
				{
					maxx = Xm[j];
					maxy = Ym[j];
				}
			}
			// cout<<minx<<" "<<miny<<endl;
		   //  cout<<maxx<<" "<<maxy<<endl;
			minx--;
			miny--;
			maxx++;
			maxy++;
			if (minx < 0)
			{
				minx = 0;
				test1 = false;
			}
			if (miny < 0)
			{
				miny = 0;
				test2 = false;
			}
			if (maxx > 9)
			{
				maxx = 9;
				test3 = false;
			}
			if (maxy > 9)
			{
				maxy = 9;
				test4 = false;
			}

			for (int i = minx; i <= maxx; i++)
				for (int j = miny; j <= maxy; j++)
				{
					A[j][i] = 'M';
				}
			if (test1)minx++;
			if (test2)miny++;
			if (test3)maxx--;
			if (test4)maxy--;
			for (int i = minx; i <= maxx; i++)
				for (int j = miny; j <= maxy; j++)
				{
					A[j][i] = 'X';
				}
			i = 0;
		}

	}

	void Botoprotas1(int &x, int &y)
	{


		// cout<<"naudojamas botoprotas 1"<<endl;

		bool test = true;
		char krypt;

		while (test)
		{
			Botskaic(x, y, krypt);
			if (A[y][x] != 'M' && A[y][x] != 'X')
				test = false;
		}


	}

	void Botoprotas2(int &x, int &y, bool &botsuvis, int &botstadija)
	{
		/*                 //TESTAI
		cout<<"naudojamas botoprotas 2"<<endl;
		cout<<"x= "<<x<<endl;
		cout<<"y= "<<y<<endl;
		cout<<"botsuvis= "<<botsuvis<<endl;
		cout<<"botstadija= "<<botstadija<<endl;
		cout<<"apsuk="<<apsuk<<endl;
		cout<<"a= "<<a<<endl;
		*/
		if (botstadija == 1)
		{
			//  cout<<"1 TESTAS\n";
// cout<<"pasiekta 1 stadija"<<endl;

			if (a == 1)
			{
				x++;
			}
			else if (a == 2)
			{
				x--;
				y++;
			}
			else if (a == 3)
			{
				y--;
				x--;
			}
			else if (a == 4)
			{
				x++;
				y--;
			}
			a++;
			if (a == 5)
			{
				a = 1;
				apsuk = false;
				botstadija = 0;
				apvedimas(x, y, true);
			}
		}
		else if (botstadija > 1 && botsuvis == true && apsuk == false)
		{
			//   cout<<"2 TESTAS\n";
		  // cout<<"pasiekta 2 stadija"<<endl;

			if (a == 2)
			{
				x++;
			}
			else if (a == 3)
			{
				y++;
			}
			else if (a == 4)
			{
				x--;
			}
			else if (a == 0)
			{
				y--;
			}
			if (x < 0 || y < 0 || x>9 || y>9)
			{
				// cout<<"NAUDOJAMAS X<0 protokolas"<<endl;
				a = 1;
				apsuk = false;
				botstadija = 0;
				Botoprotas1(x, y);
				apvedimas(x, y, true);
			}
		}
		else if (apsuk == false || (apsuk == true && botsuvis == true))
		{

			// cout<<"3 TESTAS\n";


			int i, j;

			if (a == 2)
			{
				j = x - 1;
				i = y;
			}
			if (a == 3)
			{
				i = y - 1;
				j = x;
			}
			//  cout<<"4 TESTAS\n";

			if (a == 2 || a == 3)
			{
				while (A[i][j] == 'X')
				{
					if (a == 2)
					{
						j--;
					}
					else if (a == 3)
					{
						i--;
					}
				}
			}
			if (a == 2 || a == 3)
			{
				y = i;
				x = j;
				apsuk = true;
				if (x < 0 || y < 0)
				{
					// cout<<"NAUDOJAMAS X<0 protokolas"<<endl;
					a = 1;
					apsuk = false;
					botstadija = 0;
					Botoprotas1(x, y);
					apvedimas(x, y, true);
				}
			}
			else
			{
				//cout<<"Naudojamas pirmas isejimas"<<endl;
				a = 1;
				apsuk = false;
				botstadija = 0;
				Botoprotas1(x, y);
				apvedimas(x, y, true);
			}
			// cout<<"5 TESTAS\n";
		}
		else
		{
			// cout<<"Naudojamas Antras isejimas"<<endl;
			a = 1;
			apsuk = false;
			botstadija = 0;
			Botoprotas1(x, y);
			apvedimas(x, y, true);
		}

		if ((A[y][x] == 'X' || A[y][x] == 'M') || (x < 0 || y < 0 || x>9 || y>9))
		{

			//     cout<<"6 TESTAS\n";
			Botoprotas2(x, y, botsuvis, botstadija);

		}
	}

};

void cls(int i)
{
	for (int j = 0; j < i; j++)
		cout << endl;
	//cout << string(i, '\n');  //visual studio nepatinka toks
}

void Rodytilauka(laivai Rolships, laivai Rolhit, laivai Botships, laivai Bothit, int rg, int bg)
{
	cls(1);

	cout << " Tavo gyvybes= " << rg << "                " << "Boto gyvybes= " << bg << endl;
	cout << "   " << "A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J" << "    |      " << "A " << "B " << "C " << "D " << "E " << "F " << "G " << "H " << "I " << "J" << endl;

	for (int i = 0; i < 10; i++)
	{

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		Rolships.rodytieil(i);
		cout << "   " << "|" << "   ";
		//cout << string(3, ' ') << "|" << string(3, ' ');  //visual studio nepatinka toks

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		//	Botships.rodytieil(i);
		Bothit.rodytieil(i);
		cout << endl;
	}
	cout << endl;

	/*
	for(int i=0; i<10; i++)
	{
	cout<<"   ";
	Rolhit.rodytieil(i);
	cout<<"   |      ";
	Bothit.rodytieil(i);
	cout<<endl;
	}
	*/
	cls(1);
}

void Sauti(int x, int y, laivai &Botships, laivai &Bothit, bool &suvis)
{
	bool test;
	char s;
	Botships.sauti1(x, y, test);
	if (test)
		s = 'X';
	else
		s = 'M';
	Botships.sauti2(x, y, s);
	Bothit.sauti2(x, y, s);
	//cout<<endl<<"x= "<<x<<" y= "<<y<<" s= "<<s<<endl;
	suvis = test;
}

int main()
{
	ifstream df("in.txt");

	laivai Rolships, Rolhit, Botships, Bothit;

	bool test, suvis, botsuvis = false;
	int x, y;
	char r;
	char krypt;
	int k = 0, j = 0;
	int rg = 20, bg = 20; //gyvybes




	int xb, yb, botstadija = 0; //Boto protas
	bool bottest = false;



	//zaidejo laivu iterpimas

	Rolships.uzpildyt();
	Rolships.rodyti();

	for (int i = 4; i != 0; i--)
	{
		k = k + 1;
		j = k;
		while (j)
		{
			test = true;
			cout << "Iterpkite " << i << " dydzio laiva, iveskite x, y" << endl;
			cls(15);

			//	df >> r >> y;
			cin >> r >> y;

			x = r - 64;

			x--;
			y--;

			if (i != 1)
			{
				cout << "vertikaliai - v horizontaliai - h" << endl;

				//	df >> krypt;
				cin >> krypt;

			}
			else krypt = 'h';

			Rolships.tikrinimas(krypt, x, y, i, test);
			if (test)
			{

				cls(15);
				//cout << endl << "x=" << x << "\ny=" << y << endl << endl; //testas

				Rolships.iterpti(krypt, x, y, i);

				Rolships.rodyti();

				j--;
			}
			else
			{
				Rolships.rodyti();
				cout << "Kordinates netinkamos\n";
			}
		}
	}


	//boto laivu iterpimas

	srand(time(NULL));

	k = 0;
	j = 0;

	Botships.uzpildyt();

	for (int i = 4; i != 0; i--)
	{
		k = k + 1;
		j = k;
		while (j)
		{
			test = true;

			Botskaic(x, y, krypt);


			Botships.tikrinimas(krypt, x, y, i, test);
			if (test)
			{
				Botships.iterpti(krypt, x, y, i);
				j--;



				//cout<<i<<" dydzio laivas\n";
				//Botships.rodyti();
			}
		}
	}

	Rolhit.uzpildyt();
	Bothit.uzpildyt();

	Rodytilauka(Rolships, Rolhit, Botships, Bothit, rg, bg);

	//Saudymas

	int kartas = 0;


	while (rg > 0 && bg > 0)
	{

		//Zaidejo suvis
		cout << "Kur noretumete sauti? x,y ";
		cin >> r >> y;
		//r='A';
		//y=1;
		x = r - 64;
		x--;
		y--;
		Sauti(x, y, Botships, Bothit, suvis);

		if (suvis)
		{
			cout << "Pataikei!" << endl;
			bg--;
		}
		else
			cout << "Nepataikei!" << endl;

		//Boto suvis


		if (botstadija == 0)
		{
			Rolhit.Botoprotas1(xb, yb);
		}
		else
		{
			Rolhit.Botoprotas2(xb, yb, botsuvis, botstadija);
		}

		Sauti(xb, yb, Rolships, Rolhit, botsuvis);

		if (botsuvis)
		{
			Rolhit.apvedimas(xb, yb, false);
			cout << "Botas pataike!" << endl;
			rg--;
			botstadija++;
		}
		else
		{
			cout << "Botas nepataike!" << endl;
		}

		Rodytilauka(Rolships, Rolhit, Botships, Bothit, rg, bg);
		kartas++;
		cout << endl << "tiek kartu: " << kartas << endl;
	}
	cout << "PABAIGA" << endl;
	if (bg == 0)cout << "Tu laimejai!" << endl;
	else cout << "Tu Pralaimejai!" << endl;

	cin >> bg;


	return 0;
}

/*
I 1 v
A 3 h
A 5 h
A 7 h
A 9 h
F 1 h
E 3
E 5
E 7
J 10
*/

