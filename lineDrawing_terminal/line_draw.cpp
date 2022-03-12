#include <iostream>
#include <cstdlib>
#include <cmath>

#include <sys/ioctl.h>
#include <unistd.h>

#define tam 20

using namespace std;

struct Points
{
    int x;
    int y;
};

int i;
int j;

void show_tela(char **tela, int row, int col)
{
    cout << '\n';
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; ++j)
        {
            cout << tela[i][j];    
        }
        cout << '\n';
    }
}

void simpleDDA(char **tela, int row, int col, Points p1, Points p2)
{
    tela[p1.x][p1.y] = '*';
    tela[p2.x][p2.y] = '*';

    float dx = abs(p2.x - p1.x);
    float dy = abs(p2.y - p1.y);
    float step;

    if (dx >= dy)
        step = dx;
    else
        step = dy;

    cout << dx << '\t' << dy << '\n';
    cout << step << '\n';

    dx = dx / step;
    dy = dy / step;

    cout << dx << '\t' << dy << '\n';

    float x = p1.x;
    float y = p1.y;

    cout << 'x' << '\t' << 'y' << "\tstep" << '\n';
    for (i = 1; i <= step; ++i)
    {
        cout << x << '\t' << y << '\t' << i << '\n';
        tela[static_cast<int>(x)][static_cast<int>(y)] = '@';

        if(p1.x < p2.x)
            x = x + dx;
        else
            x = x - dx;

        if(p1.y < p2.y)
            y = y + dy;
        else
            y = y - dy;
    }
}

void Bresenham_Algorithm(char **tela, int row, int col, Points p1, Points p2)
{
 // Credito: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B
 // Bresenham's line algorithm
  const bool steep = (fabs(p2.y - p1.y) > fabs(p2.x - p1.x));
  if(steep)
  {
    std::swap(p1.x, p1.y);
    std::swap(p2.x, p2.y);
  }
 
  if(p1.x > p2.x)
  {
    std::swap(p1.x, p2.x);
    std::swap(p1.y, p2.y);
  }
 
  const float dx = p2.x - p1.x;
  const float dy = fabs(p2.y - p1.y);
 
  float error = dx / 2.0f;
  const int ystep = (p1.y < p2.y) ? 1 : -1;
  int y = (int)p1.y;
 
  const int maxX = (int)p2.x;
 
  for(int x=(int)p1.x; x<=maxX; x++)
  {
    if(steep)
    {
        tela[y][x] = '@';
    }
    else
    {
        tela[x][y] = '@';
    }
 
    error -= dy;
    if(error < 0)
    {
        y += ystep;
        error += dx;
    }
  }
}

int main()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    //cout << "Rows: " << w.ws_row << '\n';
    //cout << "Columns: " << w.ws_col << '\n';

    char **tela = new char*[w.ws_row - 1];
    for(i=0; i<w.ws_row; ++i)
        tela[i] = new char[w.ws_col - 1];

    for(i=0; i<w.ws_row; i++)
        for(j=0; j<w.ws_col; ++j)
            tela[i][j] = '.';

    //show_tela(tela, w.ws_row, w.ws_col);

    Points p1 = {
        .x = 0, 
        .y = 0}; 

    Points p2 = {
        .x = 19, 
        .y = 19}; 
    
    do
    {
        cout << "Max x: " << w.ws_row - 2 << '\n';
        cout << "MAx y: " << w.ws_col -1 << '\n';

        cout << "P1(x,y): ";
        cin >> p1.x >> p1.y;
        cin.ignore();

        cout << "P2(x,y): ";
        cin >> p2.x >> p2.y;
        cin.ignore();

    }while((p1.x>w.ws_row || p1.x < 0)||
           (p1.y>w.ws_col || p1.y < 0)||
           (p2.x>w.ws_row || p2.x < 0)||
           (p2.y>w.ws_col || p2.y < 0));


    //simpleDDA(tela, w.ws_row, w.ws_col, p1, p2);
    Bresenham_Algorithm(tela, w.ws_row, w.ws_col, p1, p2);

    show_tela(tela, w.ws_row, w.ws_col);
    
    for (i=0; i<w.ws_row; ++i)
        delete[] tela[i];
    delete[] tela;

    return 0;
}
