#include <graphics.h>
#include <conio.h>
#include <math.h> //for M_PI constant is ratio of circles circumference /2. M_PI = 180degree
void drawTree(int x, int y, int length, int width, double startAngle, double angle, int layer);
void drawLine(int x1, int y1, int x2, int y2, int width); //she provided this function
void vShapeBranch(int x, int y, int length, int width, double startAngle, double angle, int layer);
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "/tc/bgi");

    int x = 320; //x-coord of the root
    int y = 386; //y-coord of the root
    int length = 100; //length of the trunk
    int width = 10; //width(thickness) of the trunk of the tree
    double startAngle = M_PI/2; //angle of the trunk starts at 90degree since the trunk is verticle to the ground.
    double angle = M_PI/7; //aute angle between a branch and the branch growing out from hte first branch
                           //or half of the angle of v-shape branch
    int layer = 4; //number of layers of the tree

    drawTree(x, y, length, width, startAngle, angle, layer);

    getch();

    closegraph();
}
void drawTree(int x, int y, int length, int width, double startAngle, double angle, int layer)
{
    //Trunk:
    int x1 = x; 
    int y1 = y; 
    int x2 = x; 
    int y2 = y - length; 
    drawLine(x1, y1, x2, y2, width);
    
    //Branches:
    vShapeBranch(x2, y2, length, width, startAngle, angle, layer);
}
void drawLine(int x1, int y1, int x2, int y2, int width_)
{
    for(int i = -width_/2; i < width_/2; i++)
    {
        line(x1+i, y1, x2+i, y2); 
        //as long as (x2+i) - (x1+i) does not change, y1 and y2 does not need to change
    }
}
void vShapeBranch(int x, int y, int length, int width, double startAngle, double angle, int layer)
{
    int x1 = x;
    int y1 = y;

    if(layer > 0)
    {
        double newLength = length * 3/4;
        int newWidth = width * 2/3;

        double LnewStartAngle = startAngle + angle; 
        double RnewStartAngle = startAngle - angle;

        if(newLength < 10)
        {
            newLength = 10;
        }
        if(newWidth < 2)
        {
            newWidth = 2;
        }
        int Lx2 = x1 + (newLength * cos(LnewStartAngle));
        int Ly2 = y1 - (newLength * sin(LnewStartAngle));
        drawLine(x1, y1, Lx2, Ly2, newWidth);
        vShapeBranch(Lx2, Ly2, newLength, newWidth, LnewStartAngle, angle, layer - 1);

        int Rx2 = x1 + (newLength * cos(RnewStartAngle));
        int Ry2 = y1 - (newLength * sin(RnewStartAngle)); 
        drawLine(x1, y1, Rx2, Ry2, newWidth);
        vShapeBranch(Rx2, Ry2, newLength, newWidth, RnewStartAngle, angle, layer - 1);
    }  
}


