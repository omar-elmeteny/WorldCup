#include "Ball.h"
#include "glut.h"
#include "Util.h"

Ball::Ball() {
	ballTexture.LoadBMP("textures/ball.bmp");
	position = { 0, 0, 0.55 };
}

void Ball::draw() {
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	ballTexture.Use();

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	glPushMatrix();
	glTranslated(position.x, position.y, position.z);
	glutSolidSphere(0.5, 100, 100);
	glPopMatrix();

	unuseTexture();
}