#include "Court.h"
#include <glut.h>
#include "Util.h"

Court::Court() {
	
}

void Court::draw() {
	GLfloat green[3] = { 0, 0.68f, 0 };
	glColor3f(green[0], green[1], green[2]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);

	glPushMatrix();
	glTranslated(0, 0, -thickness);
	glScaled(height, width, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);

	// Draw center line
	glPushMatrix();
	glTranslated(0, 0, thickness / 2);
	glScaled(lineThickness, width, thickness);
	glutSolidCube(1);
	glPopMatrix();
	// draw side lines
	glPushMatrix();
	glTranslated(0, -width / 2 + lineThickness / 2, thickness / 2);
	glScaled(height, lineThickness, thickness);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, width / 2 - lineThickness / 2, thickness / 2);
	glScaled(height, lineThickness, thickness);
	glutSolidCube(1);
	glPopMatrix();
	
	// draw corner lines
	glPushMatrix();
	glTranslated(height / 2 - lineThickness / 2, 0, thickness / 2);
	glScaled(lineThickness, width, thickness);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-height / 2 + lineThickness / 2, 0, thickness / 2);
	glScaled(lineThickness, width, thickness);
	glutSolidCube(1);
	glPopMatrix();
	
	//glutSolidTorus(10, 10 + lineThickness, 10, 10);

	GLUquadric *quad = gluNewQuadric();
	gluQuadricDrawStyle(quad, GLU_LINE);
	
	gluDisk(quad, 10, 10 + lineThickness, 1000, 1000);

	glPushMatrix();
	glTranslated(-height/2, -width / 2, 0);
	gluPartialDisk(quad, 2, 2 + lineThickness, 100, 100, 0, 90);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-height / 2, width / 2, 0);
	gluPartialDisk(quad, 2, 2 + lineThickness, 100, 100, 90, 90);
	glPopMatrix();

	glPushMatrix();
	glTranslated(height / 2, width / 2, 0);
	gluPartialDisk(quad, 2, 2 + lineThickness, 100, 100, 180, 90);
	glPopMatrix();

	glPushMatrix();
	glTranslated(height / 2, -width / 2, 0);
	gluPartialDisk(quad, 2, 2 + lineThickness, 100, 100, 270, 90);
	glPopMatrix();

	glPushMatrix();
	glTranslated(height / 2, -width / 2, 0);
	gluPartialDisk(quad, 2, 2 + lineThickness, 100, 100, 270, 90);
	glPopMatrix();

	glEnable(GL_LIGHTING);

}
