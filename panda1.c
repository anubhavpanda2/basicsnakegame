#include <stdlib.h>
#include <GL/glut.h>
static int slices = 16;
static int stacks = 16;
GLfloat xRotated, yRotated, zRotated,i=0.0,j=0.3,k=0.5;
GLdouble size=1,x=0.0,y=3.0,max_x,max_y,c=0,x1=10,v=0;
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(i,j,k);
 //glColor3d(0,1,0);
   /* glPushMatrix();
        glTranslated(x,y=1.5,-6);
        glRotated(-60,1,0,0);
       // glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();*/
    glPushMatrix();
        glTranslated(x,y,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}
void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) {    //The current mouse coordinates
	switch (key) {
           case 'r':
           i=1;
           j=0;
           k=0;
           /*if(i>=1.0)
           i=0.0;
           if(j>=1.0)
           j=0.2;
           if(k>=1.0)
           k=0.1;*/
           break;
           case 'g':
           i=0;
           j=1;
           k=0;
           
              break;
                case 'b':
           i=0;
           j=0;
           k=1;
           
              break;    
              case 'h':
              v=1;
              break; 
              case 'v':
              v=0;
              break;
           }
           }


void update (int value)
 {
     
     if(v==0)
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
     
       
     glutPostRedisplay();
     glutTimerFunc(50,update,0);
     
}



static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutTimerFunc(15,update,0);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
//    glutKeyboardFunc(key);
    //glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return EXIT_SUCCESS;
}
