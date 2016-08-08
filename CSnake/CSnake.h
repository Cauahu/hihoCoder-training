#ifndef CSNAKE_H
#define CSNAKE_H


#include <vector>
#include <iostream>

using namespace std;

struct Node
{
    int _x;
    int _y;
};
class CSnake
{
public :
    CSnake(int w = 50, int h = 50);
    ~CSnake();
    void playGame();
    void changeDirector(const int &newDirector);
    void moveSnake();
    bool isDie();
    void display();

private :
    vector<Node> SnakeNode;//snake's datastruct
    Node Food;//food's position
    char _director;//w, s, a, d represent up, down, left, right
    int _length;
    bool isdie;
    int _height;
    int _width;

private :
    bool Judge();//when snake moves, we need to judge it's station
    void AddNode(const int &x, const int &y);//add snake's node
    void PutFood(); // put food randamly
};

#endif
