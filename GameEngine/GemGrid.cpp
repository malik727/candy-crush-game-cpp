#include "GemGrid.h"

int* GemGrid::oldCoords = NULL;
bool GemGrid::isSwap = false;
int* GemGrid::swapLineCoords = NULL;

int GemGrid::getLength()const
{
    return length;
}
int GemGrid::getHeight()const
{
    return height;
}
void GemGrid::setDimensions(int length, int height)
{
    this->length = length;
    this->height = height;
    grid = new Points*[height];
    for(int i=0; i<height; i++)
    {
        grid[i] = new Points[length];
    }
}
void GemGrid::initializeRandomly()
{
    score = 0;
    int y = 80;
    for(int i=0; i<height; i++)
    {
        int offset = 80;
        if(length == 7)
        {
            offset = 60;
        }
        int x = 900/length + offset;
        for(int j=0; j<length; j++)
        {
            int randomNum = rand() % 5 + 1;
            if(j > 1)
            {
                while(randomNum == grid[i][j-1].getGemType() && randomNum == grid[i][j-2].getGemType())
                {
                    randomNum = rand() % 5 + 1;
                }
            }
            if(i > 1)
            {
                while(randomNum == grid[i-1][j].getGemType() && randomNum == grid[i-2][j].getGemType())
                {
                    randomNum = rand() % 5 + 1;
                }
            }
            grid[i][j].setX(x);
            grid[i][j].setY(y);
            grid[i][j].setGemType(randomNum);
            x += 80;
        }
        y += 80;
    }
}
void GemGrid::drawBoard()
{
    this->cascade();
    float lineColor[3] = {0.118, 0.565, 1.000};
    DrawLine(grid[0][0].getX()-40, grid[length-1][height-1].getY()+100, grid[0][0].getX()-40, 0, 5, lineColor);
    DrawLine(0, grid[length-1][height-1].getY()+100, 900, grid[length-1][height-1].getY()+100, 5, lineColor);
    DrawLine(grid[height-1][length-1].getX()+80, grid[length-1][height-1].getY()+100, grid[height-1][length-1].getX()+80, 0, 5, lineColor);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<length; j++)
        {
            int a,b;
            a = grid[i][j].getX();
            b = grid[i][j].getY();
            if(grid[i][j].getGemType() == 1)
            {
                gem = new FrenchGem(); //It is a square type of gem
                gem->drawGem(a, b);
            }
            else if(grid[i][j].getGemType() == 2)
            {
                gem = new TriangleGem(); 
                gem->drawGem(a, b);
            }
            else if(grid[i][j].getGemType() == 3)
            {
                gem = new ScissorGem();
                gem->drawGem(a,b);
            }
            else if(grid[i][j].getGemType() == 4)
            {
                gem = new SphereGem();
                gem->drawGem(a,b);
            }
            else if(grid[i][j].getGemType() == 5)
            {
                gem = new BaguetteGem(); //it is a rectangular type of gem
                gem->drawGem(a,b);
            }
        }
    }
}

void GemGrid::setNULL()
{
    oldCoords = NULL;
}
void GemGrid::drawSwapLine()
{
    if(isSwap == true && swapLineCoords != NULL)
    {
        if(swapLineCoords[4] == 0)
        {
            DrawLine(grid[swapLineCoords[0]][swapLineCoords[1]].getX()-3, grid[swapLineCoords[0]][swapLineCoords[1]].getY()+20, grid[swapLineCoords[2]][swapLineCoords[3]].getX()+42, grid[swapLineCoords[2]][swapLineCoords[3]].getY()+20, 5, colors[DARK_MAGENTA]);
        }
        if(swapLineCoords[4] == 1)
        {
            DrawLine(grid[swapLineCoords[0]][swapLineCoords[1]].getX()+42, grid[swapLineCoords[0]][swapLineCoords[1]].getY()+20, grid[swapLineCoords[2]][swapLineCoords[3]].getX()-3, grid[swapLineCoords[2]][swapLineCoords[3]].getY()+20, 5, colors[DARK_MAGENTA]);
        }
        if(swapLineCoords[4] == 2)
        {
            DrawLine(grid[swapLineCoords[0]][swapLineCoords[1]].getX()+20, grid[swapLineCoords[0]][swapLineCoords[1]].getY()-3, grid[swapLineCoords[2]][swapLineCoords[3]].getX()+20, grid[swapLineCoords[2]][swapLineCoords[3]].getY()+42, 5, colors[DARK_MAGENTA]);
        }
        if(swapLineCoords[4] == 3)
        {
            DrawLine(grid[swapLineCoords[0]][swapLineCoords[1]].getX()+20, grid[swapLineCoords[0]][swapLineCoords[1]].getY()+42, grid[swapLineCoords[2]][swapLineCoords[3]].getX()+20, grid[swapLineCoords[2]][swapLineCoords[3]].getY()-3, 5, colors[DARK_MAGENTA]);
        }
    }
}
void GemGrid::swapGem(int x1, int y1)
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<length; j++)
        {
            int a = grid[i][j].getX();
            int b = grid[i][j].getY();
            if((x1 >= a+5 && x1 <= a+35) && (y1 >= b+5 && y1 <= b+35))
            {
        
                if(oldCoords != NULL)
                {
                    if(i == oldCoords[0] && j == oldCoords[1])
                    {
                        delete[] oldCoords;
                        oldCoords = NULL;
                        continue;
                    }
                    else 
                    {
                        int current_i, current_j, old_i, old_j;
                        current_i = i;
                        current_j = j;
                        old_i = oldCoords[0];
                        old_j = oldCoords[1];

                        if(old_i == current_i+1 || old_i == current_i-1)
                        {
                            int gemShapeInt = grid[old_i][old_j].getGemType();
                            int currentGemShape = grid[current_i][current_j].getGemType();
                            
                            bool swapAllowed = false;
                            int gemCount = 0;
                            grid[current_i][current_j].setGemType(gemShapeInt);
                            grid[old_i][old_j].setGemType(currentGemShape);
                            for(int counter = 0; counter < length; counter++) //Checking for row
                            {
                                if(gemCount == 3)
                                {
                                    swapAllowed = true;
                                    break;
                                }
                                if(gemShapeInt == grid[current_i][counter].getGemType())
                                {
                                    gemCount++;
                                    continue;
                                }
                                gemCount = 0;
                            }
                            for(int counter = 0; counter<height; counter++) //Checking for column
                            {
                                if(gemCount == 3)
                                {
                                    swapAllowed = true;
                                    break;
                                }
                                if(gemShapeInt == grid[counter][current_j].getGemType())
                                {
                                    gemCount++;
                                    continue;
                                }
                                gemCount = 0;
                            }
                            gemCount = 0;
                            if(swapAllowed == false)
                            {
                                grid[current_i][current_j].setGemType(currentGemShape);
                                grid[old_i][old_j].setGemType(gemShapeInt);
                                if(score >= 100)
                                {
                                    score -= 100;
                                }
                                delete[] swapLineCoords;
                                swapLineCoords = NULL;
                                isSwap = false;
                            }
                            if(swapAllowed == true)
                            {
                                delete[] swapLineCoords;
                                swapLineCoords = NULL;
                                swapLineCoords = new int[5];
                                swapLineCoords[0] = old_i; 
                                swapLineCoords[1] = old_j; 
                                swapLineCoords[2] = current_i; 
                                swapLineCoords[3] = current_j;
                                if(old_i > current_i)
                                {
                                    swapLineCoords[4] = 2; 
                                } 
                                else if(current_i > old_i)
                                {
                                    swapLineCoords[4] = 3;
                                }
                                isSwap = true;
                                swapAllowed = false;
                            }
                        }
                        if(old_j == current_j+1 || old_j == current_j-1)
                        {
                            int gemShapeInt = grid[old_i][old_j].getGemType();
                            int currentGemShape = grid[current_i][current_j].getGemType();

                            bool swapAllowed = false;
                            int gemCount = 0;
                            grid[current_i][current_j].setGemType(gemShapeInt);
                            grid[old_i][old_j].setGemType(currentGemShape);

                            for(int counter = 0; counter < height; counter++) //Checking for column
                            {
                                if(gemCount >= 3)
                                {
                                    swapAllowed = true;
                                    break;
                                }
                                if(gemShapeInt == grid[counter][current_j].getGemType())
                                {
                                    gemCount++;
                                    continue;
                                }
                                gemCount = 0;
                            }
                            for(int counter = 0; counter < length; counter++) //Checking for row
                            {
                                if(gemCount >= 3)
                                {
                                    swapAllowed = true;
                                    break;
                                }
                                if(gemShapeInt == grid[current_i][counter].getGemType())
                                {
                                    gemCount++;
                                    continue;
                                }
                                gemCount = 0;
                            }
                            gemCount = 0;

                            if(swapAllowed == false)
                            {
                                grid[current_i][current_j].setGemType(currentGemShape);
                                grid[old_i][old_j].setGemType(gemShapeInt);
                                if(score >= 100)
                                {
                                    score -= 100;
                                }
                                delete[] swapLineCoords;
                                swapLineCoords = NULL;
                                isSwap = false;
                            }
                            else if(swapAllowed == true)
                            {
                                delete[] swapLineCoords;
                                swapLineCoords = NULL;
                                swapLineCoords = new int[5];
                                swapLineCoords[0] = old_i; 
                                swapLineCoords[1] = old_j; 
                                swapLineCoords[2] = current_i; 
                                swapLineCoords[3] = current_j; 
                                if(old_j > current_j)
                                {
                                    swapLineCoords[4] = 0; 
                                }
                                else if(current_j > old_j)
                                {
                                    swapLineCoords[4] = 1; 
                                }
            
                                isSwap = true;
                            }
                        }

                        delete[] oldCoords;
                        oldCoords = NULL;
                        continue;
                    }
                    delete[] oldCoords;
                    oldCoords = NULL;
                }
                if(oldCoords == NULL)
                {
                    oldCoords = new int[2];
                    oldCoords[0] = i;
                    oldCoords[1] = j;
                }
            }
        }
    }
}
void GemGrid::cascade()
{
    
    int gemCount = 0, gemType;
    int ipointHistory[5], jPointHistory[5], p=0;

    for(int k=1; k<=5; k++) //Checking for cascading in rows
    {
        p = 0;
        gemCount = 0;
        gemType = k;
        for(int i=0; i<height; i++)
        {
            gemCount = 0;
            for(int j=0; j<length; j++)
            {
                if(gemCount >= 3)
                {
                    if(gemType == grid[i][j].getGemType() && gemCount < 5)
                    {
                        ipointHistory[p] = i;
                        jPointHistory[p] = j;
                        p++;
                        gemCount++;
                        continue;
                    }
                    else
                    {
                        if(gemCount == 3)
                        {
                            score += 200;
                        }
                        if(gemCount == 4)
                        {
                            score += 300;
                        }
                        if(gemCount == 5)
                        {
                            score += 400;
                        }
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        cout<<"\n ------------------------------------------"<<endl;
                        cout<<"\nCascade possible: "<<gemCount<<endl;
                        cout<<"\nGem Type: "<<gemType<<endl;
                        gemCount = 0;   
                        p=0;
                    }
                }
                if(gemType == grid[i][j].getGemType())
                {
                    ipointHistory[p] = i;
                    jPointHistory[p] = j;
                    p++;
                    gemCount++;
                    if(gemCount == 3 && j == length - 1)
                    {         
                        score += 200;
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        gemCount = 0;   
                        p=0;
                    }
                    else if(gemCount == 3 && j == length - 1)
                    {         
                        score += 300;
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        gemCount = 0;   
                        p=0;
                    }
                    continue;
                }
                gemCount = 0;
                p = 0;
            }
        }

        for(int i=0; i<length; i++)
        {
            gemCount = 0;
            for(int j=0; j<height; j++)
            {
                if(gemCount >= 3)
                {
                    if(gemType == grid[j][i].getGemType() && gemCount < 5)
                    {
                        ipointHistory[p] = j;
                        jPointHistory[p] = i;
                        p++;
                        gemCount++;
                        continue;
                    }
                    else
                    {
                        if(gemCount == 3)
                        {
                            score += 200;
                        }
                        if(gemCount == 4)
                        {
                            score += 300;
                        }
                        if(gemCount == 5)
                        {
                            score += 400;
                        }
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        gemCount = 0;   
                        p=0;
                    }
                }
                if(gemType == grid[j][i].getGemType())
                {
                    ipointHistory[p] = j;
                    jPointHistory[p] = i;
                    p++;
                    gemCount++;
                    if(gemCount == 3 && j == height - 1)
                    {
                        score += 200;
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        gemCount = 0;   
                        p=0;
                    }
                    if(gemCount == 4 && j == height - 1)
                    {
                        score += 300;
                        for(int l=0; l<gemCount; l++)
                        {
                            if(ipointHistory[l] == height-1)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int randomNum = rand() % 5 + 1;
                                grid[ip][jp].setGemType(randomNum);
                            }
                            if(ipointHistory[l] < height-1 && jPointHistory[l] < length)
                            {
                                int ip = ipointHistory[l], jp = jPointHistory[l];
                                int u;
                                for(u = ip; u<height-1; u++)
                                {
                                    grid[u][jp].setGemType(grid[u+1][jp].getGemType());
                                }
                                if(u == height-1)
                                {
                                    int randomNum = rand() % 5 + 1;
                                    grid[u][jp].setGemType(randomNum);
                                }
                            }
                        }
                        gemCount = 0;   
                        p=0;
                    }
                    continue;
                }
                gemCount = 0;
                p = 0;
            }
        }
    }
    
    
    
}
int GemGrid::getScore()const
{
    return score;
}