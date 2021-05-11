#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Player
{
    private:
        string id;
        string name;
        string highScore;
        string level;
    public:
        Player()
        {
            id = "";
            name = "";
            highScore = "";
            level = "";
        }
        Player(string name, string level, string highScore)
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
            name += "\n";
            file<<name;
            file.close();
            file.open("PlayerData/PlayersLevel.txt", ios::in | ios::out | ios::app);
            this->level = level;
            level+="\n";
            file<<level;
            file.close();
            file.open("PlayerData/PlayersScore.txt", ios::in | ios::out | ios::app);
            this->highScore = highScore;
            highScore+="\n";
            file<<highScore;
            file.close();
        }
        Player(const Player &copy)
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
            this->name = copy.name;
            file<<this->name+"\n";
            file.close();
            file.open("PlayerData/PlayersLevel.txt", ios::in | ios::out | ios::app);
            this->level = copy.level;
            file<<this->level+"\n";
            file.close();
            file.open("PlayerData/PlayersScore.txt", ios::in | ios::out | ios::app);
            this->highScore = copy.highScore;
            file<<this->highScore+"\n";
            file.close();
        }
        void addPlayer(string, string ,string);
        void emptyDB();
        int getIDCount();
        void getProfiles(string* names, int* levels);
        void getHighScores(int* scores, string* names);
        void setName(string);
        void setLevel(string);
        void setScore(string);
        string getName()const;
        string getHName()const;
        int getLevel()const;
        string getID()const;
        void saveState(string, int, int);
};

#endif