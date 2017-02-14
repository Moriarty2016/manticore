#include <stdio.h>

/**
 * Example code for the state abandon example in the Manticore script corpus.
 *
 * # Compile binary
 * $ gcc -m32 -static -g state_explore.c -o state_explore
 *
 * # Pull out the address of the branch we want to ignore
 * $ ADDRESS=0x$(objdump -S state_explore | grep -A 1 'value == 0x41' |
 *                 tail -n 1 | sed 's|^\s*||g' | cut -f1 -d:)
 *
 * # Run the analysis
 * $ python state_explore.py state_explore $ADDRESS
 */
int
main(int argc, char *argv[])
{
    int value;

    read(0, &value, sizeof value);

    if ((value & 0xff) != 0) {
        if (value >= 0x40) {
            write(1, "1", 1);
            if (value == 0x41) {
                write(1, "a", 1);
            } else if (value == 0x42) {
                write(1, "b", 1);
            } else if (value == 0x43) {
                write(1, "c", 1);
            } else if (value == 0x44) {
                write(1, "d", 1);
            } else {
                write(1, "e", 1);
            }
        } else {
            write(1, "2", 1);
        }
    } else if ((value & 0xff00) != 0) {
        if (value > 0x1000) {
            write(1, "3", 1);
        } else {
            write(1, "4", 1);
        }
    } else if ((value & 0xff0000) != 0) {
        if (value > 0xf0000) {
            write(1, "5", 1);
        } else {
            write(1, "6", 1);
        }
    }
    write(1, "\n", 2);

    return 0;
}