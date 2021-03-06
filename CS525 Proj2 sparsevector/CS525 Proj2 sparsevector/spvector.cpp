#include <stdlib.h>
#include <stdio.h>
#include "spvector.h"
typedef struct ElementNode ElementNode;
typedef struct RowNode RowNode;

struct ElementNode
{
	int    data;
	int    pos;
	struct ElementNode* next;
};



struct RowNode
{
	int pos;
	struct ElementNode* elements;
	struct RowNode* next;
};

/*print functions*/
void printf_elements(ConstElementNode_handle p_e, char *fmt, int dim)
{
	int i, last_pos = -1;
	while (p_e)
	{
		for (i = last_pos + 1; i<p_e->pos; ++i)
		{
			printf(fmt, 0);
		}
		printf(fmt, p_e->data);
		last_pos = p_e->pos;
		p_e = p_e->next;
	}
	for (i = last_pos + 1; i<dim; ++i)
	{
		printf(fmt, 0);
	}
}

void print_elements(ConstElementNode_handle p_e)
{
	while (p_e)
	{
		printf("%i at pos %i, ", p_e->data, p_e->pos);
		p_e = p_e->next;
	}
}

void print_rows(ConstRowNode_handle p_r)
{
	while (p_r)
	{
		printf("row %i: ", p_r->pos);
		print_elements(p_r->elements);
		printf("\n");
		p_r = p_r->next;
	}
}

void printf_rows(ConstRowNode_handle p_r, char *fmt, int dim)
{

	int i, j, last_pos = -1;
	while (p_r)
	{
		for (i = last_pos + 1; i<p_r->pos; ++i) /* output row of 0's */
		{
			for (j = 0; j<dim; ++j) printf(fmt, 0);
			printf("\n");
		}
		printf_elements(p_r->elements, fmt, dim);
		printf("\n");
		last_pos = p_r->pos;
		p_r = p_r->next;
	}
	for (i = last_pos + 1; i<dim; ++i) /* output row of 0's */
	{
		for (j = 0; j<dim; ++j) printf(fmt, 0);
		printf("\n");
	}
}


int  determinant(ConstRowNode_handle p_r, int dim)
{
	/* this is a meaningless code to get rid of "unsed argument" warnings in
	* Borland an MS */
	int result = 1;
	if (dim == 0) ++result;
	if (p_r)    --result;
	return result;
}

int insert_element(ElementNode_handle * p_e, int pos, int val)
{
	if (*p_e == NULL)
	{
		*p_e = (ElementNode_handle)(malloc(sizeof(ElementNode)));

		if (*p_e == NULL)  //If I malloc and it's STILL NULL, malloc failed, return 1
		{
			return 1;
		}

		(*p_e)->data = val;
		(*p_e)->pos = pos;
		(*p_e)->next = NULL;
		return 0;
	}
	else
	{
		ElementNode_handle current = *p_e;
		ElementNode_handle next = (*p_e)->next;
		ElementNode_handle nodeToInsert = NULL;
		if (val != 0)
		{
			 nodeToInsert = (ElementNode_handle)(malloc(sizeof(ElementNode)));
			
			 if(nodeToInsert == NULL)
			 {
				 return 1;
			 }

			 else {
				 nodeToInsert->data = val;
				 nodeToInsert->pos = pos;
				 nodeToInsert->next = NULL;
			 
			 }
			 
		}

		//Check if next==NULL
		if (next == NULL)
		{
			if (val != 0)
			{
				if (pos < current->pos)  //Node to insert comes before first node in vector, node to insert is new head of vector
				{
					nodeToInsert->next = (*p_e);
					p_e = &nodeToInsert;



		
				}

				else if (pos == current->pos)  //Simple replacement, don't need to use the new node we created
				{
					(*p_e)->data = val;
					
				
				}

				else  //New node comes after current head of vector
				{
					(*p_e)->next = nodeToInsert;


				}

				
			}

			else
			{
				if (pos = current->pos)
				{
					free(*p_e);
					*p_e = NULL;
				}
			}
/*
			current = NULL;
			free(current);
			next = NULL;
			free(next);
			nodeToInsert = NULL;
			free(nodeToInsert);  //Double check these lines?

			return 0;
*/
		}
		else
			{
				if (val != 0)
				{
					do
					{
						if (pos < current->pos)  //Similar to above
						{
							nodeToInsert->next = (*p_e);
							p_e = &nodeToInsert;
						}

						else if (pos == current->pos)
						{
							(*p_e)->data = val;
						}

						else if (next != NULL && pos < next->pos)
						{
							current->next = nodeToInsert;
							nodeToInsert->next = next;
						}

						else if (next == NULL)
						{
							current->next = nodeToInsert;
						}

						else
						{
							current = next;
							next = next->next;
						}


					} while (current != NULL);

				}

				else
				{
					free(nodeToInsert);
					nodeToInsert = NULL;
					do {
						if (pos == next->pos)
						{
							current->next = next->next;
							free(next);
						}

						current = next;
						next = next->next;


					} while (next != NULL);
				}


			}

			current = NULL;
			
			next = NULL;
			
			nodeToInsert = NULL;
		 //Double check these lines?

			


		}

		return 0;

}






void delete_element(ElementNode_handle * p_e, int pos)
{



	ElementNode * prev = *p_e;
	ElementNode * current = (prev)->next;

	if (prev->pos == pos)
	{
		free(prev);
		(*p_e) = current;
	}


	do
	{

		if (current->pos == pos)
		{
			/* If we're deleting the head node, delete *p_e and point the head to the next node */

			prev->next = current->next;
			free(current);

		}

		else if (current->pos > pos)
		{
			current = NULL;
			/* No position corresponding to input, nothing to delete. */
		}

		else
		{

			prev = current;
			if (current != NULL)
			{
				current = current->next;
			}
		}

	} while (current != NULL);


}

int get(ConstElementNode_handle p_e, int pos)
{

	const ElementNode * n = p_e;


	do {
		if (n->pos == pos)
		{
			return n->data;
		}

		else
		{
			/* printf("Current position & data check:  %i, %i\n", n->pos, n->data);*/

			if (n->pos > pos)
			{
				n = NULL;
			}
			else
			{
				n = n->next;
			}
			
		}
	} while (n != NULL);





	return 0;









	
}

int scalar_product(ConstElementNode_handle p_e1, ConstElementNode_handle p_e2)
{
	int temp = 0;

	const ElementNode * current1 = p_e1;
	const ElementNode * current2 = p_e2;


	while (current1 != NULL && current2 != NULL)
	{
		if (current1->pos > current2->pos)
		{
			current2 = current2->next;
		}

		else if (current1->pos < current2->pos)
		{
			current1 = current1->next;
		}

		else
		{
			temp = temp + (current1->data * current2->data);
			current1 = current1->next;

		}
	}

	return temp;



}


ElementNode_handle add(ConstElementNode_handle p_e1, ConstElementNode_handle p_e2)
{

	ElementNode_handle temp = NULL;


	const ElementNode * current1 = p_e1;
	const ElementNode * current2 = p_e2;

	int holder = 0;

	int i = 0;



	while (current1 != NULL || current2 != NULL)
	{
		/* printf("Inserting element %i into new vector.\n", i);*/
		/*
		printf("Current loop:  %i\n", i);
		printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

		*/     holder = get(p_e1, i) + get(p_e2, i);

		/*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
		printf("Holder value assigned:  %i\n", holder);*/

	if (holder != 0)
	{
		if (temp == NULL)
		{
			temp = 0;
		}
		insert_element(&temp, i, holder);
	}



	if (current1 != NULL  &&  i == current1->pos)
	{

		current1 = current1->next;


	}

	if (current2 != NULL && i == current2->pos)
	{

		current2 = current2->next;

	}


	i++;


	}
	/*
	if(temp==NULL)
	{
	printf("Temp is null like it should be.\n");
	}*/
	
	if (temp == NULL)
	{
		free(temp);
		return NULL;
	}
	else
	{
		return temp;

	}
}

void free_elements(ElementNode_handle p_e)
{
	if (p_e != NULL)
	{

		ElementNode * current = p_e;
		ElementNode * next = (*p_e).next;

		while (current != NULL)
		{
			free(current);
			current = next;
			if (next != NULL)
			{
				next = next->next;
			}
		}
	}
}


/*
int insert_element(ElementNode** e, int i, int j)
{
	ElementNode_handle * eh = e;
	return (insert_element(eh, i, j));
}
*/



/*  Row functions */


int insert_row(RowNode_handle *p_r, int pos, ElementNode_handle p_e)
{
	return 1;
}


int insert_element2(RowNode_handle *pp_r, int pos_row, int pos_col, int val)
{
	return 1;
}


RowNode_handle find_row(RowNode_handle *pp_r, int pos)
{
	return NULL;
}

RowNode_handle transpose(ConstRowNode_handle p_r)
{

	return NULL;
}

RowNode_handle mult(ConstRowNode_handle p_r1, ConstRowNode_handle p_r2)
{
	return NULL;
}



void free_rows(RowNode_handle p_r)
{


}


/*
int  determinant( ConstRowNode_handle p_r, int dim )
{
return 1;
}
*/

