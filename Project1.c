/*
COMP 122
Chi Ieong Ng
10/6/2019
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** result;

// method to print a value in binary
void printInBinary(long int n)
{
    if( n )
    {
        printInBinary(n/2);
        if (n & 1)
            printf("1");
        else
            printf("0");
    }
}

// method to print result
void printResult(int index, int argc)
{
    // if no result to print using this function, return
    if( result == NULL )
        return;

    // if this is index is greater than equal to argc, return
    // else print
    if( index < argc )
    {
        // print this
        printf("%s\n",result[index]);

        // recur
        printResult(index+1,argc);
    }
}

void processDecimalToDecimal(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        // get the integer value to this
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,10);
        // copy this to the result
        result[index] = (char*)malloc(sizeof(char) * 20);
        sprintf(result[index],"%ld",value);
        processDecimalToDecimal(index+1,argc,argv);
    }
}

char** decimalToDecimal(int argc, char* argv[])
{
    // provide the array result with memory
    result = (char**)malloc(sizeof(char*) * argc);

    // process
    processDecimalToDecimal(3,argc,argv);
	return result;
}

void processDecimalToBinary(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        // get the integer value to this
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,10);
        // print this in binary
        if( value == 0 )
            printf("0");
        else
            printInBinary(value);
        // change line
        printf("\n");
        processDecimalToBinary(index+1,argc,argv);
    }
}

char** decimalToBinary(int argc, char* argv[])
{
    processDecimalToBinary(3,argc,argv);
    return NULL;
}

void processDecimalToHex(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,10);
        result[index] = (char*)malloc(sizeof(char) * 20);
        sprintf(result[index],"%08lX",value);
        processDecimalToHex(index+1,argc,argv);
    }
}

char** decimalToHex(int argc, char* argv[])
{
    // provide the array result with memory
    result = (char**)malloc(sizeof(char*) * argc);
    processDecimalToHex(3,argc,argv);
	return result;
}

void processBinaryToDecimal(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,2);
        printf("%ld\n",value);
        processBinaryToDecimal(index+1,argc,argv);
    }
}

char** binaryToDecimal(int argc, char* argv[])
{
    processBinaryToDecimal(3,argc,argv);
	return NULL;
}

char** binaryToBinary(int argc, char* argv[])
{
	int i;
    for( i=3; i<argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    return NULL;
}

void processBinaryToHex(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,2);
        result[index] = (char*)malloc(sizeof(char) * 20);
        sprintf(result[index],"%08lX",value);
        processBinaryToHex(index+1,argc,argv);
    }
}

char** binaryToHex(int argc, char* argv[])
{
    // provide the array result with memory
    result = (char**)malloc(sizeof(char*) * argc);
    processBinaryToHex(3,argc,argv);
    return result;
}

void processHexToDecimal(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,16);
        result[index] = (char*)malloc(sizeof(char) * 20);
        sprintf(result[index],"%ld",value);
        processHexToDecimal(index+1,argc,argv);
    }
}

char** hexToDecimal(int argc, char* argv[])
{
    // provide the array result with memory
    result = (char**)malloc(sizeof(char*) * argc);
    processHexToDecimal(3,argc,argv);
	return result;
}

void processHexToBinary(int index,int argc, char* argv[])
{
    if( index < argc )
    {
        char * endPtr;
        long int value = strtol(argv[index],&endPtr,16);
        if( value == 0 )
            printf("0");
        else
            printInBinary(value);
        printf("\n");
        processHexToBinary(index+1,argc,argv);
    }
}

char** hexToBinary(int argc, char* argv[])
{
    processHexToBinary(3,argc,argv);
    return NULL;
}

char** hexToHex(int argc, char* argv[])
{
    int i;
    for( i=3; i<argc; i++)
    {
        printf("%s\n",argv[i]);
    }
	return NULL;
}

// Redirect to corresponding function
void seekUserInput(int argc, char* argv[])
{
	if (strcmp(argv[1], "binary")==0 && strcmp(argv[2], "decimal")==0) result = binaryToDecimal(argc, argv);
	else if (strcmp(argv[1], "binary")==0 && strcmp(argv[2], "binary")==0) result = binaryToBinary(argc, argv);
	else if (strcmp(argv[1], "binary")==0 && strcmp(argv[2], "hex")==0) result = binaryToHex(argc, argv);
	else if (strcmp(argv[1], "decimal")==0 && strcmp(argv[2], "decimal")==0) result = decimalToDecimal(argc, argv);
	else if (strcmp(argv[1], "decimal")==0 && strcmp(argv[2], "binary")==0) result = decimalToBinary(argc, argv);
	else if (strcmp(argv[1], "decimal")==0 && strcmp(argv[2], "hex")==0) result = decimalToHex(argc, argv);
	else if (strcmp(argv[1], "hex")==0 && strcmp(argv[2], "decimal")==0) result = hexToDecimal(argc, argv);
	else if (strcmp(argv[1], "hex")==0 && strcmp(argv[2], "binary")==0) result = hexToBinary(argc, argv);
	else if (strcmp(argv[1], "hex")==0 && strcmp(argv[2], "hex")==0) result = hexToHex(argc, argv);

	// return result;
}

// Check if user input contains letters
bool inputValidation(int argc, char* argv[])
{
    // check if the first argument is correct
    // the first argument is at index 1
    if( !(strcmp(argv[1], "binary")==0 || strcmp(argv[1], "decimal")==0 || strcmp(argv[1], "hex") == 0) )
        return false;

    // check if the second argument is correct
    // the second argument is at index 2
    if( !(strcmp(argv[2], "binary")==0 || strcmp(argv[2], "decimal")==0 || strcmp(argv[2], "hex") == 0) )
        return false;

    // check the rest of the digits
	return true;
}

int main(int argc, char* argv[])
{
	if (argc <= 3)
    {
		printf("ERROR: You have to insert at least 3 arguments.");
		return 1;
	}

	if (!inputValidation(argc, argv))
    {
        printf("Invalid input\n");
        return 2;
    }
    seekUserInput(argc, argv);

    printResult(3,argc);

    free(result);

	return 0;
}
