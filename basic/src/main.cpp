#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float angle = 0.0;


void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glBegin(GL_TRIANGLES);
  glVertex3f(0.5, -0.5, 0);
  glVertex3f(0.0, angle, 0.5);
  glVertex3f(angle, 0.0, 0.5);
  glEnd();

  angle+=0.01;

  glutSwapBuffers();
}

int main(int argc, char * argv[]) {

  // init glut
  glutInit(&argc, argv);
  // Set display mode
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  // set window position
  glutInitWindowPosition(50, 50);
  // Set window size
  glutInitWindowSize(500, 500);

  // Create the window
  glutCreateWindow("Lmaoooo");

  // Set display function
  glutDisplayFunc(renderScene);

  // Set idle function
  glutIdleFunc(renderScene);
  
  // call the main loop
  glutMainLoop();
  
  return 1;

}
