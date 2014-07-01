#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>//Drawing funciton
#include <vector>
#include <iostream>

using namespace std;

void draw();

int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(800, 900);
glutInitWindowPosition(320, 240);
glutCreateWindow("Test window");
glClearColor(0, 0, 0, 0);
glutDisplayFunc(draw);
glutMainLoop();

return 0;
} 
