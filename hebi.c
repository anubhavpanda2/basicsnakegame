#include <GL/glut.h>

const int   A = 500;  /* length of a side of the monitor window */
const float B = 500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */
int x=50;
int y=-50;
float i=0;
float j=0;
float l=0;
int c1=4;
int c2=0;
int c3=0;
int c4=0;
int d;
int e=1;
int x1;
int y1;
int x2;
int y2;
void myinit(void)
{
  glClearColor(1, 1, 1, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}
void update (int value)
 {
     if((x==x1)&&(y==y1))
     {
              e+=1;
              x1=rand()%200-200;
              y1=rand()%200-200;
              }
     if(x<-250)
     x=250;
     if(y<-250)
     y=250;
     if(x>250)
     x=-250;
     if(y>250)
     y=-250;
     if(c1==4)
     x+=1;
     if(c2==4)
     x-=1;
     if(c3==4)
     y+=1;
     if(c4==4)
     y-=1;
  /*   if(v==0)
     {
      if(y>=2)
      {
      y=y-0.1;c=1;
      x=rand()%3-3;
      }
     else if(y<=-2){
      y=y+0.1;c=0;}
      else
      { 
          if(c==0)
         y=y+0.1;
         else
         y=y-0.1;
         }
    }// y=y+6;
     if(v==1)
     {
      if(x>=2)
      {
      x=x-0.1;c=1;
      y=rand()%3-3;
      }
     else if(x<=-2){
      x=x+0.1;c=0;}
      else
      { 
          if(c==0)
         x=x+0.1;
         else
         x=x-0.1;
         }
    }
     
    */   
     glutPostRedisplay();
     glutTimerFunc(10,update,0);
     
}


void display( void )
{
                                    
  glClear(GL_COLOR_BUFFER_BIT);     /* clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
glPointSize(6); 
float p,m;
p=x;
m=y;
  glBegin(GL_POINTS) ;             /* draw a filled polygon */
      glColor3f ( i, j, l);       /* draw in light red */
      
     for(d=0;d<e;d++)
     { 
      if(c1==4)
      {
      if(p>x2)
      {
      glVertex2f( p, y );
      p-=5;
       }       /* (x,y) */
       else
       glVertex2f( p, y );
      }
      else if(c2==4)
      {
      if(p<x2)
      {
      glVertex2f(p , y );
      p+=5;
      }
      else
      {
       glVertex2f( p, y );
       p-=5;
       }
      }
      else if(c3==4)
      {
        if(m>y2)
        {   
      glVertex2f( x, m );
      m-=5;
      }
      else
      {
       glVertex2f( x, m );
       m-=5;
       }
      }
      else if(c4==4)
      {
      
       if(m<y2)
       {    
      glVertex2f( x, m );
      m+=5;
      }
      else
      {
          if(c1==4)
          {
       glVertex2f( p, m );
       p-=5;
       }
       if(c1==4)
          {
       glVertex2f( p, y );
       p-=5;
       }
      }
      }
	  }
      glVertex2f( x1, y1 );
      //glVertex2f(  C/2, -C/2 );         /* (x,y) */
      //glVertex2f(  C/2,  C/2 );         /* (x,y) */
      //glVertex2f( -C/2,  C/2 );         /* (x,y) */
  glEnd();

  glFlush();                        /* send all commands */
}
void keyboard( char k, int x, int y)
{

if(i>=1.0)
           i=0.0;
           if(j>=1.0)
           j=0.0;
           if(l>=1.0)
           l=0.0;     
    switch (k)
    {
    case 'r':
	 i+= 0.1;
     if(i==1)
     i=0;			// increase rotation by 5 degrees
	break;
    case 'g':
	j+=0.1;
    if(j==1)
    j=0;			// decrease rotation by 5 degrees
	break;
    case 'b':
    l+=0.1;
    if(l==1)
    l=0;
	break;
    case 'd':
         if(c2!=4)
         {
         if(c3==4)
         c3=3;
         else if(c4==4)
         c4=3;
         
         c1=4;
         }
         //c2=0;
         //c3=0;
         //c4=0;
         x2=x;
         y2=y;
         break;
         case 'a':
               if(c1!=4)
         {
         if(c3==4)
         c3=3;
         else if(c4==4)
         c4=3;
         
       
       //       c1=0;
              c2=4;
         //     c3=0;
           //   c4=0;
           }
              x2=x;
         y2=y;

              break;
              case 'w':
                    if(c4!=4)
         {
          if(c1==4)
         c1=3;
         if(c2==4)
         c2=3;
       
                   //c1=0;
                   //c2=0;
                   c3=4;
  }                 //c4=0;
                   x2=x;
         y2=y;

                   break;
                   case 's':
                        if(c3!=4)
         {
                        if(c1==4)
         c1=3;
         if(c2==4)
         c2=3;
       //                c1=0;
     //              c2=0;
   //                c3=0;
                   c4=4;
                   }
                   break; 			// exit
    }

    glutPostRedisplay();		// redraw the image now
}
void main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize( A, A );       /* A x A pixel screen window  */

  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("My Rectangle"); /* window title                   */
  glutDisplayFunc(display);         /* tell OpenGL main loop what     */
   glutKeyboardFunc(keyboard);		// call keyboard() when key is hit
    glutTimerFunc(15,update,0);
    x1=rand()%200-200;
    y1=rand()%200-200;
  myinit();                         /* set attributes                 */
  glutMainLoop();                   /* pass control to the main loop  */
}
