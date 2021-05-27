/*
 * **    blink.c -    blink with 1s delay 
 * */

#include <stdio.h>
#include <unistd.h>
#include <gpiod.h>

#define GPIOCHIP        1
#define GPIOLINE        24

int 
main(int argc, char *argv[])
{
        struct gpiod_chip *output_chip;
        struct gpiod_line *output_line1;
        struct gpiod_line *output_line2;
        int line_value;

        /* open chip and get line */
        output_chip = gpiod_chip_open_by_number(GPIOCHIP);
        output_line1 = gpiod_chip_get_line(output_chip, 46);
        output_line2 = gpiod_chip_get_line(output_chip, 47);

        /* config as output and set a description */
        gpiod_line_request_output(output_line1, "blink",
                GPIOD_LINE_ACTIVE_STATE_HIGH);
        gpiod_line_request_output(output_line2, "blink",
                GPIOD_LINE_ACTIVE_STATE_HIGH);

        
        gpiod_line_set_value(output_line1, 1);
        gpiod_line_set_value(output_line2, 0);
        

        return 0;
}
