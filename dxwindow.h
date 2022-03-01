#include "directX.h"
#define maxw 32
struct windows{
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
int newWindow(int x,int y,int w, int h,int r,int g, int b){
	int www=wcount; 	
	if(www<maxw-1){
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
void windowsRefresh(){
	int n;
	boxs(0,0,vinfo.xres-1,vinfo.yres-1,0,0,0);
	for(n=0;n<wcount;n++)boxs(win[n].x,win[n].y,win[n].w,win[n].h,win[n].r,win[n].g,win[n].b);
}