#ifndef MAINENGINE_H
#define MAINENGINE_H

#include "../PlayerData/Player.h"
#include "GamePlay.h"
#include <iostream>

class MainEngine
{
    private:
        bool gameRunning;
        int state;
        int subState;
        int totalCount; //used for file handling
        Player* user;
        GamePlay mainGame;
        static int keyPressed;
        static string nameInput;
        int menuArrowControl;
        int mainLevel;

    public:
        MainEngine()
        {
            gameRunning = true;
            state = 0; //0 means splash screen
            subState = 1;
            user = new Player();
            menuArrowControl = 0;
            mainLevel = 0;
        }
        void initialize(); 
        void pause();
        void resume();
        bool running();
        void quit();
        void gemSelected(int, int);
        void changeState(int state);
        int getState()const;
        void resetOldCoords();
        void drawSwapLine();
        void setKeyPressed(int);
        int getScore()const;
        void upKeyPressed();
        void downKeyPressed();
        int getCurrentLevel();
};

#endif