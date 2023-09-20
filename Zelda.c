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








void CopySpriteNbitMasked(const unsigned char* data, int x, int y, int width, int height, const color_t* palette, color_t maskColor, unsigned int bitwidth)  
 {
   
   color_t* VRAM = (color_t*) 0xAC000000;
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


void CopySpriteNbit(const unsigned char* data, int x, int y, int width, int height, color_t* palette, unsigned int bitwidth) {
   color_t* VRAM = (color_t*) 0xAC000000;
   VRAM += (LCD_WIDTH_PX*y + x);
   int offset = 0;
   unsigned char buf;
   int j;
   for( j=y; j<y+height; j++) {
	  int i;
      int availbits = 0;
      for( i=x; i<x+width;  i++) {
         if (!availbits) {
            buf = data[offset++];
            availbits = 8;
         }
         color_t this = ((color_t)buf>>(8-bitwidth));
         *VRAM = palette[(color_t)this];
         VRAM++;
         buf<<=bitwidth;
         availbits-=bitwidth;
      }
      VRAM += (LCD_WIDTH_PX-width);
   }
} 


void CopySprite(color_t* sprite, int x, int y, int width, int height) {
   color_t* VRAM = (color_t*)0xAC000000;
   VRAM += LCD_WIDTH_PX*y + x;
   int j;
   for( j=y; j<y+height; j++) {
	int i;
      for(i=x; i<x+width; i++) {
         *(VRAM++) = *(sprite++);
      }
      VRAM += LCD_WIDTH_PX-width;
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

	CopySprite(bg, 0, 0, 384 ,216);
	SaveVRAM_1;
	int key;
	int x;
	int y;
	int n;
	float xp = 175;
	float yp = 95;
	int pos = 0;
	Bdisp_PutDisp_DD();
	while (true)
	{
		Bdisp_EnableColor(1);
		key = PRGM_GetKey();
		if (key == KEY_PRGM_LEFT){
			xp-=2;
			pos=2;
		}
		if (key == KEY_PRGM_RIGHT){
			xp+=2;
			pos=3;
		}
		if (key == KEY_PRGM_UP){
			pos=1;
			yp-=2;
		}
		if (key == KEY_PRGM_DOWN){
			pos=0;
			yp+=2;
		}

		if (xp<1){
			xp=1;
		}
		if (yp<1){
			yp=1;
		}
		if (xp>384-16){
			xp=384-16;
		}
		if(yp>190){
			yp=190;
		}
		LoadVRAM_1;
		CopySprite(bg, 0, 0, 384 ,216);
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
		GetKey_NonBlock();
		Bdisp_PutDisp_DD();
		
	}
}