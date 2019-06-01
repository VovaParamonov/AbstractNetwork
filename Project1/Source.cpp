#include<glut.h>
#include<math.h>
#include<stdlib.h>

#include"List.cpp"
#include"Point.h"


int animSpeed = 10; // �������� �������� � ������������

using namespace std;

List<Point> points;

//.........................global settings......................

//������� ������
int width = 1200;
int height = 580;

//���-�� �����
int numberOfPoints = 100;

//�������� ��������
int minSpeedX = -3;
int maxSpeedX = 3;

int minSpeedY = -3;
int maxSpeedY = 3;

//���������� ��� ����������
int distanceConnection = 100;


//�������
int pointSize = 3;
float lineWidth = 1.5;

//..............................................................


void movePoints();
void drawLines();

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	movePoints();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	width = w;
	height = h;
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(animSpeed, timer, 0);
}

int main(int argc, char **argv) {
	// �������������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_ALPHA | GLUT_RGBA);
	glEnable(GLUT_ALPHA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("����������� ����");

	//Settings
	glPointSize(pointSize);
	glLineWidth(lineWidth);

	// ����������� �������� �������
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutTimerFunc(animSpeed, timer, 0);

	for (int i = 0; i < numberOfPoints; i++) {
		points.push(Point(
			rand() % width + 1, //������� ��������� ���������� X
			rand() % height + 1, //������� ��������� ���������� Y
			(minSpeedX + rand() % maxSpeedX*2)*0.1, // ������� ��������� �������� �� X
			(minSpeedY + rand() % maxSpeedY*2)*0.1 // ������� ��������� �������� �� Y
		));
	}

	// �������� ���� GLUT
	glutMainLoop();

	return 0;
}

void movePoints() {

	glColor3d(0, 1, 1);

	glBegin(GL_POINTS);
	for (int i = 0; i < points.len(); i++) {

		glVertex2f(points[i].posX, points[i].posY);

		points[i].move(width, height);
	}
	glEnd();
	
	drawLines();
}


float hypotenuse;

void drawLines() {
	for (int i = 0; i < points.len(); i++) {
		for (int j = 0; j < points.len(); j++) {
			hypotenuse = sqrt(pow(points[i].posX - points[j].posX, 2) + pow(points[i].posY - points[j].posY, 2));

			glColor3f(0, (distanceConnection-hypotenuse)*0.01, (distanceConnection-hypotenuse)*0.01);

			if (hypotenuse <= distanceConnection) {
				glBegin(GL_LINES);
				glVertex2f(points[i].posX, points[i].posY);
				glVertex2f(points[j].posX, points[j].posY);
				glEnd();
			}
		}
	}
}