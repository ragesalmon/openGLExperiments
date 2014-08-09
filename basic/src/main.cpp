#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include <cmath>

float angle1 = 0.0;
float angle2 = 0.0;

void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glBegin(GL_TRIANGLES);
  glVertex3f(sin(angle1), cos(angle2), 0);
  glVertex3f(sin(angle2), sin(angle1), 0);
  glVertex3f(cos(angle2), sin(angle2), 0);
  glEnd();

  angle1 += 0.0007;
  angle2 += 0.001;

  glutSwapBuffers();
}

int main(int argc, char * argv[]) {

  srand((unsigned)time(0));
  // init glut
  glutInit(&argc, argv);
  // Set display mode
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  // set window position
  glutInitWindowPosition(50, 50);
  // Set window size
  glutInitWindowSize(500, 500);

  // Create the window
  glutCreateWindow("BasicGL");

  // Set display function
  glutDisplayFunc(renderScene);

  // Set idle function
  glutIdleFunc(renderScene);
  
  // call the main loop
  glutMainLoop();
  
  return 1;

}
