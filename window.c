#include "dxwindow.h"
//g++ -o vline vline.c
int main(int argc,char *argv[])
{
    int n=0;
    int fbfd = startX(argv[0]);
    if (fbfd == -1) exit(1);
    if ((int)fbp == -1)exit(1);
	for(n=0;n<4;n++)newWindow(n*10,n*10,100,100,n*50+100,n*50+100,n*50+100);
	windowsRefresh();
	sleep(5);
	endX(fbfd);
    return 0;
}










