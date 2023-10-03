bool winnerOfGame(char * colors){
    int Alice = 0;
    int Bob = 0;
    int length = strlen(colors);
    for(int i = 1; i < length-1; ++i){
        if(colors[i-1] == colors[i] && colors[i] == colors[i+1]
         &&colors[i] == 'A'){
            ++Alice;
        }
        if(colors[i-1] == colors[i] && colors[i] == colors[i+1]
         &&colors[i] == 'B'){
            ++Bob;
        }
    }
    return (Alice > Bob ? 1:0);
}