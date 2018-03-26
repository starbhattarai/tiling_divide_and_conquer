
#include <stdio.h>
#include <stdlib.h>


void tromino ( int xBoard, int yBoard,int xMiss, int yMiss,int boardSize ); /* function to do tiling */

	int count;
	   
void tromino( int xBoard, int yBoard, int xMiss, int yMiss, int boardSize )
{	
     
     int halfsize = boardSize/2, /* size of subboard */
         xcen,  /* x coordinate of center of board */
         ycen,  /* y coordinate of center of board */
         xuleft,  /* x coordinate of missing square in upper left subboard */
         yuleft,  /* y coordinate of missing square in upper left subboard */
         xuright, /* x coordinate of missing square in upper right subboard */
         yuright, /* y coordinate of missing square in upper right subboard */
         xlright, /* x coordinate of missing square in lower right subboard */
         ylright, /* y coordinate of missing square in lower right subboard */
         xlowleft,  /* x coordinate of missing square in lower left subboard */
         ylowleft;  /* y coordinate of missing square in lower left subboard */

     if ( boardSize == 2 ) {   /* 2x2 board print position of tromino */
          printf( "(( %d , %d ), ", xBoard, yBoard);		
        
          /* find and print orientation of tromino */
          if ( xBoard == xMiss )
               /* missing square in left half */
               if ( yBoard == yMiss )
                    /* missing square in lower left */
                    printf( "0 )\n" ); //LL
               else
                    /* missing square in upper left */
                    printf( "1 )\n" ); //UL
          else
               /* missing square in right half */
               if ( yBoard == yMiss )
                    /* missing square in lower right */
                    printf( "3 )\n" ); //LR    --UL
               else
                    /* missing square in upper right */
                    printf( "2 )\n" ); //UR
	count++;
          return ;
     }

     /* compute x and y coordinates of center of board */
     xcen = xBoard + halfsize;
     ycen = yBoard + halfsize;

     
     count++;
	

     /* tile the four subboards */
     tromino( xBoard, yBoard, xlowleft, ylowleft, halfsize );
     tromino( xBoard, yBoard + halfsize, xuleft, yuleft, halfsize );
/* print position of special, center tromino */
     printf( "(( %d , %d), ", xcen-1, ycen-1 );

     /* Find and print orientation of center tromino. */
     if ( xMiss < xcen) {		 
          xuright = xlright = xcen;
          yuright = ycen;
          ylright = ycen - 1;
          if ( yMiss < ycen ) {			
               printf( "0\n" );
               xuleft = xcen - 1;
               yuleft = ycen;
               xlowleft = xMiss;
               ylowleft = yMiss;
          }
          else {		 
               printf( "1\n" );
               xuleft = xMiss;
               yuleft = yMiss;
               xlowleft = xcen - 1;
               ylowleft = ycen - 1;
          }
     }
     else {
          /* missing square in right half */
          xuleft = xlowleft = xcen - 1;
          yuleft = ycen;
          ylowleft = ycen - 1;
          if ( yMiss < ycen ) {			/* missing square in lower right quadrant */
               printf( "3\n" );
               xuright = xcen;
               yuright = ycen;
               xlright = xMiss;
               ylright = yMiss;
          }
          else {		/* missing square in upper right quadrant */
			   printf( "2 )\n" );
               xuright = xMiss;
               yuright = yMiss;
               xlright = xcen;
               ylright = ycen - 1;
          }
     }
     tromino( xBoard + halfsize, yBoard, xlright, ylright, halfsize );
     tromino( xBoard + halfsize, yBoard + halfsize, xuright, yuright, halfsize );
       
}	   

int main()
{
     int boardSize, xMiss = 0, yMiss = 0;  /*x & y coordinate of missing square */
	
     do {
          printf( "\n-------------------------------------" );
          printf( "\nEnter size of board (0 to quit): " );
          scanf( "%d", &boardSize );
		count=0;
          if ( boardSize ) {
               printf( "\nEnter coordinates of missing square: " );
               scanf( "%d%d", &xMiss, &yMiss );

               printf("\nBOARD SIZE: %d", boardSize);
        printf("\nLOCATION AT 0 AND 0");
        printf("\nMISSING SQUARE AT: %d AND %d" , xMiss , yMiss);

        printf("\nALL TROMINOES FOLLOW:::\n");
               tromino( 0, 0, xMiss, yMiss, boardSize );
     printf("\n\n TOTAL OF TROMINOES COMPUTED:::%d" ,count);
               
          }
     } while ( boardSize );
     return EXIT_SUCCESS;
}
