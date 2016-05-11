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
    int i,last_pos=-1;
    while (p_e)
    {
        for (i=last_pos+1; i<p_e->pos; ++i)
        {
            printf(fmt,0);
        }
        printf(fmt,p_e->data);
        last_pos=p_e->pos;
        p_e = p_e->next;
    }
    for (i=last_pos+1; i<dim; ++i)
    {
        printf(fmt,0);
    }
}

void print_elements(ConstElementNode_handle p_e)
{
    while (p_e)
    {
        printf("%i at pos %i, ",p_e->data,p_e->pos);
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

    int i,j,last_pos=-1;
    while (p_r)
    {
        for (i=last_pos+1; i<p_r->pos; ++i) /* output row of 0's */
        {
            for (j=0; j<dim; ++j) printf(fmt,0);
            printf("\n");
        }
        printf_elements(p_r->elements,fmt,dim);
        printf("\n");
        last_pos=p_r->pos;
        p_r = p_r->next;
    }
    for (i=last_pos+1; i<dim; ++i) /* output row of 0's */
    {
        for (j=0; j<dim; ++j) printf(fmt,0);
        printf("\n");
    }
}


int  determinant(ConstRowNode_handle p_r,int dim)
{
    /* this is a meaningless code to get rid of "unsed argument" warnings in
     * Borland an MS */
    int result=1;
    if (dim==0) ++result;
    if (p_r)    --result;
    return result;
}















    /*If current = null, new list, so just create node with given position and data
    if(current == NULL)
    {
        printf("Error checking: current == NULL\n");
        (*p_e) = nodeToInsert;



        printf("Error checking - current==NULL:  starting node's position and data are (%i, %i)\n", nodeToInsert->pos, nodeToInsert->data);
        return 0;
    }

else{printf("Current node data, position, and next:  (%i, %i, %i)\n", current->data, current->pos, current->next);}

    printf("Creating next node\n");

    ElementNode * next = (*p_e)->next;


    printf("Testing values:  temp node position and data:  (%i, %i)\n", nodeToInsert->pos, nodeToInsert->data);
    printf("Testing values:  current node position and data:  (%i, %i)\n", current->pos, current->data);
    if(next != NULL)
    {
        printf("Testing values - initial test:  next node position and data:  (%i, %i)\n", next->pos, next->data);
    }


if(nodeToInsert==NULL)
{
    printf("ERROR:  Insufficient memory.\n");
    return 1;
}



If next=null, list only  has 1 node, so place it with regards to current as needed
else if(next == NULL)
{

    if((*p_e) == NULL)
    {
        printf("Dafak why is *p_e NULL\n");
    }
    printf("Error checking:  next == NULL\n");
    if((*p_e)->pos >pos)
    {
        printf("Error checking:  node pos > input pos\n");
        (*p_e)->next = nodeToInsert;
        p_e = &nodeToInsert;


        (*p_e)->next = nodeToInsert;  */



       /*nodeToInsert->next = (*p_e);
       (*p_e)=nodeToInsert;

    }

    else if((*p_e)->pos <pos)
    {
        printf("Error checking:  node pos < input pos\n");
       (*p_e)->next = nodeToInsert;
        printf("Error checking:  *p_e-> next updated successfully\n");


        /*nodeToInsert->next = (*p_e);
        (*p_e) = nodeToInsert;
        printf("Error checking - next == NULL:  2nd node's position and data are (%i, %i)\n", nodeToInsert->pos, nodeToInsert->data);
        next = nodeToInsert;
        printf("Error checking - next == NULL:  2nd node's position and data updated to (%i, %i)\n", next->pos, next->data);
    }

    else
    {
        if(val == 0)
        {
            printf("Error checking - next == NULL:  val == 0, freeing current node\n");
            free(current);
        }
        else
        {
            (*p_e)->data=val;
        }
    }


    next = (*p_e)->next;
    if(next!=NULL)
   {
       printf("Error checking: next == NULL, should be updated.  'next' position and value:  (%i, %i)\n", next->pos, next->data);
   }

    return 0;

}




else
{
    printf("Testing values - entered loop:  next node position and data:  (%i, %i)\n", next->pos, next->data);



    do
    {

        if(next != NULL)
       {

        if(pos < current->pos)
        {
            nodeToInsert->next = current;
            return 0;
        }

        else if(pos > current->pos && pos < next->pos)
        {

            printf("Error checking:  current < pos < next:  (%i, %i, %i)\n", current->pos, pos, next->pos);

            current->next = nodeToInsert;
            nodeToInsert->next = next;
            return 0;
        }

        else if(pos > current->pos && current->next == NULL)
        {
            current->next = nodeToInsert;
            return 0;



        }

        else if(pos == next->pos)
        {
            if(val ==0)
            {
                current->next = next->next;
                free(next);
            }

            else
            {
                current->data = val;
            }
            return 0;
        }
       }


       else
       {
           if(current->pos < pos)
           {
               current->next = nodeToInsert;
           }
           else
           {
               printf("Something has gone horribly, horribly wrong here.\n");
           }
           return 0;
       }
current = next;
next = (next->next);

if(next != NULL)
 {printf("Testing values - in loop:  current node position and data:  (%i, %i)\n", current->pos, current->data);
 printf("Testing values - in loop:  next node position and data:  (%i, %i)\n", next->pos, next->data);
 }




    }while(next != NULL);




}

    
    int inserted;
    inserted =1;
    printf("Creating first ElementNode 'previous'.  \n");
    ElementNode * previous = (*p_e);
    printf("'previous' created successfully \n");

    printf("Creating second ElementNode_handle 'current'. \n");
    ElementNode current = *((*previous).next);
    printf("'current' created successfully \n");

    printf("Creating temporary node.\n");
    ElementNode * nodeToInsert = malloc(sizeof(ElementNode));



If previous = null, this is a new list, so all we need to do is just create the node with the given position and data



    if(&nodeToInsert == NULL)
    {
        printf("ERROR: Insufficient memory.\n");
        return 1;
    }

    printf("Temporary node created successfully\n");


    printf("Assigning position to temporary node.\n");
    (*nodeToInsert).pos = pos;
    printf("Position assigned successfully.\n");
    printf("Assigning data to temporary node\n");
    (*nodeToInsert).data = val;
    printf("Data assigned successfully.\n");

    printf("Position of temporary node:  %i\n", (*nodeToInsert).pos);


    if(&previous == NULL)
    {
        return 1;
    }

     If previous != NULL and current = NULL, there's only one node in the list, so the new node goes either in front of or behind it
    else if(&current == NULL)
    {
        if (pos > (*previous).pos)
        {
            (*previous).next = nodeToInsert;
              return 0;
        }

        else if(pos < (*previous).pos)
        {
            (*nodeToInsert).next = previous;
              return 0;
        }

        else
        {
                      if(val == 0)
            {
                printf("Should be deleting from list here - single node.\n");
                free(previous);

                  return 0;
            }

            else
            {
                printf("Should be overwriting data here - single node.\n");

                (*previous).data = val;
                  return 0;
        }
    }

    }


if(&current==NULL)
{
    printf("Current is NULL, something's wrong here.\n");
}

    else{
    do
    {
        printf("Do-while loop entered.\n");
        printf("Position of node 'previous':  %i\n", (*previous).pos);

printf("Position of node 'current':  %s\n", current->pos);



        if (pos > (*previous).pos  && pos < (current).pos)
        {
            printf("Should be inserting into list here. \n");

            (*previous).next = nodeToInsert;
            (*nodeToInsert).next = &current;
            inserted ==0;
              return 0;
        }
        
                    else if(current->pos < pos)
                    {
                        current->next = p_e;
                        inserted==0;

                    }




        else if(pos == current.pos)
        {
            if(val == 0)
            {
                printf("Should be deleting from list here\n");
                (*previous).next = &(current.next);
                free(&current);
                  return 0;
            }

            else
            {
                printf("Should be overwriting data here.\n");

                (*previous).data = val;
                  return 0;
            }
        }
printf("Updating previous and current nodes.\n");
printf("Position of node 'previous':  %i\n", (*previous).pos);
if(&current)
{printf("Position of node 'current':  %i\n", current.pos);}
        previous = &current;
        current= *(current.next);

printf("Updated position of node 'previous':  %i\n", (*previous).pos);
printf("Updated position of node 'current':  %i\n", current.pos);

    }
    while(inserted==1  && &current);


    }
*/


void delete_element(ElementNode_handle * p_e, int pos)
{



    ElementNode * prev = *p_e;
    ElementNode * current = (prev)->next;

    if(prev->pos == pos)
    {
        free(prev);
        (*p_e)= current;
    }


    do
    {

        if(current->pos == pos)
        {
            /* If we're deleting the head node, delete *p_e and point the head to the next node */

            prev->next = current->next;
            free(current);

        }

        else if(current->pos > pos)
        {
            current = NULL;
            /* No position corresponding to input, nothing to delete. */
        }

        else
        {

            prev = current;
            if(current != NULL)
            {current=current->next;}
        }

    }
    while(current!=NULL);


}

int get(ConstElementNode_handle p_e, int pos)
{

   const ElementNode * n = p_e;


    do{
    if(n->pos == pos)
    {
        return n->data;
    }

    else
    {
       /* printf("Current position & data check:  %i, %i\n", n->pos, n->data);*/

        if(n->pos > pos)
        {
            n=NULL;
        }
        else
      {
          n=n->next;
      }
       /* printf("Position of n->next (also shows n->next exists):  %i", n->pos);

      /*  if(n->next != NULL)
        {n=n->next;}
        else
        {return 0;}
    */}
    }while(n!=NULL);





return 0;









/*
    int got;
    got=0;
    ElementNode * node = p_e;


    do
    {
         if(node->pos > pos)
        {/*printf("Error checking:  returning 0 as node at position %i does not exist in this vector \n", got);
            return 0;
            /*If the node doesn't exist, return 0--makes the scalar product easier
        }

       else if(node->pos == pos)
        {  printf("Current node position (from get()):  %i\n", pos);
           printf("Output data from get():  %i\n", node->data);

           if(node->next == NULL)
           {
               printf("From get():  this is the last node in this list!!!\n");
           }


           if(node->pos == 18)
           {
               printf("This is the 18th node.\n");
               if(node->next == NULL)
               {
                   printf("The 18th node points to NULL and something has gone horribly horribly wrong.\n");
               }
           }

            return node->data;
        }

    else{
        node = (node->next);
        /*got++;
        }
    }
    while(1==1);
*/
}

int scalar_product(ConstElementNode_handle p_e1, ConstElementNode_handle p_e2)
{
int temp =0;

const ElementNode * current1 = p_e1;
const ElementNode * current2 = p_e2;


while(current1 !=NULL && current2!=NULL)
{
    if(current1->pos > current2->pos)
    {
        current2=current2->next;
    }

    else if(current1->pos < current2->pos)
    {
    current1=current1->next;
    }

    else
    {
        temp = temp + (current1->data * current2->data);
        current1=current1->next;

    }
}

return temp;




/*int i =0;*/






/*
do{/*printf("Current loop is: %i,  ", i);
        a=get(p_e1, i);
        b=get(p_e2, i);
/*printf("current value from vector 1 is %i, current value from vector 2 is %i, ",a, b);

    temp = temp + a*b;
   /* printf("current sum at loop #%i is:  %i\n", i, temp);
    i=i+1;
    current=current->next;




}while(current!=NULL);



current=p_e1;
while(current->next !=NULL)
{
    current=current->next;
}
/*
printf("Final current position & data (in scalar product):  %i, %i\n", current->pos, current->data);



if(current != NULL)
{
    temp = temp + (get(p_e1, i) * get(p_e2, i));
}


temp = temp + (get(p_e1, i+1) * get(p_e2, i+1));


/*

printf("Error checking: value at pos 19 of vector 1:  %i\n", get(p_e1, 19));
printf("Error checking: value at pos 19 of vector 2:  %i\n", get(p_e2, 19));
printf("Error checking:  final value of temp is:  %i\n", temp);
*/
return temp;
    /*int a;
int out=0;
for(a=1; a<20; a++)
{
    out+=(a*a*a*a);
}
printf("Value of sum of pow4:  %i\n", out);

    int i = 0;
    int temp = 0;

    ElementNode * current = p_e1;

/*
temp += (*p_e1).data * (*p_e2).data;

if((*p_e1).next != NULL)
{
    current1 = (*p_e1).next;
}

if((*p_e2).next !=NULL)
{
    current2=(*p_e2).next;
}

  * while(current != NULL)
    {

        printf("Error checking:  value in vector 1 at pos %i is:  %i\n", i, get(p_e1, i));
        printf("Error checking:  value in vector 2 at pos %i is:  %i\n", i, get(p_e2, i));


        temp =  temp + get(p_e1, i) * get(p_e2, i);
        printf("Current node position (from scalar mult):  %i\n", current->pos);


            printf("Error checking:  value in vector 1 at pos %i is:  %i (not using get())\n", i, current1->data);


            current = (current->next);




            printf("Error checking:  value in vector 2 at pos %i is:  %i (not using get())\n", i, current2->data);

            current2=(current2->next);

 i++;
    }

    return temp;
    */
}


ElementNode_handle add(ConstElementNode_handle p_e1, ConstElementNode_handle p_e2)
{

    ElementNode_handle temp = NULL;


   const ElementNode * current1 = p_e1;
   const ElementNode * current2 = p_e2;

    int holder=0;

    int i=0;


 /*
    while(current1 !=NULL && current2!=NULL)
{

    if(current1->pos > current2->pos)
    {

        current2=current2->next;
    }

    else if(current1->pos < current2->pos)
    {
    current1=current1->next;
    }

    else
    {
        insert_element(&temp, current1->pos, (current1->data + current2->data));
        current1=current1->next;

    }
}*/

    while(current1 != NULL || current2 != NULL)
    {
       /* printf("Inserting element %i into new vector.\n", i);*/
/*
printf("Current loop:  %i\n", i);
printf("Current positions in curr1, cur2:  (%i, %i)\n", current1->pos, current2->pos);

   */     holder = get(p_e1, i) + get(p_e2, i);

      /*  printf("a+b = holder:  %i + %i = %i", a, b, holder);
          printf("Holder value assigned:  %i\n", holder);*/

      if(holder !=0)
       {
           if(temp==NULL)
           {
               temp=0;
           }
           insert_element(&temp, i, holder);
       }



        if(current1!=NULL  &&  i== current1->pos)
        {

            current1=current1->next;


        }

         if(current2!=NULL && i== current2->pos )
        {

            current2=current2->next;

        }


        i++;


    }
    /*
if(temp==NULL)
{
    printf("Temp is null like it should be.\n");
}*/if(temp==NULL)
{
    free(temp);
    return NULL;
}
  else
  {return temp;

}
}

void free_elements(ElementNode_handle p_e)
{
if(p_e != NULL)
  {

    ElementNode * current = p_e;
    ElementNode * next = (*p_e).next;

    while(current != NULL)
    {
        free(current);
        current = next;
        if(next != NULL)
        {next = next->next;}
    }
  }
}




/*  Row functions */


int insert_row( RowNode_handle *p_r,int pos,ElementNode_handle p_e )
{
    return 1;
}


int insert_element2( RowNode_handle *pp_r,int pos_row,int pos_col,int val )
{
    return 1;
}


RowNode_handle find_row( RowNode_handle *pp_r,int pos )
{
    return NULL;
}

RowNode_handle transpose( ConstRowNode_handle p_r )
{

    return NULL;
}

RowNode_handle mult( ConstRowNode_handle p_r1, ConstRowNode_handle p_r2 )
{
    return NULL;
}



void free_rows( RowNode_handle p_r )
{


}


/*
int  determinant( ConstRowNode_handle p_r, int dim )
{
    return 1;
}
*/

