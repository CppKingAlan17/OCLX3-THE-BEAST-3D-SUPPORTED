#include"OCLX3.hpp"
using namespace GraphicsEngine;
using namespace Physics;
ConsoleGraphicsEngine cl;
float x=80.0f;
float y=30.0f;
float speed=1.0f;
float trackx;
float tracky;
void Check(){
if(x==100 || x==90 || x==0){
cl.OnUserUpdate(true);
cout<<"game over"<<endl;
_getch();
_getch();
}
if(speed==3){
speed-=1;
}else if(speed==0){
speed+=1;
}else {

}
}
bool frame1=false;
float roady=4.0f;
float roady2;
void Road(){
roady2+=2;
if(frame1==false){
roady+=1;
roady2+=1;
cl.LoadTexture("TREE.txt",0,roady,FG_LightGreen);
cl.LoadTexture("TREE.txt",100,roady2,FG_LightGreen);
cl.LoadTexture("TREE.txt",18,roady,FG_GREEN);
cl.LoadTexture("Lines.txt",40,4,FG_WHITE);
cl.LoadTexture("TREE.txt",100,roady,FG_GREEN);
if(roady2==27){
roady2-=y;
}
if(roady==y){
cl.OnUserUpdate(true);
roady-=y;
cl.OnUserCreate(true);
frame1=true;
}
}else {
roady+=1;
roady2+=1;
cl.LoadTexture("TREE.txt",0,roady,FG_LightGreen);
cl.LoadTexture("TREE.txt",90,roady2,FG_LightGreen);
cl.LoadTexture("TREE.txt",18,roady,FG_GREEN);
cl.LoadTexture("Lines2.txt",40,4,FG_WHITE);
cl.LoadTexture("TREE.txt",100,roady,FG_GREEN);
if(roady2==27){
roady2-=y;
}
if(roady==y){
cl.OnUserUpdate(true);
roady-=y;
cl.OnUserCreate(true);
frame1=false;
}
}
}
void RoadS(){
if(frame1==false){
roady-=1;
cl.LoadTexture("ROAD.txt",0,roady,FG_RED);
cl.LoadTexture("ROAD.txt",100,roady,FG_YELLOW);
if(roady==10){
cl.OnUserUpdate(true);
roady+=y;
cl.OnUserCreate(true);
frame1=true;
}
}else {
roady-=1;
cl.LoadTexture("ROAD2.txt",0,roady,FG_YELLOW);
cl.LoadTexture("ROAD2.txt",90,roady,FG_RED);
if(roady==10){
cl.OnUserUpdate(true);
roady+=y;
cl.OnUserCreate(true);
frame1=false;
}
}
}
int main(){
cl.OnUserCreate(true);
cl.LoadTexture("Intro.txt",0,0,FG_CYAN);
_getch();
while(1){
cl.CreateConsoleWindow("3D RACING GAME");
if(_kbhit()){
switch(_getch()){
case 'w':
Check();
cl.OnUserUpdate(true);
cl.OnUserCreate(true);
cl.LoadTexture("carCenter.txt",x,y,FG_DARK_YELLOW);
Road();
break;
case 'd':
Check();
x+=speed;
cl.OnUserCreate(true);
cl.OnUserUpdate(true);
cl.LoadTexture("carRight.txt",x,y,FG_DARK_YELLOW);
Road();
break;
case 'a':
Check();
x-=speed;
cl.OnUserCreate(true);
cl.OnUserUpdate(true);
cl.LoadTexture("carLeft.txt",x,36,FG_DARK_YELLOW);
Road();
break;
case 's':
speed-=1;
RoadS();
break;
case 'W':
speed+=1;
Check();
cl.OnUserUpdate(true);
cl.OnUserCreate(true);
cl.LoadTexture("carCenter.txt",x,y,FG_DARK_YELLOW);
Shadows3D(x,y,FG_GREY);
Road();
break;
}
}
}
}