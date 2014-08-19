#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <GL/glut.h>
const int XSize = 800, YSize  = 800;

void renderscene(void) {
  glClear(GL_COLOR_BUFFER_BIT);
}

GLfloat curX = 0.5, curY = 0.5;

void drawRect() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, XSize, YSize, 0, -1, 1);
  glMatrixMode(GL_MODELVIEW);
  glBegin(GL_POLYGON);
  glColor3f(static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX));
  glVertex2f(0.0f, 0.0f);
  glColor3f(static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX));
  glVertex2f(XSize, 0.0f);
  glColor3f(static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX));
  glVertex2f(XSize, YSize);
  glColor3f(static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX), static_cast <float> (rand())/ static_cast <float> (RAND_MAX));
  glVertex2f(0.0f, YSize);
  glEnd();
  glutSwapBuffers();
}
    
  

int main(int argc, char * argv[]) {
  srand(time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(XSize, YSize);

  glutCreateWindow("Pixels");

  glutDisplayFunc(renderscene);
  glutIdleFunc(drawRect);

  glutMainLoop();

  return 0;
}
