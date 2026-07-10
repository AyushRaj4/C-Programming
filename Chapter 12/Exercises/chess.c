int evaluate_position(char board[8][8]) {
    int black = 0, white = 0;
    for (char *p = board[0]; p < board[0] + 64; p++) {
        if (*p >= 65 && *p <= 90) {
            if (*p == 'Q')
                white += 9;
            else if (*p == 'R')
                white += 5;
            else if (*p == 'B' || *p == 'N')
                white += 3;
            else
                white++;
        }

        else {
            if (*p == 'q')
                black += 9;
            else if (*p == 'r')
                black += 5;
            else if (*p == 'b' || *p == 'n')
                black += 3;
            else
                black++;
        }
    }

    return white - black;
}
