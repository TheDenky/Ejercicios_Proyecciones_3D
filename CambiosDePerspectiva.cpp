#include <GL/glut.h>

//tamaño de la ventana
int w = 700, h=700;
double rx = 0, ry = 0, rz = 0, px = 0, py = 0, pz = 0;
int da = -5, db = 1, dc = -5;

void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (GLfloat)h / (GLfloat)w, 1, 300);
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
	gluLookAt(da + rx, db + ry, dc + rz, px, py, pz, 0, 0.1,0);
	//
	glPushMatrix();
	
	///////////////////
	//lado frontal
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-500.5, -500.5, -500.5);
	glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-500.5, 500.5, -500.5);
	glColor3f(0.0, 0.0, 1.0);
		glVertex3f(500.5, 500.5, -500.5);
	glColor3f(1.0, 0.0, 1.0);
		glVertex3f(500.5, -500.5, -500.5);
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
	
	//////////////////
	
	//Ejes
	//y
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(0,100,0);
	glEnd();
	//x
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(100,0,0);
	glEnd();
	//z
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, 0, 0);
	glVertex3f(0,0,100);
	glEnd();
 
glFlush();
glutSwapBuffers();
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
			db = 0;
			da = -10;
			dc = 0.0;
			break;
		case GLUT_KEY_DOWN:
			db = 1;
			da = -5;
			dc = -5;
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
	glutSpecialFunc(flechas);
	glutReshapeFunc(reshape);
	//glutPassiveMotionFunc(MouseMotion);
	glutMainLoop();
}
