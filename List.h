/*
 * List.h
 *
 *  Created on: 17 de mai de 2021
 *      Author: root
 */

#ifndef LIST_H_
#define LIST_H_
struct List
{
	int Number;
	struct List * Next, *Prev;
};

struct List * Put(struct List*, int);
struct List * Get(struct List*, int);
struct List * Last(struct List*);
struct List * First(struct List*);
struct List * Remove(struct List**, int);
void Clear(struct List **);
void Show(struct List *);




#endif /* LIST_H_ */
