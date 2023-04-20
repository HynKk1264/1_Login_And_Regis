#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;
	ifstream read("./data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsExistingUser(const string& username)
{
	ifstream file("./data\\" + username + ".txt");
	return file.good();
}


int main()
{
	int choice = 0;
	bool quit = false;

	while (!quit)
	{
		cout << "1: Register\n";
		cout << "2: Login\n";
		cout << "3: Quit\n";
		cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string username, password;

			cout << "Select a username: "; cin >> username;

			if (IsExistingUser(username))
			{
				cout << "Username already exists, please select another one" << endl;
				main();
			}

			cout << "Select a password: "; cin >> password;

			ofstream file;
			file.open("./data\\" + username + ".txt");
			file << username << endl << password;
			file.close();

			cout << "Successfully registered" << endl;
			break;
		}
		case 2: 
		{
			bool status = IsLoggedIn();
			if (!status) {
				cout << "False login" << endl;
				system("PAUSE");
				return 0;
			}
			else {
				cout << "Succesfully logged in" << endl;
				system("PAUSE");
				return 1;
			}
			break;
		}
		case 3:
			quit = true;
			break;
		default:
			cout << "Invalid choice, please try again." << endl;
			break;
		}
	}

	return 0;
}

/*
int main()
{
	int choice;

	cout << "1: Register\n";
	cout << "2: Login\n";
	cout << "Your choice: "; cin >> choice;
	if (choice == 1)
	{
		string username, password;

		cout << "Select a username: "; cin >> username;
		cout << "Select a password: "; cin >> password;

		ofstream file;
		
		file.open("./data\\" + username + ".txt");
		file << username << endl << password;
		
		file.close();

		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "False login" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Succesfully logged in" << endl;
			system("PAUSE");
			return 1;
		}
	}
	else
	{
		cout << "Invalid, try again!" << endl;
		main();
	}
}
*/