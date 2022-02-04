#include<iostream>//basic c++ input output
#include<windows.h>//windows control for controlling and coustomizing
#include<fstream>//loading text files as textures
#include<conio.h>//kbhit and other math
#include<stdio.h>//_getch other math
#include<string>//string control
#include<vector>///manages size auto acts like an buffer stores thing drawed on the screen
#include<cmath>//c++ maths advanced
#include<chrono>//time as elasped time mesurment
#include<math.h>//math functions
#include<iomanip>//shapes width
#include<thread>//munti threading
#define PAUSE system("pause > nul");
using namespace std;
enum PIXELS {
PIXEL_SOLID=219,//the square pixel char of the screen
PIXEL_MESHED=178,//the meshed pixel char of the screen
PIXEL_VeryMeshed=177,//the very meshed pixel char of the screen
PIXEL_VeryMeshed2=176,
};
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
        int n_mConsoleWidth;
    int n_mConsoleHeight;
    bool ConsoleConstructed=false;
    void SolidShape(int Length,int Size=219){
char a=Size;
for(int i=1;i<Length;i++){
 for(int j=1;j<=0;j++);
    cout<<a;
}
 }
public:
     int columns, rows;
void CreateConsoleWindow(LPCSTR WindowName,short width,short height,int twidth,int theight){
SetConsoleTitle(WindowName);
 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
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
     HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    if(ConsoleConstructed==false){
n_mConsoleHeight+=theight;
n_mConsoleWidth+=twidth;
ConsoleConstructed=true;
    }else {

    }
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
//circle code main function varibles
void Pos(short x,short y){
HANDLE PosHandle=GetStdHandle(STD_OUTPUT_HANDLE);
cout.flush();
COORD Position={x,y};
SetConsoleCursorPosition(PosHandle,Position);//changes the console cursor position
}
void LoadLineLeft(int PIXEL,int x,int y){
char PIXEL_=PIXEL;
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
    Pos(x,y);
cout<<PIXEL_;
        }
        x-=1;
 y+=1;
}
}
void LoadLineRight(int PIXEL,int x,int y){
char PIXEL_=PIXEL;
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
    Pos(x,y);
cout<<PIXEL_;
        }
        x+=1;
 y+=1;
}
}
void LoadLineUpLeft(int PIXEL,int x,int y){
char PIXEL_=PIXEL;
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
    Pos(x,y);
cout<<PIXEL_;
        }
        x-=1;
 y-=1;
}
}
void LoadLineUpRight(int PIXEL,int x,int y){
char PIXEL_=PIXEL;
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
    Pos(x,y);
cout<<PIXEL_;
        }
        x+=1;
 y+=1;
}
}
 void TriangleRight(int PIXEL,int x,int y,int color,int triangletype){
char PIXEL_=PIXEL;
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
            PColor(color);
        Pos(x,y);
      SolidShape(i,PIXEL);
        }
        if(triangletype==1){
        y+=1;
        }else if(triangletype==2){
        y-=1;
        }
}
 }
void LoadPixel(int PIXEL,int x,int y,int color=FG_WHITE){
if(OnUserCreate1==true){
if(ConsoleConstructed==true){
int currentlength;
char PIXEL_=PIXEL;
bool mesured=false;
if(mesured==false){
currentlength+=2*n_mConsoleWidth;
mesured=true;
}
for(int i=0;i<n_mConsoleHeight;i++){
        for(int j=0;j<=n_mConsoleWidth;j++){
            PColor(color);
            Pos(x,y);
      SolidShape(currentlength,PIXEL);
        }
        y+=1;
}
}else {

}
}else {

}
}
void Draw(int x,int y,int PIXEL){

}
void LoadTexture(string Texture,int x,int y,int color){
ifstream File(Texture);
string line;
if(File.is_open()){
while(getline(File,line)){
if(OnUserCreate1==true){
Pos(x,y);
PColor(color);
cout<<line;
current_line++;
y+=1;
}else {

}
}
}else {
cout<<"file not found error 404"<<endl;
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
}
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
void PColor(int color){
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h,color);
}
void OnUserUpdate(bool Update){
if(Update==true){
OnUserUpdate1=true;
 static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it

    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
OnUserUpdate1=false;
}else {

}
}

void GetScreenHeight(){
 CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    cout<<columns<<endl;
}
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
void OnUserCreate(bool Create){
if(Create==true){
OnUserCreate1=true;
OnUserUpdate1=false;
}else {
OnUserCreate1=false;
}
}
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
namespace Physics {
void PosS(short x,short y){
HANDLE PosHandle=GetStdHandle(STD_OUTPUT_HANDLE);
cout.flush();
COORD Position={x,y};
SetConsoleCursorPosition(PosHandle,Position);//changes the console cursor position
}
void Shadows3D(int x,int y,int color){
    bool setup=false;
    int newy;
    int newy2;
    int newy3;
if(setup==false){

y+=1;
newy+=y;
newy2+=newy;
newy2+=1;
newy3+=newy2;
newy3+=1;
setup=true;
}
char a=219;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(h,FG_GREY);
PosS(x,newy);
cout<<a;
cout<<a;
PosS(x,newy2);
cout<<a;
cout<<a;
cout<<a;
PosS(x,newy3);
cout<<a;
cout<<a;
}
}
