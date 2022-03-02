#include "dxwindow.h"
//g++ -o vline vline.c
int main(int argc,char *argv[])
{
    int i=-1;
    char cc[2080];
    char *ccc;
    int n=0;
    int fbfd = startX(argv[0]);
    if (fbfd == -1) exit(1);
    if ((int)fbp == -1)exit(1);
	for(n=0;n<4;n++){
		ccc=cc+(n*10);
		sprintf(ccc,"W%d",n);
		newWindow(ccc,n*20,n*20,200,200,n*50+100,n*50+100,n*50+100);
	}
	windowsRefresh();
	while(1){
		if(getc(stdin)==27)break;
		i=redrawCursor();
		if(i!=-1){
			printf("windows press:%d\n",i);
			break;
		}
	}
	exitWindow();
	endX(fbfd);
    return 0;
}










