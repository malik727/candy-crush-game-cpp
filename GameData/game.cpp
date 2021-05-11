//============================================================================
// Name        : game.cpp
// Author      : Malik Talha Saee
// Version     : v1.0
// Copyright   : (c) Copyright. All Rights are Reserved.
// Description : 2D game of Gem Chronicles
//============================================================================

#ifndef MAINGAME_CPP_
#define MAINGAME_CPP_

#include "../Utilities/util.h"
#include "../GameEngine/MainEngine.h"
#include <iostream>
#include <string>
#include <cmath>
#include <time.h> 

using namespace std;

MainEngine game;
	int v = 600;
void SetCanvasSize(int width, int height) 
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/* Main Game Function */
void GameDisplay()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	game.initialize();
	game.drawSwapLine();
	glutSwapBuffers();
}

void NonPrintableKeys(int key, int x, int y) 
{
	if (key == GLUT_KEY_LEFT)
	{

	} 
	else if(key == GLUT_KEY_RIGHT)
	{

	} 
	else if(key == GLUT_KEY_UP) 
	{
		game.upKeyPressed();
	}
	else if(key == GLUT_KEY_DOWN) 
	{
		game.downKeyPressed();
	}
	/* The function below calls the Display function to redo the drawing. Whenever you need to redraw just call this function */
	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y) 
{
	game.setKeyPressed(key);
	glutPostRedisplay();
}

void Timer(int m)
{
	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();
	glutTimerFunc(1000, Timer, 0);
}

void MousePressedAndMoved(int x, int y) 
{
	y = 750 - y; //Setting back the coordinates to be cartesian
	// cout<<"\nMose pressed and moved!"<<endl;
	// cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseMoved(int x, int y) 
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) 
{
	y = 750 - y;
	if (button == GLUT_LEFT_BUTTON)
	{
	// 	cout << GLUT_DOWN << " " << GLUT_UP << endl;
		if(state == 0)
		{
			game.gemSelected(x, y);
		}
		if(state == 1)
		{
			game.gemSelected(x, y);
			game.resetOldCoords();
		}
	} 
	// else if(button == GLUT_RIGHT_BUTTON)
	// {
	// 	cout<<"Right Button Pressed"<<endl;
	// }
	
	glutPostRedisplay();
}

/* The Main Function */

int main(int argc, char*argv[]) 
{
	int width, height;
	width = 900;
	height = 750;
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(600, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("Gem Chronicles");
	SetCanvasSize(width, height);
	glutDisplayFunc(GameDisplay);
	glutIdleFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); 
	glutMotionFunc(MousePressedAndMoved); 
	glutMainLoop();
	return 1;
}
#endif /* MAINGAME_CPP_ */
