#include "Package.h"

typedef struct tm Time;

typedef struct Point
{

    int x,y;
    int player;
    
} Point;

class Record
{

public:
    Time StartTime;
    Time EndTime;
    Point Points[230];
    int Count;
    
    Record *next;

    Time CreateTime();
    void AddRecord(int x,int y,int player);
    Point Withdraw();
    Record(/* args */);
    ~Record();

};

Record::Record(/* args */)
{
    
    StartTime = CreateTime();
    Count = 0;
    next = NULL;

}

Time Record::CreateTime()
{
    time_t nowtime;
	//首先创建一个time_t 类型的变量nowtime
	Time p;
	//然后创建一个新时间结构体指针 p 
	time(&nowtime);
	//使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量nowtime的地址值。
	p = *localtime(&nowtime);
    return p;
}

void Record::AddRecord(int x,int y,int player)
{
    Points[Count].x = x;
    Points[Count].y = y;
    Points[Count++].player = player;
}

Point Record::Withdraw()
{
    Point point;
    point.x = Points[Count-1].x;
    point.y = Points[Count-1].y;
    point.player = Points[Count---1].player;

    return point;
}

Record::~Record()
{
}


