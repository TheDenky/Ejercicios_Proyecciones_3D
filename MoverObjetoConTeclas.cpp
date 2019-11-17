#include <GL/glut.h>
#include <iostream>
using namespace std;
//tamaño de la ventana
int w = 800, h=700;
double rx = 0, ry = 0, rz = 0, px = 0, py = 0, pz = 0;

void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20, (GLfloat)h / (GLfloat)w, 1, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void){
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-10 + rx, 9 + ry, -10 + rz, px, py, pz, 0, 1,0);
	glPushMatrix();
	
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
glFlush();
glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y){
	switch (key){
		case 49: //1
			ry = ry + 0.3;
			py = py + 0.3;
			break;
			
		case 50: //2
			ry = ry - 0.2;
			py = py - 0.2;
			break;			
	}
	glutPostRedisplay();
}

void flechas(int key, int x, int y){
	switch (key) {
		case GLUT_KEY_RIGHT:
			rx = rx + 0.2;
			px = px + 0.2;
			break;
		case GLUT_KEY_LEFT:
			rx = rx - 0.2;
			px = px - 0.2;
			break;
		case GLUT_KEY_UP:
			rz = rz + 0.2;
			pz = pz + 0.2;
			break;
		case GLUT_KEY_DOWN:
			rz = rz - 0.2;
			pz = pz - 0.2;
			break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(w, h);
	glutCreateWindow("Volumen de vista");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(flechas);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
