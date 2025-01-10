/*****************************************************************//**
 * @file main_video_test.cpp
 *
 * @brief Basic test of 4 basic i/o cores
 *
 * @author p chu
 * @version v1.0: initial release
 *********************************************************************/

//#define _DEBUG
#include "chu_init.h"
#include "gpio_cores.h"
#include "vga_core.h"
#include "sseg_core.h"
#include "spi_core.h"
#include "ps2_core.h"
#include <cmath>
#include <cstdlib>
#include <thread>
#include <future>
#include <ctime>

void test_start(GpoCore *led_p) {
   int i;

   for (i = 0; i < 20; i++) {
      led_p->write(0xff00);
      sleep_ms(50);
      led_p->write(0x0000);
      sleep_ms(50);
   }
}

/**
 * check bar generator core
 * @param bar_p pointer to Gpv instance
 */
void bar_check(GpvCore *bar_p) {
   bar_p->bypass(0);
   sleep_ms(3000);
}

/**
 * check color-to-grayscale core
 * @param gray_p pointer to Gpv instance
 */
void gray_check(GpvCore *gray_p) {
   gray_p->bypass(0);
   sleep_ms(3000);
   gray_p->bypass(1);
}

void osd_gamble(OsdCore *osd_p) {
	osd_p->set_color(0xfff, 0x000);
	osd_p->bypass(0);

	osd_p->wr_char(34, 24, 71); //G
	osd_p->wr_char(37, 24, 65); //A
	osd_p->wr_char(40, 24, 77); //M
	osd_p->wr_char(43, 24, 66); //B
	osd_p->wr_char(46, 24, 76); //L
	osd_p->wr_char(49, 24, 69); //E
}

void osd_start(OsdCore *osd_p) {
	osd_p->set_color(0xfff, 0x000);
	osd_p->bypass(0);

	osd_p->wr_char(29, 8, 67); //C
	osd_p->wr_char(30, 8, 108); //l
	osd_p->wr_char(31, 8, 105); //i
	osd_p->wr_char(32, 8, 99); //c
	osd_p->wr_char(33, 8, 107); //k

	osd_p->wr_char(35, 8, 116); //t
	osd_p->wr_char(36, 8, 104); //h
	osd_p->wr_char(37, 8, 101); //e

	osd_p->wr_char(39, 8, 98); //b
	osd_p->wr_char(40, 8, 117); //u
	osd_p->wr_char(41, 8, 116); //t
	osd_p->wr_char(42, 8, 116); //t
	osd_p->wr_char(43, 8, 111); //o
	osd_p->wr_char(44, 8, 110); //n

	osd_p->wr_char(46, 8, 116); //t
	osd_p->wr_char(47, 8, 111); //o

	osd_p->wr_char(49, 8, 115); //s
	osd_p->wr_char(50, 8, 116); //t
	osd_p->wr_char(51, 8, 97); //a
	osd_p->wr_char(52, 8, 114); //r
	osd_p->wr_char(53, 8, 116); //t
	osd_p->wr_char(54, 8, 46); //.

}

void osd_magicNum(OsdCore *osd_p) {
	osd_p->set_color(0xfff, 0x000); // dark gray/green
	osd_p->bypass(0);

	osd_p->wr_char(27, 8, 84); //T
	osd_p->wr_char(28, 8, 114); //r
	osd_p->wr_char(29, 8, 121); //y

	osd_p->wr_char(31, 8, 116); //t
	osd_p->wr_char(32, 8, 111); //o

	osd_p->wr_char(34, 8, 114); //r
	osd_p->wr_char(35, 8, 111); //o
	osd_p->wr_char(36, 8, 108); //l
	osd_p->wr_char(37, 8, 108); //l

	osd_p->wr_char(39, 8, 116); //t
	osd_p->wr_char(40, 8, 104); //h
	osd_p->wr_char(41, 8, 101); //e

	osd_p->wr_char(43, 8, 109); //m
	osd_p->wr_char(44, 8, 97); //a
	osd_p->wr_char(45, 8, 103); //g
	osd_p->wr_char(46, 8, 105); //i
	osd_p->wr_char(47, 8, 99); //c

	osd_p->wr_char(49, 8, 110); //n
	osd_p->wr_char(50, 8, 117); //u
	osd_p->wr_char(51, 8, 109); //m
	osd_p->wr_char(52, 8, 98); //b
	osd_p->wr_char(53, 8, 101); //e
	osd_p->wr_char(54, 8, 114); //r
	osd_p->wr_char(55, 8, 46); //.

}

/**
 * check osd core
 * @param osd_p pointer to osd instance
 */
void osd_check(OsdCore *osd_p) {
   osd_p->set_color(0xfff, 0x000); // dark gray/green
   osd_p->bypass(0);
  // osd_p->clr_screen();
  /* for (int i = 0; i < 64; i++) {
      osd_p->wr_char(8 + i, 20, i);
      osd_p->wr_char(8 + i, 21, 64 + i, 1);
      sleep_ms(100);
   }
   sleep_ms(3000); */

   osd_p->wr_char(29, 6, 82); // R
   osd_p->wr_char(31, 6, 79); // O
   osd_p->wr_char(33, 6, 76); // L
   osd_p->wr_char(35, 6, 76); // L

   osd_p->wr_char(38, 6, 84);  // T
   osd_p->wr_char(40, 6, 72);  // H
   osd_p->wr_char(42, 6, 69);  // E

   osd_p->wr_char(45, 6, 68);  // D
   osd_p->wr_char(47, 6, 73);  // I
   osd_p->wr_char(49, 6, 67);  // C
   osd_p->wr_char(51, 6, 69);  // E
   osd_p->wr_char(52, 6, 33); // !
}

void osd_winner(OsdCore *osd_p) {
	osd_p->set_color(0xfff, 0x000);
	osd_p->bypass(0);

	osd_p->wr_char(35, 6, 89); // Y
	osd_p->wr_char(37, 6, 79); // O
	osd_p->wr_char(39, 6, 85); // U

	osd_p->wr_char(42, 6, 87); // W
	osd_p->wr_char(44, 6, 73); // I
	osd_p->wr_char(46, 6, 78); // N
	osd_p->wr_char(47, 6, 33); // !
}
/**
 * test frame buffer core
 * @param frame_p pointer to frame buffer instance
 */
void frame_check(FrameCore *frame_p, OsdCore *osd_p) {
	osd_start(osd_p);
	osd_check(osd_p);
   int x, y, color, color2;

   frame_p->clr_screen(0x008);
   color = 0xb08;
   color2 = 0xfff;
   for(int y = 370; y < 420; y++) { // button
	   frame_p->plot_line(230, y, 430, y, color);
   }

   // screen for dice
	for(int y = 150; y < 350; y++) { // white box
		frame_p->plot_line(230, y, 430, y, color2);
	}


}

/**
 * test ghost sprite
 * @param ghost_p pointer to mouse sprite instance
 */
void mouse_check(SpriteCore *mouse_p) {
   int x, y;

   mouse_p->bypass(0);
   // clear top and bottom lines
   for (int i = 0; i < 32; i++) {
      mouse_p->wr_mem(i, 0);
      mouse_p->wr_mem(31 * 32 + i, 0);
   }

   // slowly move mouse pointer
   x = 0;
   y = 0;
   for (int i = 0; i < 80; i++) {
      mouse_p->move_xy(x, y);
      sleep_ms(50);
      x = x + 4;
      y = y + 3;
   }
   sleep_ms(3000);
   // load top and bottom rows
   for (int i = 0; i < 32; i++) {
      sleep_ms(20);
      mouse_p->wr_mem(i, 0x00f);
      mouse_p->wr_mem(31 * 32 + i, 0xf00);
   }
   sleep_ms(3000);
}

/**
 * test ghost sprite
 * @param ghost_p pointer to ghost sprite instance
 */
void ghost_check(SpriteCore *ghost_p) {
   int x, y;

   // slowly move mouse pointer
   ghost_p->bypass(0);
   ghost_p->wr_ctrl(0x1c);  //animation; blue ghost
   x = 0;
   y = 100;
   for (int i = 0; i < 156; i++) {
      ghost_p->move_xy(x, y);
      sleep_ms(100);
      x = x + 4;
      if (i == 80) {
         // change to red ghost half way
         ghost_p->wr_ctrl(0x04);
      }
   }
   sleep_ms(3000);
}

int get_shake(SpiCore *spi_p, int delayTime) {
    const uint8_t RD_CMD = 0x0b;
    const uint8_t DATA_REG = 0x08;
    const float raw_max = 127.0 / 2.0;  // Max 8-bit reading for +/-2g
    int8_t xraw, yraw, zraw;
    float x, y, z;
    float acc_value;

    spi_p->set_freq(400000);
    spi_p->set_mode(0, 0);

    // Read 8-bit x/y/z g values
    spi_p->assert_ss(0); // Activate
    spi_p->transfer(RD_CMD);  // Read command
    spi_p->transfer(DATA_REG);
    xraw = spi_p->transfer(0x00);
    yraw = spi_p->transfer(0x00);
    zraw = spi_p->transfer(0x00);
    spi_p->deassert_ss(0);

    x = (float)xraw / raw_max;
    y = (float)yraw / raw_max;
    z = (float)zraw / raw_max;

    acc_value = sqrt((x * x) + (y * y) + (z * z));
    int posTap = (int)(acc_value * 100);
    return posTap;
}

int CHANGE_ME = 230;

void dice_roll(SpiCore *spi_p, FrameCore *frame_p, OsdCore *osd_p, int n)
{
    srand(n); // Seed the random number generator
    int magicNum = (rand() % 6) + 1;
    osd_p->clr_screen();
    osd_check(osd_p);
    osd_magicNum(osd_p);
    // uart.disp("You now have a magic number: ");
    // uart.disp(magicNum);
    // uart.disp("\n\rShake to roll the dice!\n\r");

    bool gameActive = false;
    int y, color, color2, color3;

     frame_p->clr_screen(0x008);
     color = 0xfff;
     color2 = 0xf02;

    int total = 0;

    // screen for dice
	for(int y = 150; y < 350; y++) { // white box
		frame_p->plot_line(230, y, 430, y, color);
	}

	   // game logic starts

    uart.disp("Waiting for a shake event...\n\r");
    while (!gameActive) { // wait for the user to START shaking
        gameActive = (get_shake(spi_p, 5000) > CHANGE_ME);
    }

    while (true) { // while the user is shaking:
        int shake = get_shake(spi_p, 5000); // get shake magnitude

        if (shake < CHANGE_ME) { // if shake mag is low enough (no movement), print result
            int diceNum = (rand() % 6) + 1;
            uart.disp("You rolled: ");
            uart.disp(diceNum);
            uart.disp("\n\r");

            // screen for dice
        	for(int y = 150; y < 350; y++) { // white box
        		frame_p->plot_line(230, y, 430, y, color);
        	}

            switch(diceNum) {
            case 1:
   	   	   	   for(int y = 230; y < 260; y++) {
       	   	   	   frame_p->plot_line(317, y, 347, y, color2);
   	   	   	   }
				break;
            case 2:
            	for(int y = 150; y < 350; y++) { // white box
       	   	   	   frame_p->plot_line(230, y, 430, y, color);
   	   	   	   	}
   	   	   	    for(int y = 170; y < 200; y++) { // top right corner
       	   	   	   frame_p->plot_line(380, y, 410, y, color2);
   	   	   	   	}
   	   	   	    for(int y = 300; y < 330; y++) { // bottom left corner
   	   	   	    	frame_p->plot_line(250, y, 280, y, color2);
   	   	   	    }
   	   	   	    break;
            case 3:
            	for(int y = 230; y < 260; y++) { // middle
            	       frame_p->plot_line(317, y, 347, y, color2);
            	}
            	for(int y = 170; y < 200; y++) { // top right corner
            		   frame_p->plot_line(380, y, 410, y, color2);
            	}
            	for(int y = 300; y < 330; y++) { // bottom left corner
            	       frame_p->plot_line(250, y, 280, y, color2);
            	}
            	break;
            case 4:
            	for(int y = 170; y < 200; y++) { // top right corner
                   frame_p->plot_line(380, y, 410, y, color2);
           	   }

           	   for(int y = 170; y < 200; y++) { // top left corner
           	       frame_p->plot_line(250, y, 280, y, color2);
           	   }

           	   for(int y = 300; y < 330; y++) { // bottom right corner
           	       frame_p->plot_line(380, y, 410, y, color2);
           	   }

           	   for(int y = 300; y < 330; y++) { // bottom left corner
           	       frame_p->plot_line(250, y, 280, y, color2);
           	   }
           	   break;
            case 5:
            	   for(int y = 230; y < 260; y++) { // middle
            	       frame_p->plot_line(317, y, 347, y, color2);
            	   }

            	   for(int y = 170; y < 200; y++) { // top right corner
            	       frame_p->plot_line(380, y, 410, y, color2);
            	   }

            	   for(int y = 170; y < 200; y++) { // top left corner
            	       frame_p->plot_line(250, y, 280, y, color2);
            	   }

            	   for(int y = 300; y < 330; y++) { // bottom right corner
            	       frame_p->plot_line(380, y, 410, y, color2);
            	   }

            	   for(int y = 300; y < 330; y++) { // bottom left corner
            	       frame_p->plot_line(250, y, 280, y, color2);
            	   }
            	   break;
            case 6:
            	   for(int y = 230; y < 260; y++) { // middle right
            	       frame_p->plot_line(380, y, 410, y, color2);
            	   }

            	   for(int y = 230; y < 260; y++) { // middle left
            	       frame_p->plot_line(250, y, 280, y, color2);
            	   }

            	   for(int y = 170; y < 200; y++) { // top right corner
            	       frame_p->plot_line(380, y, 410, y, color2);
            	   }

            	   for(int y = 170; y < 200; y++) { // top left corner
            	       frame_p->plot_line(250, y, 280, y, color2);
            	   }

            	   for(int y = 300; y < 330; y++) { // bottom right corner
            	       frame_p->plot_line(380, y, 410, y, color2);
            	   }

            	   for(int y = 300; y < 330; y++) { // bottom left corner
            	       frame_p->plot_line(250, y, 280, y, color2);
            	   }
            	   break;
            default:
    	   	   	   for(int y = 230; y < 260; y++) {
        	   	   	   frame_p->plot_line(317, y, 347, y, color2);
    	   	   	   }
            }

            if (diceNum == magicNum) {
            	osd_p->clr_screen();
            	osd_winner(osd_p);
                uart.disp("You win!\n\r");
            	color3 = 0xb08;
            	for(int y = 370; y < 420; y++) { // button
            	   frame_p->plot_line(230, y, 430, y, color3);
            	   osd_gamble(osd_p);
                }
                //gameActive = false; //EXITS
                break;
            } else {
                uart.disp("You lost! Shake again to try.\n\r");
               // n *= 2;
                do {
                    gameActive = (get_shake(spi_p, 5000) > CHANGE_ME);
                    n*=2;
                } while (!gameActive);

            }

        }
    }
}

int ps2_check(Ps2Core *ps2_p, SpriteCore *mouse_p) {
   int id;
   int lbtn, rbtn, xmov, ymov;
   char ch;
   unsigned long last;
   static int xpos = 0, ypos = 0;
   int tempX = 0, tempY = 0;


   uart.disp("\n\rPS2 device (1-keyboard / 2-mouse): ");
   id = ps2_p->init();
   uart.disp(id);
   uart.disp("\n\r");
   last = now_ms();
   do {
      if (id == 2) {  // mouse
         if (ps2_p->get_mouse_activity(&lbtn, &rbtn, &xmov, &ymov)) {
             mouse_p->move_xy(xpos, ypos);

             tempX = xpos + xmov;
             tempY = ypos - ymov;

             if (tempX >= 0 && tempX <= 640)
                 xpos = tempX;
             if (tempY >= 0 && tempY <= 480)
                 ypos = tempY;

             if (lbtn == 1) {
             	if ((xpos < 430 && ypos < 420) && (xpos > 230 && ypos > 370)) {
             		uart.disp("Gamble");
             		return 1;
             	}

             }
            last = now_ms();

         }   // end get_mouse_activitiy()
      } else {
         if (ps2_p->get_kb_ch(&ch)) {
            uart.disp(ch);
            uart.disp(" ");
            last = now_ms();
         } // end get_kb_ch()
      }  // end id==2
   } while (now_ms());

   return 0;


}


// external core instantiation
GpoCore led(get_slot_addr(BRIDGE_BASE, S2_LED));
GpiCore sw(get_slot_addr(BRIDGE_BASE, S3_SW));
FrameCore frame(FRAME_BASE);
GpvCore bar(get_sprite_addr(BRIDGE_BASE, V7_BAR));
GpvCore gray(get_sprite_addr(BRIDGE_BASE, V6_GRAY));
SpriteCore ghost(get_sprite_addr(BRIDGE_BASE, V3_GHOST), 1024);
SpriteCore mouse(get_sprite_addr(BRIDGE_BASE, V1_MOUSE), 1024);
OsdCore osd(get_sprite_addr(BRIDGE_BASE, V2_OSD));
SsegCore sseg(get_slot_addr(BRIDGE_BASE, S8_SSEG));
SpiCore spi(get_slot_addr(BRIDGE_BASE, S9_SPI));
Ps2Core ps2(get_slot_addr(BRIDGE_BASE, S11_PS2));


int main() {
    frame.bypass(0);
    ghost.bypass(1);

    frame_check(&frame, &osd);
    osd_gamble(&osd);

    while (1) {
        int n = 30; // seed

//        uart.disp("Press the Gamble button to start the game.\n\r");
        while (!ps2_check(&ps2, &mouse));

        dice_roll(&spi, &frame, &osd, n);


        bool replay = false;
        while (1) {
            int ps2Result = ps2_check(&ps2, &mouse);

            if (ps2Result == 1) { // BUTTON CLICKED
                replay = true;
                break;
            } else if (ps2Result == 0) {
                replay = false;
                break;
            }
        }

        if (!replay) {
            break;
        }
    }

    return 0;
}

