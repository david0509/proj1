#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char ** result;


char ** decimalToDecimal (int argc, char* argv[])
{

}

char ** decimalToBinary (int argc, char* argv[])
{
    int p = 1, r = argv[2];

    char *bin = (char*)malloc(sizeof(char) * 100);

    itoa(r, bin, 2);

    return bin;
}

char ** decimalToHex (int argc, char* argv[])
{

}

char ** binaryToDecimal(int argc, char* argv[])
{
    int p = 1, r = argv[2];

	char *dec = (char*)malloc(sizeof(char) * 100);

	itoa(r, dec, 10);

	return dec;
}

char ** binaryToBinary (int argc, char* argv[]) {

}

char ** binaryToHex(int argc, char* argv[])

{
    int p = 1, r = argv[2];

	char *hex = (char*)malloc(sizeof(char) * 100);

	itoa(r, hex, 16);

	return hex;
}

char ** hexToDecimal (int argc, char* argv[]) {

}
char ** hexToBinary (int argc, char* argv[]) {

}
char ** hexToHex (int argc, char* argv[]) {

}

// Redirect to corresponding function
void seekUserInput(int argc, char* argv[]) {
  if (strcmp(argv[0], "binary") && strcmp(argv[1], "decimal")) result = binaryToDecimal(argc, argv);
  else if (strcmp(argv[0], "binary") && strcmp(argv[1], "binary")) result = binaryToBinary(argc, argv);
  else if (strcmp(argv[0], "binary") && strcmp(argv[1], "hex")) result = binaryToHex(argc, argv);
  else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "decimal")) result = decimalToDecimal(argc, argv);
  else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "binary")) result = decimalToBinary(argc, argv);
  else if (strcmp(argv[0], "decimal") && strcmp(argv[1], "hex")) result = decimalToHex(argc, argv);
  else if (strcmp(argv[0], "hex") && strcmp(argv[1], "decimal")) result = hexToDecimal(argc, argv);
  else if (strcmp(argv[0], "hex") && strcmp(argv[1], "binary")) result = hexToBinary(argc, argv);
  else if (strcmp(argv[0], "hex") && strcmp(argv[1], "hex")) result = hexToHex(argc, argv);
}

// Check if user input contains letters
bool inputValidation(int argc, char *argv[]) {
  if( strcmp(argv[0], "binary") || strcmp(argv[0], "decimal")) {
    for (int i=2;i<argc;i+=1)  {
      char *pos = argv[i];
      while (*pos != '\0')  {
        if ( !isdigit(*(pos++)) ) return false;
      }
    }
    return true;
  }
  return true;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("ERROR: You have to insert at least 3 argumetns.");
		system("pause");
		return 0;
	}
  result = (char**) malloc(argc*4);
	if ( inputValidation(argc, argv) )
    seekUserInput(argc, argv);


  printf("%s\n", "System exit.");
	system("pause");
	return 0;

}
