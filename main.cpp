#include<windows.h>
#include<gl/glut.h>
#include "imageloader.h"

using namespace std;


void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
float sca = 0.0f;
float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

GLuint _textureId;
GLuint _textureId2;

GLuint loadTexture(Image* image) {
GLuint textureId;
glGenTextures(1, &textureId);
glBindTexture(GL_TEXTURE_2D, textureId);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
return textureId;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("672020150_672020151_672020148");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_NORMALIZE);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
	Image* image1 = loadBMP("aspal.bmp");    //ganti nama file foto anda formatx harus .bmp
	_textureId = loadTexture(image1);
	delete image1;
	Image* image2 = loadBMP("atap.bmp");    //ganti nama file foto anda formatx harus .bmp
	_textureId2 = loadTexture(image2);
	delete image2;
}

void display(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(zrot, 0.0f, 0.0f, 1.0f);

    glScalef(sca + 1, sca + 1, sca + 1);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    //tiang depan kiri
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-23.0, 20.0, 60);
    glVertex3f(-23.0, -20.0, 60);
    glVertex3f(-18.0, -20.0, 60);
    glVertex3f(-18.0, 20.0, 60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-23.0, 20.0, 55);
    glVertex3f(-23.0, -20.0, 55);
    glVertex3f(-18.0, -20.0, 55);
    glVertex3f(-18.0, 20.0, 55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-23.0, -20.0, 60);
    glVertex3f(-23.0, 20.0, 60);
    glVertex3f(-23.0, 20.0, 55);
    glVertex3f(-23.0, -20.0, 55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-24.5, -20.0, 61);
    glVertex3f(-24.5, -16.0, 61);
    glVertex3f(-16.5, -16.0, 61);
    glVertex3f(-16.5, -20.0, 61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-24.5, -20.0, 53);
    glVertex3f(-24.5, -16.0, 53);
    glVertex3f(-16.5, -16.0, 53);
    glVertex3f(-16.5, -20.0, 53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-24.5, -20.0, 61);
    glVertex3f(-24.5, -16.0, 61);
    glVertex3f(-24.5, -16.0, 53);
    glVertex3f(-24.5, -20.0, 53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-16.5, -20.0, 61);
    glVertex3f(-16.5, -16.0, 61);
    glVertex3f(-16.5, -16.0, 53);
    glVertex3f(-16.5, -20.0, 53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-24.5, -16.0, 61);
    glVertex3f(-16.5, -16.0, 61);
    glVertex3f(-16.5, -16.0, 53);
    glVertex3f(-24.5, -16.0, 53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(-24.5, -20.1, 61);
    glVertex3f(-16.5, -20.1, 61);
    glVertex3f(-16.5, -20.1, 53);
    glVertex3f(-24.5, -20.1, 53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-18.0, -20.0, 60);
    glVertex3f(-18.0, 20.0, 60);
    glVertex3f(-18.0, 20.0, 55);
    glVertex3f(-18.0, -20.0, 55);
    glEnd();

    //tiang depan kqnqn
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(8.0, 20.0, 60);
    glVertex3f(8.0, -20.0, 60);
    glVertex3f(13.0, -20.0, 60);
    glVertex3f(13.0, 20.0, 60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(6.5, -20.0, 61);
    glVertex3f(14.5, -20.0, 61);
    glVertex3f(14.5, -16.0, 61);
    glVertex3f(6.5, -16.0, 61);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(14.5, -20.0, 61);
    glVertex3f(14.5, -20.0, 53);
    glVertex3f(14.5, -16.0, 53);
    glVertex3f(14.5, -16.0, 61);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(6.5, -20.0, 61);
    glVertex3f(6.5, -20.0, 53);
    glVertex3f(6.5, -16.0, 53);
    glVertex3f(6.5, -16.0, 61);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(6.5, -20.0, 53);
    glVertex3f(14.5, -20.0, 53);
    glVertex3f(14.5, -16.0, 53);
    glVertex3f(6.5, -16.0, 53);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(6.5, -16.0, 61);
    glVertex3f(14.5, -16.0, 61);
    glVertex3f(14.5, -16.0, 53);
    glVertex3f(6.5, -16.0, 53);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(2.90, 2.0, 0.0);
    glVertex3f(6.5, -20.1, 61);
    glVertex3f(14.5, -20.1, 61);
    glVertex3f(14.5, -20.1, 53);
    glVertex3f(6.5, -20.1, 53);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(13.0, 20.0, 60);
    glVertex3f(13.0, -20.0, 60);
    glVertex3f(13.0, -20.0, 55);
    glVertex3f(13.0, 20.0, 55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(8.0, 20.0, 60);
    glVertex3f(8.0, -20.0, 60);
    glVertex3f(8.0, -20.0, 55);
    glVertex3f(8.0, 20.0, 55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(8.0, 20.0, 55);
    glVertex3f(8.0, -20.0, 55);
    glVertex3f(13.0, -20.0, 55);
    glVertex3f(13.0, 20.0, 55);
    glEnd();
    //segitiga depan
    glBegin(GL_TRIANGLES);
    glColor3f(0.525,0.525,0.525);
    glVertex3f(-23.0, 20.0, 60);
    glVertex3f(-5.0, 40.0, 60);
    glVertex3f(13.0, 20.0, 60);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-14.0, 30.0, 63);
    glVertex3f(-5.0, 40.0, 63);
    glVertex3f(4.0, 30.0, 63);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-14.0, 30.0, 63);
    glVertex3f(-11.0, 28.0, 63);
    glVertex3f(-8.0, 30.0, 63);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-8.0, 30.0, 63);
    glVertex3f(-5.0, 28.0, 63);
    glVertex3f(-2.0, 30.0, 63);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-2.0, 30.0, 63);
    glVertex3f(1.0, 28.0, 63);
    glVertex3f(4.0, 30.0, 63);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-23.0, 20.0, 65);
    glVertex3f(-5.0, 40.0, 65);
    glVertex3f(-5.0, 37.0, 65);
    glVertex3f(-20.0, 20.0, 65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(13.0, 20.0, 65);
    glVertex3f(-5.0, 40.0, 65);
    glVertex3f(-5.0, 37.0, 65);
    glVertex3f(10.0, 20.0, 65);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.525,0.525,0.525);
    glVertex3f(-23.0, 20.0, 65);
    glVertex3f(-5.0, 40.0, 65);
    glVertex3f(-5.0, 40.0, 60);
    glVertex3f(-23.0, 20.0, 60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.525,0.525,0.525);
    glVertex3f(13.0, 20.0, 65);
    glVertex3f(-5.0, 40.0, 65);
    glVertex3f(-5.0, 40.0, 60);
    glVertex3f(13.0, 20.0, 60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.0, 20.0, 60.1);
    glVertex3f(-23.0, 18.0, 60.1);
    glVertex3f(13.0, 18.0, 60.1);
    glVertex3f(13.0, 20.0, 60.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23, 18.0, 61.1);
    glVertex3f(-20, 16.0, 61.1);
    glVertex3f(-17, 18.0, 61.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-17, 18.0, 61.1);
    glVertex3f(-14, 16.0, 61.1);
    glVertex3f(-11, 18.0, 61.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-11, 18.0, 61.1);
    glVertex3f(-8, 16.0, 61.1);
    glVertex3f(-5, 18.0, 61.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-5, 18.0, 61.1);
    glVertex3f(-2, 16.0, 61.1);
    glVertex3f(1, 18.0, 61.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(1, 18.0, 61.1);
    glVertex3f(4, 16.0, 61.1);
    glVertex3f(7, 18.0, 61.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(7, 18.0, 61.1);
    glVertex3f(10, 16.0, 61.1);
    glVertex3f(13, 18.0, 61.1);
    glEnd();
    //Atap depan kiri
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-23.1, 20.0, 60);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-23.1, 20.0, 30);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-5.0, 40.0, -15);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-5.0, 40.0, 60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 20.0, 65);
    glVertex3f(-23.1, 18.0, 65);
    glVertex3f(-23.1, 18.0, 30);
    glVertex3f(-23.1, 20.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 65);
    glVertex3f(-23.1, 16.0, 62);
    glVertex3f(-23.1, 18.0, 59);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 59);
    glVertex3f(-23.1, 16.0, 56);
    glVertex3f(-23.1, 18.0, 53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 53);
    glVertex3f(-23.1, 16.0, 50);
    glVertex3f(-23.1, 18.0, 47);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 47);
    glVertex3f(-23.1, 16.0, 45);
    glVertex3f(-23.1, 18.0, 42);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 42);
    glVertex3f(-23.1, 16.0, 39);
    glVertex3f(-23.1, 18.0, 36);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-23.1, 18.0, 36);
    glVertex3f(-23.1, 16.0, 33);
    glVertex3f(-23.1, 18.0, 30);
    glEnd();
    //Atap depan Kanan
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(13.1, 20.0, 60);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(13.1, 20.0, 30);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-5.0, 40.0, -15);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-5.0, 40.0, 60);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 20.0, 65);
    glVertex3f(13.1, 18.0, 65);
    glVertex3f(13.1, 18.0, 30);
    glVertex3f(13.1, 20.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 65);
    glVertex3f(13.1, 16.0, 62);
    glVertex3f(13.1, 18.0, 59);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 59);
    glVertex3f(13.1, 16.0, 56);
    glVertex3f(13.1, 18.0, 53);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 53);
    glVertex3f(13.1, 16.0, 50);
    glVertex3f(13.1, 18.0, 47);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 47);
    glVertex3f(13.1, 16.0, 45);
    glVertex3f(13.1, 18.0, 42);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 42);
    glVertex3f(13.1, 16.0, 39);
    glVertex3f(13.1, 18.0, 36);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(13.1, 18.0, 36);
    glVertex3f(13.1, 16.0, 33);
    glVertex3f(13.1, 18.0, 30);
    glEnd();

    // Segitiga samping kiri
    glBegin(GL_POLYGON);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(-65.0, 20.0, 30);//depan
    glVertex3f(-65.0, 40.0, -15);//tengah
    glVertex3f(-65.0, 20.0, -50);//belakang
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(-65.0, 20.0, -50);//tengah
    glVertex3f(-65.0, 45.0, -74);//tengah
    glVertex3f(-65.0, 20.0, -99);//tengah
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(-65.0, 20.0, -99);//tengah
    glVertex3f(-65.0, 45.0, -114);//tengah
    glVertex3f(-65.0, 20.0, -129);//tengah
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 20.0, 30);
    glVertex3f(-65.0, 18.0, 30);
    glVertex3f(-65.0, 18.0, -130);
    glVertex3f(-65.0, 20.0, -130);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 30);
    glVertex3f(-65.0, 16.0, 27);
    glVertex3f(-65.0, 18.0, 25);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 25);
    glVertex3f(-65.0, 16.0, 22);
    glVertex3f(-65.0, 18.0, 19);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 19);
    glVertex3f(-65.0, 16.0, 16);
    glVertex3f(-65.0, 18.0, 13);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 13);
    glVertex3f(-65.0, 16.0, 10);
    glVertex3f(-65.0, 18.0, 7);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 7);
    glVertex3f(-65.0, 16.0, 5);
    glVertex3f(-65.0, 18.0, 2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 2);
    glVertex3f(-65.0, 16.0, -1);
    glVertex3f(-65.0, 18.0, -4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -4);
    glVertex3f(-65.0, 16.0, -7);
    glVertex3f(-65.0, 18.0, -10);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -10);
    glVertex3f(-65.0, 16.0, -13);
    glVertex3f(-65.0, 18.0, -16);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -16);
    glVertex3f(-65.0, 16.0, -19);
    glVertex3f(-65.0, 18.0, -21);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -21);
    glVertex3f(-65.0, 16.0, -24);
    glVertex3f(-65.0, 18.0, -27);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -27);
    glVertex3f(-65.0, 16.0, -30);
    glVertex3f(-65.0, 18.0, -33);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0,-33);
    glVertex3f(-65.0, 16.0, -36);
    glVertex3f(-65.0, 18.0, -39);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -39);
    glVertex3f(-65.0, 16.0, -42);
    glVertex3f(-65.0, 18.0, -45);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -45);
    glVertex3f(-65.0, 16.0, -48);
    glVertex3f(-65.0, 18.0, -52);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -52);
    glVertex3f(-65.0, 16.0, -55);
    glVertex3f(-65.0, 18.0, -58);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -58);
    glVertex3f(-65.0, 16.0, -61);
    glVertex3f(-65.0, 18.0, -64);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -64);
    glVertex3f(-65.0, 16.0, -67);
    glVertex3f(-65.0, 18.0, -70);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -70);
    glVertex3f(-65.0, 16.0, -73);
    glVertex3f(-65.0, 18.0, -76);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -76);
    glVertex3f(-65.0, 16.0, -79);
    glVertex3f(-65.0, 18.0, -82);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -82);
    glVertex3f(-65.0, 16.0, -85);
    glVertex3f(-65.0, 18.0, -88);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -88);
    glVertex3f(-65.0, 16.0, -91);
    glVertex3f(-65.0, 18.0, -94);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -94);
    glVertex3f(-65.0, 16.0, -97);
    glVertex3f(-65.0, 18.0, -100);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -100);
    glVertex3f(-65.0, 16.0, -103);
    glVertex3f(-65.0, 18.0, -106);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -106);
    glVertex3f(-65.0, 16.0, -109);
    glVertex3f(-65.0, 18.0, -112);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -112);
    glVertex3f(-65.0, 16.0, -115);
    glVertex3f(-65.0, 18.0, -118);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -118);
    glVertex3f(-65.0, 16.0, -121);
    glVertex3f(-65.0, 18.0, -124);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -124);
    glVertex3f(-65.0, 16.0, -127);
    glVertex3f(-65.0, 18.0, -130);
    glEnd();
    // atap depan
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-65.0, 40.0, -15);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-65.0, 20.0, 30);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(65.0, 20.0, 30);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(65.0, 40.0, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 20.0, 30);
    glVertex3f(-65.0, 18.0, 30);
    glVertex3f(-23.0, 18.0, 30);
    glVertex3f(-23.0, 20.0, 30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 20.0, 30);
    glVertex3f(65.0, 18.0, 30);
    glVertex3f(13.0, 18.0, 30);
    glVertex3f(13.0, 20.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 30);
    glVertex3f(62.5, 16.0, 30);
    glVertex3f(60.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(60.0, 18.0, 30);
    glVertex3f(57.0, 16.0, 30);
    glVertex3f(54.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(54.0, 18.0, 30);
    glVertex3f(51.0, 16.0, 30);
    glVertex3f(48.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(48.0, 18.0, 30);
    glVertex3f(45.0, 16.0, 30);
    glVertex3f(42.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(42.0, 18.0, 30);
    glVertex3f(39.0, 16.0, 30);
    glVertex3f(36.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(36.0, 18.0, 30);
    glVertex3f(33.0, 16.0, 30);
    glVertex3f(30.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(30.0, 18.0, 30);
    glVertex3f(27.0, 16.0, 30);
    glVertex3f(24.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(24.0, 18.0, 30);
    glVertex3f(21.0, 16.0, 30);
    glVertex3f(18.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(18.0, 18.0, 30);
    glVertex3f(15.0, 16.0, 30);
    glVertex3f(13.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, 30);
    glVertex3f(-62.5, 16.0, 30);
    glVertex3f(-60.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-60.0, 18.0, 30);
    glVertex3f(-57.0, 16.0, 30);
    glVertex3f(-54.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-54.0, 18.0, 30);
    glVertex3f(-51.0, 16.0, 30);
    glVertex3f(-48.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-48.0, 18.0, 30);
    glVertex3f(-45.0, 16.0, 30);
    glVertex3f(-42.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-42.0, 18.0, 30);
    glVertex3f(-39.0, 16.0, 30);
    glVertex3f(-36.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-36.0, 18.0, 30);
    glVertex3f(-33.0, 16.0, 30);
    glVertex3f(-30.0, 18.0, 30);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-30.0, 18.0, 30);
    glVertex3f(-27.0, 16.0, 30);
    glVertex3f(-24.0, 18.0, 30);
    glEnd();
    // atap belakang
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-65.0, 40.0, -15);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-65.0, 20.0, -50);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(65.0, 20.0, -50);
	glTexCoord2f(1.0f, 0.0f);
    glVertex3f(65.0, 40.0, -15);
    glEnd();

    // Segitiga samping kanan
    glBegin(GL_TRIANGLES);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(65.0, 20.0, 30);//depan
    glVertex3f(65.0, 40.0, -15);//tengah
    glVertex3f(65.0, 20.0, -50);//belakang
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(65.0, 20.0, -50);//tengah
    glVertex3f(65.0, 45.0, -74);//tengah
    glVertex3f(65.0, 20.0, -99);//tengah
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.45,0.45,0.45);
    glVertex3f(95.0, 20.0, -99);//tengah
    glVertex3f(95.0, 45.0, -114);//tengah
    glVertex3f(95.0, 20.0, -129);//tengah
    glEnd();
    //ATAP belakang ATAS 2
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-65.0, 20.0, -99);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-65.0, 45.0, -74);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(65.0, 45.0, -74);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(65.0, 20.0, -99);
    glEnd();
    //atap depan 2
  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-65.0, 20.0, -50);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-65.0, 45.0, -74);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(65.0, 45.0, -74);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(65.0, 20.0, -50);
    glEnd();
    //atap depan atas 3
  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glTexCoord2f(0.0f,0.0f);
    glVertex3f(-65.0, 20.0, -99);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-65.0, 45.0, -114);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(95.0, 45.0, -114);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(95.0, 20.0, -99);
    glEnd();
  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
	glTexCoord2f(0.0f,0.0f);
    glVertex3f(-65.0, 20.0, -129);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-65.0, 45.0, -114);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(95.0, 45.0, -114);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(95.0, 20.0, -129);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 20.0, 30);
    glVertex3f(65.0, 18.0, 30);
    glVertex3f(65.0, 18.0, -98);
    glVertex3f(65.0, 20.0, -98);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 30);
    glVertex3f(65.0, 16.0, 27);
    glVertex3f(65.0, 18.0, 25);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 25);
    glVertex3f(65.0, 16.0, 22);
    glVertex3f(65.0, 18.0, 19);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 19);
    glVertex3f(65.0, 16.0, 16);
    glVertex3f(65.0, 18.0, 13);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 13);
    glVertex3f(65.0, 16.0, 10);
    glVertex3f(65.0, 18.0, 7);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 7);
    glVertex3f(65.0, 16.0, 5);
    glVertex3f(65.0, 18.0, 2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, 2);
    glVertex3f(65.0, 16.0, -1);
    glVertex3f(65.0, 18.0, -4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -4);
    glVertex3f(65.0, 16.0, -7);
    glVertex3f(65.0, 18.0, -10);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -10);
    glVertex3f(65.0, 16.0, -13);
    glVertex3f(65.0, 18.0, -16);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -16);
    glVertex3f(65.0, 16.0, -19);
    glVertex3f(65.0, 18.0, -21);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -21);
    glVertex3f(65.0, 16.0, -24);
    glVertex3f(65.0, 18.0, -27);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -27);
    glVertex3f(65.0, 16.0, -30);
    glVertex3f(65.0, 18.0, -33);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0,-33);
    glVertex3f(65.0, 16.0, -36);
    glVertex3f(65.0, 18.0, -39);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -39);
    glVertex3f(65.0, 16.0, -41);
    glVertex3f(65.0, 18.0, -44);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -44);
    glVertex3f(65.0, 16.0, -47);
    glVertex3f(65.0, 18.0, -50);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -50);
    glVertex3f(65.0, 16.0, -53);
    glVertex3f(65.0, 18.0, -56);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -56);
    glVertex3f(65.0, 16.0, -59);
    glVertex3f(65.0, 18.0, -62);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -62);
    glVertex3f(65.0, 16.0, -65);
    glVertex3f(65.0, 18.0, -68);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -68);
    glVertex3f(65.0, 16.0, -71);
    glVertex3f(65.0, 18.0, -74);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -74);
    glVertex3f(65.0, 16.0, -77);
    glVertex3f(65.0, 18.0, -80);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -80);
    glVertex3f(65.0, 16.0, -83);
    glVertex3f(65.0, 18.0, -86);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -86);
    glVertex3f(65.0, 16.0, -89);
    glVertex3f(65.0, 18.0, -92);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -92);
    glVertex3f(65.0, 16.0, -95);
    glVertex3f(65.0, 18.0, -98);
    glEnd();
    //Dinding depan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, -17.0, -30);
    glVertex3f(-59.9, 20.0, -30);
    glVertex3f(59.9, 20.0, -30);
    glVertex3f(59.9, -17.0, -30);
    glEnd();

    //jedela Depan
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-48.0, 8.0, -29.8);
    glVertex3f(-42.0, 8.0, -29.8);
    glVertex3f(-42.0, 2.0, -29.8);
    glVertex3f(-48.0, 2.0, -29.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-24.0, 8.0, -29.8);
    glVertex3f(-11.0, 8.0, -29.8);
    glVertex3f(-11.0, 2.0, -29.8);
    glVertex3f(-24.0, 2.0, -29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-8.0, 8.0, -29.8);
    glVertex3f(8.0, 8.0, -29.8);
    glVertex3f(8.0, 2.0, -29.8);
    glVertex3f(-8.0, 2.0, -29.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(12.0, 8.0, -29.8);
    glVertex3f(24.0, 8.0, -29.8);
    glVertex3f(24.0, 2.0, -29.8);
    glVertex3f(12.0, 2.0, -29.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(42.0, 8.0, -29.8);
    glVertex3f(48.0, 8.0, -29.8);
    glVertex3f(48.0, 2.0, -29.8);
    glVertex3f(42.0, 2.0, -29.8);
    glEnd();

    //pintu depan
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-50.0, 10.0, -29.8);
    glVertex3f(-40.0, 10.0, -29.8);
    glVertex3f(-40.0, -20.0, -29.8);
    glVertex3f(-50.0, -20.0, -29.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-25.0, 10.0, -29.8);
    glVertex3f(-10.0, 10.0, -29.8);
    glVertex3f(-10.0, -20.0, -29.8);
    glVertex3f(-25.0, -20.0, -29.8);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(10.0, -20.0, -29.6);
    glVertex3f(10.0, 10.0, -29.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-10.0, 10.0, -29.8);
    glVertex3f(10.0, 10.0, -29.8);
    glVertex3f(10.0, -20.0, -29.8);
    glVertex3f(-10.0, -20.0, -29.8);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-10.0, -20.0, -29.6);
    glVertex3f(-10.0, 10.0, -29.6);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(10.0, 10.0, -29.8);
    glVertex3f(25.0, 10.0, -29.8);
    glVertex3f(25.0, -20.0, -29.8);
    glVertex3f(10.0, -20.0, -29.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(40.0, 10.0, -29.8);
    glVertex3f(50.0, 10.0, -29.8);
    glVertex3f(50.0, -20.0, -29.8);
    glVertex3f(40.0, -20.0, -29.8);
    glEnd();

    //pintu : jedela, gagang -> kanan
    //gagang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(60.2, -8.0, -18.1);
    glVertex3f(60.2, -4.0, -18.1);
    glVertex3f(60.2, -4.0, -19.1);
    glVertex3f(60.2, -8.0, -19.1);
    glEnd();

    //jedela
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(60.2, -1.0,-11.2);
    glVertex3f(60.2, 5.0, -11.2);
    glVertex3f(60.2, 5.0, -19.2);
    glVertex3f(60.2, -1.0, -19.2);
    glEnd();
    
        //jedela
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(56.9, -1.0,-11.2);
    glVertex3f(56.9, 5.0, -11.2);
    glVertex3f(56.9, 5.0, -19.2);
    glVertex3f(56.9, -1.0, -19.2);
    glEnd();
        //gagang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(56.9, -8.0, -18.1);
    glVertex3f(56.9, -4.0, -18.1);
    glVertex3f(56.9, -4.0, -19.1);
    glVertex3f(56.9, -8.0, -19.1);
    glEnd();

    // pintu kanan
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(60.1, -17.0, -10);
    glVertex3f(60.1, 7.0, -10);
    glVertex3f(60.1, 7.0, -20);
    glVertex3f(60.1, -17.0, -20);
    glEnd();
        // pintu kanan
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(56.9, -17.0, -10);
    glVertex3f(56.9, 7.0, -10);
    glVertex3f(56.9, 7.0, -20);
    glVertex3f(56.9, -17.0, -20);
    glEnd();

    // pintu belakang
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-35.0, -17.0, -125.1);
    glVertex3f(-35.0, 7.0, -125.1);
    glVertex3f(-25.0, 7.0, -125.1);
    glVertex3f(-25.0, -17.0,-125.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(55.0, -17.0, -125.1);
    glVertex3f(55.0, 7.0, -125.1);
    glVertex3f(65.0, 7.0, -125.1);
    glVertex3f(65.0, -17.0, -125.1);
    glEnd();

    // jendela samping kiri belakang
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.1, -5.0, -80);
    glVertex3f(-60.1, 12.0, -80);
    glVertex3f(-60.1, 12.0, -95);
    glVertex3f(-60.1, -5.0, -95);
    glEnd();

    // jendela samping kiri depan 2
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.1, -5.0, 10);
    glVertex3f(-60.1, 12.0, 10);
    glVertex3f(-60.1, 12.0, -20);
    glVertex3f(-60.1, -5.0, -20);
    glEnd();

    // jendela samping kiri depan 2
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-56.9, -5.0, 10);
    glVertex3f(-56.9, 12.0, 10);
    glVertex3f(-56.9, 12.0, -20);
    glVertex3f(-56.9, -5.0, -20);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.2, 0.0);
    glVertex3f(-60.2, 4.0, -80);
    glVertex3f(-60.2, 4.0, -95);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-60.2, -5.0, -88);
    glVertex3f(-60.2, 12.0, -88);
    glEnd();


    //4 tiang kecil depan
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-39, 20.0, 15);
    glVertex3f(-41, 20.0, 15);
    glVertex3f(-41, -17.0, 15);
    glVertex3f(-39, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-39, 20.0, 15);
    glVertex3f(-39, 20.0, 14);
    glVertex3f(-39, -17.0, 14);
    glVertex3f(-39, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-41, 20.0, 15);
    glVertex3f(-41, 20.0, 14);
    glVertex3f(-41, -17.0, 14);
    glVertex3f(-41, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-39, 20.0, 14);
    glVertex3f(-41, 20.0, 14);
    glVertex3f(-41, -17.0, 14);
    glVertex3f(-39, -17.0, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20, 20.0, 15);
    glVertex3f(-22, 20.0, 15);
    glVertex3f(-22, -17.0, 15);
    glVertex3f(-20, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20, 20.0, 15);
    glVertex3f(-20, 20.0, 14);
    glVertex3f(-20, -17.0, 14);
    glVertex3f(-20, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-22, 20.0, 15);
    glVertex3f(-22, 20.0, 14);
    glVertex3f(-22, -17.0, 14);
    glVertex3f(-22, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20, 20.0, 14);
    glVertex3f(-22, 20.0, 14);
    glVertex3f(-22, -17.0, 14);
    glVertex3f(-20, -17.0, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(39, 20.0, 15);
    glVertex3f(41, 20.0, 15);
    glVertex3f(41, -17.0, 15);
    glVertex3f(39, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(39, 20.0, 15);
    glVertex3f(39, 20.0, 14);
    glVertex3f(39, -17.0, 14);
    glVertex3f(39, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(41, 20.0, 15);
    glVertex3f(41, 20.0, 14);
    glVertex3f(41, -17.0, 14);
    glVertex3f(41, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(39, 20.0, 14);
    glVertex3f(41, 20.0, 14);
    glVertex3f(41, -17.0, 14);
    glVertex3f(39, -17.0, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(8, 20.0, 15);
    glVertex3f(10, 20.0, 15);
    glVertex3f(10, -17.0, 15);
    glVertex3f(8, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(8, 20.0, 15);
    glVertex3f(8, 20.0, 14);
    glVertex3f(8, -17.0, 14);
    glVertex3f(8, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(10, 20.0, 15);
    glVertex3f(10, 20.0, 14);
    glVertex3f(10, -17.0, 14);
    glVertex3f(10, -17.0, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(8, 20.0, 14);
    glVertex3f(10, 20.0, 14);
    glVertex3f(10, -17.0, 14);
    glVertex3f(8, -17.0, 14);
    glEnd();
    //atas ruangan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-65.0, 20.0, 30);
    glVertex3f(-65.0, 20.0, -99);
    glVertex3f(65.0, 20.0, -99);
    glVertex3f(65.0, 20.0, 30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-65.0, 20.0, -129);
    glVertex3f(-65.0, 20.0, -99);
    glVertex3f(95.0, 20.0, -99);
    glVertex3f(95.0, 20.0, -129);
    glEnd();
    // atas bawah segitiga
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-23.0, 20.0, 20);
    glVertex3f(-23.0, 20.0, 60);
    glVertex3f(13.0,  20.0, 60);
    glVertex3f(13.0,  20.0, 20);
    glEnd();
    // teras depan
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-23.0, -20.0, 20);
    glVertex3f(-23.0, -20.0, 60);
    glVertex3f(13.0, -20.0, 60);
    glVertex3f(13.0, -20.0, 20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.0, -17.0, 10);
    glVertex3f(-60.0, -17.0, 17);
    glVertex3f(60.0, -17.0, 17);
    glVertex3f(60.0, -17.0, 10);
    glEnd();
    //Tangga
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-60.0, -17.0, 17);
    glVertex3f(-60.0, -17.0, 18);
    glVertex3f(60.0, -17.0, 18);
    glVertex3f(60.0, -17.0, 17);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-60.0, -17.0, 18);
    glVertex3f(-60.0, -18.0, 18);
    glVertex3f(60.0, -18.0, 18);
    glVertex3f(60.0, -17.0, 18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-60.0, -18.0, 18);
    glVertex3f(-60.0, -18.0, 19);
    glVertex3f(60.0, -18.0, 19);
    glVertex3f(60.0, -18.0, 18);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-60.0, -18.0, 19);
    glVertex3f(-60.0, -19.0, 19);
    glVertex3f(60.0, -19.0, 19);
    glVertex3f(60.0, -18.0, 19);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-60.0, -19.0, 19);
    glVertex3f(-60.0, -19.0, 20);
    glVertex3f(60.0, -19.0, 20);
    glVertex3f(60.0, -19.0, 19);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-60.0, -19.0, 20);
    glVertex3f(-60.0, -20.0, 20);
    glVertex3f(60.0, -20.0, 20);
    glVertex3f(60.0, -19.0, 20);
    glEnd();
    //Dinding kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, 20.0, 17);
    glVertex3f(-59.9, -17.0, 17);
    glVertex3f(-59.9, -17.0, -99);
    glVertex3f(-59.9, 20.0, -99);
    glEnd();
    //Dinding kiri depan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, -20.0, 17);
    glVertex3f(-57, -20.0, 17);
    glVertex3f(-57, 20.0, 17);
    glVertex3f(-59.9, 20.0, 17);
    glEnd();

    //Dinding kiri samping depan 2
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-57, -20.0, 17);
    glVertex3f(-57, -20.0, -29.8);
    glVertex3f(-57, 20.0, -29.8);
    glVertex3f(-57, 20.0, 17);
    glEnd();
    
    //Dinding kiri 2
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, 20.0, -125);
    glVertex3f(-59.9, -17.0, -125);
    glVertex3f(-59.9, -17.0, -99);
    glVertex3f(-59.9, 20.0, -99);
    glEnd();
    
    //Dinding kanan
   glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(59.9, 20.0, 17);
    glVertex3f(59.9, -17.0, 17);
    glVertex3f(59.9, -17.0, -99);
    glVertex3f(59.9, 20.0, -99);
    glEnd();
    
    //Dinding kanan depan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(59.9, -20.0, 17);
    glVertex3f(57, -20.0, 17);
    glVertex3f(57, 20.0, 17);
    glVertex3f(59.9, 20.0, 17);
    glEnd();

    //Dinding kanan samping depan 2
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(57, -20.0, 17);
    glVertex3f(57, -20.0, -29.8);
    glVertex3f(57, 20.0, -29.8);
    glVertex3f(57, 20.0, 17);
    glEnd();
    
    //Dinding kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(90.0, 20.0, -125);
    glVertex3f(90.0, -17.0, -125);
    glVertex3f(90.0, -17.0, -99);
    glVertex3f(90.0, 20.0, -99);
    glEnd();
    //Dinding belakang 1
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, -17.0, -49.9);
    glVertex3f(-59.9, 20.0, -49.9);
    glVertex3f(59.9, 20.0, -49.9);
    glVertex3f(59.9, -17.0, -49.9);
    glEnd();
    // DINDING BELAKANG 2
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, -17.0, -99);
    glVertex3f(-59.9, 20.0, -99);
    glVertex3f(90.0, 20.0, -99);
    glVertex3f(90.0, -17.0, -99);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-59.9, -17.0, -125);
    glVertex3f(-59.9, 20.0, -125);
    glVertex3f(90.0, 20.0, -125);
    glVertex3f(90.0, -17.0, -125);
    glEnd();
    //segitiga hiasan delakang
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 20.0, -129);
    glVertex3f(-65.0, 18.0, -129);
    glVertex3f(95.0, 18.0, -129);
    glVertex3f(95.0, 20.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-65.0, 18.0, -129);
    glVertex3f(-62.5, 16.0, -129);
    glVertex3f(-60.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-60.0, 18.0, -129);
    glVertex3f(-57.0, 16.0, -129);
    glVertex3f(-54.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-54.0, 18.0, -129);
    glVertex3f(-51.0, 16.0, -129);
    glVertex3f(-48.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-48.0, 18.0, -129);
    glVertex3f(-45.0, 16.0, -129);
    glVertex3f(-42.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-42.0, 18.0, -129);
    glVertex3f(-39.0, 16.0, -129);
    glVertex3f(-36.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-36.0, 18.0, -129);
    glVertex3f(-33.0, 16.0, -129);
    glVertex3f(-30.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-30.0, 18.0, -129);
    glVertex3f(-27.0, 16.0, -129);
    glVertex3f(-24.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-24.0, 18.0, -129);
    glVertex3f(-21.0, 16.0, -129);
    glVertex3f(-18.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-18.0, 18.0, -129);
    glVertex3f(-15.0, 16.0, -129);
    glVertex3f(-12.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-12.0, 18.0, -129);
    glVertex3f(-9.0, 16.0, -129);
    glVertex3f(-6.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(-6.0, 18.0, -129);
    glVertex3f(-3.0, 16.0, -129);
    glVertex3f(-0.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(0.0, 18.0, -129);
    glVertex3f(3.0, 16.0, -129);
    glVertex3f(6.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(6.0, 18.0, -129);
    glVertex3f(9.0, 16.0, -129);
    glVertex3f(12.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(12.0, 18.0, -129);
    glVertex3f(15.0, 16.0, -129);
    glVertex3f(18.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(18.0, 18.0, -129);
    glVertex3f(21.0, 16.0, -129);
    glVertex3f(24.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(24.0, 18.0, -129);
    glVertex3f(27.0, 16.0, -129);
    glVertex3f(30.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(30.0, 18.0, -129);
    glVertex3f(33.0, 16.0, -129);
    glVertex3f(36.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(36.0, 18.0, -129);
    glVertex3f(39.0, 16.0, -129);
    glVertex3f(41.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(41.0, 18.0, -129);
    glVertex3f(44.0, 16.0, -129);
    glVertex3f(47.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(47.0, 18.0, -129);
    glVertex3f(50.0, 16.0, -129);
    glVertex3f(53.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(53.0, 18.0, -129);
    glVertex3f(56.0, 16.0, -129);
    glVertex3f(59.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(59.0, 18.0, -129);
    glVertex3f(62.0, 16.0, -129);
    glVertex3f(65.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -129);
    glVertex3f(68.0, 16.0, -129);
    glVertex3f(71.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(71.0, 18.0, -129);
    glVertex3f(74.0, 16.0, -129);
    glVertex3f(77.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(77.0, 18.0, -129);
    glVertex3f(80.0, 16.0, -129);
    glVertex3f(83.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(83.0, 18.0, -129);
    glVertex3f(86.0, 16.0, -129);
    glVertex3f(89.0, 18.0, -129);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(89.0, 18.0, -129);
    glVertex3f(92.0, 16.0, -129);
    glVertex3f(95.0, 18.0, -129);
    glEnd();

    //depan belakang
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 20.0, -98);
    glVertex3f(65.0, 18.0, -98);
    glVertex3f(95.0, 18.0, -98);
    glVertex3f(95.0, 20.0, -98);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(65.0, 18.0, -98);
    glVertex3f(68.0, 16.0, -98);
    glVertex3f(71.0, 18.0, -98);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(71.0, 18.0, -98);
    glVertex3f(74.0, 16.0, -98);
    glVertex3f(77.0, 18.0, -98);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(77.0, 18.0, -98);
    glVertex3f(80.0, 16.0, -98);
    glVertex3f(83.0, 18.0, -98);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(83.0, 18.0, -98);
    glVertex3f(86.0, 16.0, -98);
    glVertex3f(89.0, 18.0, -98);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(89.0, 18.0, -98);
    glVertex3f(92.0, 16.0, -98);
    glVertex3f(95.0, 18.0, -98);
    glEnd();

    //belakang segitiga kanan
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 20.0, -129);
    glVertex3f(95.0, 18.0, -129);
    glVertex3f(95.0, 18.0, -98);
    glVertex3f(95.0, 20.0, -98);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 18.0, -98);
    glVertex3f(95.0, 16.0, -101);
    glVertex3f(95.0, 18.0, -104);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 18.0, -104);
    glVertex3f(95.0, 16.0, -107);
    glVertex3f(95.0, 18.0, -110);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 18.0, -110);
    glVertex3f(95.0, 16.0, -113);
    glVertex3f(95.0, 18.0, -116);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 18.0, -116);
    glVertex3f(95.0, 16.0, -119);
    glVertex3f(95.0, 18.0, -122);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(95.0, 18.0, -122);
    glVertex3f(95.0, 16.0, -125);
    glVertex3f(95.0, 18.0, -128);
    glEnd();
    //hall
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.2, 0.1);
    glVertex3f(62.0, 10.0, 10);
    glVertex3f(62.0, 20.0, -15);
    glVertex3f(62.0, 10.0, -40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(120.0, 10.0, 10);
    glVertex3f(120.0, 20.0, -15);
    glVertex3f(120.0, 10.0, -40);
    glEnd();

  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(62.0, 10.0, 10);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(62.0, 20.0, -15);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(120.0, 20.0, -15);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(120.0, 10.0, 10);
    glEnd();

  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(62.0, 10.0, -40);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(62.0, 20.0, -15);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(120.0, 20.0, -15);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(120.0, 10.0, -40);
    glEnd();
    //Tiang Hall kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, 5);
    glVertex3f(65.0, 10.0, 5);
    glVertex3f(70.0, 10.0, 5);
    glVertex3f(70.0, -20.0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, 5);
    glVertex3f(65.0, 10.0, 5);
    glVertex3f(65.0, 10.0, 0);
    glVertex3f(65.0, -20.0, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(70.0, -20.0, 5);
    glVertex3f(70.0, 10.0, 5);
    glVertex3f(70.0, 10.0, 0);
    glVertex3f(70.0, -20.0, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, 0);
    glVertex3f(65.0, 10.0, 0);
    glVertex3f(70.0, 10.0, 0);
    glVertex3f(70.0, -20.0, 0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, -35);
    glVertex3f(65.0, 10.0, -35);
    glVertex3f(70.0, 10.0, -35);
    glVertex3f(70.0, -20.0, -35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, -30);
    glVertex3f(65.0, 10.0, -30);
    glVertex3f(65.0, 10.0, -35);
    glVertex3f(65.0, -20.0, -35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(70.0, -20.0, -30);
    glVertex3f(70.0, 10.0, -30);
    glVertex3f(70.0, 10.0, -35);
    glVertex3f(70.0, -20.0,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(65.0, -20.0, -30);
    glVertex3f(65.0, 10.0, -30);
    glVertex3f(70.0, 10.0, -30);
    glVertex3f(70.0, -20.0, -30);
    glEnd();

    //Kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, 5);
    glVertex3f(110.0, 10.0, 5);
    glVertex3f(115.0, 10.0, 5);
    glVertex3f(115.0, -20.0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, 5);
    glVertex3f(110.0, 10.0, 5);
    glVertex3f(110.0, 10.0, 0);
    glVertex3f(110.0, -20.0, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(115.0, -20.0, 5);
    glVertex3f(115.0, 10.0, 5);
    glVertex3f(115.0, 10.0, 0);
    glVertex3f(115.0, -20.0, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, 0);
    glVertex3f(110.0, 10.0, 0);
    glVertex3f(115.0, 10.0, 0);
    glVertex3f(115.0, -20.0, 0);
    glEnd();

    //belakang kanan hall
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, -35);
    glVertex3f(110.0, 10.0, -35);
    glVertex3f(115.0, 10.0, -35);
    glVertex3f(115.0, -20.0, -35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, -30);
    glVertex3f(110.0, 10.0, -30);
    glVertex3f(110.0, 10.0, -35);
    glVertex3f(110.0, -20.0, -35);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(115.0, -20.0, -30);
    glVertex3f(115.0, 10.0, -30);
    glVertex3f(115.0, 10.0, -35);
    glVertex3f(115.0, -20.0,-35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.8, 1.0);
    glVertex3f(110.0, -20.0, -30);
    glVertex3f(110.0, 10.0, -30);
    glVertex3f(115.0, 10.0, -30);
    glVertex3f(115.0, -20.0, -30);
    glEnd();

    //lantai hall
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(58.0, -20.0, 5);
    glVertex3f(58.0, -20.0, -35);
    glVertex3f(120.0, -20.0, -35);
    glVertex3f(120.0, -20.0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(58.0, -17.0, 5);
    glVertex3f(58.0, -17.0, -35);
    glVertex3f(120.0, -17.0, -35);
    glVertex3f(120.0, -17.0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(58.0, -20.0, 5);
    glVertex3f(58.0, -17.0, 5);
    glVertex3f(120.0, -17.0, 5);
    glVertex3f(120.0, -20.0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(58.0, -20.0, -35);
    glVertex3f(58.0, -17.0, -35);
    glVertex3f(120.0, -17.0, -35);
    glVertex3f(120.0, -20.0, -35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(120.0, -20.0, 5);
    glVertex3f(120.0, -17.0, 5);
    glVertex3f(120.0, -17.0, -35);
    glVertex3f(120.0, -20.0,-35);
    glEnd();

    //lantai bawah rumah
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.0, -17.0, 10);
    glVertex3f(60.0, -17.0, 10);
    glVertex3f(60.0, -17.0, -125);
    glVertex3f(-60.0, -17.0,-125);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.0, -20.0, 20);
    glVertex3f(60.0, -20.0, 20);
    glVertex3f(60.0, -20.0, -125);
    glVertex3f(-60.0, -20.0,-125);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(60.0, -20.0, 20);
    glVertex3f(60.0, -17.0, 17);
    glVertex3f(60.0, -17.0, -99);
    glVertex3f(60.0, -20.0,-99);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(60.0, -20.0, -99);
    glVertex3f(60.0, -17.0, -99);
    glVertex3f(90.0, -17.0, -99);
    glVertex3f(90.0, -20.0,-99);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(60.0, -20.0, -125);
    glVertex3f(60.0, -17.0, -125);
    glVertex3f(90.0, -17.0, -125);
    glVertex3f(90.0, -20.0,-125);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(90.0, -20.0, -99);
    glVertex3f(90.0, -17.0, -99);
    glVertex3f(90.0, -17.0, -125);
    glVertex3f(90.0, -20.0,-125);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(-60.0, -20.0, 20);
    glVertex3f(-60.0, -17.0, 17);
    glVertex3f(-60.0, -17.0, -125);
    glVertex3f(-60.0, -20.0,-125);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.90, 0.90, 0.90);
    glVertex3f(60.0, -20.0, -99);
    glVertex3f(60.0, -20.0, -125);
    glVertex3f(90.0, -20.0, -125);
    glVertex3f(90.0, -20.0, -99);
    glEnd();

    //jalan
  	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-80.0, -20.1, 100);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-80.0, -20.1, -200);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(130.0, -20.1, -200);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(130.0, -20.1, 100);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case 't':
    case 'T':
        xrot += 3.0;
        break;
    case 'g':
    case 'G':
        xrot -= 3.0;
        break;
    case 'y':
    case 'Y':
        yrot += 3.0;
        break;
    case 'h':
    case 'H':
        yrot -= 3.0;
        break;
    case 'u':
    case 'U':
        zrot += 3.0;
        break;
    case 'j':
    case 'J':
        zrot -= 3.0;
        break;
    case 'i':
    case 'I':
        sca += 0.1;
        break;
    case 'k':
    case 'K':
        sca -= 0.1;
        break;
    case '1':
        ymov += 3.0;
        break;
    case '2':
        ymov -= 3.0;
        break;
    case '3':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 1000.0);
    glTranslatef(0.0, -5.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
}

