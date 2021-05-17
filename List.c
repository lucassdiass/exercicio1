/*
 * List.c
 *
 *  Created on: 17 de mai de 2021
 *      Author: Lucas Dias
 */
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
struct List * Put(struct List*l, int x)
{
	struct List * new_element=NULL,*tmp=NULL;
	new_element=(struct List*)malloc(sizeof(struct List ));
	if(new_element)
	{
		new_element->Next=new_element->Prev=NULL;
		new_element->Number=x;
	}
	if(l!=NULL)
	{
		tmp=l;
		while(l->Next!=NULL)
		{
			l=l->Next;
		}
		l->Next=new_element;
		new_element->Prev=l;
		l=tmp;
		printf("retorna l\n");
		return l;
	}
	printf("retorna new elemetn\n");

	return new_element;
}
struct List * Get(struct List*l, int pos)
{
	struct List * element=NULL;
	int index=1;
	if(pos && l)
	{
		for(element=l;element && index!=pos; element=element->Next, index++);
	}
	return element;//se pos for não positivo o ponteiro retornado será nulo
}
struct List * Last(struct List*l)
{
	struct List * element=NULL;
	if((element=l)!=NULL)
	{
		for(;element->Next;element=element->Next);
	}
	return element;
}
struct List * First(struct List*l)
{
	return l;
}
struct List * Remove(struct List**l, int pos)
{
	struct List * element=NULL, *tmp=NULL;
	int index=1;
	if(pos && l && *l)
	{
		tmp=*l;
		if(pos==1)
		{
			tmp->Next->Prev=NULL;
			tmp->Next=NULL;
			*l=(*l)->Next;
			element=tmp;
		}
		else
		{
			for(;index!=pos&&tmp;index++,tmp=tmp->Next);
			if(tmp && index==pos)
			{
				element=tmp;
				tmp->Prev->Next=element->Next;
				element->Next->Prev=tmp->Prev;
				element->Next=element->Prev=NULL;
			}
		}
	}
	return element;
}
void Clear(struct List **l)
{
	struct List*tmp=NULL,*aux=NULL;
	if(l&&*l)
	{
		tmp=*l;
		while(tmp)
		{
			aux=tmp;
			tmp=tmp->Next;
			free(aux);
			aux=NULL;
		}
	}
}

void Show(struct List *l)
{
	struct List*tmp=l;
	while(tmp)
	{
		printf("%d ", tmp->Number);
		tmp=tmp->Next;
	}
	printf("\n");
}

