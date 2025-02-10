
// The number of states in your table
#define NSTATES 15

// The starting state, at the beginning of each line
#define START 0

#define INIT 1

// The state to go to after a valid line
// All lines end with the newline character '\n'
#define ACCEPT 12

// The state to jump to as soon as a line is invalid
#define ERROR 13

int table[NSTATES][256];

void fillTable() {

    // Make all states lead to ERROR by default
    for (int i = 0; i < (NSTATES-1); i++) {
        for (int c = 0; c < 256; c++) {
            table[i][c] = ERROR;
        }
    }

    // Skip whitespace
    table[START][' '] = START;
    table[INIT][' '] = INIT;

    // If we reach a newline, and are not in the middle of a statement, accept
    table[START]['\n'] = ACCEPT;
    table[INIT]['\n'] = ACCEPT;

    // Task 2.5: Add support for comments
    table[START]['/'] = 11;
    table[INIT]['/'] = 11;
    table[11]['/'] = 14;
    for (int c = 0; c < 256; c++) 
    {
            table[14][c] = 14;
    }
    table[14]['\n'] = ACCEPT;

    // Task 2.4: Add support for labels in the beginning og lines
    for (char c = '0'; c <= '9'; c++)
    {
        table[START][c] = 10;
        table[10][c] = 10;
    }
    table[10][':'] = INIT;

    // Accept the statement "go"
    table[START]['g'] = 2;
    table[INIT]['g'] = 2;
    table[2]['o'] = 3;
    table[3]['\n'] = ACCEPT;


    // TODO Expand the table to pass (and fail) the described syntax
    // table[...][...] = ...

    // Task 2.2: Allow spaces between valid statements
    table[3][' '] = INIT; 

    // Taks 2.3: Add support for statements 
    // 'dx=<number>' and 'dy=<number>' 
    table[START]['d'] = 4;
    table[INIT]['d'] = 4;
    table[4]['x'] = 5;
    table[4]['y'] = 6;
    table[5]['='] = 7;
    table[6]['='] = 7;
    table[7]['-'] = 9;

    for (char c = '0'; c <= '9'; c++)
    {
        table[7][c] = 9;
        table[9][c] = 9;
    }

    table[9][' '] = INIT;
    table[9]['\n'] = ACCEPT;

}
