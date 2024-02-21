#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"

int main(void) {
    /* configure systick */
    systick_config();

    while(1) {}
}