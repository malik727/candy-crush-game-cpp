#include "Player.h"

void Player::addPlayer(string name, string level, string highScore)
{
    int idCount = this->getIDCount();
    string stringID = to_string(idCount+1), insert;
    fstream file;
    file.open("PlayerData/PlayersName.txt", ios::out | ios::app);
    file.close();
    file.open("PlayerData/PlayersLevel.txt", ios::out | ios::app);
    file.close();
    file.open("PlayerData/PlayersScore.txt", ios::out | ios::app);
    file.close();
    this->id = stringID;
    file.open("PlayerData/PlayersName.txt", ios::in | ios::out | ios::app);
    this->name = name;
    file<<this->name+"\n";
    file.close();
    file.open("PlayerData/PlayersLevel.txt", ios::in | ios::out | ios::app);
    this->level = level;
    file<<this->level+"\n";
    file.close();
    file.open("PlayerData/PlayersScore.txt", ios::in | ios::out | ios::app);
    this->highScore = highScore;
    file<<this->highScore+"\n";
    file.close();
}
int Player::getIDCount()
{
    int count = 0;
    ifstream file;
    string line = "";
    file.open("PlayerData/PlayersName.txt", ios::in);
    while(getline(file, line))
    {
        count++;
    }
    file.close();
    return count;
}
void Player::getHighScores(int* scores, string* names)
{
    string line;
    int getTotalLines = getIDCount(), i = 0;
    string* tempNames;
    tempNames = new string[getTotalLines];
    ifstream file;
    file.open("PlayerData/PlayersName.txt", ios::in);
    while(getline(file, line))
    {
        tempNames[i] = line;
        i++;
    }
    i = 0;
    file.close();
    string* tempScores;
    tempScores = new string[getTotalLines];
    file.open("PlayerData/PlayersScore.txt", ios::in);
    while(getline(file, line))
    {
        tempScores[i] = line;
        i++;
    }
    i = 0;
    file.close();
    while(i != getIDCount())
    {
        if(i == 10 || i == getIDCount())
        {
            break;
        }
        scores[i] = stoi(tempScores[i]);
        names[i] = tempNames[i];
        i++;
    }
    for(int j=0; j<getTotalLines; j++)
    {
        if(j == 10 || getTotalLines == 1)
        {
            break;
        }
        if(scores[j] < scores[j+1])
        {
            int temp = scores[j];
            scores[j] = scores[j+1];
            scores[j+1] = temp;
            string stemp = names[j];
            names[j] = names[j+1];
            names[j+1] = stemp;
        }
    }
    delete[] tempNames;
    delete[] tempScores;
}
void Player::getProfiles(string* names, int* levels)
{
    string line;
    int getTotalLines = getIDCount(), i = 0;
    string* tempNames;
    tempNames = new string[getTotalLines];
    ifstream file;
    file.open("PlayerData/PlayersName.txt", ios::in);
    while(getline(file, line))
    {
        tempNames[i] = line;
        i++;
    }
    i = 0;
    file.close();
    string* tempLevels;
    tempLevels = new string[getTotalLines];
    file.open("PlayerData/PlayersLevel.txt", ios::in);
    while(getline(file, line))
    {
        tempLevels[i] = line;
        i++;
    }
    i = 0;
    file.close();
    while(i != getIDCount())
    {
        if(i == 12 || i == getIDCount())
        {
            break;
        }
        levels[i] = stoi(tempLevels[i])-1;
        names[i] = tempNames[i];
        i++;
    }
    delete[] tempNames;
    delete[] tempLevels;
}
void Player::setName(string s)
{
    name = s;
}
void Player::setLevel(string s)
{
    level = s;
}
void Player::setScore(string s)
{
    highScore = s;
}
string Player::getName()const
{
    return name;
}
string Player::getHName()const
{
    string temp = "";
    for(int i=0; i<name.length(); i++)
    {
        if(name[i] == ' ')
        {
            break;
        }
        temp += name[i];
    }
    return temp;
}
int Player::getLevel()const
{
    int ilevel = stoi(this->level);
    return ilevel;
}
void Player::saveState(string s_id, int i_level, int i_score)
{
    cout<<"\nSaving..."<<endl;
    string line;
    int getTotalLines = getIDCount(), i = 0;
    string* tempNames;
    tempNames = new string[getTotalLines];
    ifstream file;
    file.open("PlayerData/PlayersName.txt", ios::in);
    while(getline(file, line))
    {
        tempNames[i] = line;
        i++;
    }
    i = 0;
    file.close();
    string* tempLevels;
    tempLevels = new string[getTotalLines];
    file.open("PlayerData/PlayersLevel.txt", ios::in);
    while(getline(file, line))
    {
        if(i == stoi(s_id)-1)
        {
            tempLevels[i] = to_string(i_level);
            i++;
            continue;
        }
        tempLevels[i] = line;
        i++;
    }
    i = 0;
    string* tempScores;
    tempScores = new string[getTotalLines];
    file.open("PlayerData/PlayersScore.txt", ios::in);
    while(getline(file, line))
    {
        int tk = stoi(s_id);
        if(i == tk-1)
        {
            i_score += stoi(line);
            tempLevels[i] = to_string(i_score);
            i++;
            continue;
        }
        tempScores[i] = line;
        i++;
    }
    i = 0;
    file.close();
    fstream file2;
    file2.open("PlayerData/PlayersScore.txt", ios::trunc | ios::app | ios::out);
    for(int i=0; i<getIDCount(); i++)
    {
        //file2<<tempScores[i]+"\n";
    }
    file2.close();
    file2.open("PlayerData/PlayersLevel.txt", ios::trunc | ios::app | ios::out);
    for(int i=0; i<getIDCount(); i++)
    {
        //file2<<tempLevels[i]+"\n";
    }
    file2.close();
    delete[] tempNames;
    delete[] tempLevels;
    delete[] tempScores;
}
string Player::getID()const
{
    return this->id;
}