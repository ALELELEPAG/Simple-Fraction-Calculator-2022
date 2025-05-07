// ass4_40211512_Lepage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;
//a)
void input_fraction_matrix(int nom[3][3], int denom[3][3], int m, int n);
//b)
void print_fraction_matrix(int nom[3][3], int denom[3][3], int m, int n);
//c)
void fraction_operation(int a, int b, int c, int d, int& top, int& bot, int option);
//d)
void determinant(int nom[3][3], int denom[3][3], int& det_nom, int& det_denom);
//int det_nom_main, det_denom_main;

int main()
{
    int nom[3][3], denom[3][3], m=3, n=3;
	//e)
    input_fraction_matrix(nom, denom, 3, 3);
	//extra
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (denom[i][j] == 0) {
				cout << "Error : division by zero" << "\n";
				return 0;
			}
		}
	}
    print_fraction_matrix(nom, denom, 3,3);
	int det_nom, det_denom;
	//f)
	determinant(nom, denom, det_nom, det_denom);
	cout << "\n" << "Determinant = " << det_nom << " / " << det_denom << "\n";
	//g)
	if (det_nom != 0) {
		cout << "\nCalculating inverse matrix: \n";
		int inv_nom[3][3], inv_denom[3][3];
		int top = 0, bot = 0;
		fraction_operation(nom[2][2], denom[2][2], det_nom, det_denom, top, bot, 4);
		inv_nom[1][1] = top;
		inv_denom[1][1] = bot;
		fraction_operation(-nom[1][2], denom[1][2], det_nom, det_denom, top, bot, 4);
		inv_nom[1][2] = top;
		inv_denom[1][2] = bot;
		fraction_operation(-nom[2][1], denom[2][1], det_nom, det_denom, top, bot, 4);
		inv_nom[2][1] = top;
		inv_denom[2][1] = bot;
		fraction_operation(nom[1][1], denom[1][1], det_nom, det_denom, top, bot, 4);
		inv_nom[2][2] = top;
		inv_denom[2][2] = bot;
		cout << "\n";
		//e)
		print_fraction_matrix(inv_nom, inv_denom, 3, 3);
	}
	else {
		cout << "\nDeterminant is zero, inverse impossible.\n";
	}
	//extra
	int choice;
	cout << "Input any number to continue, 0 to quit :";
	cin >> choice;
	cout << "\n";
	if (choice == 0) {
		return 0;
	}
	while (choice != 0) {
		input_fraction_matrix(nom, denom, 3, 3);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (denom[i][j] == 0) {
					cout << "Error : division by zero" << "\n";
					return 0;
				}
			}
		}
		print_fraction_matrix(nom, denom, 3, 3);
		int det_nom, det_denom;
		determinant(nom, denom, det_nom, det_denom);
		cout << "\n" << "Determinant = " << det_nom << " / " << det_denom << "\n";
		if (det_nom != 0) {
			cout << "\nCalculating inverse matrix: \n";
			int inv_nom[3][3], inv_denom[3][3];
			int top = 0, bot = 0;
			fraction_operation(nom[2][2], denom[2][2], det_nom, det_denom, top, bot, 4);
			inv_nom[1][1] = top;
			inv_denom[1][1] = bot;
			fraction_operation(-nom[1][2], denom[1][2], det_nom, det_denom, top, bot, 4);
			inv_nom[1][2] = top;
			inv_denom[1][2] = bot;
			fraction_operation(-nom[2][1], denom[2][1], det_nom, det_denom, top, bot, 4);
			inv_nom[2][1] = top;
			inv_denom[2][1] = bot;
			fraction_operation(nom[1][1], denom[1][1], det_nom, det_denom, top, bot, 4);
			inv_nom[2][2] = top;
			inv_denom[2][2] = bot;

			print_fraction_matrix(inv_nom, inv_denom, 3, 3);
		}
		else {
			cout << "\nDeterminant is zero, inverse impossible.\n";
		}
		int choice;
		cout << "\nInput any number to continue, 0 to quit :\n";
		cin >> choice;
		cout << "\n";
		if (choice == 0) {
			return 0;
		}
	}
}

//a)
void input_fraction_matrix(int nom[3][3], int denom[3][3], int m, int n) {

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            cout << "Enter numerator and denominator of 2X2 matrix at position " << i << " " << j << "\n";
            cin >> nom[i][j];
            cout << "----" << "\n";
            cin >> denom[i][j];
            cout << "\n";
        }

    }
}

//b)
void print_fraction_matrix(int nom[3][3], int denom[3][3], int m, int n) {
    cout << "Matrix :" << "\n";
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int maxfact = 1;
            for (int f = 1; f < abs(nom[i][j])* abs(denom[i][j]); f++) {
                if (abs(nom[i][j]) % f == 0 && abs(denom[i][j]) % f == 0) {
                    maxfact = f;
                }
            }
            nom[i][j] /= maxfact;
            denom[i][j] /= maxfact;
            cout << nom[i][j] << "/" << denom[i][j] << "\t";
        }
        cout << "\n";
    }
}

//c)
void fraction_operation(int a, int b, int c, int d, int& top, int& bot, int option) {
	if (option == 1) {
		// implementing a/b + c/d = (ad + bc)/ bd
		top = a * d + b * c;
		bot = b * d;
		cout << a << '/' << b << " + " << c << '/' << d << " = ";
	}
	else if (option == 2) {
		top = a * d - b * c;
		bot = b * d;
		cout << a << '/' << b << " - " << c << '/' << d << " = ";
	}
	else if (option == 3) {
		cout << a << '/' << b << " * " << c << '/' << d << " = ";
		top = a * c;
		bot = b * d;

	}
	else if (option == 4) {
		cout << a << '/' << b << " / " << c << '/' << d << " = ";
		top = a * d;
		bot = b * c;

		if (bot == 0) {
			cout << "\nError can not divide by zero\n\n\n";
			exit(1);
		}
	}
	//simplify fraction
	int min = top;
	if (min > bot)
		min = bot;
	for (int i = min; i >= 2; i--) {
		if (top % i == 0 && bot % i == 0) {
			top /= i;
			bot /= i;
		}
	}
	//more simplifaction and print out operation result
	if (top == bot)
		cout << 1 << endl;
	else if (top == 0)
		cout << 0 << endl;
	else if (bot == 1)
		cout << top << endl;
	else {
		cout << top << "/" << bot << endl;
	}
}

//d)
void determinant(int nom[3][3], int denom[3][3], int& det_nom, int& det_denom) {

	int top=0, bot=0;
	cout << "\nCalculating maxtrix determinant: \n";
	fraction_operation(nom[1][1], denom[1][1], nom[2][2], denom[2][2], top, bot, 3);
	int ad_nom = top;
	int ad_denom = bot;

	fraction_operation(nom[2][1], denom[2][1], nom[1][2], denom[1][2], top, bot, 3);
	int bc_nom = top;
	int bc_denom = bot;

	fraction_operation(ad_nom, ad_denom, bc_nom, bc_denom, top, bot, 2);
	det_nom = top;
	det_denom = bot;
	int maxfact =1;
	for (int f = 1; f < abs(top * bot); f++) {
		if (abs(top) % f == 0 && abs(bot) % f == 0) {
			maxfact = f;
		}
	}
	det_nom = top/maxfact;
	det_denom = bot/maxfact;
	//det_nom_main = det_nom;
	//det_denom_main = det_denom;
	//cout << "\n" << "Determinant = " << det_nom << " / " << det_denom << "\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
