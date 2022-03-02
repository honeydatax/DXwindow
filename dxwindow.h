#include "directX.h"
#define maxw 32
struct windows{
	char *title;
	int *dc;
	int x;
	int y;
	int w;
	int h;
	int r;
	int g;
	int b;
};
struct cursors{
	int x;
	int y;
	int x1;
	int y1;
	int *cursor;
};
struct cursors curs;
struct windows win[maxw];
int wcount=0;
void drawlabel(int *dc,char *title,int x,int y,int w, int h){
	char c[w/9+2];
	strncpy(c,title,w/9);
	c[w/9+1]=0;
	igputs(dc,x,y,0,0,0,c);
}
void drawWindow(char *title,int *dc,int x,int y,int w, int h,int r,int g, int b){
	iboxs(0,0,w,h,dc,r,g,b);
	irectangle(0,0,w,h,dc,0,0,0);
	drawlabel(dc,title,0,0,w,h);
}
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
		win[wcount].dc=creatImage(w,h);
		if(w>vinfo.xres-1)win[wcount].w=vinfo.xres-1;
		if(w>vinfo.yres-1)win[wcount].h=vinfo.yres-1;
		drawWindow(win[wcount].title,win[wcount].dc,win[wcount].x,win[wcount].y,win[wcount].w,win[wcount].h,win[wcount].r,win[wcount].g,win[wcount].b);
		wcount++;
	}else{
		www=-1;
	}
}
void windowsRefresh(){
	int n;
	int nx;
	int ny;
	boxs(0,0,vinfo.xres-1,vinfo.yres-1,0,0,0);
	for(n=0;n<wcount;n++){
		nx=win[n].x;
		ny=win[n].y;
		if(nx+win[n].w>vinfo.xres-1)nx=0;
		if(ny+win[n].h>vinfo.yres-1)ny=0;
		putImage(nx,ny,win[n].dc);
	}
}
void exitWindow(){
	int n;
	for(n=0;n<wcount;n++){
		if(win[n].dc!=NULL)free(win[n].dc);
	}
	if(curs.cursor!=NULL)free(curs.cursor);
}
void drawCursor(){
	ball(curs.x+16,curs.y+16,3,128,128,128);
	circle(curs.x+16,curs.y+16,3,0,0,0);
}
void showCursor(){
	curs.cursor=creatImage(32,32);
	mouseEvent();
	curs.x=mouseX-16;
	curs.y=mouseY-16;
	if(curs.x<0)curs.x=0;
	if(curs.y<0)curs.y=0;
	if(curs.x>=vinfo.xres-1)curs.x=vinfo.xres-33;
	if(curs.y>=vinfo.yres-1)curs.y=vinfo.yres-33;
	curs.x1=curs.x;
	curs.y1=curs.y;
	copyImage(curs.x,curs.y,curs.cursor);
	drawCursor();
}
void redrawCursor(){
	mouseEvent();
	curs.x1=mouseX-16;
	curs.y1=mouseY-16;
	if(curs.x1<0)curs.x1=0;
	if(curs.y1<0)curs.y1=0;
	if(curs.x1>=vinfo.xres-1)curs.x1=vinfo.xres-33;
	if(curs.y1>=vinfo.yres-1)curs.y1=vinfo.yres-33;
	if(curs.x1!=curs.x || curs.y1!=curs.y){
		if(curs.x1!=0 && curs.y1!=0 && curs.x1<vinfo.xres-33 && curs.y1<vinfo.yres-33){
			putImage(curs.x,curs.y,curs.cursor);
			curs.x=curs.x1;
			curs.y=curs.y1;
			copyImage(curs.x,curs.y,curs.cursor);		
			drawCursor();
		}
	}
}