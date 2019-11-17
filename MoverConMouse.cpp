// Para compilar en MacOSX
// g++ inicialesNombre.cpp -lglut -lGL -lGLU -lGLEW -o inicialesNombre

#include <stdlib.h>
#include <stdio.h>
#ifdef __APPLE__
#include "GLUT/glut.h"
#else
#include "GL/glut.h"
#endif

#define NUMVTR (12)
#define NUMVTA (4)

static int winwidth,winheight;
static int mx,my;
static int flag=0;
static float rotx=0.0f, roty=0.0f;

//Begin M
GLfloat vertice[NUMVTR][3]={{-1,0,0},{-1,0,1},
                			{-1,2,0},{-1,2,1},
                			{0,2,0},{0,2,1},
                			{0,1.5,0},{0,1.5,1},
                			{-0.5,1,0},{-0.5,1,1},
                            {0,0,0},{0,0,1}};

GLfloat color[NUMVTR][3]={{1,0,0},{1,0,0},
                          {0,1,0},{0,1,0},
                          {0,0,1},{0,0,1},
                          {0,1,0},{0,1,0},
                          {1,0,0},{1,0,0},
                          {0,0,1},{0,0,1}};

GLfloat ver[NUMVTA][3]={{-1,1,0},{-1,1,1},
                        {-0.5,1,0},{-0.5,1,1}};

GLfloat col[NUMVTA][3]={{0,0,1},{0,0,1},
                        {0,1,0},{0,1,0}};

void drawgraphix()
{
	int i,j,k;

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//Begin R
	glPushMatrix();

	glTranslatef(0.0f,0.0f,-3.0f);

	glRotatef(rotx,0.0f,1.0f,0.0f);
	glRotatef(roty,1.0f,0.0f,0.0f);

	glPopMatrix();
	//End R
//	begin -
  glPushMatrix();

  glTranslatef(0.0f,0.0f,-3.0f);

  glRotatef(rotx,0.0f,1.0f,0.0f);
  glRotatef(roty,1.0f,0.0f,0.0f);


    //lado frontal
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5, 0.5, -0.5);
	glColor3f(1.0, 0.0, 1.0);
		glVertex3f(0.5, -0.5, -0.5);
	glEnd();
	
	// LADO TRASERO: lado blanco
glBegin(GL_POLYGON);
glColor3f(   1.0,  1.0, 1.0 );
glVertex3f(  0.5, -0.5, 0.5 );
glVertex3f(  0.5,  0.5, 0.5 );
glVertex3f( -0.5,  0.5, 0.5 );
glVertex3f( -0.5, -0.5, 0.5 );
glEnd();

// LADO DERECHO: lado morado
glBegin(GL_POLYGON);
glColor3f(  1.0,  0.0,  1.0 );
glVertex3f( 0.5, -0.5, -0.5 );
glVertex3f( 0.5,  0.5, -0.5 );
glVertex3f( 0.5,  0.5,  0.5 );
glVertex3f( 0.5, -0.5,  0.5 );
glEnd();

// LADO IZQUIERDO: lado verde
glBegin(GL_POLYGON);
glColor3f(   0.0,  1.0,  0.0 );
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();

// LADO SUPERIOR: lado azul
glBegin(GL_POLYGON);
glColor3f(   0.0,  0.0,  1.0 );
glVertex3f(  0.5,  0.5,  0.5 );
glVertex3f(  0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5, -0.5 );
glVertex3f( -0.5,  0.5,  0.5 );
glEnd();

// LADO INFERIOR: lado rojo
glBegin(GL_POLYGON);
glColor3f(   1.0,  0.0,  0.0 );
glVertex3f(  0.5, -0.5, -0.5 );
glVertex3f(  0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5,  0.5 );
glVertex3f( -0.5, -0.5, -0.5 );
glEnd();

  glPopMatrix();

	glutSwapBuffers();//Liberar la memoria una vez dibujado
}



void reshapefunc(int width,int height)
{
	winwidth=width;
	winheight=height;

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0,(float)width/height,1.0,10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}

void mousefunc(int button,int state,int x,int y)
{
	if (button==GLUT_LEFT_BUTTON) {
		if (state==GLUT_DOWN) {
			flag=1;
		} else {
			flag=0;
		}
	}
}

void motionfunc(int x,int y)
{
	if (flag>0) {
		if (flag>1) {
			rotx+=360.0f*(x-mx)/winwidth;
			roty+=360.0f*(y-my)/winheight;
		}

		mx=x;
		my=y;
    drawgraphix();


		flag=2;
	}
}

void idlefunc()
{
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
   winwidth=1300;
   winheight=500;

   glutInit(&argc,argv);
   glutInitWindowSize(winwidth,winheight);
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   glutCreateWindow("Estudiante: Ruben Denky Valles Martinez");

   glutDisplayFunc(drawgraphix);
   glutReshapeFunc(reshapefunc);
   glutMouseFunc(mousefunc);
   glutMotionFunc(motionfunc);
   //glutKeyboardFunc(keyboardfunc);
   glutIdleFunc(idlefunc);

   glutMainLoop();

   return(0);
}
