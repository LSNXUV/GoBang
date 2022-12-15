
#include "Records.h"


class GoBang
{
    protected:

        int BoardSize;

        int ChessBoard[MaxSize][MaxSize];
        int BoardLocationX;
        int BoardLocationY;

        Records records;

    public:

        void InitWindow();
        void welcome(int delay);
        void menu();
        
        bool Regex(string str);
        void InitChess();
        void EmptyRemind();
        void gotoxy(int x, int y);
        
        void DrawBoard();
        void DrawWinPoint(int x,int y);
        void ClearPoint(int x,int y,int player);
        void DrawPoint(int x,int y,int player);
        void DrawActPoint(int x,int y,int player);
        void DrawActStep(int x,int y,int step);
        //双人对战
        bool Win(int x,int y,int player);
        void DoublePlay();

        //查看历史棋局
        void History(int delay);
        void Review(int id,int delay);
        void PrintHistory(int delay);
        void RcWelcome(int delay);
        void RcMenu();

        
        void ShowCursor(bool visible);
        void SetTextWhite();
        void SetTextRed();
        void SetTextBlue();
        void SetTextGreen();

        void Mprintf(string str);
        void Cprintf(string str);
        void Slowprintf(string str);

        void DeleteGoAway();
        void SizeGoAway();

        void goodbye();

        GoBang(/* args */);
        ~GoBang();
};


GoBang::GoBang(/* args */)
{
    BoardSize = 15;
    BoardLocationX = 18;
    BoardLocationY = 7;
    // record = *(new Record);
    records = *(new Records);
    InitChess();
}

void GoBang::InitWindow()
{
    //关闭右上角最大化和关闭
	SizeGoAway();
	
}

void GoBang::InitChess()
{
    for(int i = 0;i<BoardSize;i++)
    {
        for(int j = 0;j<BoardSize;j++)
        {
            ChessBoard[i][j] = 0;
        }
    }
}

void GoBang::EmptyRemind()
{
    cout<<"\n";
    SetTextGreen();
    for(int i = 3;i>=1;i--)
    {
        printf("                                           当前无对局记录  %d 秒后自动退出",i);
        Sleep(1000);
        cout<<"\r";
    }
    SetTextWhite();
}

bool GoBang::Regex(string str)
{
    bool flag;
	flag = true;
	regex r("\\d{1,8}");
	while (!(flag = regex_match(str, r)))
	{
		return flag;
	}
	return flag;
}

void GoBang::welcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                        ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆            五 子 棋 终 结 者           ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                        ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★★★★★              ★★★★★★★            ★★★★★〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★★★★★              ★★★★★★★            ★★★★★〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                P.双人游戏              ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆              H.查看历史对局            ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆              U.打开软件说明            ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓"); Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓"); Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                0.退出游戏              ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void GoBang::RcWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                        ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆            查 看 历 史 棋 局           ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                        ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★★★★★              ★★★★★★★            ★★★★★〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★★★★★              ★★★★★★★            ★★★★★〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆              H.查看历史对局            ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆               0.回到主界面             ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                        ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void GoBang::RcMenu()
{
    int choice;

    while(true)
    {
        RcWelcome(20);
        if(records.Count==0){
            EmptyRemind();
            return;
        }
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 72 || choice == 104 
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        PrintHistory(20);
    }
}

void GoBang::menu()
{
    system("mode con cols=112 lines=47");
    InitWindow();
    char Title[200];
    sprintf(Title,"% 134s","五子棋终结者");
	SetConsoleTitleA(Title);
    int choice;


    while(true)
    {
        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 80 || choice == 112 ||
                choice == 72 || choice == 104 ||
                choice == 85 || choice == 117
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 80:
        case 112:
            InitChess();
            DoublePlay();
            break;
        case 72:
        case 104:
            RcMenu();
            break;
        case 85:
        case 117:
            system("start 软件说明书.docx 2>nul");
        default:
            break;
        }

    }
    goodbye();
    return;
}

void GoBang::gotoxy(int x, int y) {					//移动光标
	COORD pos;
    pos.X = x,pos.Y = y;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

bool GoBang::Win(int x,int y,int player)
{
    
    int MinX = max( 0 , x - 4 );
    int MaxX = min( x + 4 , BoardSize - 1 );
    int MinY = max( 0 , y - 4 );
    int MaxY = min( y + 4 , BoardSize - 1 );

    int sum;
    //水平方向
    for(int i = MinX;i <= MaxX-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[j][y] == player) sum++;
            else  break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int j = i;j<i+5;j++)
                {
                    DrawWinPoint(j,y);
                    Sleep(50);
                    DrawPoint(j,y,player);
                }
            }
            for(int j = i;j<i+5;j++)
            {
                DrawWinPoint(j,y);
            }
            return true;
        }
    }
   
    //垂直方向
    for(int i = MinY;i <= MaxY-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[x][j] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int j = i;j<i+5;j++)
                {
                    DrawWinPoint(x,j);
                    Sleep(50);
                    DrawPoint(x,j,player);
                }
            }
            for(int j = i;j<i+5;j++)
            {
                DrawWinPoint(x,j);
            }
            return true;
        }
    }
    
    int i,j;

    for(i = x,j = y;i > MinX && j > MinY; i--,j--);
    for(;i <= MaxX-4 && j <= MaxY-4; i++,j++)
    {
        sum = 0;
        for(int p = i,q = j;p < i+5;p++,q++)
        {
            if(ChessBoard[p][q] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int p = i,q = j;p < i+5;p++,q++)
                {
                    DrawWinPoint(p,q);Sleep(50);DrawPoint(p,q,player);
                }
            }
            for(int p = i,q = j;p < i+5;p++,q++)
            {
                DrawWinPoint(p,q);
            }
            return true;
        }
    }
    
    for(i = x,j = y;i > MinX && j < MaxY; i--,j++);
    for(;i <= MaxX-4 && j >= MinY+4; i++,j--)
    {
        sum = 0;
        for(int p = i,q = j;p < i+5;p++,q--)
        {
            if(ChessBoard[p][q] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int p = i,q = j;p < i+5;p++,q--)
                {
                    DrawWinPoint(p,q);Sleep(50);DrawPoint(p,q,player);
                }
            }
            for(int p = i,q = j;p < i+5;p++,q--)
            {
                DrawWinPoint(p,q);
            }
            return true;
        }
    }
    
    return false;
}

void GoBang::DrawBoard()
{

    gotoxy(0,BoardLocationY);
    
    for(int i = 0;i<BoardSize;i++)
    {
        if(i==0) printf("                   ─────────────────────────────────────────────────────────────────────────\n                  ");
        else printf("\n                  |────|────|────|────|────|────|────|────|────|────|────|────|────|────|─── |\n                  ");
        Sleep(10);
        for(int j = 0;j<BoardSize;j++)
        {
            printf("|    ");Sleep(5);
        
        }
        printf("|");
        Sleep(10);
    }
    printf("\n                   ─────────────────────────────────────────────────────────────────────────\n");

}

void GoBang::DrawWinPoint(int x,int y)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    Sleep(50);
    printf("●");
}

void GoBang::DrawPoint(int x,int y,int player)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    if(player == 1) {SetTextGreen();printf("●");SetTextWhite();}
    else if(player == 2) {SetTextBlue();printf("●");SetTextWhite();}
    else printf("●");
}

//当前执子
void GoBang::DrawActPoint(int x,int y,int player)
{
    gotoxy(x,y);
    if(player == 1) {SetTextGreen();printf("●");SetTextWhite();}
    else if(player == 2) {SetTextBlue();printf("●");SetTextWhite();}
    else printf("●");
}

void GoBang::DrawActStep(int x,int y,int step)
{
    gotoxy(x,y);
    printf("%d  ",step);
}

void GoBang::ClearPoint(int x,int y,int player)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    printf("  ");
}


void GoBang::DoublePlay()
{

    printf("\n\n");
    SetTextGreen();
    Slowprintf("欢迎来到五子棋终结者,按Enter开始游戏");
    SetTextWhite();
    while(getch()!=13);

    system("cls");
    
    // system("color F0");
    gotoxy(0,2);
    SetTextGreen();Cprintf("五子棋终结者");Sleep(20);SetTextWhite();
    gotoxy(0,4);
    
    Cprintf("w a s d (绿方) / ↑ ← ↓ → (蓝方)    Enter 确认落子    Backspace 悔棋    Esc 退出游戏");Sleep(20);
    
    int choice,ActStep = 0;
    int step = 1;
    Record *record;
    record = new Record;
    Point point;

    //random
    default_random_engine engine(time(0));
    uniform_real_distribution<double> random(0.0, 1.0);
    double RandNum;
    //初始位置
    int x = 7,y = 7,player = 1;
    ChessBoard[x][y] = player;

    DrawBoard();
    PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
    DrawPoint(x,y,player);

    //输出当前执子和步数
    DrawActPoint(102,16,player);Sleep(20);DrawActStep(102,20,ActStep);Sleep(20);
    gotoxy(99,14);
    printf("当前执子");Sleep(20);
    gotoxy(99,18);
    printf("当前步数");Sleep(20);
    
    while(true)
    {
        
        player = 2-player%2;
        ChessBoard[x][y] = player;
        while(true)
        {
            choice = getch();
            if( choice == 87 || choice == 119 ||    /* W */
                choice == 81 || choice == 113 ||    /* Q */
                choice == 69 || choice == 101 ||    /* E */
                choice == 65 || choice == 97 ||     /* A */
                choice == 90 || choice == 122 ||    /* Z */
                choice == 83 || choice == 115 ||    /* D */
                choice == 88 || choice == 120 ||    /* X */
                choice == 68 || choice == 100 ||    /* S */
                choice == 72 || choice == 80 ||      
                choice == 49 || choice == 51 ||     /* 1 3 */
                choice == 75 || choice == 77 ||
                choice == 55 || choice == 57 ||     /* 7 9 */
                choice == 13 || choice == 8 ||
                choice == 27
            ) break;
        }
        if(choice == 27) break;

        switch (choice)
        {
        case 87:
        case 119:
        case 72:
            /* 上移 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 81:
        case 113:
        case 55:
            /* 左上方移动 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 65:
        case 97:
        case 75:
            /* 左移 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 69:
        case 101:
        case 57:
            /* 右上方移动 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 83:
        case 115:
        case 80:
            /* 下移  */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 90:
        case 122:
        case 49:
            /* 左下方移动 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 68:
        case 100: 
        case 77:
            /* 右移 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 88:
        case 120:
        case 51:
            /* 右下方移动 */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 8:
            if(record->Count == 0) break;
        
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            point = record->Withdraw();
            x = point.x,y = point.y,player = point.player;
    
            DrawPoint(x,y,player);
            DrawActPoint(102,16,player);
            DrawActStep(102,20,--ActStep);
            break;

        case 13:

            PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);

            if(Win(x,y,2-player%2)){
                PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE);
                DrawActStep(102,20,++ActStep);
                gotoxy(0,40);
                record->AddRecord(x,y,2-player%2);
                records.AddRecords(record);
                if(player == 1){ SetTextGreen();Cprintf("玩家一(绿方)获胜！");SetTextWhite();}
                else {SetTextBlue(); Cprintf("玩家二(蓝方)获胜！");SetTextWhite();}
                printf("\n\n");Cprintf("按Esc退出");
                while(getch()!=27);
                return;
            }
            record->AddRecord(x,y,player);

            ChessBoard[x][y] = player++;
            player = 2-player%2;

            DrawActPoint(102,16,player);
            DrawActStep(102,20,++ActStep);
            step = 0;

            while(step<BoardSize)
            {
                RandNum = random(engine);
                
                
       
                if (RandNum <= 0.125)
                    if(!ChessBoard[(x+BoardSize-step)%BoardSize][y]) {x=(x+BoardSize-step)%BoardSize; DrawPoint(x,y,player);step++; break;}
                if (RandNum <= 0.250)
                    if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                        {x=(x+BoardSize-step)%BoardSize;y=(y+BoardSize-step)%BoardSize;DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 0.375)
                    if(!ChessBoard[x][(y+BoardSize-step)%BoardSize]) {y=(y+BoardSize-step)%BoardSize; DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 0.50)
                    if(!ChessBoard[(x+BoardSize+step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                        {x=(x+BoardSize+step)%BoardSize;y=(y+BoardSize-step)%BoardSize;DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 0.625)
                    if(!ChessBoard[(x+BoardSize+step)%BoardSize][y]) {x=(x+BoardSize+step)%BoardSize; DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 0.750)
                    if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize+step)%BoardSize]) 
                        {x=(x+BoardSize-step)%BoardSize;y=(y+BoardSize+step)%BoardSize;DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 0.875)
                    if(!ChessBoard[x][(y+BoardSize+step)%BoardSize]) {y=(y+BoardSize+step)%BoardSize; DrawPoint(x,y,player);step++; break;}
                if(RandNum <= 1.00)
                    if(!ChessBoard[(x+BoardSize+step)%BoardSize][(y+BoardSize+step)%BoardSize]) 
                        {x=(x+BoardSize+step)%BoardSize;y=(y+BoardSize+step)%BoardSize;DrawPoint(x,y,player);step++; break;}
                step++;
            }
            if(step == BoardSize) {
                record->AddRecord(x,y,2-player%2);
                record->AddRecord(x,y,0);
                records.AddRecords(record);
                gotoxy(0,40);Cprintf("你故意和棋的样子真狼狈`(*>﹏<*)′");
                printf("\n\n");SetTextGreen();Cprintf("按Esc退出");SetTextWhite();
                while(getch()!=27);
                return;
            }
            
            break;
        
        default:
            break;
        }

    }

}

void GoBang::History(int delay)
{
    system("cls");
    printf("\n\n\n");
    Record *head = records.Head->next;
    printf("\n                       ");printf("    ────────────────────────────────────────────────────");Sleep(delay);
    printf("\n                      ");printf("    |序号\t|   开始时间\t|   结束时间\t|落子数\t|胜利方\t|");Sleep(delay);
    int i = 1;
    // string winner;
    while(head){
        printf("\n                       ");printf("    ────────────────────────────────────────────────────");Sleep(delay);
        printf("\n                      ");

        printf("    |  %d\t|   %02d:%02d:%02d\t|   %02d:%02d:%02d\t|  %d\t|",
        i++,head->StartTime.tm_hour,head->StartTime.tm_min,head->StartTime.tm_sec,
        head->EndTime.tm_hour,head->EndTime.tm_min,head->EndTime.tm_sec,head->Count
        );

        int winner = head->Points[head->Count-1].player;
        if(winner == 1)
        {
            SetTextGreen();
            printf("%s\t|","  ●");
            SetTextWhite();
        }else if(winner == 2)
        {
            SetTextBlue();
            printf("%s\t|","  ●");
            SetTextWhite();
        }else{
            printf("%s\t|"," 和棋");
        }
        head = head->next;
    }
    printf("\n                       ");printf("    ────────────────────────────────────────────────────");Sleep(delay);
}

void GoBang::Review(int id,int delay)
{
    system("cls");
    Record *head = records.Head->next;
    int i = 1;
    while(head && i++ != id){
        head = head->next;
    }
    DrawBoard();
    i = 0;
    while(i<head->Count)
    {
        if (delay == 1)
            PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
        else Sleep(delay);
        DrawPoint(head->Points[i].x, head->Points[i].y, head->Points[i].player);
        i++;
    }
    gotoxy(56,38);
    printf("\n\n");Cprintf("按Esc退出");
    while(getch()!=27);

}

void GoBang::PrintHistory(int delay)
{
    
    int id;
    string str;
    while(true)
    {
        History(delay);
        printf("\n\n");
        Cprintf("选0为退出查看");
        printf("\n\n");
        ShowCursor(true);
        Cprintf("选择序号查看棋局:");
        cin>>str;
        while(!Regex(str))
        {
            printf("\n\n");
            Cprintf("序号只能是正整数:");
            cin>>str;
        }
        id = atoi(str.c_str());
        if(id>records.Count) continue;
        if(id == 0) break;
        str = "";
        printf("\n\n\n");
        Cprintf("请输入回放速度(慢回放：1 / 快回放：speed(毫秒))：");
        cin >> str;
        while (!Regex(str))
        {
            printf("\n\n");
            Cprintf("速度只能是正整数:");
            cin >> str;
        }
        ShowCursor(false);
        Review(id, atoi(str.c_str()));
    }

}

void GoBang::ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
}

void GoBang::SetTextRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void GoBang::SetTextGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void GoBang::SetTextBlue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void GoBang::SetTextWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GoBang::Mprintf(string str)
{
	cout<<setw(56)<<str;
}

void GoBang::Cprintf(string str)
{
	cout<<setw(56+str.length()/2)<<str;
}

void GoBang::Slowprintf(string str)
{
    const char *Str = str.c_str();
    cout<<setw(20+strlen(Str)/2);

    for(int i=0; i<str.length();i++)
    {
        cout<<Str[i];
        Sleep(20);
    }
}


//取消最大化，最小化
void GoBang::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//取消关闭  
void GoBang::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void GoBang::goodbye()
{
	SetTextGreen();
    printf("\n");
	Cprintf("欢迎下次游玩~\n");
	SetTextWhite();

    Sleep(3000);
    // return;
}

GoBang::~GoBang()
{
}
