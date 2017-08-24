//AUTHOR:ZQS_SIAT
//DATE:2017-0803
//ABSTRACT:read the file of txt,store it in arrays
#include<iostream>
#include<fstream>
#include<string>
#include"stdlib.h"

using namespace std;

///Read file's line numbers
int CountLines(char *filename);

void main(void)
{
	ifstream file;
	int LINES;
	char filename[512];
	cout << "Please import the file name that you want to open: " << endl;
	cin >> filename;
	file.open(filename,ios::in);
	if (file.fail())
	{
		cout << "The file is not existing!" << endl;
		file.close();
		system("pause");
	}
	else
	{
		LINES = CountLines(filename);
		int *tc = new int[LINES];
		char *t = new char[LINES];
		int i = 0;
		while (!file.eof())
		{
			file >> tc[i];
			file >> t[i];
			i++;
		}
		file.close();
		for (i = 0; i < LINES; i++)
			cout << tc[i] << "\t" << t[i] << endl;
		system("pause");
	}
}

int CountLines(char *filename)
{
	ifstream ReadFile;
	int n = 0;
	string temp;
	ReadFile.open(filename,ios::in);
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, temp))
		{
			n++;
		}
		return n;
	}
	ReadFile.close();

}