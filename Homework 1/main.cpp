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
	int letterFreq[26];
	int newLineCount;
};

int main(void) {
	
	string filename;
	ifstream lineFstrstr;
	ifstream wordFstrstr;
	string line;
	vector<string> lineContents;
	vector<string> strContents;

	do {
		cout << "Enter the name of the file to be processed: ";
		cin >> filename;
		try {
			lineFstrstr.open(filename);
			wordFstrstr.open(filename);
			if (lineFstrstr)
				break;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		cout << "File does not exist." << endl << endl;
	} while (!lineFstrstr);

	Book b;
	b.wordCount = 0;
	b.newLineCount = 0;

	getline(lineFstrstr, line);
	b.title = line;

	getline(lineFstrstr, line);
	b.author = line;

	while (getline(lineFstrstr, line)) {
		if (line.compare(0, 8, "Contents") == 0)
			break;
	}

	while (getline(wordFstrstr, line)) {
		if (line.compare(0, 8, "Contents") == 0)
			break;
	}

	getline(lineFstrstr, line);
	while (lineFstrstr) {
		b.newLineCount++;
		lineContents.push_back(line);
		getline(lineFstrstr, line);
	}

	wordFstrstr >> line;
	while (wordFstrstr) {
		b.wordCount++;
		strContents.push_back(line);
		wordFstrstr >> line;
	}

	// Save the info in cardcatalog.txt
	ofstream output("CardCatalog.txt", std::ios_base::app | std::ios_base::out);
	output << "Title: " << b.title << endl;
	output << "Full Author: " << b.author << endl;

	int pos = b.author.find(' ');
	output << "Author First Name: " << b.author.substr(0, pos) << endl;
	output << "Author Last Name: " << b.author.substr(pos + 1, b.author.size()) << endl;

	output << "Word Count: " << b.wordCount << endl;
	output << "Line Count: " << b.newLineCount << endl;

	cout << lineContents.size() << endl;
	cout << strContents.size() << endl;

	for (int i = 0; i < sizeof(b.letterFreq) / sizeof(int); i++) {
		b.letterFreq[i] = 0;
	}

	for (int i = 0; i < strContents.size(); i++) {
		for (int j = 0; j < strContents[j].size(); j++) {
			b.letterFreq[LALPHA.find(tolower(strContents[i][j]))]++;
		}
	}

	system("pause");
	return 0;
}