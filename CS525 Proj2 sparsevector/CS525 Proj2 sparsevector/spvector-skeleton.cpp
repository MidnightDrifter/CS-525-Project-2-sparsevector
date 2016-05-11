#include <stdlib.h>
#include <stdio.h>
#include "spvector.h"


/*print functions*/
void printf_elements( ElementNode const * p_e, char const * fmt, int dim )
{
    int i,last_pos=-1;
    while( p_e ) {
        for( i=last_pos+1; i<p_e->pos; ++i ) {
            printf( fmt,0 );
        }
        printf( fmt,p_e->data );
        last_pos=p_e->pos;
        p_e = p_e->next;
    }
    for( i=last_pos+1; i<dim; ++i ) {
        printf( fmt,0 );
    }
}

void print_elements( ElementNode const * p_e )
{
    while( p_e ) {
        printf( "%i at pos %i, ",p_e->data,p_e->pos );
        p_e = p_e->next;
    }
}

int  determinant( RowNode const *,int )
{
    return 0;
}
