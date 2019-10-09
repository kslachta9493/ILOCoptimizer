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
	Instruction *first, *second, *third, *currentinstr;
	currentinstr = head;

	if (currentinstr->next != NULL)
		first = currentinstr->next;
	if (currentinstr->next != NULL)
		second = currentinstr->next->next;
	if (currentinstr->next != NULL)
		third = currentinstr->next->next->next;
	while (third != NULL) 
	{
		if (first->opcode == second->opcode && first-> opcode == LOADI )
		{
			Instruction *destroy1, *destroy2;
			switch (third->opcode)
			{
				case ADD:
					first->field1 = first->field1 + second->field1;
					first->field2 = third->field3;
					first->next = third->next;
					//free second and third
					destroy1 = second;
					destroy2 = third;
					free(destroy1);
					free(destroy2);

					//get new second and third
					second = first->next;
					third = second->next;
					break;
				case SUB:
					first->field1 = first->field1 - second->field1;
					first->field2 = third->field3;
					first->next = third->next;
					//free second and third
					destroy1 = second;
					destroy2 = third;
					free(destroy1);
					free(destroy2);

					//get new second and third
					second = first->next;
					third = second->next;
					break;
				case MUL:
					first->field1 = first->field1 * second->field1;
					first->field2 = third->field3;
					first->next = third->next;
					//free second and third
					destroy1 = second;
					destroy2 = third;
					free(destroy1);
					free(destroy2);

					//get new second and third
					second = first->next;
					third = second->next;
					break;
				default:
					first = second;
					second = third;
					third = third->next;
					break;
			}

		} else
		{
			first = second;
			second = third;
			third = third->next;
		}
	}

	if (head) 
		PrintInstructionList(stdout, head);
		DestroyInstructionList(head);
	
	return EXIT_SUCCESS;
}

