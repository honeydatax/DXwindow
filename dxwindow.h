#include "directX.h"
#define maxw 32
struct windows{
	char *title;
	int x;
	int y;
	int w;
	int h;
	int r;
	int g;
	int b;
};
struct windows win[maxw];
int wcount=0;
int newWindow(char *title,int x,int y,int w, int h,int r,int g, int b){
	int www=wcount; 	
	if(www<maxw-1){
		win[wcount].title=title;
		win[wcount].x=x;
		win[wcount].y=y;
		win[wcount].w=w;
		win[wcount].h=h;
		win[wcount].r=r;
		win[wcount].g=g;
		win[wcount].b=b;
		wcount++;
	}else{
		www=-1;
	}
}
void drawlabel(char *title,int x,int y,int w, int h){
	char c[w/9+2];
	strncpy(c,title,w/9);
	c[w/9+1]=0;
	gputs(x,y,0,0,0,c);
}
void drawWindow(char *title,int x,int y,int w, int h,int r,int g, int b){
	boxs(x,y,w,h,r,g,b);
	drawlabel(title,x,y,w,h);
}
void windowsRefresh(){
	int n;
	boxs(0,0,vinfo.xres-1,vinfo.yres-1,0,0,0);
	for(n=0;n<wcount;n++)drawWindow(win[n].title,win[n].x,win[n].y,win[n].w+win[n].x,win[n].h+win[n].y,win[n].r,win[n].g,win[n].b);
}
