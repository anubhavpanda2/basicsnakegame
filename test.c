#include <GL/glut.h>

const int   A = 500;  /* length of a side of the monitor window */
const float B = 500;  /* length of a side of the clipping rectangle */
const float C = 200;  /* length of a side of the square the program draws */

float i=0;
float j=0;
float l=0;
void myinit(void)
{
  glClearColor(0.7, 0.7, 0.7, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -B/2, B/2, -B/2, B/2);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
                                    
  glClear(GL_COLOR_BUFFER_BIT);     /* clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */

  glBegin(GL_POLYGON) ;             /* draw a filled polygon */
      glColor3f ( i, j, l);       /* draw in light red */
      glVertex2f( -C/2, -C/2 );         /* (x,y) */
      glVertex2f(  C/2, -C/2 );         /* (x,y) */
      glVertex2f(  C/2,  C/2 );         /* (x,y) */
      glVertex2f( -C/2,  C/2 );         /* (x,y) */
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
	break;			// exit
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
  myinit();                         /* set attributes                 */
  glutMainLoop();                   /* pass control to the main loop  */
}
