/*
 * this program simulates making a sandwich
 * press 'S' to start the simulation
 * press 'B' to make bread toasted
 * press 'L' for lettuce
 * press 'C' for cheese
 * press 'T' for tomatoe
 * press 'O' for final touch of olive and top bread
 * press 'E' to take a bite
 * press 'ESC' to end simulation
 */

#include "allegro.h"
#include <stdlib.h>


struct object
{
	int x;
	int y;
	int colorR;
	int colorG;
	int colorB;
};

void rectangleFunc(BITMAP* buffer, object rect, int length, int height);
void InitGraphics();
void plate(BITMAP* buffer);
void bread(BITMAP* buffer);
void toasted(BITMAP* buffer);
void lettuce(BITMAP* buffer);
void tomato(BITMAP* buffer);
void olive(BITMAP* buffer);
void eat(BITMAP* buffer);

void main() 
{
	InitGraphics();
	srand(time(NULL));

BITMAP* buffer = create_bitmap(screen->w, screen->h);

//instrcutions manual
textout_centre_ex(buffer, font, "PRESS 'S' TO START",SCREEN_W / 2, SCREEN_H / 2,makecol(255, 255, 255),-1);
textout_centre_ex(buffer, font, "THE SANDWICH SIMULATION",SCREEN_W / 2, 210,makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'B' - TOAST",45, 1,makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'L' - LETTUCE",53, 16,makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'C' - CHEESE",49, 31,makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'T' - TOMATO",49, 46,makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'O' - OLIVE", 44, 61, makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'E' - EAT", 38, 76, makecol(255, 255, 255), -1);
textout_centre_ex(buffer, font, "'ESC' - STOP",50, 91,makecol(255, 255, 255), -1);

	while (key[KEY_ESC] == 0) {
	
			while (key[KEY_S]) {
			plate(buffer);
			bread(buffer);
		}

		while (key[KEY_B]) { toasted(buffer); }
		while (key[KEY_L]) { lettuce(buffer); }
		while (key[KEY_C]) { 
			for (int i = 0; i < 184; i += 2) {
				object cheese;
				cheese.x = 210;
				cheese.y = 109 + i;
				cheese.colorR = 255;
				cheese.colorG = 255;
				cheese.colorB = 89;
				rectangleFunc(buffer, cheese, 400, 300);
			}
			}
		while (key[KEY_T]) { tomato(buffer); }
		while (key[KEY_O]) { olive(buffer); }
		while (key[KEY_E]) { eat(buffer); }
		
		blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h);
			}

	readkey();
	}

void rectangleFunc(BITMAP* buffer, object obj, int length, int height) {

	for (obj.y; obj.y < height; obj.y++) {
		for (obj.x; obj.x < length; obj.x++)
		{
			putpixel(buffer, obj.x, obj.y, makecol(obj.colorR, obj.colorG, obj.colorB));
		}
	}
}

void plate(BITMAP* buffer) {
		circlefill(buffer, 300, 200, 186, makecol(249, 249, 231));
		circle(buffer, 300, 200, 150, makecol(195, 195, 195));
}

void bread(BITMAP* buffer) {
	rectfill(buffer, 180, 79, 426, 330, makecol(135, 59, 30)); //brown
	circlefill(buffer, 180, 105, 26, makecol(135, 59, 30)); //bread sides L
	circlefill(buffer, 426, 105, 26, makecol(135, 59, 30)); //bread sides R
	rectfill(buffer, 184, 83, 422, 326, makecol(221, 175, 114)); //yellow
	circlefill(buffer, 180, 105, 22, makecol(221, 175, 114)); //bread sides L
	circlefill(buffer, 426, 105, 22, makecol(221, 175, 114)); //bread sides R
}

void toasted(BITMAP* buffer) {
	rectfill(buffer, 184, 83, 422, 326, makecol(176, 119, 77)); //brownish
	circlefill(buffer, 180, 105, 22, makecol(176, 119, 77)); //bread sides L
	circlefill(buffer, 426, 105, 22, makecol(176, 119, 77)); //bread sides R
	for (int y = 83; y < 326; y += 40) {
		for (int x = 124; x < 422; x += 50) {
			circlefill(buffer, rand() % (400 - 209) + 209, rand() % (300 - 104) + 104, rand() % 9 + 2, makecol(151, 92, 56));
		}
	}
}

void lettuce(BITMAP* buffer) {

circlefill(buffer, rand() % (380 - 230 + 1) + 230, rand() % (271 - 139 + 1) + 139, rand() % 35 + 27, makecol(128, 173, 38));

		//veins on lettuce
		line(buffer, 298, 99, 298, 355, makecol(76, 120, 17));// ----
		line(buffer, 299, 99, 299, 355, makecol(76, 120, 17));// MAIN
		line(buffer, 300, 99, 300, 355, makecol(76, 120, 17));// VEIN
		line(buffer, 301, 99, 301, 355, makecol(76, 120, 17));// ----

		line(buffer, 251, 91, 301, 120, makecol(76, 120, 17));
		line(buffer, 235, 167, 301, 210, makecol(76, 120, 17));// ----
		line(buffer, 235, 168, 301, 211, makecol(76, 120, 17));// LEFTt
		line(buffer, 217, 235, 301, 300, makecol(76, 120, 17));// VEINS
		line(buffer, 217, 236, 301, 301, makecol(76, 120, 17));// ----
		line(buffer, 217, 237, 301, 302, makecol(76, 120, 17));

		line(buffer, 351, 131, 301, 160, makecol(76, 120, 17));
		line(buffer, 351, 132, 301, 161, makecol(76, 120, 17));// ----
		line(buffer, 367, 217, 301, 260, makecol(76, 120, 17));// RIGHT
		line(buffer, 367, 218, 301, 261, makecol(76, 120, 17));// VEINS
		line(buffer, 367, 219, 301, 262, makecol(76, 120, 17));// ----

}

void tomato(BITMAP* buffer) {

	circlefill(buffer, 220, 150, 46, makecol(185, 43, 38));
	circlefill(buffer, 220, 150, 40, makecol(237, 109, 105));

	circlefill(buffer, 290, 290, 53, makecol(185, 43, 38));
	circlefill(buffer, 290, 290, 47, makecol(237, 109, 105));

	circlefill(buffer, 340, 168, 56, makecol(185, 43, 38));
	circlefill(buffer, 340, 168, 50, makecol(237, 109, 105));
}

void olive(BITMAP* buffer) {

	rectfill(buffer, 188, 87, 434, 338, makecol(135, 59, 30));
	circlefill(buffer, 188, 113, 26, makecol(135, 59, 30)); //bread sides L
	circlefill(buffer, 434, 113, 26, makecol(135, 59, 30)); //bread sides R
	rectfill(buffer, 192, 91, 430, 334, makecol(176, 119, 77));
	circlefill(buffer, 188, 113, 22, makecol(176, 119, 77)); //bread sides L
	circlefill(buffer, 434, 113, 22, makecol(176, 119, 77)); //bread sides R
	
	//grill lines
	line(buffer, 201, 179, 322, 107, makecol(135, 59, 30));
	line(buffer, 201, 180, 322, 108, makecol(135, 59, 30));
	line(buffer, 201, 181, 322, 109, makecol(135, 59, 30));
	line(buffer, 201, 182, 322, 110, makecol(135, 59, 30));
	line(buffer, 201, 183, 322, 111, makecol(135, 59, 30));

	line(buffer, 199, 266, 420, 143, makecol(135, 59, 30));
	line(buffer, 199, 267, 420, 144, makecol(135, 59, 30));
	line(buffer, 199, 268, 420, 145, makecol(135, 59, 30));
	line(buffer, 199, 269, 420, 146, makecol(135, 59, 30));
	line(buffer, 199, 270, 420, 147, makecol(135, 59, 30));

	line(buffer, 289, 316, 420, 243, makecol(135, 59, 30));
	line(buffer, 289, 317, 420, 244, makecol(135, 59, 30));
	line(buffer, 289, 318, 420, 245, makecol(135, 59, 30));
	line(buffer, 289, 319, 420, 246, makecol(135, 59, 30));
	line(buffer, 289, 320, 420, 247, makecol(135, 59, 30));
	//olive
	ellipsefill(buffer, 320, 207, 32, 47, makecol(169, 219, 71));
	ellipsefill(buffer, 319, 177, 18, 12, makecol(246, 100, 60));
	line(buffer, 271, 131, 309, 168, makecol(199, 162, 105));
	line(buffer, 271, 132, 309, 169, makecol(199, 162, 105));
	line(buffer, 271, 133, 309, 170, makecol(199, 162, 105));
}

void eat(BITMAP* buffer) {

	//function for bite on sandwich
	ellipsefill(buffer, 300, 95, 45, 33, makecol(185, 43, 38));
	circlefill(buffer, 250, 93, 20, makecol(185, 43, 38));
	circlefill(buffer, 350, 93, 20, makecol(185, 43, 38));

	ellipsefill(buffer, 300, 89, 45, 33, makecol(255, 255, 89));
	circlefill(buffer, 250, 88, 20, makecol(255, 255, 89));
	circlefill(buffer, 350, 88, 20, makecol(255, 255, 89));

	ellipsefill(buffer, 300, 85, 45, 33, makecol(128, 173, 38));
	circlefill(buffer, 250, 84, 20, makecol(128, 173, 38));
	circlefill(buffer, 350, 84, 20, makecol(128, 173, 38));

	ellipsefill(buffer, 300, 83, 45,31, makecol(249, 249, 231));
	circlefill(buffer, 250, 81, 20, makecol(249, 249, 231));
	circlefill(buffer, 350, 81, 20, makecol(249, 249, 231));

}
void InitGraphics() {
	allegro_init();
	set_color_depth(24);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 400, 0, 0);
	install_keyboard();
}
END_OF_MAIN()






