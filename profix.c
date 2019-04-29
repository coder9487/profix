#include<stdio.h>
#include<string.h>


#define MAX 50
#define DEBUG 1




/****	fucction declare	******/

int transfer(char input_charator);
int is_variable(char input_char);
int notation_precidentce(char input_char);

/****	fucction declare	******/


struct notation_datatype
{
	char notation;
	int precidence;
};





/**
 *	precidentce (3)	/ and *
 *		    (2) + and -
 *		    (1) ~
 *
 * */




int profix_counter = 0;
int notation_counter = 0;


struct notation_datatype statck[10];


char notation[MAX/2];
char infix[MAX] = {};
char profix[MAX] = {};

int main()
{

	puts("Enter infix :");
	fgets(infix,MAX, stdin);

	int for_1_counter = strlen(infix)-1;
	for(;for_1_counter != -1;for_1_counter--)
	{
        transfer(infix[for_1_counter]);

		if(DEBUG)
		{
			//printf("%c",infix[for_1_counter]);

		}
	}





	int i = notation_counter-1;
	for(;i != -1;i--)
	{
		if(DEBUG)
		{
			printf("%c:%d \n",statck[i].notation,statck[i].precidence);


		}
	}










}


int transfer(char input_charator)
{

	if(is_variable(input_charator))
	{
		profix[profix_counter++]=input_charator;
	}
	else
	{
		if(notation_precidentce(input_charator))
		{
            if(statck[notation_counter-1].precidence > statck[notation_counter].precidence)
                {

                POP

                }

            statck[notation_counter].notation = input_charator;
            statck[notation_counter++].precidence = notation_precidentce(input_charator);
		}

	}









}


int notation_precidentce(char input_char)
{
	int return_type = 0;
	switch (input_char)
	{

	case '(':
		return_type = 4;
		break;
	case '*' :
	case '/' :
		return_type = 3;
		break;
	case '+':
	case '-':
		return_type = 2;
		break;
	case '~':
		return_type = 1;
		break;


	}
	return return_type;
}

int is_variable(char input_char)
{
	if((input_char >= 'A' && input_char <= 'Z')||(input_char >= 'a' && input_char <= 'z'))
		return 1;
	else
		return 0;
}



