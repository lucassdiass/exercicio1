/*
 ============================================================================
 Name        : Prompt.c
 Author      :
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
void print_entry(char *entry, struct List **list_main) {
	if(entry==NULL||*entry=='\0')
	{
		return;
	}
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
	struct List *list=NULL, *aux=NULL;;
	int number=0, index=0;
	char*tmp=NULL, *straux=NULL;
	memset(input, 0x00, sizeof(char)*201);
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}
		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}
		print_entry(input, &list);
		tmp=(char*)malloc(sizeof(char)*strlen(input));
		if(!tmp)
		{
			return -1;
		}
		straux=input;
		memcpy(tmp, input, strlen(input));
		memset(input, 0x00, sizeof(char)*strlen(tmp));
		while(*(tmp+index)&&(*(tmp+index)!=' '&&*(tmp+index)!='\n'))
		{
			*straux=*(tmp+index);
			straux++;
			index++;
		}
		index++;
		printf("entry %s\n", input);
		if(strlen(input)==strlen("put"))
		{
			if(!strncmp("put", input, strlen(input)))
			{
				number=atoi(tmp+index);
				list=Put(list,number);
				Show(list);
			}
			else if(!strncmp("get", input, strlen(input)))
			{
				number=atoi(tmp+index);
				aux=Get(list, number);
				if(aux)
				{
					printf("%d\n", aux->Number);
					aux=NULL;
				}
			}
		}
		else if(strlen(input)==strlen("list"))
		{
			if(!strncmp("list", input, strlen(input)))
			{
				Show(list);
			}
			else if(!strncmp("last", input, strlen(input)))
			{
				aux=Last(list);
				if(aux)
				{
					printf("%d\n", aux->Number);
					aux=NULL;
				}
			}
		}
		else if(strlen(input)==strlen("remove"))
		{
			number=atoi(tmp+index);
			aux=Remove(&list, number);
			if(aux)
			{
				printf("%d\n", aux->Number);
				aux=NULL;
			}
		}
		else if(strlen(input)==strlen("clear"))
		{
			if(!strncmp("clear", input, strlen(input)))
			{
				Clear(&list);
			}
			else if(!strncmp("first", straux, strlen(straux)))
			{
				aux=First(list);
				if(aux)
				{
					printf("%d\n", aux->Number);
					aux=NULL;
				}
			}
		}
		free(tmp);
		tmp=NULL;
		index=0;
		memset(input, 0x00, sizeof(char)*201);
		fflush(stdin);
	}
	Clear(&list);
	return EXIT_SUCCESS;
}



