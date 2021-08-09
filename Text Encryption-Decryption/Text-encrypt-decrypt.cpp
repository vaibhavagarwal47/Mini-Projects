#include<bits/stdc++.h>
#include<fstream>
using namespace std;

// Class for encrypting the text file
class Encryption
{
protected:
	ifstream inFile;
	ofstream outFile;
public:

	// Constructor opens the input and output file.
	Encryption(char *inFileName, char *outFileName)
	{
		inFile.open(inFileName);
		outFile.open(outFileName);
		if (!inFile)
		{
			cout << "The File " << inFileName
			     << " cannot be opened. " ;
			exit(1);
		}
		if (!outFile)
		{
			cout << "The File " << outFileName
			     << " cannot be opened. " ;
			exit(1);
		}
	}

	// Destructor that destroys the input and output file.
	~Encryption()
	{
		inFile.close();
		outFile.close();
	}
	// Pure virtual function
	virtual char transform(char ch) const = 0;

	// Actually encrypts the input file and stores it in output file.
	void encrypt()
	{
		char ch;
		char transCh;
		inFile.get(ch);
		while (!inFile.fail())
		{
			transCh = transform(ch);
			outFile.put(transCh);
			inFile.get(ch);
		}
	}
};


// The subclass simply overides the virtual transformation function
class SimpleEncryption : public Encryption
{
public:

	char transform(char ch) const
	{
		// this function returns every character in the file to 2 alphabets ahead of current one to the output file.
		return ch + 2;
	}
	SimpleEncryption(char *inFileName, char *outFileName):
		Encryption(inFileName, outFileName)
	{}
};

// ------------------------------------------------------------------------------------------


// Class for decrypting the text file
class Decryption
{
protected:
	ifstream inFile;
	ofstream outFile;
public:

	// Constructor opens the input and output file.
	Decryption(char *inFileName, char *outFileName)
	{
		inFile.open(inFileName);
		outFile.open(outFileName);
		if (!inFile)
		{
			cout << "The File " << inFileName
			     << " cannot be opened. " ;
			exit(1);
		}
		if (!outFile)
		{
			cout << "The File " << outFileName
			     << " cannot be opened. " ;
			exit(1);
		}
	}

	// Destructor that destroys the input and output file.
	~Decryption()
	{
		inFile.close();
		outFile.close();
	}

	// Pure virtual function
	virtual char transform(char ch) const = 0;

	// Actually decrypts the input file and stores it in output file.
	void decrypt()
	{
		char ch;
		char transCh;
		inFile.get(ch);
		while (!inFile.fail())
		{
			transCh = transform(ch);
			outFile.put(transCh);
			inFile.get(ch);
		}
	}
};


// The subclass simply overides the virtual transformation function
class SimpleDecryption : public Decryption
{
public:

	char transform(char ch) const
	{
		// this function returns every character in the file to 2 alphabets ahead of current one to the output file.
		return ch - 2;
	}
	SimpleDecryption(char *inFileName, char *outFileName):
		Decryption(inFileName, outFileName)
	{}
};

// ------------------------------------------------------------------------------------------


// Main function
int main()
{
	system("cls");
	char inFileName[200], outFileName[200];
	int again = 1;
	do
	{
		system("cls");
		cout << "\t\t\t\t\t\t--------------------------------" << endl;
		cout << "\t\t\t\t\t\t| TEXT ENCRYPTION / DECRYPTION |" << endl;
		cout << "\t\t\t\t\t\t--------------------------------" << endl;
		string choice;
		cout << "> What do you want to perform : \n # Encryption \n # Decryption" << endl << endl;
		cout << "> ";
		cin >> choice;
		cout << endl;
		if (choice == "Encryption" || choice == "encryption")
		{
			cout << "> Enter Name of the File to Encrypt: ";
			cin >> inFileName;
			cout << "> Enter Name of the File to receive the Encrypted Text: " ;
			cin >> outFileName;
			SimpleEncryption obfuscate(inFileName, outFileName);
			obfuscate.encrypt();
			cout << "> Sucessfully Encrypted." << endl;
			cout << "> Check File { " << outFileName << " } for the Encrypted Text." << endl;
		}
		if (choice == "Decryption" || choice == "decryption")
		{
			cout << "> Enter Name of File to Decrypt: ";
			cin >> inFileName;
			cout << "> Enter Name of File to receive the Decrypted Text: " ;
			cin >> outFileName;
			SimpleDecryption obfuscate(inFileName, outFileName);
			obfuscate.decrypt();
			cout << "> Sucessfully Decrypted." << endl;
			cout << "> Check File { " << outFileName << " } for the Decrypted Text." << endl;
		}
		cout << endl << endl;
		cout << "> Want to do more Encryption/Decryption, Press 1." << endl;
		cout << "> Want to exit the Program, Press 0." << endl;
		cout << "> ";
		cin >> again;
	} while (again != 0);
	return 0;
}