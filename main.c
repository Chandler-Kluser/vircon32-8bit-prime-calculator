// include Vircon libraries
#include "time.h"
#include "video.h"
#include "audio.h"
#include "math.h"
#include "input.h"
#include "misc.h"
#include "string.h"

int x_index = 5;
int y_index = 5;

void main(void)
{
	// clear the screen in some visible color
    clear_screen(color_black);

    // write some text directly
    print_at(x_index,y_index,"Calculating Primes...");
    set_drawing_point(x_index,y_index);
    int i = 0;
    int* text;
    while(1) {
        // start guessing the number is prime
        int isprimeyet = 1;                 
        for (int aux = 2; aux<i+1; aux++){
            // the number is prime so far ...
            if (isprimeyet) {
                // aux==number --> it is surely prime
                if (aux==i) {
                    // check drawing index is outside screen
                    if (y_index>screen_height-bios_character_height*2) {
                        // fix screen cursor
                        y_index=5;
                        x_index+=bios_character_width*4;
                    }
                    // convert int to string (int pointer)
                    itoa(i,text,10);
                    // break line in y_index to avoid overlapping
                    y_index+=bios_character_height;
                    // print prime string to cursor x,y indexes
                    print_at(x_index,y_index,text);
                } else
                // check if prime can be divided by aux
                if (i%aux==0) isprimeyet=0;
            } else break;
        }
        if (i==255) break;
        i++;
    }
    
    // we are done: after main, Vircon will halt
    // execution and our text will keep showing
}