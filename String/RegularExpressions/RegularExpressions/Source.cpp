#include <iostream>
#include <regex>

using namespace std;

void printMatches(string str, regex reg) {
	smatch matches;
	cout << boolalpha;
	while (regex_search(str, matches, reg)) {
		cout << "Is there a match? : " << matches.ready() << "\n";
		cout << "Are there no matches? : " << matches.empty() << "\n";
		cout << "Number of matches : " << matches.size() << "\n";
		cout << matches.str(1) << "\n";
		str = matches.suffix().str();
		cout << "\n";

	}
}

void printMatches2(string str, regex reg) {
	sregex_iterator currentMatch(str.begin(), str.end(), reg);
	sregex_iterator lastMatch;
	while (currentMatch != lastMatch) {
		smatch match = *currentMatch;
		cout << match.str() << "\n";
		currentMatch++;
	}
	cout << endl;
}

int main() {
	string str = "The ape was at the apex";
	//Anything that has "pick" and ends with a char
	regex reg("(ape[^ ]?)");
	printMatches(str, reg);

	//anything that has "pick" followed by 1 or more chars that is not " "
	string str2 = "I picked the pickle";
	regex reg2("(pick([^ ]+)?)");
	printMatches2(str2, reg2);

	//Anything that starts with crmpfp
	string str3 = "Cat rat mat far pat";
	regex reg3("([crmfp]at)"); //Cat didn't match here
	printMatches2(str3, reg3);

	//Anything that starts with C-F or c-f
	regex reg4("([C-Fc-f]at)");
	printMatches2(str3, reg4);

	//Anything that doesn't start with uppercase C or lowercase r
	regex reg5("([^Cr]at)");

	string str6 = "Cat rat mat far pat";
	regex reg6("([Cr]at)");
	string owlFood = regex_replace(str6, reg6, "Owl");
	cout << owlFood << "\n\n";

	string str7 = "F.B.I. I.R.S. CIA";
	regex reg7("([^ ]\..\..\.)");
	printMatches2(str7, reg7);

	string str8 = "This is a\n\t multiline string\n\r that has many lines.";
	regex reg8("\\n|\\t|\\r");
	string noLBStr = regex_replace(str8, reg8, "");
	//you can replce
	// \b : backspace
	// \f : form feed
	// \r : carriage return
	// \t : tab
	// \v : vertical tab
	cout << noLBStr << endl;

	// \d [0-9]
	// \D [^0-9]
	string str9 = "123456";
	regex reg9("\\d");
	printMatches2(str9, reg9);

	string str10 = "123 12345 123456 1234567";
	regex reg10("\\d{5,7}");
	printMatches2(str10, reg10);

	// \w [a-zA-Z0-9]
	// \W [^a-zA-Z0-9]
	string str11 = "412-867-5309";
	regex reg11("\\w{3}-\\w{3}-\\w{4}");
	printMatches2(str11, reg11);

	// \s [\f\n\r\t\v]
	// \S [^\f\n\r\t\v]
	string str12 = "Mohanakrishna Vanamala Hariprasad";
	regex reg12("\\w{2,20}\\s\\w{2,20}\\s\\w{2,20}");
	printMatches2(str12, reg12);

	string str13 = "a as ape bug";
	regex reg13("a[a-z]+");
	printMatches2(str13, reg13);

	string str14 = ("db@aol.com m@.com @apple.com db@.com");
	regex reg14("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");
	printMatches2(str14, reg14);
	return 0;
}