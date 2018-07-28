#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cmath>
#include<cstring>
#include <Windows.h>
#include <MMSystem.h>

#include <stdlib.h>
using namespace std;

void FindClash(int from);
void EndGame(int value);
void Special(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
bool flag = false;
bool isClashed = false;
float _moveX = -0.75;
float _moveY = 0.0;
float _moveCX = 0.75;
float _moveCY = 0.0;
int winner = 0;
int LOOP = 0;
void drawScene()
{
//    PlaySound(TEXT("D:\clas.wav"), NULL, SND_SYNC);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);

    ///Background

    ///BORDER STARTS
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f,1.0f,0.0f);
    glVertex3f(-1.0f,-1.0f,0.0f);
    glVertex3f(-.93f,-1.0f,0.0f);
    glVertex3f(-0.93f,1.0f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(1.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(.93f,-1.0f,0.0f);
    glVertex3f(0.93f,1.0f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(1.0f,1.0f,0.0f);
    glVertex3f(1.0f,0.9f,0.0f);
    glVertex3f(-1.0f,0.9f,0.0f);
    glVertex3f(-1.0f,1.0f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(1.0f,-1.0f,0.0f);
    glVertex3f(1.0f,-0.9f,0.0f);
    glVertex3f(-1.0f,-0.9f,0.0f);
    glVertex3f(-1.0f,-1.0f,0.0f);
    glEnd();
    ///BORDER ENDS


    glColor3f(0.14,0.14,0.14);
/*-----------------------------------B START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.8f,0.8f,0.0f);
    glVertex3f(-0.825f,0.8f,0.0f);
    glVertex3f(-0.825f,0.4f,0.0f);
    glVertex3f(-0.8f,0.4f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(-0.84f,0.8f,0.0f);
    glVertex3f(-0.7f,0.8f,0.0f);
    glVertex3f(-0.7f,0.75f,0.0f);
    glVertex3f(-0.84f,0.75f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(-0.825f,0.625f,0.0f);
    glVertex3f(-0.7f,0.625f,0.0f);
    glVertex3f(-0.7f,0.575f,0.0f);
    glVertex3f(-0.825f,0.575f,0.0f);
    glEnd();

///4
    glBegin(GL_QUADS);
    glVertex3f(-0.84f,0.45f,0.0f);
    glVertex3f(-0.7f,0.45f,0.0f);
    glVertex3f(-0.7f,0.4f,0.0f);
    glVertex3f(-0.84f,0.4f,0.0f);
    glEnd();

///5
    glBegin(GL_QUADS);
    glVertex3f(-0.7f,0.8f,0.0f);
    glVertex3f(-0.725f,0.8f,0.0f);
    glVertex3f(-0.725f,0.4f,0.0f);
    glVertex3f(-0.7f,0.4f,0.0f);
    glEnd();
/*-----------------------------------B END---------------------------------*/

/*-----------------------------------U START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.6f,0.8f,0.0f);
    glVertex3f(-0.625f,0.8f,0.0f);
    glVertex3f(-0.625f,0.4f,0.0f);
    glVertex3f(-0.6f,0.4f,0.0f);
    glEnd();

///4
    glBegin(GL_QUADS);
    glVertex3f(-0.64f,0.45f,0.0f);
    glVertex3f(-0.5f,0.45f,0.0f);
    glVertex3f(-0.5f,0.4f,0.0f);
    glVertex3f(-0.64f,0.4f,0.0f);
    glEnd();

///5
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,0.8f,0.0f);
    glVertex3f(-0.525f,0.8f,0.0f);
    glVertex3f(-0.525f,0.4f,0.0f);
    glVertex3f(-0.5f,0.4f,0.0f);
    glEnd();
/*-----------------------------------U END---------------------------------*/

/*-----------------------------------M START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.4f,0.8f,0.0f);
    glVertex3f(-0.425f,0.8f,0.0f);
    glVertex3f(-0.425f,0.4f,0.0f);
    glVertex3f(-0.4f,0.4f,0.0f);
    glEnd();

///6
    glBegin(GL_QUADS);
    glVertex3f(-0.425f,0.8f,0.0f);
    glVertex3f(-0.4,0.8f,0.0f);
    glVertex3f(-0.355f,0.6f,0.0f);
    glVertex3f(-0.355f,0.4f,0.0f);
    glEnd();

///7
    glBegin(GL_QUADS);
    glVertex3f(-0.29f,0.8f,0.0f);
    glVertex3f(-0.315,0.8f,0.0f);
    glVertex3f(-0.355f,0.6f,0.0f);
    glVertex3f(-0.355f,0.4f,0.0f);
    glEnd();


///5
    glBegin(GL_QUADS);
    glVertex3f(-0.29f,0.8f,0.0f);
    glVertex3f(-0.315f,0.8f,0.0f);
    glVertex3f(-0.315f,0.4f,0.0f);
    glVertex3f(-0.29f,0.4f,0.0f);
    glEnd();
/*-----------------------------------M END---------------------------------*/

/*-----------------------------------P START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.2f,0.8f,0.0f);
    glVertex3f(-0.225f,0.8f,0.0f);
    glVertex3f(-0.225f,0.4f,0.0f);
    glVertex3f(-0.2f,0.4f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(-0.24f,0.8f,0.0f);
    glVertex3f(-0.1f,0.8f,0.0f);
    glVertex3f(-0.1f,0.75f,0.0f);
    glVertex3f(-0.24f,0.75f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(-0.225f,0.625f,0.0f);
    glVertex3f(-0.1f,0.625f,0.0f);
    glVertex3f(-0.1f,0.575f,0.0f);
    glVertex3f(-0.225f,0.575f,0.0f);
    glEnd();
///5
    glBegin(GL_QUADS);
    glVertex3f(-0.1f,0.8f,0.0f);
    glVertex3f(-0.125f,0.8f,0.0f);
    glVertex3f(-0.125f,0.6f,0.0f);
    glVertex3f(-0.1f,0.6f,0.0f);
    glEnd();
/*-----------------------------------P END---------------------------------*/

/*-----------------------------------E START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.0f,0.8f,0.0f);
    glVertex3f(-0.025f,0.8f,0.0f);
    glVertex3f(-0.025f,0.4f,0.0f);
    glVertex3f(-0.0f,0.4f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(-0.04f,0.8f,0.0f);
    glVertex3f(0.1f,0.8f,0.0f);
    glVertex3f(0.1f,0.75f,0.0f);
    glVertex3f(-0.04f,0.75f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(-0.025f,0.625f,0.0f);
    glVertex3f(0.1f,0.625f,0.0f);
    glVertex3f(0.1f,0.575f,0.0f);
    glVertex3f(-0.025f,0.575f,0.0f);
    glEnd();

///4
    glBegin(GL_QUADS);
    glVertex3f(-0.04f,0.45f,0.0f);
    glVertex3f(0.1f,0.45f,0.0f);
    glVertex3f(0.1f,0.4f,0.0f);
    glVertex3f(-0.04f,0.4f,0.0f);
    glEnd();
/*-----------------------------------E END---------------------------------*/

/*-----------------------------------R START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(0.17f,0.8f,0.0f);
    glVertex3f(0.195f,0.8f,0.0f);
    glVertex3f(0.195f,0.4f,0.0f);
    glVertex3f(0.17f,0.4f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(0.29f,0.8f,0.0f);
    glVertex3f(0.15f,0.8f,0.0f);
    glVertex3f(0.15f,0.75f,0.0f);
    glVertex3f(0.29f,0.75f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(0.29f,0.625f,0.0f);
    glVertex3f(0.175f,0.625f,0.0f);
    glVertex3f(0.175f,0.575f,0.0f);
    glVertex3f(0.29f,0.575f,0.0f);
    glEnd();
///5
    glBegin(GL_QUADS);
    glVertex3f(0.27f,0.8f,0.0f);
    glVertex3f(0.29f,0.8f,0.0f);
    glVertex3f(0.29f,0.6f,0.0f);
    glVertex3f(0.27f,0.6f,0.0f);
    glEnd();

///8
    glBegin(GL_QUADS);
    glVertex3f(0.17f,0.6f,0.0f);
    glVertex3f(0.20f,0.6f,0.0f);
    glVertex3f(0.3f,0.45f,0.0f);
    glVertex3f(0.3f,0.4f,0.0f);
    glEnd();
/*-----------------------------------R END---------------------------------*/

/*-----------------------------------C START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,0.2f,0.0f);
    glVertex3f(-0.525f,0.2f,0.0f);
    glVertex3f(-0.525f,-0.2f,0.0f);
    glVertex3f(-0.5f,-0.2f,0.0f);

///2
    glBegin(GL_QUADS);
    glVertex3f(-0.5f,0.2f,0.0f);
    glVertex3f(-0.4f,0.2f,0.0f);
    glVertex3f(-0.4f,0.15f,0.0f);
    glVertex3f(-0.5f,0.15f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.42f,0.2f,0.0f);
    glVertex3f(-0.4f,0.2f,0.0f);
    glVertex3f(-0.4f,0.13f,0.0f);
    glVertex3f(-0.42f,0.13f,0.0f);
    glEnd();

///4
    glBegin(GL_QUADS);
    glVertex3f(-0.52f,-0.2f,0.0f);
    glVertex3f(-0.4f,-0.2f,0.0f);
    glVertex3f(-0.4f,-0.15f,0.0f);
    glVertex3f(-0.52f,-0.15f,0.0f);
    glEnd();
/*-----------------------------------C END---------------------------------*/

/*-----------------------------------A START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.3f,0.2f,0.0f);
    glVertex3f(-0.325f,0.2f,0.0f);
    glVertex3f(-0.325f,-0.2f,0.0f);
    glVertex3f(-0.3f,-0.2f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(-0.34f,0.2f,0.0f);
    glVertex3f(-0.2f,0.2f,0.0f);
    glVertex3f(-0.2f,0.15f,0.0f);
    glVertex3f(-0.34f,0.15f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(-0.325f,0.025f,0.0f);
    glVertex3f(-0.2f,0.025f,0.0f);
    glVertex3f(-0.2f,-0.025f,0.0f);
    glVertex3f(-0.325f,-0.025f,0.0f);
    glEnd();
///5
    glBegin(GL_QUADS);
    glVertex3f(-0.2f,0.2f,0.0f);
    glVertex3f(-0.225f,0.2f,0.0f);
    glVertex3f(-0.225f,-0.2f,0.0f);
    glVertex3f(-0.2f,-0.2f,0.0f);
    glEnd();
/*-----------------------------------A END---------------------------------*/

/*-----------------------------------R START---------------------------------*/
///1
    glBegin(GL_QUADS);
    glVertex3f(-0.1f,0.2f,0.0f);
    glVertex3f(-0.125f,0.2f,0.0f);
    glVertex3f(-0.125f,-0.2f,0.0f);
    glVertex3f(-0.1f,-0.2f,0.0f);
    glEnd();

///2
    glBegin(GL_QUADS);
    glVertex3f(0.01f,0.2f,0.0f);
    glVertex3f(-0.14f,0.2f,0.0f);
    glVertex3f(-0.14f,0.15f,0.0f);
    glVertex3f(0.01f,0.15f,0.0f);
    glEnd();

///3
    glBegin(GL_QUADS);
    glVertex3f(0.01f,0.025f,0.0f);
    glVertex3f(-0.12f,0.025f,0.0f);
    glVertex3f(-0.12f,-0.025f,0.0f);
    glVertex3f(0.01f,-0.025f,0.0f);
    glEnd();
///5
    glBegin(GL_QUADS);
    glVertex3f(0.01f,0.2f,0.0f);
    glVertex3f(-0.01f,0.2f,0.0f);
    glVertex3f(-0.01f,0.0f,0.0f);
    glVertex3f(0.01f,0.0f,0.0f);
    glEnd();

///8
    glBegin(GL_QUADS);
    glVertex3f(-0.12f,0.0f,0.0f);
    glVertex3f(-0.09f,0.0f,0.0f);
    glVertex3f(0.01f,-0.15f,0.0f);
    glVertex3f(0.01f,-0.2f,0.0f);
    glEnd();
/*-----------------------------------R END---------------------------------*/



/*-----------------------------------R END---------------------------------*/
    if(isClashed)
    {
        glColor3f(0.0,0.0,0.0);

/*-----------------------------------C START---------------------------------*/
    ///1
        glBegin(GL_QUADS);
        glVertex3f(-0.5f,0.2f,0.0f);
        glVertex3f(-0.525f,0.2f,0.0f);
        glVertex3f(-0.525f,-0.2f,0.0f);
        glVertex3f(-0.5f,-0.2f,0.0f);

    ///2
        glBegin(GL_QUADS);
        glVertex3f(-0.5f,0.2f,0.0f);
        glVertex3f(-0.4f,0.2f,0.0f);
        glVertex3f(-0.4f,0.15f,0.0f);
        glVertex3f(-0.5f,0.15f,0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3f(-0.42f,0.2f,0.0f);
        glVertex3f(-0.4f,0.2f,0.0f);
        glVertex3f(-0.4f,0.13f,0.0f);
        glVertex3f(-0.42f,0.13f,0.0f);
        glEnd();

    ///4
        glBegin(GL_QUADS);
        glVertex3f(-0.52f,-0.2f,0.0f);
        glVertex3f(-0.4f,-0.2f,0.0f);
        glVertex3f(-0.4f,-0.15f,0.0f);
        glVertex3f(-0.52f,-0.15f,0.0f);
        glEnd();
    /*-----------------------------------C END---------------------------------*/

    /*-----------------------------------A START---------------------------------*/
    ///1
        glBegin(GL_QUADS);
        glVertex3f(-0.3f,0.2f,0.0f);
        glVertex3f(-0.325f,0.2f,0.0f);
        glVertex3f(-0.325f,-0.2f,0.0f);
        glVertex3f(-0.3f,-0.2f,0.0f);
        glEnd();

    ///2
        glBegin(GL_QUADS);
        glVertex3f(-0.34f,0.2f,0.0f);
        glVertex3f(-0.2f,0.2f,0.0f);
        glVertex3f(-0.2f,0.15f,0.0f);
        glVertex3f(-0.34f,0.15f,0.0f);
        glEnd();

    ///3
        glBegin(GL_QUADS);
        glVertex3f(-0.325f,0.025f,0.0f);
        glVertex3f(-0.2f,0.025f,0.0f);
        glVertex3f(-0.2f,-0.025f,0.0f);
        glVertex3f(-0.325f,-0.025f,0.0f);
        glEnd();
    ///5
        glBegin(GL_QUADS);
        glVertex3f(-0.2f,0.2f,0.0f);
        glVertex3f(-0.225f,0.2f,0.0f);
        glVertex3f(-0.225f,-0.2f,0.0f);
        glVertex3f(-0.2f,-0.2f,0.0f);
        glEnd();
    /*-----------------------------------A END---------------------------------*/

    /*-----------------------------------R START---------------------------------*/
    ///1
        glBegin(GL_QUADS);
        glVertex3f(-0.1f,0.2f,0.0f);
        glVertex3f(-0.125f,0.2f,0.0f);
        glVertex3f(-0.125f,-0.2f,0.0f);
        glVertex3f(-0.1f,-0.2f,0.0f);
        glEnd();

    ///2
        glBegin(GL_QUADS);
        glVertex3f(0.01f,0.2f,0.0f);
        glVertex3f(-0.14f,0.2f,0.0f);
        glVertex3f(-0.14f,0.15f,0.0f);
        glVertex3f(0.01f,0.15f,0.0f);
        glEnd();

    ///3
        glBegin(GL_QUADS);
        glVertex3f(0.01f,0.025f,0.0f);
        glVertex3f(-0.12f,0.025f,0.0f);
        glVertex3f(-0.12f,-0.025f,0.0f);
        glVertex3f(0.01f,-0.025f,0.0f);
        glEnd();
    ///5
        glBegin(GL_QUADS);
        glVertex3f(0.01f,0.2f,0.0f);
        glVertex3f(-0.01f,0.2f,0.0f);
        glVertex3f(-0.01f,0.0f,0.0f);
        glVertex3f(0.01f,0.0f,0.0f);
        glEnd();

    ///8
        glBegin(GL_QUADS);
        glVertex3f(-0.12f,0.0f,0.0f);
        glVertex3f(-0.09f,0.0f,0.0f);
        glVertex3f(0.01f,-0.15f,0.0f);
        glVertex3f(0.01f,-0.2f,0.0f);
        glEnd();
    /*-----------------------------------R END---------------------------------*/
        if(winner==1)
        {
            glBegin(GL_QUADS);
            glVertex3f(0.2f,0.2f,0.0f);
            glVertex3f(0.25f,0.2f,0.0f);
            glVertex3f(0.25f,-0.2f,0.0f);
            glVertex3f(0.2f,-0.2f,0.0f);
            glEnd();
            glutPostRedisplay();

        }

        else if(winner==2)
        {
        /*-----------------------------------R START---------------------------------*/
        ///1
            glBegin(GL_QUADS);
            glVertex3f(0.17f,0.02f,0.0f);
            glVertex3f(0.195f,0.02f,0.0f);
            glVertex3f(0.195f,-0.2f,0.0f);
            glVertex3f(0.17f,-0.2f,0.0f);
            glEnd();

        ///2
            glBegin(GL_QUADS);
            glVertex3f(0.29f,0.2f,0.0f);
            glVertex3f(0.17f,0.2f,0.0f);
            glVertex3f(0.17f,0.15f,0.0f);
            glVertex3f(0.29f,0.15f,0.0f);
            glEnd();

        ///3
            glBegin(GL_QUADS);
            glVertex3f(0.29f,0.02f,0.0f);
            glVertex3f(0.175f,0.02f,0.0f);
            glVertex3f(0.175f,-0.02f,0.0f);
            glVertex3f(0.29f,-0.02f,0.0f);
            glEnd();

        ///4
            glBegin(GL_QUADS);
            glVertex3f(0.29f,-0.2f,0.0f);
            glVertex3f(0.17f,-0.2f,0.0f);
            glVertex3f(0.17f,-0.15f,0.0f);
            glVertex3f(0.29f,-0.15f,0.0f);
            glEnd();


        ///5
            glBegin(GL_QUADS);
            glVertex3f(0.27f,0.2f,0.0f);
            glVertex3f(0.29f,0.2f,0.0f);
            glVertex3f(0.29f,0.0f,0.0f);
            glVertex3f(0.27f,0.0f,0.0f);
            glEnd();
        /*-----------------------------------R END---------------------------------*/
        }
    }


/*---------------------------------------------------------------------------------*/
/*-----------------------------------1st Car Start---------------------------------*/
/*---------------------------------------------------------------------------------*/
    glPushMatrix();
    glScalef(0.5f,1.0f,1.0f);
    glTranslatef(_moveX,_moveY, 0.0);

    glColor3f(.580,0.043,0.247);
    glutSolidSphere(0.1,50,50);
    glColor3f(.780,0,0.22);
    glutSolidSphere(0.075,50,50);
    glColor3f(.580,0.043,0.247);
    glBegin(GL_QUADS);
    glVertex3f(0.08,-0.075,0);
    glVertex3f(0.08,-0.1,0);
    glVertex3f(-0.08,-0.1,0);
    glVertex3f(-0.08,-0.075,0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(0.025,-0.025,0);
    glVertex3f(0.025,-0.075,0);
    glVertex3f(-0.025,-0.075,0);
    glVertex3f(-0.025,-0.0025,0);
    glEnd();
    glutSolidSphere(0.015,50,50);
    glPopMatrix();
    ///1st Car End

    ///2nd Car Start
    glPushMatrix();
    glScalef(0.5f,1.0f,1.0f);
    glTranslatef(_moveCX,_moveCY, 0.0);
    glColor3f(0.105,0.6,0.54);
    glutSolidSphere(0.1,50,50);
    glColor3f(0.56,0.77,0.66);
    glutSolidSphere(0.075,50,50);
    glColor3f(0.105,0.6,0.54);
    glBegin(GL_QUADS);
    glVertex3f(0.08,-0.075,0);
    glVertex3f(0.08,-0.1,0);
    glVertex3f(-0.08,-0.1,0);
    glVertex3f(-0.08,-0.075,0);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.025,-0.025,0);
    glVertex3f(-0.025,-0.075,0);
    glVertex3f(0.025,-0.075,0);
    glVertex3f(0.025,-0.0025,0);
    glEnd();
    glutSolidSphere(0.015,50,50);
    glPopMatrix();
    ///2nd Car End

    glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:     // ESC key
        exit(0);
        break;

    case 65:     ///S
        _moveCX -= 0.1f;
        glutPostRedisplay();
        FindClash(5);
        break;

    case 83:     /// S
        _moveCY -= 0.1f;
        glutPostRedisplay();
        FindClash(7);
        break;

    case 68:     /// D
        _moveCX += 0.1f;
        glutPostRedisplay();
        FindClash(6);
        break;

    case 87:     /// W
        _moveCY += 0.1f;
        glutPostRedisplay();
        FindClash(8);
        break;
    }
}
void whoOwn()
{
    if(_moveCX < -1.85 || _moveCX > 1.85)
    {
        if(!isClashed)
        {
            cout << "Arrow key Won"<<endl;
            PlaySound(TEXT("G:\clash.wav"), NULL, SND_SYNC);
            PlaySound(TEXT("G:\lalgari.wav"), NULL, SND_SYNC);
            isClashed = true;
            EndGame(1);
        }
    }
    else if(_moveCY < -.85 || _moveCY > 0.85)
    {
        if(!isClashed)
        {
            cout << "Arrow key Won"<<endl;
            PlaySound(TEXT("G:\clash.wav"), NULL, SND_SYNC);
            PlaySound(TEXT("G:\lalgari.wav"), NULL, SND_SYNC);
            isClashed = true;
            EndGame(1);
        }
    }
    else if(_moveX < -1.85 || _moveX > 1.85)
    {
        if(!isClashed)
        {
            cout << "ASDW key Won"<<endl;
            PlaySound(TEXT("G:\clash.wav"), NULL, SND_SYNC);
            PlaySound(TEXT("G:\Nil.wav"), NULL, SND_SYNC);
            isClashed = true;
            EndGame(2);
        }
    }
    else if(_moveY < -.85 || _moveY > 0.85)
    {
        if(!isClashed)
        {
            cout << "ASDW key Won"<<endl;
            PlaySound(TEXT("G:\clash.wav"), NULL, SND_SYNC);
            PlaySound(TEXT("G:\Nil.wav"), NULL, SND_SYNC);
            isClashed = true;
            EndGame(2);
        }
    }
}

void Special(int key, int x, int y)
{
    switch (key)
    {
    case 27:
        PlaySound(TEXT("G:\clap.wav"), NULL, SND_SYNC);
        exit(0);
        glutPostRedisplay();
        break;

    case GLUT_KEY_LEFT:
        _moveX -= 0.1f;
        glutPostRedisplay();
        FindClash(1);
        break;

    case GLUT_KEY_DOWN:
        _moveY -= 0.1f;
        glutPostRedisplay();
        FindClash(3);
        break;

    case GLUT_KEY_RIGHT:
        _moveX += 0.1f;
        glutPostRedisplay();
        FindClash(2);
        break;

    case GLUT_KEY_UP:
        _moveY += 0.1f;
        glutPostRedisplay();
        FindClash(4);
        break;
    }
}

void FindClash(int from)
{
    int car1X = 600*_moveX;
    int car2X = 600*_moveCX;
    int car1Y = 600*_moveY;
    int car2Y = 600*_moveCY;

    car1X += 50000;
    car2X += 50000;
    car1Y += 50000;
    car2Y += 50000;
    if((abs(car1X-car2X)<=61 && (abs(car1Y-car2Y)<=1)))
    {
        if(car1X < car2X)
        {
            if(from==2)
            {
                _moveCX += 0.1f;
            }
            else if(from==5)
            {
                _moveX -= 0.1f;
            }
        }
        else if(car1X > car2X)
        {
            if(from==1)
            {
                _moveCX -= 0.1f;
            }
            else if(from==6)
            {
                _moveX += 0.1f;
            }
        }
    }

    if((abs(car2X-car1X)<=61 && (abs(car1Y-car2Y)<=61)))
    {
        if(!(abs(car1Y-car2Y)<=1))
        {
            if(car1X < car2X)
            {
                if(from==2)
                {
                    _moveCX += 0.1f;
                }
                else if(from==5)
                {
                    _moveX -= 0.1f;
                }
            }
            else if(car1X > car2X)
            {
                if(from==1)
                {
                    _moveCX -= 0.1f;
                }
                else if(from==6)
                {
                    _moveX += 0.1f;
                }
            }
        }
    }

    if(abs(car1X-car2X)<=1 && (abs(car1Y-car2Y)<=61))
    {
        if(car1Y < car2Y)
        {
            if(from==4)
            {
                _moveCY += 0.1f;
            }
            else if(from==7)
            {
                _moveY -= 0.1f;
            }
        }
        else if(car1Y > car2Y)
        {
            if(from==3)
            {
                _moveCY -= 0.1f;
            }
            else if(from==8)
            {
                _moveY += 0.1f;
            }
        }
    }
    if(abs(car1X-car2X)<=61 && (abs(car1Y-car2Y)<=61))
    {
        if(!(abs(car1X-car2X)<=1))
        {
            if(car1Y < car2Y)
            {
                if(from==4)
                {
                    _moveCY += 0.1f;
                }
                else if(from==7)
                {
                    _moveY -= 0.1f;
                }
            }
            else if(car1Y > car2Y)
            {
                if(from==3)
                {
                    _moveCY -= 0.1f;
                }
                else if(from==8)
                {
                    _moveY += 0.1f;
                }
            }
        }
    }
    whoOwn();
}

void EndGame(int value)
{
    if(value==1)
    {
        glClearColor(0.14,0.14,0.14, 1);
        winner = 1;
        _moveX = 0;
        _moveY = 0.5;
        _moveCX = 100000000000000;
        _moveCY = 100000000000000;

            if(LOOP==0)
            {
                PlaySound(TEXT("G:\clap.wav"), NULL, SND_SYNC);
                LOOP++;
            }
    }
    else if(value==2)
    {
        glClearColor(0.14,0.14,0.14, 1);
        winner = 2;
        _moveX = 100000000000000;
        _moveY = 100000000000000;
        _moveCX = 0;
        _moveCY = 0.5;

            if(LOOP==0)
            {
                PlaySound(TEXT("G:\clap.wav"), NULL, SND_SYNC);
                LOOP++;
            }
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bumper Car Game");
    glutDisplayFunc(drawScene);
    glutFullScreen();
    glutSpecialFunc(Special);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}
