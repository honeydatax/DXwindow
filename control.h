#include "dxwindow.h"
#define flagoutput 4
#define flaginput 10

void drawLabels(label l,int *dc){
	char caption[100];
	if(l.c.h<16)l.c.h=16;
	iboxs(l.c.x,l.c.y,l.c.x+l.c.w,l.c.y+l.c.h,dc,l.r,l.g,l.b);
	irectangle(l.c.x,l.c.y,l.c.x+l.c.w,l.c.y+l.c.h,dc,0,0,0);
	strcpy(caption,l.caption);
	int tl=l.c.w/8-1;
	if (tl<0) tl=0;
	if (l.c.w/8+1> 98)tl=98;
	caption[tl]='\0';
	igputs(dc,l.c.x+3,l.c.y+3,0,0,0,caption);
}
int insides(label l1,int x,int y){
	if(x>l1.c.x && y>l1.c.y && x<l1.c.x+l1.c.w && y<l1.c.y+l1.c.h){
		return 1;
	}
	return 0;
}
