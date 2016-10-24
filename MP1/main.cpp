//
//  main.cpp
//  Sample OpenGL
//
//  Created by Suraj Venkat on 2/1/16.
//  Copyright © 2016 Suraj Venkat. All rights reserved.
//
#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

//
// Example code for OpenGL programming
//
#include <stdio.h>
#include <stdlib.h>

#include <ctime>
//#include <SOIL/SOIL.h>

int nFPS = 30;
float fRotateAngle = 0.f;
clock_t startClock=0,curClock;
long long int prevF=0,curF=0;
int dipMode=1;
int state = 0;
int rads ;

void init(void)
{
    // init your data, setup OpenGL environment here
    glClearColor(0,0,1.0,1.0); // clear color is gray
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // uncomment this function if you only want to draw wireframe model
    // GL_POINT / GL_LINE / GL_FILL (default)
    glPointSize(4.0);
}

void display(void)
{
    if(dipMode==1)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    
    
    curF++;
    
    if(curF%16==0)
    {
        rads = rads + (1.57);
        if(rads > 3.14)
            rads = 0;
        
    }
    
    // put your OpenGL display commands here
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    // reset OpenGL transformation matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // reset transformation matrix to identity
    
    // setup look at transformation so that
    // eye is at : (0,0,3)
    // look at center is at : (0,0,0)
    // up direction is +y axis
    gluLookAt(0.f,0.f,3.f,0.f,0.f,0.f,0.f,1.f,0.f);
    glRotatef(fRotateAngle,0.f,1.f,0.f);
    
    // Test drawing a solid teapot
    
    //glutSolidTeapot(1.f); // call glut utility to draw a solid teapot
    
    glBegin(GL_TRIANGLE_STRIP );
    glColor3f(1.0,0.7,0.03*(curF%30)); // set current color to Red
    
    glVertex2f(  (-0.6) + 0.45 * sinf(rads),  (0.6 ) + 0.45 * cosf(rads));
    
    glVertex2f(  (-0.6) + 0.46 * sinf(rads) ,  1.0 + 0.46 * cosf(rads));
    
    glVertex2f( (-0.2 ) + 0.28 * sinf(rads),  (0.6 )+ 0.28 * cosf(rads));
    
    
    
    glColor3f(1.0,0.8,0.03*(curF%30)); // set current color to Red
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (1 ) +  0.05 * cosf(rads));
    glVertex2f( (0.2 ) + 0.1 * sinf(rads),  (0.6) + 0.1 * cosf(rads));
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (0.6 ) + 0.05 * cosf(rads));
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN );
    
    glColor3f(0.5,0.7,0.03*(curF%30)); // set current color to Red
    glVertex2f(  (0.6) + 0.65 * sinf(rads),  (-1 ) + 0.05 * cosf(rads) );
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (-0.6 ) + 0.05 * cosf(rads));
    glVertex2f( (0.2 ) + 0.15 * sinf(rads),  (-0.6 )+ 0.15 * cosf(rads));
    
    glVertex2f( (-0.2 ) + 0.25 * sinf(rads),  (-0.6 ) + 0.25 * cosf(rads));
    glVertex2f( (-0.6 ) + 0.35 * sinf(rads),  (-0.6 )+ 0.35 * cosf(rads));
    glVertex2f( (-0.6 ) + 0.45 * sinf(rads),  (-1.0 ) + 0.45 * cosf(rads));
    
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP );
    glColor3f(0.5,0.7,0.03*(curF%30));
    glVertex2f(  (-0.2 ) + 0.25 * sinf(rads),  (-0.6 ) + 0.25 * cosf(rads));
    
    
    glVertex2f( (0.2 ) + 0.15 * sinf(rads),  (-0.6 ) + 0.15 * cosf(rads));
    
    glColor3f(1.0,0.7,0.03*(curF%30));
    glVertex2f( (-0.2 ) + 0.28 * sinf(rads),  (0.6 ) + 0.28 * cosf(rads));
    
    glColor3f(1.0,0.8,0.03*(curF%30)); // set current color to Red
    glVertex2f( (0.2 ) + 0.1 * sinf(rads),  (0.6) + 0.1 * cosf(rads));
    glEnd();
    
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0xFFFF);
    
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);
    glVertex2f(  (-0.6) + 0.46 * sinf(rads) ,  1.0 + 0.46 * cosf(rads));
    glVertex2f(  (-0.6) + 0.45 * sinf(rads),  (0.6 ) + 0.45 * cosf(rads));
    glVertex2f( (-0.2 ) + 0.28 * sinf(rads),  (0.6 )+ 0.28 * cosf(rads));
    glVertex2f( (-0.2 ) + 0.25 * sinf(rads),  (-0.6 ) + 0.25 * cosf(rads));
    glVertex2f( (-0.6 ) + 0.35 * sinf(rads),  (-0.6 )+ 0.35 * cosf(rads));
    glVertex2f( (-0.6 ) + 0.45 * sinf(rads),  (-1.0 ) + 0.45 * cosf(rads));
    glVertex2f(  (0.6) + 0.65 * sinf(rads),  (-1 ) + 0.05 * cosf(rads) );
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (-0.6 ) + 0.05 * cosf(rads));
    glVertex2f( (0.2 ) + 0.15 * sinf(rads),  (-0.6 ) + 0.15 * cosf(rads));
    glVertex2f( (0.2 ) + 0.1 * sinf(rads),  (0.6) + 0.1 * cosf(rads));
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (0.6 ) + 0.05 * cosf(rads));
    glVertex2f( (0.6 ) + 0.05 * sinf(rads),  (1 ) +  0.05 * cosf(rads));
    glVertex2f(  (-0.6) + 0.46 * sinf(rads) ,  1.0 + 0.46 * cosf(rads));
    glEnd();
    
    //glFlush();
    glutSwapBuffers();	// swap front/back framebuffer to avoid flickering
    
    curClock=glutGet(GLUT_ELAPSED_TIME);
    float elapsed=(curClock-startClock)/(float)CLOCKS_PER_SEC;
    if(elapsed>1.0f){
        float fps=(float)(curF-prevF)/elapsed;
        //printf("fps:%f\n",fps);
        prevF=curF;
        startClock=curClock;
    }
}

void reshape (int w, int h)
{
    // reset viewport ( drawing screen ) size
    glViewport(0, 0, w, h);
    float fAspect = ((float)w)/h;
    // reset OpenGL projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.f,fAspect,0.001f,30.f);
}



void keyboard(unsigned char key, int x, int y)
{
    // put your keyboard control here
    if (key == 27)
    {
        // ESC hit, so quit
        printf("demonstration finished.\n");
        exit(0);
    }
    if( key == 'h'){
        dipMode = 1-dipMode;
    }
}

void mouse(int button, int state, int x, int y)
{
    // process your mouse control here
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        printf("push left mouse button.\n");
}


void timer(int v)
{
    fRotateAngle += 1.f; // change rotation angles
    glutPostRedisplay(); // trigger display function by sending redraw into message queue
    glutTimerFunc(1000/nFPS,timer,v); // restart timer again
}

int main(int argc, char* argv[])
{
    glutInit(&argc, (char**)argv);
    // set up for double-buffering & RGB color buffer & depth test
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ((const char*)"MP1_venkat3");
    
    init(); // setting up user data & OpenGL environment
    
    // set up the call-back functions
    glutDisplayFunc(display);  // called when drawing
    glutReshapeFunc(reshape);  // called when change window size
    glutKeyboardFunc(keyboard); // called when received keyboard interaction
    glutMouseFunc(mouse);	    // called when received mouse interaction
    glutTimerFunc(100,timer,nFPS); // a periodic timer. Usually used for updating animation
    
    startClock=clock();
    
    glutMainLoop(); // start the main message-callback loop
    
    return 0;
}