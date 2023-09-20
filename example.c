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
#define true 1






void CopySpriteNbitMasked(const unsigned char* data, int x, int y, int width, int height, const color_t* palette, color_t maskColor, unsigned int bitwidth)  
 {
   color_t* VRAM = (color_t*) 0xA8000000;
   VRAM += (LCD_WIDTH_PX*y + x);
   int offset = 0;
   unsigned char buf;
   int j;
   for( j=y; j<y+height; j++)  
   {
	  int i;
      int availbits = 0;
      for( i=x; i<x+width;  i++)  
      {
         if (!availbits)  
         {
            buf = data[offset++];
            availbits = 8;
         }
         color_t this = ((color_t)buf>>(8-bitwidth));
         color_t color = palette[this];
         if(color != maskColor)
         {
            *VRAM = color;
         }
         VRAM++;
         buf<<=bitwidth;
         availbits-=bitwidth;
      }
      VRAM += (LCD_WIDTH_PX-width);
   }
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
	char K[] = {'\33', '\34', '\35', '\36', '\37', '\38', '\39', '\40', '\41', '\42', '\43', '\44', '\45', '\46', '\47',
'\48', '\49', '\50', '\51', '\52', '\53', '\54', '\55', '\56', '\57', '\60', '\61', '\62', '\63', '\64', '\65',
'\66', '\67', '\68', '\69', '\70', '\71', '\72', '\73', '\74', '\75', '\76', '\77', '\78', '\79', '\80', '\81', '\82', 
'\83', '\84', '\85', '\86', '\87', '\88', '\89', '\90', '\91', '\92', '\93', '\94', '\95', '\96', '\97', '\98', '\99', '\100', '\101', '\102', '\103',
'\104', '\105', '\106', '\107', '\108', '\109', '\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117', 
'\118', '\119', '\120', '\121', '\122', '\123', '\124', '\125', '\126', '\127','\0'};

	const color_t sprite_palette[19] = {0xf810, 0x0000, 0x0280, 0x0300, 0xc5a0, 0xcd60, 0x5102, 0x6164, 0x9388, 0xb48b, 0x72a7, 0x6226, 0xac09, 0xffff, 0x8b28, 0x2840, 0x4143, 0x59c4, 0xc4c3};

	const unsigned char linkf[532] = {
		0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,
		0,0,0,0,1,1,2,2,2,2,2,2,2,1,1,0,0,0,0,
		0,0,0,1,2,2,3,3,3,3,3,3,3,2,2,1,0,0,0,
		0,0,0,1,3,3,3,3,3,3,3,3,3,3,3,1,0,0,0,
		0,0,1,2,3,3,4,4,5,5,5,4,4,3,3,2,1,0,0,
		0,0,1,2,5,5,6,6,6,6,6,6,6,5,5,2,1,0,0,
		0,0,1,2,4,6,6,6,7,6,6,7,6,6,4,2,1,0,0,
		1,1,1,5,6,6,6,7,6,6,7,6,6,6,6,5,1,1,1,
		1,8,8,6,6,6,6,6,6,6,9,9,9,6,6,6,10,11,1,
		0,1,12,6,6,6,13,13,9,9,9,13,13,14,6,6,10,1,0,
		0,1,7,7,7,6,13,1,9,9,9,1,13,14,14,6,6,1,0,
		0,0,1,7,6,9,13,1,9,9,14,1,13,14,14,14,1,0,0,
		0,0,0,1,9,9,9,9,9,9,14,14,14,14,14,1,0,0,0,
		0,0,0,0,1,3,9,9,9,14,14,14,14,2,1,0,0,0,0,
		0,1,1,1,1,1,1,1,1,2,2,2,2,2,15,1,0,0,0,
		1,16,16,16,16,16,16,16,16,1,2,2,2,3,15,15,1,0,0,
		1,16,17,17,17,17,17,17,16,1,2,2,3,3,1,15,15,1,0,
		1,16,17,17,18,18,17,17,16,1,2,2,3,3,3,1,9,9,1,
		1,16,17,18,18,18,18,17,16,1,2,3,3,3,3,1,9,9,1,
		1,16,17,17,18,18,17,17,16,1,2,3,3,3,15,1,1,1,0,
		1,16,17,17,18,18,17,17,16,1,15,15,15,15,15,1,0,0,0,
		0,1,16,17,18,18,17,16,1,15,15,15,3,3,3,1,0,0,0,
		0,1,16,17,17,17,17,16,1,2,2,2,3,3,1,0,0,0,0,
		0,0,1,16,17,17,16,1,1,2,2,2,1,1,1,0,0,0,0,
		0,0,1,16,16,16,16,1,1,1,1,1,15,15,15,1,0,0,0,
		0,0,0,1,1,1,1,15,1,0,0,0,1,15,15,15,1,0,0,
		0,0,0,0,1,15,15,15,1,0,0,0,1,15,15,15,1,0,0,
		0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0
	};
	int key;
	int x;
	int y;
	int n;
	float xp = 175;
	float yp = 95;
	Bdisp_PutDisp_DD();
	while (true)
	{
		y=rand()%9;
		Bdisp_Fill_VRAM(COLOR_BLACK,TEXT_MODE_NORMAL);
		for (y=1;y<9;y++){
			for (x=1;x<22;x++){
				n=rand()% sizeof K-1;
				char selected[] = {' ',' ',K[n],'\0'};
				if (x==1 || x==21 || y==1 || y==8){
					PrintXY(x,y,selected,TEXT_MODE_NORMAL,TEXT_COLOR_PURPLE);
				}else{
					PrintXY(x,y,selected,TEXT_MODE_NORMAL,TEXT_COLOR_GREEN);
				}
				
			}
		}
		key = PRGM_GetKey();
		if (key == KEY_PRGM_LEFT){
			xp-=5;
		}
		if (key == KEY_PRGM_RIGHT){
			xp+=5;
		}
		if (key == KEY_PRGM_UP){
			yp-=5;
		}
		if (key == KEY_PRGM_DOWN){
			yp+=5;
		}

		if (xp<1){
			xp=1;
		}
		if (yp<1){
			yp=1;
		}
		if (xp>350){
			xp=350;
		}
		if(yp>190){
			yp=190;
		}
		n=rand()% sizeof K-1;
		char selected[] = {' ',' ',K[n],'\0'};
		PrintXY((int)xp,(int)yp,selected,TEXT_MODE_NORMAL,TEXT_COLOR_RED);
		CopySpriteNbitMasked(linkf, xp, yp, 19 ,28, sprite_palette,0xf810,8);
		GetKey_NonBlock();
		Bdisp_PutDisp_DD();
		
	}
}