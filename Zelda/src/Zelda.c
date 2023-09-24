#include <display_syscalls.h>
#include <keyboard_syscalls.h>
#include <color.h>
#include <system.h>
#include <keyboard.h>
#include <keyboard.hpp>
#include <string.h>
#include <stdio.h>
#include <display.h>
#include <stdlib.h>
#include <disp_tools.hpp>
#include <spritedef.h>
#include <tiles.h>
#include <tileset.h>
#define true 1

int PxToGrid(int a){
   int v=((int)a/24) - (a/24 < 0);
   return v;
   
}

int CheckCollide(int x,int y,int grid[17][10][4]){
   int xmin=PxToGrid(x+2);
   int xmax=PxToGrid(x+17);
   int ymin=PxToGrid(y+12);
   int ymax=PxToGrid(y+26);
   if (grid[xmin][ymin][0]==1||grid[xmin][ymax][0]==1||grid[xmax][ymin][0]==1||grid[xmax][ymax][0]==1){
      return 1;
   }else{
      return 0;
   }
   
}

int CheckCollidePot(int x,int y,int grid[17][10][4]){
   int xmin=PxToGrid(x);
   int xmax=PxToGrid(x+24);
   int ymin=PxToGrid(y);
   int ymax=PxToGrid(y+24);
   if (grid[xmin][ymin][0]==1||grid[xmin][ymax][0]==1||grid[xmax][ymin][0]==1||grid[xmax][ymax][0]==1){
      return 1;
   }else{
      return 0;
   }
   
}

int CheckPot(int x,int y,int grid[17][10][4]){
   if (grid[PxToGrid(x)][PxToGrid(y)][1]){
      return 1;
   }else{
      return 0;
   }
   
}

int CheckDoor(int x,int y,int grid[17][10][4]){
   int xmin=PxToGrid(x-6);
   int xmax=PxToGrid(x+25);
   int ymin=PxToGrid(y+5);
   int ymax=PxToGrid(y+26);
   int x2=PxToGrid(x+9);
   int y2=PxToGrid(y+13);
   if (grid[x2][ymin][3]==1 && grid[x2][ymax][3]==1){
        return 1;
    } else if (grid[xmin][y2][3]==1 && grid[xmax][y2][3]==1){
        return 1;
    }else{
        return 0;
    }
}


int normal(float xp,float yp,int pos, int anime){
   if (anime==0){
      if(pos==0){
         CopySpriteNbitMasked(linkf1, xp, yp, 19 ,28, linkf1_palette,0xf810,8);
      }
      if(pos==1){
         CopySpriteNbitMasked(linkb1, xp, yp, 19 ,28, linkb1_palette,0xf810,8);
      }
      if(pos==2){
         CopySpriteNbitMasked(linkl1, xp, yp, 19 ,28, linkl1_palette,0xf810,8);
      }
      if(pos==3){
         CopySpriteNbitMasked(linkr1, xp, yp, 19 ,28, linkr1_palette,0xf810,8);
      }
   }
   else if (anime==1){
      if(pos==0){
         CopySpriteNbitMasked(linkf2, xp, yp, 19 ,28, linkf2_palette,0xf810,8);
      }
      if(pos==1){
         CopySpriteNbitMasked(linkb2, xp, yp, 19 ,28, linkb2_palette,0xf810,8);
      }
      if(pos==2){
         CopySpriteNbitMasked(linkl2, xp, yp, 19 ,28, linkl2_palette,0xf810,8);
      }
      if(pos==3){
         CopySpriteNbitMasked(linkr2, xp, yp, 19 ,28, linkr2_palette,0xf810,8);
      }
   }
   else{
      if(pos==0){
         CopySpriteNbitMasked(linkf3, xp, yp, 19 ,28, linkf3_palette,0xf810,8);
      }
      if(pos==1){
         CopySpriteNbitMasked(linkb3, xp, yp, 19 ,28, linkb3_palette,0xf810,8);
      }
      if(pos==2){
         CopySpriteNbitMasked(linkl3, xp, yp, 19 ,28, linkl3_palette,0xf810,8);
      }
      if(pos==3){
         CopySpriteNbitMasked(linkr3, xp, yp, 19 ,28, linkr3_palette,0xf810,8);
      }
   }
}

int takedmg(float xp,float yp,int pos,int timer){
   if (timer==0||timer==2||timer==4||timer==6||timer==8){
            if(pos==0){
			      CopySpriteNbitMaskedDmg(linkf1, xp, yp, 19 ,28, linkf1_palette,0xf810,8);
		      }
            if(pos==1){
               CopySpriteNbitMaskedDmg(linkb1, xp, yp, 19 ,28, linkb1_palette,0xf810,8);
            }
            if(pos==2){
               CopySpriteNbitMaskedDmg(linkl1, xp, yp, 19 ,28, linkl1_palette,0xf810,8);
            }
            if(pos==3){
               CopySpriteNbitMaskedDmg(linkr1, xp, yp, 19 ,28, linkr1_palette,0xf810,8);
            }
         }else{
            if(pos==0){
               CopySpriteNbitMasked(linkf1, xp, yp, 19 ,28, linkf1_palette,0xf810,8);
            }
            if(pos==1){
               CopySpriteNbitMasked(linkb1, xp, yp, 19 ,28, linkb1_palette,0xf810,8);
            }
            if(pos==2){
               CopySpriteNbitMasked(linkl1, xp, yp, 19 ,28, linkl1_palette,0xf810,8);
            }
            if(pos==3){
               CopySpriteNbitMasked(linkr1, xp, yp, 19 ,28, linkr1_palette,0xf810,8);
            }
         }
}


void gameover(void){
   CopySpriteNbit(gov, 0, 0, 384, 216, gov_palette, 4);
}

int PRGM_GetKey(void)
{
  unsigned char buffer[12];
  PRGM_GetKey_OS( buffer );
  return ( buffer[1] & 0x0F ) * 10 + ( ( buffer[2] & 0xF0 ) >> 4 );
}

int GetKey_NonBlock() {
    int key;
    key = PRGM_GetKey();
    if (key == KEY_PRGM_MENU)
        GetKey(&key);
	

    return key;
}

void main(void) {
   //24px par case largeur et 16 cases dans l'ecran
   //24 px hauteur et 9 cases
   int grid[17][10][4]={0};
   int i;
   int j;
	int key;
	float xp = 8*24-9;
	float yp = 7*24-4;
	int pos = 1;
   int timer = 0;
   int life;
   int OnHead=0;
   int dir=1;
   int xpot;
   int ypot;
   int state=0;
   int HeadCld=0;
   int v=4;
   int potgravity=0;
   int locx=0;
   int locy=0;
   int locz=-1;
   map(locx,locy,locz,grid,1);
   life=5;
   int anime=0;
   Bdisp_EnableColor(1);
	while (true)
	{
      
      //CopySprite(bg, 0, 0, 384 ,216);
      for (i=0;i<16;i++){
         for (j=0;j<9;j++){
            if(grid[i][j][2]==0){
               CopySprite(cave, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==1){
               CopySprite(cave_wall_1, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==2){
               CopySprite(cave_wall_2, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==3){
               CopySprite(cave_wall_3, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==4){
               CopySprite(cave_wall_4, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==5){
               CopySprite(cave_btm_left, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==6){
               CopySprite(cave_top_left, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==7){
               CopySprite(cave_top_right, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==8){
               CopySprite(cave_btm_right, i*24, j*24, 24 ,24);
            }
            else if(grid[i][j][2]==9){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_top, i*24, j*24, 12 ,24);
            }
            else if(grid[i][j][2]==10){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_top, i*24+12, j*24, 12 ,24);
            }
            else if(grid[i][j][2]==11){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_right, i*24, j*24, 24 ,12);
            }
            else if(grid[i][j][2]==12){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_right, i*24, j*24+12, 24 ,12);
            }
            else if(grid[i][j][2]==13){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_btm, i*24, j*24, 12 ,24);
            }
            else if(grid[i][j][2]==14){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_btm, i*24+12, j*24, 12 ,24);
            }
            else if(grid[i][j][2]==15){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_left, i*24, j*24, 24 ,12);
            }
            else if(grid[i][j][2]==16){
               CopySprite(cave, i*24, j*24, 24 ,24);
               CopySprite(door_left, i*24, j*24+12, 24 ,12);
            }
         }
      }
      for (i=0;i<16;i++){
         for (j=0;j<9;j++){
            if(grid[i][j][1]==1){
               CopySpriteNbitMasked(vase, i*24, j*24, 24 ,24, vase_palette,0xf810,8);
            }
         }
      }
      timer-=1;
      
      if(OnHead==1){
         v=2;
      }else{
         v=4;
      }
		
		key = PRGM_GetKey();
		if (key == KEY_PRGM_LEFT){
			xp-=v;
         anime+=1;
         if (CheckDoor(xp-11,yp,grid)){
            map(locx-1,locy,locz,grid,1);
            locx-=1;
            xp=24*14;
         }
         if (CheckCollide(xp,yp,grid)){
            xp+=v;
         }
			pos=2;
		}else
		if (key == KEY_PRGM_RIGHT){
			xp+=v;
         anime+=1;
         if (CheckDoor(xp+12,yp,grid)){
            map(locx+1,locy,locz,grid,1);
            locx+=1;
            xp=24;
         }
         if (CheckCollide(xp,yp,grid)){
            xp-=v;
         }
			pos=3;
		}else
		if (key == KEY_PRGM_UP){
			pos=1;
			yp-=v;
         if (CheckDoor(xp,yp-5,grid)){
            map(locx,locy+1,locz,grid,1);
            locy+=1;
            yp=7*24-5;
         }
         anime+=1;
         if (CheckCollide(xp,yp,grid)){
            yp+=v;
         }
		}else
		if (key == KEY_PRGM_DOWN){
			pos=0;
			yp+=v;
         anime+=1;
         if (CheckDoor(xp,yp+14,grid)){
            map(locx,locy-1,locz,grid,1);
            locy-=1;
            yp=24;
         }
         if (CheckCollide(xp,yp,grid)){
            yp-=v;
         }
		}else{
         anime=0;
      }

		if (xp<1){
			xp=1;
		}
		if (yp<1){
			yp=1;
		}
		if (xp>384-19){
			xp=384-19;
		}
		if(yp>216-24){
			yp=216-24;
		}
      if (timer<-1){
         timer=-1;
         if (anime>2){
            anime=0;
         }
         normal(xp,yp,pos,anime);
      }
      if (timer>-1){
         takedmg(xp,yp,pos,timer);
      }
      int i;
      int j;
      

      if (key==KEY_PRGM_ALPHA){
         if (OnHead==0){
            HeadCld=1;
            if(pos==0){
               if (CheckPot(xp+10,yp+30,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp+10)][PxToGrid(yp+30)][0]=0;
                  grid[PxToGrid(xp+10)][PxToGrid(yp+30)][1]=0;
               }
            }
            if(pos==1){
               if (CheckPot(xp+10,yp-6,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp+10)][PxToGrid(yp-6)][0]=0;
                  grid[PxToGrid(xp+10)][PxToGrid(yp-6)][1]=0;
               }
            }
            if(pos==2){
               if (CheckPot(xp-6,yp+12,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp-6)][PxToGrid(yp+12)][0]=0;
                  grid[PxToGrid(xp-6)][PxToGrid(yp+12)][1]=0;
               }
            }
            if(pos==3){
               if (CheckPot(xp+25,yp+12,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp+25)][PxToGrid(yp+12)][0]=0;
                  grid[PxToGrid(xp+25)][PxToGrid(yp+12)][1]=0;
               }
            }
         }else{
            if (HeadCld==0){
               OnHead=0;
               dir=pos;
               xpot=xp-2;
               ypot=yp-8;
               state=10;
               potgravity=-2;
            }

         }
         
      }else{
         HeadCld=0;
      }
      if (state>0){
         if(state%2==1){
            potgravity+=1;
         }
         state-=1;
         if (dir==0){
            ypot+=11;
            ypot+=potgravity;
         }
         if (dir==1){
            ypot-=11;
            ypot+=potgravity;
         }
         if (dir==2){
            xpot-=12;
            ypot+=potgravity;
         }
         if (dir==3){
            xpot+=12;
            ypot+=potgravity;
         }
         if (xpot>384-24){
            xpot=384-24;
            state=0;
         }
         if (xpot<1){
            xpot=1;
            state=0;
         }
         if (ypot<1){
            ypot=1;
            state=0;
         }
         if (ypot>216-24){
            ypot=216-24;
            state=0;
         }
         CopySpriteNbitMasked(vase, xpot, ypot, 24 ,24, vase_palette,0xf810,8);
         if(CheckCollidePot(xpot,ypot,grid)){
            state=0;
         }
      }else if (state==0)
      {
         state-=1;
         CopySpriteNbitMasked(vasebrk, xpot, ypot, 24 ,24, vasebrk_palette,0xf810,8);
      }
      
      if(OnHead==1){
         CopySpriteNbitMasked(vase, xp-2, yp-10, 24 ,24, vase_palette,0xf810,8);
      }

      for (i=0; i<life+1; i++){
         CopySpriteNbitMasked(earth, 5+20*i, 10, 16 ,16, earth_palette,0xf810,8);
      }

      Bdisp_EnableColor(1);
		Bdisp_PutDisp_DD();
      if (key == KEY_PRGM_EXIT){
         if (timer < 0)
			{
            life-=1;
            timer = 10;
            if (life<0){
               gameover();
               Bdisp_PutDisp_DD();
               while (1)
               {
                  GetKey(&key);
                  key = PRGM_GetKey();
                  if (key==KEY_PRGM_RETURN){
                     xp = 8*24-9;
                     yp = 7*24-4;
                     pos = 1;
                     timer = 0;
                     life=5;
                     OnHead=0;
                     locx=0;
                     locy=0;
                     locz=-1;
                     map(0,0,-1,grid,1);
                     break;

                  }
               }
               
            }
         }
		}
		
	}
}