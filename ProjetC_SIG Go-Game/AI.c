#include "Process.c"
#include <time.h>

int random(int min, int max){
for(int i=0;i<1;i++){
    int num = (rand()%(max-min+1))+min;
    return num;}}

int Check_AI(char Mat[10][10],int x,int y,int *numplayer, List L){
    if (Mat[x][y]!=' ') return 0;
    if (x==L->lin && y==L->col) return 0;
    if (*numplayer==1) {Color(4,0); Mat[x][y]='X'; Color(14,0);}
    else {Color(3,0); Mat[x][y]='O'; Color(14,0);}
    if (!reverse_scout(x,y,*numplayer,Mat,L)){
        if (scout(x,y,*numplayer,Mat,L)==1) {Mat[x][y]=' ' ; return 0;}}
    else {NextPlayer(numplayer); return 1;}
    freelist(L);
    NextPlayer(numplayer);
    return 2;
}


int GO_AI(char Mat[10][10],int *numplayer, List L,int *pass){
    if (*pass==2) return Endgame(Mat,L);
    int x,y,iter=0;
    while (iter<100){
        x=random(0,8); y=random(0,8);
        if (!Check_AI(Mat,x,y,numplayer,L)) iter++;
        else {*pass=0; goban(Mat); return 12;}}
    for(int i=0;i<9;i++){
        for(int e=0;e<9;e++){
            if (Check_AI(Mat,x,y,numplayer,L)) {*pass=0; goban(Mat); return 12;}}}
    *pass+=1;
    goban(Mat);
    printf("                  Player %d Has Passed ! \n",*numplayer);
    NextPlayer(numplayer);
    return 12;
}


void Rotate(char Matrix[10][10],char TempMatrix[10][10]){
    int nlin=Matrix[9][0]-48, ncol=Matrix[9][1]-48 ;
    for(int i=0;i<=nlin;i++){
        for(int e=0;e<=ncol;e++){
                TempMatrix[e][nlin-i]=Matrix[i][e];}}
    if (nlin<8) {for(int i=0;i<=ncol;i++) TempMatrix[ncol+1][i]=' ';}
    if (ncol<8) {for(int i=0;i<=nlin;i++) TempMatrix[i][nlin+1]=' ';}
    TempMatrix[9][1]=Matrix[9][0]; TempMatrix[9][0]=Matrix[9][1];
    TempMatrix[9][2]=Matrix[9][3]; TempMatrix[9][3]=nlin-Matrix[9][2]+2*48;
    for(int i=4;i<9;i++) TempMatrix[9][i]=Matrix[9][i];
}

void Copy(char Matrix[10][10],char TempMatrix[10][10]){
    for(int i=0;i<10;i++){
        for(int e=0;e<10;e++){
                Matrix[i][e]=TempMatrix[i][e];}}
}

void Empty_Matrix(char Matrix[10][10]){
    for(int i=0;i<10;i++){
        for(int e=0;e<10;e++){
            Matrix[i][e]=' ';}}
}

void Convert(char Mat[10][10],char Let){
    char eny;
    if (Let=='O') eny='X';
    else eny='O';
    for(int i=0;i<10;i++){
        for(int e=0;e<10;e++){
            if (Mat[i][e]=='A') Mat[i][e]=Let;
            else if (Mat[i][e]=='E') Mat[i][e]=eny;
        }
    }
}


int TSU(char Mat[10][10],char Tem[10][10]){
    int x=Tem[9][0]-48, y=Tem[9][1]-48;
    int a=Tem[9][4]-48, b=Tem[9][5]-48;
    for(int i=0;i<=x;i++){
        for(int e=0;e<=y;e++){
            if (Tem[i][e]!='I' && Mat[i+a][e+b]!=Tem[i][e]) return 0;
                }}
    return 1;
}


int TSUME(char Mat[10][10],char Tem[10][10]){
    int x=Tem[9][2]-48, y=Tem[9][3]-48;
    int a=Tem[9][4]-48, b=Tem[9][5]-48;
    while(a<9){
        if (b==8) {Tem[9][5]='0' , Tem[9][4]+=1;}
        if (TSU(Mat,Tem)) {Mat[x+a][y+b]=Tem[9][7]; return 1;}
        Tem[9][5]+=1;
        a=Tem[9][4]-48; b=Tem[9][5]-48;}
    Tem[9][4]='0'; Tem[9][5]='0';
    return 0;
}

int TSUMEGO(char Mat[10][10],char Matrix[10][10],char Tem[10][10],int *numplayer){
    if (*numplayer==1) Convert(Matrix,'X');
    else Convert(Matrix,'O');
    if (TSUME(Mat,Matrix)) {NextPlayer(numplayer); goban(Mat); return 1;}
    for(int i=0;i<3;i++){
        Rotate(Matrix,Tem);
        Copy(Matrix,Tem);
        if (TSUME(Mat,Tem)) {NextPlayer(numplayer); goban(Mat); return 1;}
        Empty_Matrix(Tem);
    }
    Empty_Matrix(Tem);
    return 0;
}


int check_scout(int x,int y,int num,char Mat[10][10],List L,char piece){
    if (y!=8){
        if(Mat[x][y+1]==piece)  {if (scout(x,y+1,num,Mat,L)==1) return 1;}} freelist(L);
    if (x!=8){
        if (Mat[x+1][y]==piece) {if (scout(x+1,y,num,Mat,L)==1) return 1;}} freelist(L);
    if (y!=0){
        if (Mat[x][y-1]==piece) {if (scout(x,y-1,num,Mat,L)==1) return 1;}} freelist(L);
    if (x!=0){
        if (Mat[x-1][y]==piece) {if (scout(x-1,y,num,Mat,L)==1) return 1;}} freelist(L);
    return 0;
}

int Save_Capture(char Mat[10][10],int *numplayer, List L){
    char pieceA,pieceB;
    int check;
    if (numplayer==1) {pieceA='X'; pieceB='O';} else {pieceA='O'; pieceB='X';}
    for(int i=0;i<9;i++){
        for(int e=0;e<9;e++){
            check = Check_AI(Mat,i,e,numplayer,L);
            if (check==1) return 1;
            if (check==2) {
            NextPlayer(numplayer);
            Mat[i][e]=pieceB;
            if (check_scout(i,e,*numplayer,Mat,L,pieceA)) {NextPlayer(numplayer); Mat[i][e]=pieceA; goban(Mat); return 1;}
            Mat[i][e]=' ';}}}
    return 0;
}

char Matrix[10][10]=   {"IEI      ","EA       ","EAE      ","IEI      ","         ","         ","         ","         ","         ","321200 A  "};
char tsumego_1[10][10]={"   EA    ","EEEEA    ","AAAAI    ","         ","         ","         ","         ","         ","         ","240100 A  "};
char tsumego_2[10][10]={"   AE    ","AAAAE    ","EEEEI    ","         ","         ","         ","         ","         ","         ","240100 A  "};
char tsumego_3[10][10]={"AAAAA    ","AEEEA    ","EE EA    ","EAEEA    ","EAEA     ","A  A     ","         ","         ","         ","545200 A  "};
char tsumego_4[10][10]={"EEE      ","E EA     ","AEEA     ","AAAI     ","         ","         ","         ","         ","         ","331100 A  "};
char tsumego_5[10][10]={"E E      ","E EA     ","AEEA     ","AAAI     ","         ","         ","         ","         ","         ","330300 A  "};
char TempMatrix[10][10]={"         ","         ","         ","         ","         ","         ","         ","         ","         ","         "};


int GO_AI_Medium(char Mat[10][10],char Matrix[10][10],char Tem[10][10],int *numplayer, List L,int *pass){
    if (TSUMEGO(Mat,tsumego_1,TempMatrix,numplayer)) {*pass=0; return 12;}
    if (TSUMEGO(Mat,tsumego_2,TempMatrix,numplayer)) {*pass=0; return 12;}
    if (TSUMEGO(Mat,tsumego_3,TempMatrix,numplayer)) {*pass=0; return 12;}
    if (TSUMEGO(Mat,tsumego_4,TempMatrix,numplayer)) {*pass=0; return 12;}
    if (TSUMEGO(Mat,tsumego_5,TempMatrix,numplayer)) {*pass=0; return 12;}
    if (Save_Capture(Mat,numplayer,L)) {*pass=0; return 12;}
    return GO_AI(Mat,numplayer,L,pass);
}
