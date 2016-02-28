#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	int key;
	char erod;
	string phrase;
	string output;
	fstream inFile;
	fstream outFile;
	char ch;
	//ask if you want to encrypt or decrypt
	
	cout<<"Enter letter 'e' to encrypt or letter 'd' to decrypt:"<<endl;
	cin.get(erod);
	cin.ignore();
	
	//ask for sentence to be encrypted or to be decrypted
	
	switch(erod){
		case 'e':
		case 'E':cout<<"Enter word to be encrypted : "<<endl;
				 getline(cin,phrase);;
				 break;	 
				 
		case 'd':
		case 'D':cout<<"Enter word to be decrypted : "<<endl;
				 getline(cin,phrase);
				 break;
				 
		default:cout<<"Invalid entry.";
				return 1;
	}
	
	cout<<"Input key : "<<endl;
	cin>>key;
		
	if (key<=0){
		cout<<"Key should be a number greater than 0"<<endl;
		return 1;
	}

	//out put to file
	inFile.open("input.txt",ios::out);
	if(inFile){
		inFile<<phrase;
	}
	inFile.close();

	// opens files
	inFile.open("input.txt",ios::in);
	outFile.open("out.txt",ios::out);

//gets char ch from the files
	inFile.get(ch);
	//encrypts char ch
	if (erod=='e'||erod=='E'){
		while(inFile){
			output= ch+key;
			//outputs to screen 
			cout<<output;
			//output to file
			outFile<<output;
			//repeat
			inFile.get(ch);		
		}
	}
	//decrypts char ch
	if (erod=='d'||erod=='D'){
		while(inFile){
			output= ch-key;
			//outputs to screen 
			cout<<output;
			//output to file
			outFile<<output;
			//repeat
			inFile.get(ch);		
		}
	}

	//closes files
	inFile.close();
	outFile.close();

	cout<<endl<<endl;


	
	
	return 0;
}