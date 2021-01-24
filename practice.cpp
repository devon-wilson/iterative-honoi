#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void backwards(ifstream& infile)
{
	string contents;
	if(getline(infile, contents))
	{
		backwards(infile);
		cout << contents << endl;
	}
}

int main()
{
	ifstream infile;
	infile.open("SampleTextFile_20kb.txt");
	if(!infile)
	{
		cout << "unable to open file " << endl;
		return 1;
	}
	backwards(infile);
}
