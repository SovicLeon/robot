////////////////////////////////////////
//
//	File : ai.c
//	CoSpace Robot
//	Version 1.0.0
//	Jan 1 2016
//	Copyright (C) 2016 CoSpace Robot. All Rights Reserved
//
//////////////////////////////////////
//
// ONLY C Code can be compiled.
//
/////////////////////////////////////

#define CsBot_AI_H//DO NOT delete this line
#define BETWEEN(value, min, max) (value>min&&value<max)
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define false 0
#define true 1
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = {'0','2'};

int Duration = 0;
int SuperDuration = 0;
int bGameEnd = false;
int CurAction = -1;
int CurGame = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int Teleport = 0;
int LoadedObjects = 0;
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int PositionX = 0;
int PositionY = 0;
int TM_State = 0;
int Compass = 0;
int Time = 0;
int WheelLeft = 3;
int WheelRight = 3;
int LED_1 = 0;
int MyState = 0;
int AI_SensorNum = 13;





#define CsBot_AI_C//DO NOT delete this line

DLL_EXPORT void SetGameID(int GameID)
{
    CurGame = GameID;
    bGameEnd = 0;
}

DLL_EXPORT int GetGameID()
{
    return CurGame;
}

//Only Used by CsBot Dance Platform
DLL_EXPORT int IsGameEnd()
{
    return bGameEnd;
}

#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
    char info[1024];
    sprintf(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;",Duration,SuperDuration,bGameEnd,CurAction,CurGame,SuperObj_Num,SuperObj_X,SuperObj_Y,Teleport,LoadedObjects,US_Front,US_Left,US_Right,CSLeft_R,CSLeft_G,CSLeft_B,CSRight_R,CSRight_G,CSRight_B,PositionX,PositionY,TM_State,Compass,Time,WheelLeft,WheelRight,LED_1,MyState);
    return info;
}

DLL_EXPORT char* GetTeamName()
{
     return "CoSpace Team";
}

DLL_EXPORT int GetCurAction()
{
    return CurAction;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT int GetTeleport()
{
    return Teleport;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
    SuperObj_X = X;
    SuperObj_Y = Y;
    SuperObj_Num = num;
}
//Only Used by CsBot Rescue Platform
DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
    *X = SuperObj_X;
    *Y = SuperObj_Y;
    *num = SuperObj_Num;
}

#endif ////CSBOT_REAL

DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

    int sum = 0;

    US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
    US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
    US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
    CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
    CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
    CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
    CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
    CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
    CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
    PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
    PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
    TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
    Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
    Time = AI_IN[13]; packet[13] = Time; sum += Time;
    packet[14] = sum;

}
DLL_EXPORT void GetCommand(int *AI_OUT)
{
    AI_OUT[0] = WheelLeft;
    AI_OUT[1] = WheelRight;
    AI_OUT[2] = LED_1;
    AI_OUT[3] = MyState;
}



void drive(){
    LED_1 = 0;
    WheelLeft = 4;
    WheelRight = 4;
}

void pickup(){
    WheelLeft = 0;
    WheelRight = 0;
    LED_1 = 1;
    Duration = 60;
    LoadedObjects++;
    
}

void dropoff(){
    WheelLeft = 0;
    WheelRight = 0;
    LED_1 = 2;
    Duration = 50;
    LoadedObjects = 0; 
}
/*
int degree(int comp){
    int a, deg;
    if(comp<180){
        a=180-comp;
        deg=360-a;
    }
    else{
        deg=360-comp;
    }
    return deg;
}*/
void stoosemdeset(){
    if((BETWEEN(Compass, 170, 190))){
            WheelLeft = 2;
            WheelRight = 2;
        }

}

void tristosestdeset(){
    if((BETWEEN(Compass, 350, 361))||(BETWEEN(Compass, 0, 10))){
            WheelLeft = 2;
            WheelRight = 2;
        }

}

void devetdeset(){
    if((BETWEEN(Compass, 80, 100))){
            WheelLeft = 2;
            WheelRight = 2;
        }

}

void dvestosedemdeset(){
    if((BETWEEN(Compass, 260, 280))){
            WheelLeft = 2;
            WheelRight = 2;
        }

}

void Game0(){
    /*1 duration je 60ms, duration gre dol po vsakem loopu v spodnji fukciji*/
    if(Duration>0)
        Duration--;
    //orange/dropoff
    else if(((CSLeft_R>150)&&(CSLeft_G>150)&&(CSLeft_G<200)&&(CSLeft_B<10))&&((CSRight_R>150)&&(CSRight_G>150)&&(CSRight_G<200)&&(CSRight_B<10))&&(LoadedObjects>0)){
        dropoff();
    }
    //red
    else if((((CSLeft_R>150)&&(CSLeft_G<50)&&(CSLeft_B<50))||((CSRight_R>150)&&(CSRight_G<50)&&(CSRight_B<50)))&&(LoadedObjects<6)){
        pickup();
    }
    //crna
    else if((((CSLeft_R<50)&&(CSLeft_G<50)&&(CSLeft_B<50))||((CSRight_R<50)&&(CSRight_G<50)&&(CSRight_B<50)))&&(LoadedObjects<6)){
        pickup();
    }
    //cyan
    else if((((CSLeft_R<50)&&(CSLeft_G>200)&&(CSLeft_B>200))||((CSRight_R<50)&&(CSRight_G>200)&&(CSRight_B>200)))&&(LoadedObjects<6)){
        pickup();
    }
    //rumeno
    else if(((CSLeft_R>200)&&(CSLeft_G>200)&&(CSLeft_B<10))&&((CSRight_R>200)&&(CSRight_G>200)&&(CSRight_B<10))){
            WheelLeft = -2;
            WheelRight = -4;
            LED_1 = 0;
            //Duration = 15;
    }
    else if((CSLeft_R>200)&&(CSLeft_G>200)&&(CSLeft_B<10)){
            WheelLeft = 2;
            WheelRight = -3;
            LED_1 = 0;
    }
    else if((CSRight_R>200)&&(CSRight_G>200)&&(CSRight_B<10)){
            WheelLeft = -3;
            WheelRight = 2;
            LED_1 = 0;
    }
    //spin
    else if(US_Front <= 12){
        LED_1 = 0;
        if(US_Left < US_Right){
            WheelLeft = 3;
            WheelRight = -3;
        }
        else{
            WheelLeft = -3;
            WheelRight = 3;

        }
    }
    //slight dodge
    else if((US_Front>12)&&((US_Left<=12)||(US_Right<=12))){
        LED_1 = 0;
        if(US_Left < US_Right){
            WheelLeft = 4;
            WheelRight = 1;
        }
        else{
            WheelLeft = 1;
            WheelRight = 4;

        }
    }
    //ravno
    else{
        drive();
    }
}



void Game1() {
    //x in y invisible border pre setana
    //robot se vedno premika proti obsticlom ko ni us front 186
    //x in y border s zaznavanjem, na zacetku mapiranje za speed 1 ali 2
    //obracane po kompasu - pravokotno, probaj s BREAK statmentom kadar zadane pravo stopinjo itd.
    //zapis pozicije(oložišča) x in y in najti pot do nje
    /*1 duration je 60ms, duration gre dol po vsakem loopu v spodnji fukciji*/

    if(Duration>0)
        Duration--;

    else if(((BETWEEN(PositionX, 10, 350))&&(BETWEEN(PositionY, 8, 260)))||((PositionY==0)&&(PositionX==0))){
        if(((CSLeft_R>150)&&(CSLeft_G>150)&&(CSLeft_G<200)&&(CSLeft_B<10))&&((CSRight_R>150)&&(CSRight_G>150)&&(CSRight_G<200)&&(CSRight_B<10))&&(LoadedObjects>0)){
            dropoff();
        }
        //red
        else if((((CSLeft_R>150)&&(CSLeft_G<50)&&(CSLeft_B<50))||((CSRight_R>150)&&(CSRight_G<50)&&(CSRight_B<50)))&&(LoadedObjects<6)){
            pickup();
        }
        //crna
        else if((((CSLeft_R<50)&&(CSLeft_G<50)&&(CSLeft_B<50))||((CSRight_R<50)&&(CSRight_G<50)&&(CSRight_B<50)))&&(LoadedObjects<6)){
            pickup();
        }
        //cyan
        else if((((CSLeft_R<50)&&(CSLeft_G>200)&&(CSLeft_B>200))||((CSRight_R<50)&&(CSRight_G>200)&&(CSRight_B>200)))&&(LoadedObjects<6)){
            pickup();
        }
        //rumeno
        else if(((CSLeft_R>200)&&(CSLeft_G>200)&&(CSLeft_B<10))&&((CSRight_R>200)&&(CSRight_G>200)&&(CSRight_B<10))){
            WheelLeft = -2;
            WheelRight = -4;
            LED_1 = 0;
            //Duration = 15;
        }
        else if((CSLeft_R>200)&&(CSLeft_G>200)&&(CSLeft_B<10)){
            WheelLeft = 2;
            WheelRight = -3;
            LED_1 = 0;
        }
        else if((CSRight_R>200)&&(CSRight_G>200)&&(CSRight_B<10)){
            WheelLeft = -3;
            WheelRight = 2;
            LED_1 = 0;
        }
        //swamp
        else if(((BETWEEN(CSLeft_R, 125, 160))&&(BETWEEN(CSLeft_G, 135, 170))&&(BETWEEN(CSLeft_B, 180, 215)))&&((BETWEEN(CSRight_R, 125, 160))&&(BETWEEN(CSRight_G, 135, 170))&&(BETWEEN(CSRight_B, 180, 215)))){
            WheelLeft = -2;
            WheelRight = -4;
            LED_1 = 0;
            Duration = 15;
        }
        else if((BETWEEN(CSLeft_R, 125, 160))&&(BETWEEN(CSLeft_G, 135, 170))&&(BETWEEN(CSLeft_B, 180, 215))){
            WheelLeft = 4;
            WheelRight = -3;
            LED_1 = 0;
            Duration = 15;
        }
        else if((BETWEEN(CSRight_R, 125, 160))&&(BETWEEN(CSRight_G, 135, 170))&&(BETWEEN(CSRight_B, 180, 215))){
            WheelLeft = -3;
            WheelRight = 4;
            LED_1 = 0;
            Duration = 15;
        }
        //spin
        else if(US_Front <= 12){
            LED_1 = 0;
            if(US_Left < US_Right){
            WheelLeft = 3;
            WheelRight = -3;
        }
        else{
            WheelLeft = -3;
            WheelRight = 3;

        }
        }
        //slight dodge
        else if((US_Front>12)&&((US_Left<=12)||(US_Right<=12))){
            LED_1 = 0;
            if(US_Left < US_Right){
            WheelLeft = 4;
            WheelRight = 1;
        }
        else{
            WheelLeft = 1;
            WheelRight = 4;

        }
        }
        //ravno
        else{
            drive();
        }


    }

    else{

        if(PositionX<=10){  
            if((BETWEEN(Compass, 250, 290))){
                WheelLeft = 2;
                WheelRight = 2;
            }
            else{
                WheelRight = 2;
                WheelLeft = -2;
            }
        }

        else if(PositionX>=350){
            if((BETWEEN(Compass, 90, 110))){
                WheelLeft = 2;
                WheelRight = 2;
            }
            else{
                WheelRight = 2;
                WheelLeft = -2;
            }
        }
        else if(PositionY<=8){
            if((BETWEEN(Compass, 340, 361))||(BETWEEN(Compass, 0, 20))){
                WheelLeft = 2;
                WheelRight = 2;
            }
            else{
                WheelRight = 2;
                WheelLeft = -2;
            }
        }
        else if(PositionY>=260){
            if((BETWEEN(Compass, 160, 200))){
                WheelLeft = 2;
                WheelRight = 2;
            }
            else{
                WheelRight = 2;
                WheelLeft = -2;
            }
        }
    }

   
    




}


    


DLL_EXPORT void OnTimer()
{
    switch (CurGame)
    {
        case 9:
            break;
        case 10:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            break;
        case 0:
            Game0();
            break;
        case 1:
            Game1();
            break;
        default:
            break;
    }
}

