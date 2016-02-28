// Simple 1 key Ceasers Cipher
// reads txt from file

//20 February, 2014

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

main(){
	
	int key;
	char erod;
	fstream eb;
	fstream ebout;
	char ch;
	string  output;
	
	
	//ask if you want to encrypt or decrypt
	
	cout<<"Enter letter 'e' to encrypt or letter 'd' to decrypt:"<<endl;
	cin>>erod;
	
	cout<<"Input key : "<<endl;
	cin>>key;
		
	if (key<=0){
		cout<<"Key should be a number greater than 0 !!"<<endl;
		return 1;
	}
	
	eb.open("input.txt",ios::in);
	
	ebout.open("out.txt",ios::out);
	
	eb.get(ch);
	
	if (erod=='e'||erod=='E'){
		cout<<"1";
		while(eb){
			output= ch+key;
			cout<<output;
			ebout<<output;
			eb.get(ch);		
		}
	}else if (erod=='d'||erod=='D'){
		while(eb){
			output= ch-key;
			cout<<output;
			ebout<<output;
			eb.get(ch);		
		}
	}
	
	eb.close();
	ebout.close();
	
	//print output
	
	
	
	
	return 0;
}
