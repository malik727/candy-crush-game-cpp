#include "GamePlay.h"

void GamePlay::setLevel(int levelID, int levelMode)
{
    this->levelID = levelID;
    this->levelMode = levelMode;
    if(levelID == 1)
    {
        levelGrid.setDimensions(5, 5);
        levelGrid.initializeRandomly();
    }
    else if(levelID == 2)
    {
        levelGrid.setDimensions(6, 6);
        levelGrid.initializeRandomly();
    }
    else if(levelID == 3)
    {
        levelGrid.setDimensions(7, 7);
        levelGrid.initializeRandomly();
    }
    else if(levelID == 4)
    {
        levelGrid.setDimensions(7, 7);
        levelGrid.initializeRandomly();
    }
}
void GamePlay::start()
{
    DrawRectangle(70, 685, 150, 45, colors[ORCHID]);
    DrawStringTNR( 80, 700, "Score", colors[WHITE]);
    DrawStringTNR(145, 699, to_string(getScore()), colors[WHITE]);
    DrawRectangle(680, 685, 110, 45, colors[CRIMSON]);
    DrawStringTNR( 690, 700, "Level", colors[GHOST_WHITE]);
    DrawStringTNR( 760, 700, to_string(levelID), colors[GHOST_WHITE]);
    levelGrid.drawBoard();
}
bool GamePlay::checkGem(int x1, int y1)
{
    levelGrid.swapGem(x1, y1);
}
void GamePlay::resetOldCoords()
{
    levelGrid.setNULL();
}
void GamePlay::drawSwapLine()
{
    levelGrid.drawSwapLine();
}
int GamePlay::getScore()const
{
    return levelGrid.getScore();
}