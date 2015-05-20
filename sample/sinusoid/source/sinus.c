/*
 * sinus.c
 * This file is used to display the PSP's internal font (pgf and bwfon firmware files)
 * intraFont Version 0.31 by BenHur - http://www.psp-programming.com/benhur
 *
 * Rotation support by Geecko
 * Uses parts of pgeFont by InsertWittyName - http://insomniac.0x89.org
 *
 * This work is licensed under the Creative Commons Attribution-Share Alike 3.0 License.
 * See LICENSE for more details.
 *
 */

#include <3ds.h>
#include <sf2d.h>
#include <intraFont.h>
#include <stdio.h>
#include <math.h>


#define WHITE RGBA8(255, 255, 255, 255)
#define BLACK RGBA8(0, 0, 0, 255)


int main()
{
	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	consoleInit(GFX_BOTTOM, NULL);
	printf("intraFont test\n");

	intraFontInit();
	intraFont *font = intraFontLoad("/ltn8.pgf", INTRAFONT_CACHE_ASCII);
	intraFontSetStyle(font, 1.0f, BLACK, WHITE, 0.0f, INTRAFONT_ALIGN_LEFT);

	/*struct Sinusoid
	{
		float angle; // In degrees
		float amplitude;
		float step;
		float speed;
		float speed_inc;
		char str[64];
		int len;
	} sinus = {0.f,35.f,10.f,0.f,0.007f,"intraFont 0.31 - 2009 by BenHur",31};

	float x, tmp_angle;
	int i;*/
	char buf[64];

	while (aptMainLoop()) {

		hidScanInput();

		if (hidKeysHeld() & KEY_START) {
			break;
		}

		sf2d_start_frame(GFX_TOP, GFX_LEFT);

			sprintf(buf, "fps: %f", sf2d_get_fps());

			intraFontPrint(font, 20, 30, buf);
			intraFontPrint(font, 20, 50, "ola k ase");

			//sf2d_draw_rectangle(50, 60, 50, 50, RGBA8(0,255,0,255));

			// * Draw the sinusoid *

			// Get the x position of the 1st char
			/*x = 240 - intraFontMeasureText(font,sinus.str)/2;
			// Increment the speed
			if (fabsf(sinus.speed += sinus.speed_inc) > 10.f)
			sinus.speed_inc = -sinus.speed_inc;
			// Increment the angle
			tmp_angle = (sinus.angle += sinus.speed);
			if (sinus.angle > 360.f) sinus.angle -= 360.f;

			// Draw one by one
			for (i = 0; i != sinus.len; i++, tmp_angle+=sinus.step) {
				intraFontSetStyle(font,1.f,BLACK,WHITE,45.f*cosf(tmp_angle*M_PI/180.f), INTRAFONT_ALIGN_LEFT);
				x = intraFontPrintEx(font,x,136 + sinus.amplitude*sinf(tmp_angle*M_PI/180.f), sinus.str+i,1);
			}*/

		sf2d_end_frame();

		sf2d_swapbuffers();
	}

	intraFontUnload(font);
	intraFontShutdown();
	sf2d_fini();

	return 0;
}
