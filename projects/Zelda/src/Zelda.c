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
#define true 1

int PxToGrid(int a){
   int v=((int)a/24) - (a/24 < 0);
   return v;
   
}

int CheckCollide(int x,int y,int grid[16][9]){
   int xmin=PxToGrid(x+2);
   int xmax=PxToGrid(x+17);
   int ymin=PxToGrid(y+12);
   int ymax=PxToGrid(y+26);
   if (grid[xmin][ymin]==1||grid[xmin][ymax]==1||grid[xmax][ymin]==1||grid[xmax][ymax]==1){
      return 1;
   }else{
      return 0;
   }
   
}

int CheckCollidePot(int x,int y,int grid[16][9]){
   int xmin=PxToGrid(x);
   int xmax=PxToGrid(x+24);
   int ymin=PxToGrid(y);
   int ymax=PxToGrid(y+24);
   if (grid[xmin][ymin]==1||grid[xmin][ymax]==1||grid[xmax][ymin]==1||grid[xmax][ymax]==1){
      return 1;
   }else{
      return 0;
   }
   
}

int CheckPot(int x,int y,int grid[16][9]){
   if (grid[PxToGrid(x)][PxToGrid(y)]){
      return 1;
   }else{
      return 0;
   }
   
}

int delete(int x, int y, int grid[16][9]){
   return grid[PxToGrid(x)][PxToGrid(y)];
}


int normal(float xp,float yp,int pos){
   if(pos==0){
      CopySpriteNbitMasked(linkf, xp, yp, 19 ,28, linkf_palette,0xf810,8);
   }
   if(pos==1){
      CopySpriteNbitMasked(linkb, xp, yp, 19 ,28, linkb_palette,0xf810,8);
   }
   if(pos==2){
      CopySpriteNbitMasked(linkl, xp, yp, 19 ,28, linkl_palette,0xf810,8);
   }
   if(pos==3){
      CopySpriteNbitMasked(linkr, xp, yp, 19 ,28, linkr_palette,0xf810,8);
   }
}

int takedmg(float xp,float yp,int pos,int timer){
   if (timer==0||timer==2||timer==4||timer==6||timer==8){
            if(pos==0){
			      CopySpriteNbitMaskedDmg(linkf, xp, yp, 19 ,28, linkf_palette,0xf810,8);
		      }
            if(pos==1){
               CopySpriteNbitMaskedDmg(linkb, xp, yp, 19 ,28, linkb_palette,0xf810,8);
            }
            if(pos==2){
               CopySpriteNbitMaskedDmg(linkl, xp, yp, 19 ,28, linkl_palette,0xf810,8);
            }
            if(pos==3){
               CopySpriteNbitMaskedDmg(linkr, xp, yp, 19 ,28, linkr_palette,0xf810,8);
            }
         }else{
            normal(xp,yp,pos);
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

	CopySprite(bg, 0, 0, 384 ,216);
   //24px par case largeur et 16 cases dans l'ecran
   //24 px hauteur et 9 cases
   int grid[16][9]={0};
   int i;
   int j;
	int key;
	float xp = 175;
	float yp = 95;
	int pos = 0;
   int timer = 0;
   int life;
   int OnHead=0;
   int dir=0;
   int xpot;
   int ypot;
   int state=0;
   int HeadCld=0;
   grid[8][3]=1;
   grid[9][3]=1;
   grid[3][5]=1;
   grid[3][6]=1;
   grid[2][2]=1;
   life=5;
   Bdisp_EnableColor(1);
	while (true)
	{
      
      CopySprite(bg, 0, 0, 384 ,216);
      for (i=0;i<16;i++){
         for (j=0;j<9;j++){
            if(grid[i][j]==1){
               CopySpriteNbitMasked(vase, i*24, j*24, 24 ,24, vase_palette,0xf810,8);
            }
         }
      }
      timer-=1;
      
		
		key = PRGM_GetKey();
		if (key == KEY_PRGM_LEFT){
			xp-=4;
         if (CheckCollide(xp,yp,grid)){
            xp+=4;
         }
			pos=2;
		}
		if (key == KEY_PRGM_RIGHT){
			xp+=4;
         if (CheckCollide(xp,yp,grid)){
            xp-=4;
         }
			pos=3;
		}
		if (key == KEY_PRGM_UP){
			pos=1;
			yp-=4;
         if (CheckCollide(xp,yp,grid)){
            yp+=4;
         }
		}
		if (key == KEY_PRGM_DOWN){
			pos=0;
			yp+=4;
         if (CheckCollide(xp,yp,grid)){
            yp-=4;
         }
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
         normal(xp,yp,pos);
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
                  grid[PxToGrid(xp+10)][PxToGrid(yp+30)]=0;
               }
            }
            if(pos==1){
               if (CheckPot(xp+10,yp-6,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp+10)][PxToGrid(yp-6)]=0;
               }
            }
            if(pos==2){
               if (CheckPot(xp-6,yp+7,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp-6)][PxToGrid(yp+12)]=0;
               }
            }
            if(pos==3){
               if (CheckPot(xp+25,yp+7,grid)){
                  OnHead=1;
                  grid[PxToGrid(xp+25)][PxToGrid(yp+12)]=0;
               }
            }
         }else{
            if (HeadCld==0){
               OnHead=0;
               dir=pos;
               xpot=xp-2;
               ypot=yp-10;
               state=10;
            }

         }
         
      }else{
         HeadCld=0;
      }
      if (state>0){
         state-=1;
         if (dir==0){
            ypot+=12;
         }
         if (dir==1){
            ypot-=12;
         }
         if (dir==2){
            xpot-=12;
         }
         if (dir==3){
            xpot+=12;
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
                     xp = 175;
                     yp = 95;
                     pos = 0;
                     timer = 0;
                     life=5;
                     OnHead=0;
                     grid[8][3]=1;
                     grid[9][3]=1;
                     grid[3][5]=1;
                     grid[3][6]=1;
                     grid[2][2]=1;
                     break;

                  }
               }
               
            }
         }
		}
		
	}
}