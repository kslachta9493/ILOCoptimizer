/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Fall 2017                                *
 *  Author: Uli                              *
 *  Student Version                          *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "InstrUtils.h"
#include "Utils.h"

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	/* YOUR CODE GOES HERE */

	Instruction *first, *second, *currentinstr;
	currentinstr = head;

	if (currentinstr->next != NULL)
		first = currentinstr->next;
	if (currentinstr->next != NULL)
		second = currentinstr->next->next;

	while (second != NULL)
	{
		Instruction *destroyI;
		if (first->opcode == LOADI && second->opcode == MUL)
		{
			if (first->field1 % 2 == 0)
			{
				first->opcode = LSHIFTI;
				first->field2 = first->field1 / 2;
				first->field1 = second->field1;
				first->field3 = second->field3;
				first->next = second->next;
				destroyI = second;
				free(destroyI);
				second = first->next;
			} else
			{
				first = second;
				second = first->next;
			}
		} else if (first->opcode == LOADI && second->opcode == DIV)
		{
			if (first->field1 % 2 == 0)
			{
				first->opcode = RSHIFTI;
				first->field2 = first->field1 / 2;
				first->field1 = second->field1;
				first->field3 = second->field3;
				first->next = second->next;
				destroyI = second;
				free(destroyI);
				second = first->next;
			} else
			{
				first = second;
				second = first->next;
			}
		} else {
			first = second;
			second = first->next;
		}
	}

	if (head) 
		PrintInstructionList(stdout, head);
		DestroyInstructionList(head);
	
	return EXIT_SUCCESS;
}

