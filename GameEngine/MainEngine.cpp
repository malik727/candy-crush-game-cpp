#include "MainEngine.h"

int MainEngine::keyPressed = -1;
string MainEngine::nameInput = "";

void MainEngine::initialize() 
{
    if(state == 0 && gameRunning == true) //Splash Screen
    {
        float* color = colors[CRIMSON];
        glClearColor(0.941, 1.000, 0.941, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        DrawStringTNR(360, 400,"Gem Chronicles", colors[CRIMSON]);
        DrawString(430, 100, "Loading ...", color);
        DrawHollowCircle(390, 106, 10);
        glutSwapBuffers();
        addDelay(1);
        state = 1;
        subState = 1;
    }
    else if(state == 1 && gameRunning == true) //Main Menu
    {
        if(keyPressed == 78 || keyPressed == 110)
        {
            subState = 2;
            keyPressed = -1;   
        }
        if(keyPressed == 67 || keyPressed == 99)
        {
            subState = 4;
            keyPressed = -1;   
        }
        if(subState == 1)
        {
            glClearColor(0.980, 0.922, 0.843, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            DrawStringTNR( 380, 600, "Main Menu", colors[CRIMSON]);
            DrawLine(375, 595, 505, 595, 4, colors[CRIMSON]);
            DrawRectangle(615, 429, 201, 40, colors[DEEP_SKY_BLUE]);
            DrawStringTNR( 120, 400, "Gem Chronicles", colors[DEEP_SKY_BLUE]);
            DrawString( 127, 360, "... Swap to Win ...", colors[DARK_OLIVE_GREEN]);
            DrawStringTNR( 630, 440, "New Game [N]", colors[WHITE]);
            DrawStringTNR( 630, 390, "Continue [C]", colors[DARK_SLATE_BLUE]);
            DrawStringTNR( 630, 340, "HighScores [H]", colors[DARK_SLATE_BLUE]);
            DrawStringTNR( 630, 290, "Help [I]", colors[DARK_SLATE_BLUE]);
            DrawStringTNR( 630, 240, "Exit [E]", colors[DARK_SLATE_BLUE]);
            DrawString( 270, 15, "Designed and Developed by i190413", colors[BLACK]);
        }
        /* States to create a new gamer profile */
        else if(subState == 2)
        {
            glClearColor(0.416, 0.353, 0.804, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            glClear(GL_DEPTH_BUFFER_BIT);
            DrawStringTNR( 315, 600, "Create a new Game Profile", colors[WHITE]);
            DrawLine(310, 595, 590, 595, 4, colors[WHITE]);
            DrawString( 230, 450, "Type your Name: ", colors[WHITE]);
            DrawRectangle(415, 437, 260, 40, colors[WHITE]);
            DrawString( 420, 450, nameInput, colors[BLACK]);
            DrawRectangle(540, 300, 100, 45, colors[CRIMSON]);
            DrawString( 555, 315, "Back [0]", colors[WHITE]);
            DrawRectangle(650, 300, 110, 45, colors[CRIMSON]);
            DrawString( 665, 315, "Ok [Enter]", colors[WHITE]);
            DrawString( 310, 80, "Carefully type in your name and then,", colors[WHITE]);
            DrawString( 345, 50, "Press [Enter] to Continue ...", colors[WHITE]);
            
        }
        else if(subState == 3)
        {
            glClearColor(0.980, 0.922, 0.843, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            DrawStringTNR( 380, 600, "Profile Created!", colors[CRIMSON]);
            DrawLine(375, 595, 538, 595, 4, colors[CRIMSON]);
            DrawStringTNR( 120, 450, "General Instructions:", colors[INDIGO]);
            DrawString( 145, 380, "1. Player can swap gems by drag and drop using a mouse.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 320, "2. Players main goal should be to form chains of 3 or more of gems by swapping.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 260, "3. An attempt at wrong swap will cost the player -ve 100 score.", colors[DARK_SLATE_BLUE]);
            DrawString( 320, 120, "Level 1 will start after few seconds ...", colors[CRIMSON]);
            glutSwapBuffers();
            addDelay(4);
            subState = 0;
            state = 2;
        }
        /* States to load a gamer profile */
        else if(subState == 4)
        {
            string userName[12];
            int ulevels[12];
            user->getProfiles(userName, ulevels);
            glClearColor(0.255, 0.412, 0.882, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            DrawStringTNR( 390, 700, "Load Profile!", colors[WHITE]);
            DrawLine(382, 695, 530, 695, 4, colors[WHITE]);
            DrawString( 145, 640, "Select one of the profiles below using Arrow Keys and then Press [Enter]", colors[WHITE]);
            DrawString( 300, 530, "Name", colors[WHITE]);
            DrawString( 490, 530, "Levels Completed", colors[WHITE]);
            DrawLine(290, 525, 660, 525, 4, colors[WHITE]);
            DrawRectangle(300, menuArrowControl, 140, 37, colors[BLACK]);
            int offset = 490;
            for(int i=0; i<totalCount; i++)
            {
                if(i==10)
                {
                    break;
                }
                DrawString( 305, offset, userName[i], colors[WHITE]);
                DrawString( 545, offset, to_string(ulevels[i]), colors[WHITE]);
                offset -= 40;
            }
            DrawRectangle(402, 40, 100, 45, colors[WHITE]);
            DrawString( 415, 55, "Back [B]", colors[RED]);
        }
        else if(subState == 5)
        {

        }
        /* State to display highscore */
        else if(subState == 6) // *NOTE* Only top 10 high scores are displayed
        {
            string usernames[10];
            int scores[10];
            user->getHighScores(scores, usernames);
            glClearColor(0.000, 0.980, 0.604, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            DrawStringTNR( 385, 650, "High Scores", colors[CRIMSON]);
            DrawLine(375, 645, 523, 645, 4, colors[CRIMSON]);
            DrawStringTNR( 270, 590, "Top 10 High Scores are displayed here!", colors[CRIMSON]);
            DrawString( 300, 530, "Name", colors[BLACK]);
            DrawString( 530, 530, "Score", colors[BLACK]);
            DrawLine(290, 525, 610, 525, 4, colors[BLACK]);
            int offset = 490;
            for(int i=0; i<totalCount-1; i++)
            {
                if(i==10)
                {
                    break;
                }
                DrawString( 305, offset, usernames[i], colors[BLACK]);
                DrawString( 535, offset, to_string(scores[i]), colors[BLACK]);
                offset -= 25;
            }
            DrawLine(290, 540, 290, offset, 4, colors[BLACK]);
            DrawLine(610, 540, 610, offset, 4, colors[BLACK]);
            DrawRectangle(402, 40, 100, 45, colors[CRIMSON]);
            DrawString( 415, 55, "Back [B]", colors[WHITE]);
        }

        /* State to display help window */
        else if(subState == 7)
        {
            glClearColor(255, 255, 250, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            DrawStringTNR( 390, 650, "Help Menu!", colors[CRIMSON]);
            DrawLine(380, 642, 530, 642, 4, colors[CRIMSON]);
            DrawStringTNR( 120, 540, "General Instructions:", colors[INDIGO]);
            DrawString( 145, 470, "1. Player can swap gems by drag and drop using a mouse.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 410, "2. Players main goal should be to form chains of 3 or more of gems by swapping.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 350, "3. An attempt at wrong swap will cost the player -ve 100 score.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 290, "4. Players game is saved automatically after every level.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 230, "5. Press [P] to pause game during the gameplay.", colors[DARK_SLATE_BLUE]);
            DrawString( 145, 170, "6. Each level has a target score required to proceed to next level.", colors[DARK_SLATE_BLUE]);
            DrawRectangle(402, 40, 100, 45, colors[CRIMSON]);
            DrawString( 415, 55, "Back [B]", colors[WHITE]);
        }
    }
    else if(state == 2 && gameRunning == true) //Main GamePlay
    {
        glClearColor(0.941, 0.973, 1.000, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        DrawRectangle(380, 715, 110, 40, colors[DEEP_SKY_BLUE]);
        DrawString(395, 725, user->getHName()+" ...", colors[FLORAL_WHITE]);
        mainGame.start();
        if(getScore() >= 5000*mainLevel && mainLevel <=4)
        {
            mainLevel++;
            // if(this->mainLevel > user->getLevel())
            // {
            //     user->saveState(user->getID(), mainLevel, this->getScore());
            // }
            mainGame.setLevel(mainLevel, 0);
        }
    }
    else if(state == 3 && gameRunning == true) //Sub Menu
    {

    }
    else if(state == 4 && gameRunning == false) //Pause
    {
        glClearColor(0.980, 0.922, 0.843, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        DrawStringTNR( 380, 600, "Game Paused", colors[CRIMSON]);
        DrawLine(375, 595, 525, 595, 4, colors[CRIMSON]);
        DrawStringTNR( 300, 400, "Press [R] to Resume the Game", colors[DARK_SLATE_BLUE]);
        DrawStringTNR( 315, 310, "Press [E] to Exit the Game", colors[BLUE]);
        DrawStringTNR( 170, 260, "If you exit, your progress in current level will be lost but,", colors[RED]);
        DrawStringTNR( 170, 232, "the levels which have been passed will be saved.", colors[RED]);
    }
    if(keyPressed == 80 || keyPressed == 112)
    {
        this->pause();
    }
    if(keyPressed == 82 || keyPressed == 114)
    {
        this->resume();
    }
}
void MainEngine::pause()
{
    if(state == 2)
    {
        gameRunning = false;
        state = 4;
        keyPressed = -1;
    }
}
void MainEngine::resume()
{
    if(state == 4)
    {
        gameRunning = true;
        state = 2;
        keyPressed = -1;
    }
}
bool MainEngine::running()
{
    return gameRunning;
}
void MainEngine::quit()
{

}
void MainEngine::changeState(int state)
{
    this->state = state;
}
int MainEngine::getState()const
{
    return state;
}
void MainEngine::gemSelected(int x1, int y1)
{
    mainGame.checkGem(x1, y1);
}
void MainEngine::resetOldCoords()
{
    mainGame.resetOldCoords();
}
void MainEngine::drawSwapLine()
{
    mainGame.drawSwapLine();
}
void MainEngine::setKeyPressed(int x)
{
    keyPressed = x;
    if((keyPressed == (char)'h' || keyPressed == (char)'H') && subState == 1 && state == 1)
    {
        totalCount = user->getIDCount();
        subState = 6;
        keyPressed = -1;
    }
    if((keyPressed == (char)'b' || keyPressed == (char)'B') && subState == 6 && state == 1)
    {
        totalCount = user->getIDCount();
        subState = 1;
        keyPressed = -1;
    }
    if((keyPressed == (char)'b' || keyPressed == (char)'B') && subState == 7 && state == 1)
    {
        subState = 1;
        keyPressed = -1;
    }
    if((keyPressed == (char)'b' || keyPressed == (char)'B') && subState == 4 && state == 1)
    {
        subState = 1;
        keyPressed = -1;
    }
    if(keyPressed == (char)'c' || keyPressed == (char)'C' && subState == 1 && state == 1)
    {
        totalCount = user->getIDCount();
        menuArrowControl = 480;
        subState = 4;
        keyPressed = -1;
    }
    if(keyPressed == 48 && subState == 2)
    {
        subState = 1;
        keyPressed = -1;
    }
    if((keyPressed == 73 || keyPressed == 105) && state == 1 && subState == 1)
    {
        subState = 7;
        keyPressed = -1;
    }
    if(keyPressed == 69 && subState == 1)
    {
        addDelay(1);
        exit(1);
    }
    if((keyPressed == (char)'e' || keyPressed == 27) && (state == 4 || state == 2))
    {
        keyPressed = 1;
        exit(1);
    }
    if(keyPressed != -1 && state == 1 && subState == 2 && keyPressed != 8 && keyPressed != 13)
    {
        nameInput += char(keyPressed);
    }
    if(keyPressed != -1 && state == 1 && subState == 2 && keyPressed == 8 && keyPressed != 13)
    {
        if(nameInput.length() >= 1)
        {
            nameInput.pop_back();
        }
    }
    if(keyPressed == 13 && subState == 2)
    {
        user = new Player(nameInput, "1", "0");
        subState = 3;
        int t_level = user->getLevel();
        mainLevel = t_level;
        mainGame.setLevel(t_level, 0);
        keyPressed = -1;
    }
}
int MainEngine::getScore()const
{
    return mainGame.getScore();
}
void MainEngine::upKeyPressed()
{
    if(subState == 4 && menuArrowControl <= 450)
    {
        menuArrowControl += 40;
    }
}
void MainEngine::downKeyPressed()
{
    if(subState == 4 && menuArrowControl >= 530 - totalCount*40)
    {
        menuArrowControl -=40;
    }
}