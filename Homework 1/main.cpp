#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string LALPHA = "abcdefghijklmnopqrstuvwxyz";
const string UALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct Book {
	string title;
	string author;
	int wordCount;
	float letterFreq[26];
	int newLineCount;
};

int main(void) {
	
	string filename;
	ifstream fstr;
	string line;
	vector<string> contents;
	Book b = {NULL, NULL, 0, NULL, 0};

	do {
		cout << "Enter the name of the file to be processed: ";
		cin >> filename;
		try {
			fstr.open(filename);
			if (fstr)
				break;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		cout << "File does not exist." << endl << endl;
	} while (!fstr);

	Book b;
	b.wordCount = 0;
	b.newLineCount = 0;

	getline(fstr, line);
	b.title = line;

	getline(fstr, line);
	b.author = line;

	while (getline(fstr, line)) {
		if (line.compare(0, 8, "Contents") == 0)
			break;
	}

	fstr >> line;
	while (fstr) {
		b.wordCount++;
		contents.push_back(line);
		fstr >> line;
	}


	cout << contents.size() << endl;

	system("pause");
	return 0;
}