#include <iostream>
#include <GL/glut.h>
using namespace std;
void myInit(void) {
	glClearColor(0.3960, 0.2627, 0.1294, 0.0);
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 400);
}
class GLintPoint {
public:
	GLint x, y;
};
void parameterizedHouse(GLintPoint peak, GLint width, GLint height) {
	glBegin(GL_LINE_LOOP);
	glVertex2d(peak.x, peak.y);
	glVertex2d(peak.x + width / 2.0, peak.y - height / 3.0);
	glVertex2d(peak.x + width / 2.0, peak.y - height);
	glVertex2d(peak.x - width / 2.0, peak.y - height);
	glVertex2d(peak.x - width / 2.0, peak.y - height / 3.0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) / 6.0), (peak.y - (peak.y - height / 3.0)) / 6.0 + (peak.y - height / 3.0));
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) / 6.0), (peak.y - (peak.y - height / 3.0)) * 0.9 + (peak.y - height / 3.0));
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) * 0.6), (peak.y - (peak.y - height / 3.0)) * 0.9 + (peak.y - height / 3.0));
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) * 0.6), (peak.y - (peak.y - height / 3.0)) * 0.6 + (peak.y - height / 3.0));
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) / 6.0), peak.y - height);
	glVertex2d((peak.x - width / 2.0) + ((peak.x - (peak.x - width / 2.0)) / 6.0), peak.y - height / 2.0);
	glVertex2d((peak.x - width / 2.0) + width / 2.5, peak.y - height / 2.0);
	glVertex2d((peak.x - width / 2.0) + width / 2.5, peak.y - height);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2d((peak.x + width / 2.0) - ((peak.x - (peak.x - width / 2.0)) / 1.5), peak.y - height / 3.0);
	glVertex2d((peak.x + width / 2.0) - ((peak.x - (peak.x - width / 2.0)) / 1.5), peak.y - height / 2.0);
	glVertex2d((peak.x + width / 2.0) - ((peak.x - (peak.x - width / 2.0)) / 2.5), peak.y - height / 2.0);
	glVertex2d((peak.x + width / 2.0) - ((peak.x - (peak.x - width / 2.0)) / 2.5), peak.y - height / 3.0);
	glEnd();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	parameterizedHouse({ 100, 300 }, 100, 150);
	parameterizedHouse({ 225, 350 }, 75, 75);
	parameterizedHouse({ 250, 225 }, 150, 150);
	parameterizedHouse({ 400, 350 }, 150, 100);
	parameterizedHouse({ 450, 175 }, 150, 100);
	parameterizedHouse({ 600, 350 }, 200, 100);
	parameterizedHouse({ 650, 75 }, 75, -100);
	parameterizedHouse({ 750, 225 }, 50, 50);

	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("My Village");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}