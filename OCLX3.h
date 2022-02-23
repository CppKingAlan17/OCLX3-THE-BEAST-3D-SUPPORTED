#pragma comment(lib, "winmm.lib")
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include<iostream>//basic c++ input output
#include<windows.h>//windows control for controlling and coustomizing
#include<fstream>//loading text files as textures
#include<conio.h>//kbhit and other math
#include<stdio.h>//_getch other math
#include<string>//string control
#include<vector>///manages size auto acts like an buffer stores thing drawed on the screen
#include<cmath>//c++ maths advanced
#include<winuser.h>//windows user controls
#include<chrono>//time as elasped time mesurment
#include<mmsystem.h>
#include<iomanip>//shapes width
#include<mem.h>
#include<thread>//munti threading
#define _WIN32_WINNT 0x0500
#define PI 3.14159
using namespace std;
enum PIXELS {
PIXEL_SOLID=219,//the square pixel char of the screen
PIXEL_MESHED=178,//the meshed pixel char of the screen
PIXEL_VeryMeshed=177,//the very meshed pixel char of the screen
PIXEL_VeryMeshed2=176,
};
enum PIXEL_Mode {
PIXEL_VISIBLE=0,
PIXEL_NOAA=2,
PIXEL_AA=3,
PIXEL_SAA=4,
PIXEL_MSSAA=5,
};
enum MODE {
FASTRENDERMODE=0x3021,
RENDER3DMODE=0x3012,
LOWRENDERMODE=0x1230,
};
struct vec3D {
float x=0.0f;
float y=0.0f;
float z=0.0f;
};
int ScreenHeight1;
 int ScreenWidth1;
enum COLOUR
{
	FG_BLACK		= 0x0000,
	FG_DARK_BLUE    = 0x0001,
	FG_DARK_GREEN   = 0x0002,
	FG_DARK_CYAN    = 0x0003,
	FG_DARK_RED     = 0x0004,
	FG_DARK_MAGENTA = 0x0005,
	FG_DARK_YELLOW  = 0x0006,
	FG_GREY			= 0x0007, // Thanks MS :-/
	FG_DARK_GREY    = 0x0008,
	FG_BLUE			= 0x0009,
	FG_GREEN		= 0x000A,
	FG_CYAN			= 0x000B,
	FG_RED			= 0x000C,
	FG_MAGENTA		= 0x000D,
	FG_YELLOW		= 0x000E,
	FG_WHITE		= 0x000F,
	BG_BLACK		= 0x0000,
	BG_DARK_BLUE	= 0x0010,
	BG_DARK_GREEN	= 0x0020,
	BG_DARK_CYAN	= 0x0030,
	BG_DARK_RED		= 0x0040,
	BG_DARK_MAGENTA = 0x0050,
	BG_DARK_YELLOW	= 0x0060,
	BG_GREY			= 0x0070,
	BG_DARK_GREY	= 0x0080,
	BG_BLUE			= 0x0090,
	BG_GREEN		= 0x00A0,
	BG_CYAN			= 0x00B0,
	BG_RED			= 0x00C0,
	BG_MAGENTA		= 0x00D0,
	BG_YELLOW		= 0x00E0,
	BG_WHITE		= 0x00F0,
	BG_X=0x00F1,
};
enum PIXELS_Special {
PIXEL_TREE=6,
PIXEL_HEART=3,
PIXEL_TREE2=5,
PIXEL_Wavey=247,
PIXEL_FACE=2,
PIXEL_Q=234,
PIXEL_Diamond=4,
PIXEL_GENDERMALE=11,
PIXEL_GENDERFEMALE=12,
PIXEL_MUSIC=14,
PIXEL_QQ=20,
PIXEL_UnderScore=22,
PIXEL_Triangle=30,
PIXEL_SMALL=46,
PIXEL_QUATER=220,
PIXEL_n=239,
PIXEL_nn=227,
PIXEL_SOLIDHALF=221,
PIXEL_SOLIDHALFRIGHT=222,
PIXEL_QUATERUP=223,
PIXEL_Centered=255,
};
enum TextureSpaces{
SPACED=' ',
};
enum colors {
FG_GREEN1=2,
FG_Cyan=3,
FG_Purple=5,
FG_Yellow=6,
FG_GRAY=8,
FG_LightBlue=9,
FG_LightGreen=10,
FG_Ice=11,
FG_LightRed=12,
FG_LightPurple=13,
FG_LightYellow=14,
FG_BrightWhite=15,
};
enum PIXEL_TYPE
{
	PIXEL_SOLID2 = 0x2588,
	PIXEL_THREEQUARTERS2 = 0x2593,
	PIXEL_HALF2 = 0x2592,
	PIXEL_QUARTER2 = 0x2591,
};
namespace GraphicsEngine {
class ConsoleGraphicsEngine {
private:
    //user update function
 bool OnUserUpdate1;
    bool OnUserCreate1;
    bool Keep_reading=true;
    int current_line=1;
    //buffer
    vector<char>buffer;
    void DisplayVector(vector<char> &v){
for(char i=0;i<v.size();i++){
cout<<v[i];
}
    }

    bool ConsoleConstructed=false;
    void SolidShape(int Length,int PIXEL){
        char a=PIXEL;
        HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
for(int i=1;i<Length;i++){
 for(int j=1;j<=0;j++);
if(PIXEL>0){
cout<<a;
}
}
 }
 void SolidShapeVertical(int Length,int PIXEL){
     char a=PIXEL;
 for(int i=1;i<Length;i++){
 for(int j=1;j<=0;j++){
cout<<a;
}
cout<<"/n";
 }
 }
 void GameThread(){
 auto tp1 = chrono::system_clock::now();
 auto tp2 = chrono::system_clock::now();
 while(ConsoleConstructed)
 tp2 =chrono::system_clock::now();
 chrono::duration<float>ElaspedTime=tp1-tp2;
 float fElaspedtime=ElaspedTime.count();
 }
 void ShadowClac3(int x,int y2,int PIXEL,int Length){
     char a=PIXEL;
for(int i=1;i<Length;i++){
 for(int j=1;j<=0;j++);
   Pos(x,y2);
    cout<<a;
}
 }
 float fElaspedTime3=0.0f;
 float LengthOfFrame=0.0f;
 void GameThreading(){
    fElaspedTime3+=1.0f;
 }
 enum START {
 ACTIVE=true,
 };
 int nWidth;
 int nHeight;
 short *m_Glyphs = nullptr;
	short *m_Colours = nullptr;

 bool Is_Running;
 int ScreenHeight;
 int ScreenWidth;
public:


    bool LightingShow;
     int columns, rows;

void CreateConsoleWindow(LPCSTR WindowName,short width,short height,int fontw,int fonth,bool maximize,bool resizec,int MODE){
    HWND hWnd;
    if(MODE==FASTRENDERMODE){
     std::ios_base::sync_with_stdio(NULL);
     cin.tie(NULL);
    }else if(MODE==RENDER3DMODE){
     std::ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    }else if(MODE==LOWRENDERMODE){
    std::ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    }
    if(maximize==true){
DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE, MF_BYCOMMAND);
DrawMenuBar(GetConsoleWindow());
    }
    if(resizec==true){
HWND consoleWindow = GetConsoleWindow();
SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    }
if(ConsoleConstructed==false){
    CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.dwFontSize.X = fontw;                  // Width of each character in the font
cfi.dwFontSize.Y = fonth;        // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight =FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &cfi);
    _COORD coord;
    coord.X = width; coord.Y = height;

    _SMALL_RECT Rect;
    Rect.Left = 0;              Rect.Top = 0;
    Rect.Bottom = height - 1;   Rect.Right = width- 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
   SetConsoleWindowInfo(Handle,true,&Rect);

}else {

}
if(ConsoleConstructed==false){
ScreenHeight+=height;
ScreenWidth+=width;
ScreenHeight1+=height;
ScreenWidth1+=width;
}
SetConsoleTitle(WindowName);
 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;
if(ConsoleConstructed==false){
std::string str = "MODE CON COLS=" + std::to_string(ScreenWidth) + " LINES="+std::to_string(ScreenHeight);
system(str.c_str());
}
if(ConsoleConstructed==false){
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;

    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    // set the new screen buffer dimensions
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }

    // print the current screen buffer dimensions
 GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
    if(ConsoleConstructed==false){
ConsoleConstructed=true;
    }
}

void Start(int sleep){
Sleep(sleep);

}
//circle code main function varibles
void TextureDelete(string Texture){
cout.fill(10);
}
void CreateOverLappedWindow(string Text,int PIXEL,int x,int y,int width,int height,int Color,int Color2){
Pos(x,y);
PColor(Color||Color2);
cout<<Text;
}
void Pos(short x,short y){
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x,y});

}
void DrawTriangle(int numofrows,int color){
int space, rows=numofrows;

    for(int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            cout <<"  ";
        }

        while(k != 2*i-1)
        {
            LoadPixelNoPos(PIXEL_SOLID,FG_WHITE,20);
            ++k;
        }
        cout << endl;
    }
}
void LoadPixelNoPos(int PIXEL,int Color,int Mode){
PColor(Color);
char a=PIXEL;
cout<<a;
}
void ClipLeft(int PIXEL,int x,int y,int width,int height,int color){
LoadLineLeft(PIXEL,x,y,height,width,color);
}
void ClipRight(int PIXEL,int x,int y,int width,int height,int color){
LoadLineRight(PIXEL,x,y,height,width,color);
}
void ClipStraghit(int PIXEL,int x,int y,int maxiumX,int maxiumY,int width,int height,int color){
Pos(x,y);
SolidShape(width,PIXEL);
}
void ClipUpRight(int PIXEL,int x,int y,int width,int height,int color){
LoadLineUpRight(PIXEL,x,y,height,width,color);
}
void ClipUpLeft(int PIXEL,int x,int y,int width,int height,int color){
LoadLineUpLeft(PIXEL,x,y,height,height,color);
}
void LoadLineLeft(int PIXEL,int x,int y,int lengthx,int lengthw,int color){
char PIXEL_=PIXEL;
for(int i=0;i<lengthx;i++){
        for(int j=0;j<=lengthw;j++){
    Pos(x,y);
      PColor(color);
cout<<PIXEL_;
        }
        x-=1;
 y+=1;
}
}
virtual void FillTriangle(int PIXEL,int x,int y,int length,int height,int color){
PColor(color);
for(int j=0;j<length;j++ && y++){
Pos(x,y);
SolidShape(length,PIXEL);
}
}
virtual void FillPolygon(int PIXEL,int x,int y,int length,int height,int color){
PColor(color);
for(int j=0;j<height;j++ && y++){
Pos(x,y);
SolidShape(length,PIXEL);
}
}
void LoadLineRight(int PIXEL,int x,int y,int lengthx,int lengthw,int color){
char PIXEL_=PIXEL;
for(int i=0;i<lengthx;i++){
        for(int j=0;j<=lengthw;j++){
    Pos(x,y);
    PColor(color);
cout<<PIXEL_;
        }
        x+=1;
 y+=1;
}
}
void LoadLineUpLeft(int PIXEL,int x,int y,int lengthx,int lengthw,int color){
char PIXEL_=PIXEL;
for(int i=0;i<lengthx;i++){
        for(int j=0;j<=lengthw;j++){
    Pos(x,y);
      PColor(color);
cout<<PIXEL_;
        }
        x-=1;
 y-=1;
}
}
void LoadLineUp(int PIXEL,int x,int y,int length,int width,int color){
char PIXEL_=PIXEL;
for(int i;i<length;i++){
        for(int j;j<width;j++){
Pos(x,y);
cout<<PIXEL_;
        }
        cout<<endl;
}
}
void LoadLineUpRight(int PIXEL,int x,int y,int lengthx,int lengthw,int color){
char PIXEL_=PIXEL;
for(int i=0;i<lengthx;i++){
        for(int j=0;j<=lengthw;j++){
    Pos(x,y);
    PColor(color);
cout<<PIXEL_;
        }
        x+=1;
 y+=1;
}
}
bool DrawToGround(int x,int y,int maxw,int myw,int PIXEL,int Color){
LoadPixel(PIXEL,x,y*2,Color);
}
virtual void DrawSky(int maxw,int myw,int PIXEL,int Color){
GenerateTerrain(0,0,maxw,myw,PIXEL,Color);
}
virtual void GenerateTerrain(int x,int y,int width,int height,int PIXEL,int Color){
    int i=0;
if(i<height){
Pos(x,y);
for(i=0;i<height;i++){
width++;
PColor(Color);
SolidShape(width+2,PIXEL);
}
}else {

}
}
virtual void DrawGroundTile(int x,int y,int PIXEL,int Color,int myw,int mxw){
GenerateTerrain(20,20,mxw,myw,PIXEL,Color);//Draw Wall
}
virtual void DrawWall(int x,int y,int mxw,int myw,int PIXEL,int Color,int ShadowColor=FG_DARK_GREEN){
GenerateTerrain(x,y,mxw,myw,PIXEL,Color);//wall
}
virtual void DrawString(string Draw,int x,int y,int color){
Pos(x,y);
PColor(color);
cout<<Draw;
}
virtual void LineStaghit(int PIXEL,int x,int y,int length,int color){
PColor(color);
Pos(x,y);
SolidShape(length,PIXEL);
}
 void ClearScr(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
    SMALL_RECT scrollRect;
    COORD scrollTarget;
    CHAR_INFO fill;

    // Get the number of character cells in the current buffer.
   if(!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Scroll the rectangle of the entire buffer.
    scrollRect.Left = 0;
    scrollRect.Top = 0;
    scrollRect.Right = csbi.dwSize.X;
    scrollRect.Bottom = csbi.dwSize.Y;

    // Scroll it upwards off the top of the buffer with a magnitude of the entire height.
    scrollTarget.X = 0;
    scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

    // Fill with empty spaces with the buffer's default text attribute.
    fill.Char.AsciiChar   = TEXT(' ');
    fill.Attributes = csbi.wAttributes;

    // Do the scroll
    ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

    // Move the cursor to the top left corner too.
    csbi.dwCursorPosition.X = 0;
    csbi.dwCursorPosition.Y = 0;

    SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
 }
 virtual ProgramCounter(int instructions){

 }
 virtual void Center(){
    bool centercalc;
 int centerx;
 int centery;
 if(centercalc==false){
 centerx=(ScreenWidth/2);
 centery=(ScreenHeight/2);
 centercalc=true;
 }
 Pos(centerx,centery);
 }

 virtual void Sample(int x,int y,int Color,int PIXEL){
 char a=PIXEL;
 Pos(x,y);
 PColor(Color);
 cout<<a;
 }

 void Shadow2D(int x,int y){
 y+=1;
 LoadPixel(PIXEL_SOLID,x,y,FG_DARK_GREY);
 }
 void TextAnimation(int time,string S){

    // Traverse the given string S
    for (int i = 0; i < S[i]; i++) {

        cout << S[i];


        Sleep(time);
    }
    cout<<endl;
}
bool LoadPixel(int PIXEL,int x,int y,int color=FG_WHITE){
    char a=PIXEL;
            Pos(x,y);
            PColor(color);
      cout<<a;
      return true;
}
void Lighting(int lightx,int lighty,int ground){
lightx+=lightx;
lighty+=ground;
Pos(lightx,lighty);
int shadowx=(lightx+1);
int shadowy=(lighty+1);
int shadowx2=(lightx+1);
int shadowy2=(shadowy+1);
PColor(FG_GREY);
SolidShape(8,PIXEL_SOLID);
PColor(FG_DARK_GREY);
Pos(shadowx,shadowy);
SolidShape(10,PIXEL_SOLID);
Pos(shadowx2,shadowy2);
PColor(FG_GREY);
SolidShape(8,PIXEL_SOLID);
}
void WaitForKbInput(){
_getch();
}

void GetKbInput(int Key){
if(GetAsyncKeyState(Key));
}

void GroundColor(int Color){
PColor(Color);//ground
}
void FontSize(int fontw,int fonth){
    CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.dwFontSize.X = fontw;                  // Width of each character in the font
cfi.dwFontSize.Y = fonth;        // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight =FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &cfi);
}
void Circle(int PIXEL,int Color,int posx,int posy,int centerx,int centery,int radius){
int xc=centerx,yc=centery,i,p,x1=posx,y1=posy,y=posy,r=radius,x=posx;
float theta;
for(i=0;i<=360;i++){
theta=(i*3.14)/180;
x=(int)(xc+(r*cos(theta)));
y=(int)(yc+(r*sin(theta)));
LoadPixel(PIXEL_SOLID,x,y,FG_WHITE);
}
}
void Lighting2D(int lightingcolor,int gamebackground,int lx,int ly,int norx,int nory,int pixel=219){
int color1=lightingcolor;
int color2=gamebackground;
char a=pixel;
if(LightingShow==true){
Pos(lx,ly);
PColor(color1);
cout<<a;
Pos(norx,nory);
PColor(color2);
cout<<a;
}
}
virtual void CreateConsole(int x,int y,int width,int height,int Color){

}
void LoadTexture(string Texture,int x,int y,int color){
ifstream File(Texture);
string line;
if(File.is_open()){
while(getline(File,line)){
PColor(color);
Pos(x,y);
cout<<line;
Pos(x,y);
y+=1;
}
}
}


void Reflections(string reftexture,int lines,int objectx,int objecty,int refx,int color){
bool reflectionset;
if(reflectionset==false){
objecty+=lines;
}else {

}
if(objectx==refx){
LoadTexture(reftexture,objectx,objecty,color);
}else {
LoadTexture(reftexture,objectx,objecty,color);
}
}
void DrawGlassWall(int x,int y,int mxw,int myw,int PIXEL,int Color,int FloorColor){
DrawWall(x,y,mxw,myw,PIXEL,Color|FloorColor,NULL);
}
void Shadows(int shadowx,int shadowy,int height,int length,int objectright,int objectleft,int objectup){
bool shadow_instlized;
char a=PIXEL_SOLIDHALF;
int newx;
int upx=shadowx;
if(shadow_instlized==true){

}else {

if(objectright==1){
length--;
shadowx-=length;
shadowy+=height;
newx+=shadowx;
newx+=1;
}else if(objectleft==1){
length++;
shadowx+=length;
shadowy+=height;
newx+=shadowx;
newx+=1;
}else if(objectup==1){
shadowy+=height;
newx+=shadowx;
newx-=1;
}
}
Pos(shadowx,shadowy);
PColor(FG_GREY);
cout<<a;
Pos(newx,shadowy);
cout<<a;
}
void EXITGAME(){
exit(0x0000);
}
bool Save(string FileName,string DATA){

return true;
}
bool Load(){
return true;
}
void PColor(int color){
HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
 WORD wOldColorAttrs;
 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

 /*
  * First save the current color information
  */
cout.flush();
 GetConsoleScreenBufferInfo(h, &csbiInfo);
 wOldColorAttrs = csbiInfo.wAttributes;

 /*
  * Set the new color information
  */

 SetConsoleTextAttribute ( h, color );
}
virtual bool OnUserUpdate(float fElaspedTime)=0;
void DrawQuad(int x,int y,int shape,int color){
int newx=x;
newx+=1;
Pos(x,y);
char a=shape;
PColor(color);
cout<<a;
Pos(newx,y);
PColor(color);
cout<<a;
}
virtual bool OnUserCreate()=0;

void ShadowTexture(string shadow1,string shadow2,int shadowx,int shadowy,int length,int height,int objectright,int objectleft){
bool shadow_instlized;
if(shadow_instlized==true){

}else {
if(objectright==1){
length--;
shadowx-=length;
shadowx-=1;
shadowy+=height;
LoadTexture(shadow1,shadowx,shadowy,FG_GRAY);
}else if(objectleft==1){
length++;
shadowx+=length;
shadowx-=1;
shadowy+=height;
LoadTexture(shadow2,shadowx,shadowy,FG_GRAY);
}
}
}
};
}
namespace Blender{
class BlendSide{
private:
void PosCurves(short x,short y){
	HANDLE poshandle = GetStdHandle(STD_OUTPUT_HANDLE);//handler function to handle inputs and everything
		COORD postion = { x,y };//cordinated map of x,y setting the pos as user need 0,0
		SetConsoleCursorPosition(poshandle, postion);//chaning cursor pos as user x,y user needs
}

void CurveCreate(int curvesize,int background){
char a=219;
for(int i=1;i<curvesize;i++){
for(int j=1;j<=0;j++);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h,0);
cout<<a;
}
}
public:
void Curves(int sidex1,int sidex2,int sidey1,int sidey2,int sidex3,int sidey3,int sidex4,int sidey4,int curvesize,int background){
int cx;
cx+=curvesize;
cx-=2;
PosCurves(sidex1,sidey1);
CurveCreate(curvesize,background);
sidex2-=cx;
PosCurves(sidex2,sidey2);
CurveCreate(curvesize,background);
PosCurves(sidex3,sidey3);
CurveCreate(curvesize,background);
sidex4-=cx;
PosCurves(sidex4,sidey4);
CurveCreate(curvesize,background);
}
};
}
namespace Texture {
class TextureHandle {
private:
void Pos(short x,short y){
HANDLE PosHandle=GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x,y};
SetConsoleCursorPosition(PosHandle,Position);//changes the console cursor position
}
void PColor(int color){
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h,color);
}
public:
void AddTexture(string name,int linenum,int x,int y,int color){
ifstream File(name);
string line;
if(File.is_open()){
while(getline(File,line)){
Pos(x,y);
PColor(color);
cout<<line;
y+=1;
}
}else {
cout<<"file not found error 404"<<endl;
}
}
};
}
namespace CircleCalc {
void Circle(){
int h=4;
int k=5;
int x=5;
int y=10;
int r=20;
int p=x-h;
int q=y-k;
int rr=r;
int pp=p;
int qq=q;
x-=h;
r*=rr;
p*=pp;
q*=qq;
cout<< p + q <<endl;
}
}
