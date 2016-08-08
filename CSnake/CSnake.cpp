#include "CSnake.h"
#include <cstdio>
#include <ctime>
#include <conio.h>

CSnake::CSnake(int w, int h)
{
    if(w > 0 && h > 0)
    {
        _height = h;
        _width = w;
    }
    Node node[3];
    node[0]._x = 0;
    node[0]._y = 0;
    node[1]._x = 1;
    node[1]._y = 0;
    node[2]._x = 2;
    node[2]._y = 0;

    SnakeNode.push_back(node[2]);
    SnakeNode.push_back(node[1]);
    SnakeNode.push_back(node[0]);

    _length = 3;
    isdie = false;
    _director = 'd';
}

CSnake::~CSnake()
{
    SnakeNode.clear();
}

bool CSnake::Judge()
{
    if(SnakeNode[0]._x == Food._x && SnakeNode[0]._y == Food._y)//eat food
    {
        AddNode(Food._x, Food._y);
        PutFood();
        return false;
    }

    //out of range
    if(SnakeNode[0]._x > 50 || SnakeNode[0]._y > 50 || SnakeNode[0]._x < 0 || SnakeNode[0]._y < 0)
    {
        isdie = true;
        return true;
    }

    //touch snake itself
    for(int i=0;i<_length;++i)
    {
        for(int j=0;j<_length;++j)
        {
            if(SnakeNode[i]._x == SnakeNode[j]._x && SnakeNode[i]._y == SnakeNode[j]._y)
            {
                isdie = true;
                return true;
            }
        }
    }

    return false;
}


void CSnake::AddNode(const int &x, const int &y)
{
    Node newnode;
    newnode._x = 0;
    newnode._y = 0;
    SnakeNode.push_back(newnode);
    for(int i=_length;i>0;--i)
    {
        SnakeNode[i]._x = SnakeNode[i-1]._x;
        SnakeNode[i]._y = SnakeNode[i-1]._y;
    }

    SnakeNode[0]._x = x;
    SnakeNode[0]._y = y;
}

void PutFood()
{

}
void CSnake::playGame()
{

}
