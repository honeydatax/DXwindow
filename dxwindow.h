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
struct windows win[maxw];
int wcount=0;
void irectangle(int x,int y,int x2,int y2,int *dc,char r,char g,char b){
iline(x,y,x2,y,dc,r,g,b);
iline(x,y2,x2,y2,dc,r,g,b);
iline(x,y,x,y2,dc,r,g,b);
iline(x2,y,x2,y2,dc,r,g,b);
}
void igputc(int *dc,int x,int y,char r,char g,char b,char c){
char bits;
char bit;
int scrolls;
int iii=0;
int ii=0;
int xx=x;
int yy=y;
int aa=0;
aa=c*8;
for (ii=0;ii<8;ii++){
scrolls=128;
bits=font8x8[aa];
for (iii=0;iii<8;iii++){
if ((bits & scrolls)!=0){
Ipixel(xx,yy,dc,r,g,b);
}
xx++;
scrolls=scrolls/2;
}
xx=x;
aa++;
yy++;
}

} 
void igputs(int *dc,int x,int y,char r,char g,char b,char *c){
int ii=0;
int xx=x;
int yy=y;
while(c[ii]!=0){
igputc(dc,xx,yy,r,g,b,c[ii]);
xx=xx+8;
ii++;
}
}
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
}