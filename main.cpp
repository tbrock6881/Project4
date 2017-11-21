

/* 
 Implement a C++ program that prompts the user for 2 commands. 
 	Each input string should be a UNIX command, with arguments allowed. 
		For example, input 1 could be "ls -l" and input 2 could be "wc -l". 
 
 The program will then create a pipe and two child processes. 
 
 	The first child process will run the command specified in the first input. 
 	It will output to the pipe instead of standard output. 
 
	The second child process will run the command specified in the second input. 
 		It will take its input from the pipe rather than standard input. 
 
	The parent process will wait on its two children to complete, 
	then the whole thing will repeat. 
 
	Execution will stop when "quit" is entered as the first command.*
 */
//21
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

void parseString(string& , queue<string>&);
void forkThat(queue<string>& );

int main(int argc, char* argv[]) {

  string input;
  queue <string> parsedInput;

  do {
  	for (int i=0; i < 2 ; i++) {	
  		cout<<"enter command "<< i + 1<< " (incl. args) or quit: ";
  		getline(cin, input);
		if (input == "quit") {
			i = 1;	
		}
		else {
			parseString( input, parsedInput );
		}
  	}
	if (parsedInput.size() > 0 )  {
      		forkThat(parsedInput);
	}





  }while( input != "quit" );


return 0;
}

// this method parses strings
void parseString( string& input, queue<string>& parsedCommands) {

  char * holder;
  char *rawInput = new char[input.size() + 1] (); 
  strncpy( rawInput, input.c_str(), input.size() );

  holder = strtok(rawInput, " ");
  while (holder != NULL) {
	cout<<*holder<<endl;
  	parsedCommands.push( *holder );
	holder = strtok( NULL, " " );
  }
  
}
void forkThat(queue<string>& parsedCommands) {

    /*collect command with flags
     *
     *
     */



/*  
    char *firstCommand, *secondCommand, *holder;

     
     firstCommand = parsedCommands.pop();
     holder = parsedCommands.front();
     
     if (holder[0] == '-') {
	     holder = parsedCommands.pop();
	     firstCommand = firstCommand + " " + holder;
     }
  secondCommand = parsedCommands.pop();
     holder = parsedCommands.front();
     
     if (holder[0] == '-') {
	     secondCommand = secondCommand + " " + parsedCommands.pop(); 
     }
	
     cout<< "1) " << firstCommand << "2) " << secondCommand << endl;
*/

