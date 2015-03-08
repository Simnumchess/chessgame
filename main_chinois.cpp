#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

FILE *fp;
typedef struct Pos          //定义位置结构，x为横坐标， y为纵坐标
{
     int x;
      int y;
}Pos;
typedef struct Step
{
       int way;
       int nextNum;
}Step;
const int N = 8;
const int MAX = 50000;
int USERDEFINE = 1;
Pos   Initial, Way[MAX][N][N];
int NextStep[8][2] = {{1, 2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}, {1, -2}}, over = 0;
long long way = 0;
int ChessBoard[N][N] ={ 0 };     //定义8 * 8的棋盘，ChessBoard[i][j] == true代表已经遍历过当前方格，ChessBoard[i][j] == faise代表没有遍历此方格
bool Valid(Pos p)
{
       if( p.x < 0 || p.y < 0 || p.x > N - 1 || p.y > N - 1 || ChessBoard[p.x][p.y] != 0 )
        return false;
      return true;
}
int Compare(const void *a,const void *b )        //快速排序的比较函数
{
      Step *m,*n;
       m = (Step *)a;
      n = (Step *)b;
      if (m->way > n -> way)
             return 1;
      else if ( m -> way == n -> way )
            return 0;
      else
            return -1;
}
int CountWay(Pos p)   //计算位置p的可选走法数
{
      int count = 0;
       Pos buff;
      for (int i = 0; i < N; i++)
      {
             buff.x = p.x + NextStep[i][0];
            buff.y = p.y + NextStep[i][1];
            if ( Valid(buff))
                  count++;
       }
      return count;
}
void Output( Pos p, int num )    //输出路径
{
      int count = N * N - 1, x, y, x1, y1;
      x = Way[(num + 1)%USERDEFINE][Initial.x][Initial.y].x;
      y = Way[(num + 1)%USERDEFINE][Initial.x][Initial.y].y;
      cout << endl << "Solution #"<< num + 1 << " is as follows:" << endl << endl;
      printf( "Step# %2d: { %2d, %2d }\n", N * N - 1 - count, p.x, p.y );
      while ( count-- )
      {
            printf( "Step# %2d: { %2d, %2d }\n", N * N - 1 - count, x, y );
            x1 = x;
            y1 = y;
            x = Way[(num + 1)%USERDEFINE][x1][y1].x;
            y = Way[(num + 1)%USERDEFINE][x1][y1].y;
      }
      printf( "Step# 64: { %2d, %2d }\n", p.x, p.y );
}
void TraverseChessBoard( Pos& Position , int count ) //回溯法生成一个解或者所有解
{
       Pos buff;
       Step List[N];
      int i, j, k;
      if (count >= N * N)
      {
            for ( i = 0; i < N; i++ )      //找到一种满足条件的解
            {
                   buff.x = Position.x + NextStep[i][0];
                  buff.y = Position.y + NextStep[i][1];
                  if ( buff.x == Initial.x && buff.y == Initial.y )
                  {
                        //fp = fopen("国际象棋棋盘马的遍历问题解空间.doc","a+");
                         Way[0][Position.x][Position.y] = buff;
                         way++;
                         cout << "The " << way <<
"th feasible modus is as follows:" << endl << endl;
                         //fprintf(fp, "The %ld_th feasible modus is as follows:\n\n", way);
                         cout << "The ChessBoard:" << endl;
                         //fprintf(fp, "The ChessBoard:\n");
                        for ( k = 0; k < N; k++)
                        {
                               for ( j = 0; j < N; j++ )
                              {
                                     printf("%2d ",ChessBoard[k][j] );
                                     //fprintf(fp,"%2d ",ChessBoard[k][j] );
                              }
                               cout << endl;
                               //fprintf(fp,"\n");
                        }
                         cout << "The WayBoard:" << endl;
                         //fprintf(fp, "The WayBoard:\n");
                        for (int m = 0; m < N; m++ )
                        {
                               for (int n = 0; n < N; n++)
                              {
                                     printf( "{ %2d, %2d }", Way[0][m][n].x, Way[0][m][n].y );
                                     //fprintf(fp,"{ %2d, %2d }", Way[m][n].x, Way[m][n].y);
                                     Way[way][m][n] = Way[0][m][n];
                              }
                               cout << endl;
                               //fprintf(fp,"\n");
                        }
                        cout << endl;
                        //fprintf(fp,"\n");
                         if (way >= USERDEFINE )
                               over = 1;            //求得USERDEFINE 个解时,退出程序
                        //fclose(fp);
                  }
            }
             return; //求得所有解
      }
      else
      {
            int num = 0;
            for ( i = 0;i < N; i++) //找出当前可达的所有点，计算这些点向下搜索的可达点个数
            {
                   buff.x = Position.x + NextStep[i][0];
                   buff.y = Position.y + NextStep[i][1];
                   if (Valid(buff))
                  {
                         List[num].nextNum = i;
                         List[num++].way = CountWay(buff);
                  }
            }
             qsort(List, num, sizeof(Step), Compare );    //按照当前点的每个可达点的可达点的个数，升序排序
             for ( i = 0; !over&&i < num; i++ )
            {
                   int next = List[i].nextNum;                        //由可达点由少至多的顺序选取下一步
                   buff.x = Position.x + NextStep[next][0];
                   buff.y = Position.y + NextStep[next][1];
                   ChessBoard[buff.x][buff.y] = count + 1;
                   Way[0][Position.x][Position.y] = buff;
                   TraverseChessBoard(buff, count + 1);      //由下一个点遍历
                   ChessBoard[buff.x][buff.y] =0;                 //回溯
            }
      }
}
int main()
{
       Initial.x = 5;
      Initial.y = 6;
       cout << "How many solutions do you want to find?"
<< endl << endl << "Please enter the number: ";
       cin >> USERDEFINE;    //完全解时间上不允许，输入需要找到的不同路径数
       ChessBoard[Initial.x][Initial.y] = 1;
      TraverseChessBoard( Initial, 1 );                                    //生成解空间
      cout << endl << "Please enter the initial position: " ;
      cin >> Initial.x >> Initial.y;          //输入马的初始位置
      while (Initial.x >= 0 && Initial.y >= 0 && Initial.x < N && Initial.y < N )
      {
            for (int i = 0; i < USERDEFINE; i++)   //对于每一个输入，输出USERDEFINE种不同路径
                   Output( Initial , i );
             cout << endl << "Please enter the initial position: ";
             cin >> Initial.x >> Initial.y;
      }
       cout << "Bad InPut!!!" << endl;
      return 0;
}
