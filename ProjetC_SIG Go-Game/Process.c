#include <stdio.h>
#include <stdlib.h>
#include "Display.c"



void Recieve_Input(char input[4],int numplayer){
    printf("                                                                                   Enter The coordinate or a corresponding number : ");
    if (numplayer) printf("\n                                                                                                Player %d : ",numplayer);
    fgets(input,4,stdin);
    if(!strchr(input, '\n'))     //newline does not exist
        while(fgetc(stdin)!='\n');//discard until newline
    input[strlen(input)-1]='\0';
}

int Validate_Input(char T[5]){  // T is the player's input;
    if (T[1]=='\0' && T[0]>47 && T[0]<58 ){return 1;}
    if (T[0]>96 && T[0]<123) T[0]+='A'-'a';
    if (T[1]>96 && T[1]<123) T[1]+='A'-'a';
    if (T[0]>48 && T[0]<58 && T[1]>64 && T[1]<74) {
            int temp=T[0];
            T[0]=T[1];
            T[1]=temp;
            return 2;}
    else if ((T[1]>48 && T[1]<58 && T[0]>64 && T[0]<74)) return 2;
    return 0;
}


void NextPlayer(int *numplayer){
    if (*numplayer==1) *numplayer=2;
    else *numplayer=1;
}


void Add_Intersection(List Q, List L){
    if (L->next!=NULL) {
        Add_Intersection(Q,L->next);
        return ;}
    L->next = Q;}


void freelist(List L){
    if (L->next!=NULL) freelist(L->next);
    L->next=NULL;
}
int isInside(int x,int y,List L){
    if (L==NULL) return 0;
    if (x!=L->lin || y!=L->col){
        if (L->next==NULL) return 0;
        return isInside(x,y,L->next);}
    return 1;
}

int scout(int x,int y,int num,char Mat[10][10],List L){
    char piece;
    if (num==1) piece='X';
    else piece='O';
    List Q ;
    Q = (List)malloc(sizeof(intersection));
    Q->lin = x;
    Q->col = y;
    Q->next=NULL;
    if (!isInside(x,y,L)){
        Add_Intersection(Q,L);
        if (y!=8){
            if(Mat[x][y+1]==' ')  return 0;
            if(Mat[x][y+1]==piece)  {if (scout(x,y+1,num,Mat,L)==0) return 0;}}
        if (x!=8){
            if (Mat[x+1][y]==' ') return 0;
            if (Mat[x+1][y]==piece) {if (scout(x+1,y,num,Mat,L)==0) return 0;}}
        if (y!=0){
            if (Mat[x][y-1]==' ') return 0;
            if (Mat[x][y-1]==piece) {if (scout(x,y-1,num,Mat,L)==0) return 0;}}
        if (x!=0){;
            if (Mat[x-1][y]==' ') return 0;
            if (Mat[x-1][y]==piece) {if (scout(x-1,y,num,Mat,L)==0) return 0;}}
    }
    if (L->next!=NULL) {if ((L->next)->next==NULL && L->lin==-2) {L->lin=x;L->col=y;}}
    return 1;}


void Matrix_Capture(char Mat[10][10],List L){
    Sleep(40);
    if (L!=NULL){
        Mat[L->lin][L->col]=' ';
        goban(Mat);
        if (L->next!=NULL) Matrix_Capture(Mat,L->next);}}

int reverse_scout(int x,int y,int num,char Mat[10][10],List L){
    freelist(L);
    char piece;
    int result=0;
    int KO=0;
    if (num==1) {
            piece='O';
            num=2;}
    else {
            piece='X';
            num=1;}
    if (x==L->lin && y==L->col) KO=1 ;
    L->lin=-2;
    if (y!=8){
        if(Mat[x][y+1]==piece)  {if (scout(x,y+1,num,Mat,L)) {if (KO) {L->lin=x; L->col=y; freelist(L); return -1;} Matrix_Capture(Mat,L->next); result=1;} freelist(L);}}
    if (x!=8){
        if (Mat[x+1][y]==piece) {if (scout(x+1,y,num,Mat,L)) {if (KO) {L->lin=x; L->col=y; freelist(L); return -1;} Matrix_Capture(Mat,L->next); result=1;} freelist(L);}}
    if (y!=0){
        if (Mat[x][y-1]==piece) {if (scout(x,y-1,num,Mat,L)) {if (KO) {L->lin=x; L->col=y; freelist(L); return -1;} Matrix_Capture(Mat,L->next); result=1;} freelist(L);}}
    if (x!=0){
        if (Mat[x-1][y]==piece) {if (scout(x-1,y,num,Mat,L)) {if (KO) {L->lin=x; L->col=y; freelist(L); return -1;} Matrix_Capture(Mat,L->next); result=1;} freelist(L);}}
    if (L->lin==-2) L->lin=-1;
    return result;
}

int Check_Affect(char Mat[10][10],int x,int y,int *numplayer, List L){
    int revsct;
    if (Mat[x][y]!=' '){
        goban(Mat);
        rectangle("Intersection Full");
        return 0;}
    if (*numplayer==1) Mat[x][y]='X';
    else Mat[x][y]='O';
    revsct=reverse_scout(x,y,*numplayer,Mat,L);
    if (!revsct){
        if (scout(x,y,*numplayer,Mat,L)==1) {
            Mat[x][y]=' ' ;
            goban(Mat);
            rectangle("ILLEGALE : SUICIDE ! ");
            return 0;}}
    if (revsct==-1) {
        Mat[x][y]=' ' ;
        goban(Mat);
        rectangle("ILLEGALE : KO !");
        return 0;}
    freelist(L);
    return 1;
}

void Matrix_Remove(char Mat[10][10]){
    char input[4];
    goban(Mat);
    Recieve_Input(input,0);
    do{
        goban(Mat);
        printf("     Removing Process \n");
        if (!Validate_Input(input)) printf("        Invalid Input !\n");
        if (Validate_Input(input)==1 && input[0]-48==0 ) return;
        Recieve_Input(input,0);
            }while(Validate_Input(input)!=2);
    Mat[input[0]-65][input[1]-49]=' ';}



void surround(char Mat[10][10],int x,int y,List L,int *black,int *white){
    List Q = (List)malloc(sizeof(intersection));
    Q->lin = x;
    Q->col = y;
    Q->next=NULL;
    if (!isInside(x,y,L)){
        Add_Intersection(Q,L);
        if (!*black){
        if (y!=8){
            if(Mat[x][y+1]=='X')  *black=1;
            if(Mat[x][y+1]==' ')  surround(Mat,x,y+1,L,black,white);}
        if (x!=8){
            if(Mat[x+1][y]=='X')  *black=1;
            if(Mat[x+1][y]==' ')  surround(Mat,x+1,y,L,black,white);}
        if (y!=0){
            if(Mat[x][y-1]=='X')  *black=1;
            if(Mat[x][y-1]==' ')  surround(Mat,x,y-1,L,black,white);}
        if (x!=0){;
            if(Mat[x-1][y]=='X')  *black=1;
            if(Mat[x-1][y]==' ')  surround(Mat,x-1,y,L,black,white);}}
        if (!*white){
        if (y!=8){
            if(Mat[x][y+1]=='O')  *white=1;
            if(Mat[x][y+1]==' ')  surround(Mat,x,y+1,L,black,white);}
        if (x!=8){
            if(Mat[x+1][y]=='O')  *white=1;
            if(Mat[x+1][y]==' ')  surround(Mat,x+1,y,L,black,white);}
        if (y!=0){
            if(Mat[x][y-1]=='O')  *white=1;
            if(Mat[x][y-1]==' ')  surround(Mat,x,y-1,L,black,white);}
        if (x!=0){;
            if(Mat[x-1][y]=='O')  *white=1;
            if(Mat[x-1][y]==' ')  surround(Mat,x-1,y,L,black,white);}}
    }
}

void neutren(char Mat[10][10],List L){
    if (L!=NULL) {Mat[L->lin][L->col]='N'; neutren(Mat,L->next);}}

void blacken(char Mat[10][10],List L){
    if (L!=NULL) {Mat[L->lin][L->col]='X'; blacken(Mat,L->next);}}

void whiten(char Mat[10][10],List L){
    if (L!=NULL) {Mat[L->lin][L->col]='O'; whiten(Mat,L->next);}}

void territory(char Mat[10][10],List L){
    int black=0,white=0;
    for(int i=0;i<=8;i++){
        for(int e=0;e<=8;e++){
            if (Mat[i][e]==' '){
                surround(Mat,i,e,L,&black,&white);
                if (black && white) neutren(Mat,L->next);
                else if (black) blacken(Mat,L->next);
                else if (white) whiten(Mat,L->next);
                freelist(L);}
                black=0; white=0;}
                }
}

void claim_territory(char Mat[10][10],List L){
    for(int i=0;i<9;i++){
        for(int e=0;e<9;e++){
            if (Mat[i][e]==' ') {
                Mat[i][e]='X';
                if (scout(i,e,1,Mat,L)) {Matrix_Capture(Mat,L->next); freelist(L);continue;}
                freelist(L);
                if (scout(i,e,2,Mat,L)) {Matrix_Capture(Mat,L->next); freelist(L);continue;}
                freelist(L); Mat[i][e]=' ';}}}}

int Endgame(char Mat[10][10],List L){
    float black=0,white=0;
    char value='1';
    Matrix_Remove(Mat);
    //claim_territory(Mat,L);
    territory(Mat,L);
    for(int i=0;i<=8;i++){
        for(int e=0;e<=8;e++){
            if (Mat[i][e]=='X') black++;
            if (Mat[i][e]=='O') white++;}}
    white+=7.5;
    goban(Mat);
    printf("\n\n\n\n\                                                                                     Black Has %.1f Points   White Has %.1f Points  \n\n\n",black,white);
    if (white>black) printf("                                                                                                     White Won\n\n");
    else printf("                                                                                                                 Black Won\n\n");
    printf("                                                                                             Press 0 To Return To Main Menu");
    while (value!='0') value=getch();
    return 0;
}



int GO(char Mat[10][10],char input[4],int diff,int *numplayer, List L,int *pass){
    int x,y;
    if (*pass==2) return Endgame(Mat,L);
    Recieve_Input(input,*numplayer);
    if (!Validate_Input(input)){
        goban(Mat);
        rectangle("Invalid Input !");
        return 11;}
    if (Validate_Input(input)==1){
        if (input[0]-48==0){
            (*pass)+=1;
            goban(Mat);
            printf("                                                                                                -----------------------\n");
            printf("                                                                                               | Player %d Has Passed ! |  \n",*numplayer);
            printf("                                                                                                -----------------------\n");
            NextPlayer(numplayer);
            return 10;}
        if (input[0]-48==1) {Save(Mat,diff,*numplayer,*pass); return 1;}
        if (input[0]-48==2) {Save(Mat,diff,*numplayer,*pass); return 0;}
        if (input[0]-48==3) {Save(Mat,diff,*numplayer,*pass); exit(EXIT_SUCCESS);}
    }
    x=input[0]-65 , y=input[1]-49;
    if (!Check_Affect(Mat,x,y,numplayer,L)) return 11;
    NextPlayer(numplayer);
    *pass=0;
    goban(Mat);
    return 10;
}
void deleteLine(FILE *src, FILE *temp,int line){
   char buffer[100];
   int count = 1;
   while ((fgets(buffer, 100, src)) != NULL){
      if (line != count)
         fputs(buffer, temp);
      count++;}
}

void Save(char Mat[10][10],int diff,int numplayer,int pass){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                                            Do You Want To Save Your Game : \n\n");
    printf("                                                                                                     1 - Yes\n");
    printf("                                                                                                     2 - No\n");
    int value=0;
    char namesave[15];
    while(value!=1 && value!=2) value=getch()-48;
    if (value==1){
    printf("                                                                                                 Name your Save : ");
    fgets(namesave,15,stdin); if(!strchr(namesave,'\n')) {while(fgetc(stdin)!='\n'); namesave[14]='\n';}
    FILE* file;
    file = fopen("Saves.txt","a");
    char ligne[100];
    ligne[0]=diff+48; ligne[1]=numplayer+48; ligne[2]=pass+48;
    int index=3;
    for(int i=0;i<9;i++){
        for(int e=0;e<9;e++){
            ligne[index]=Mat[i][e]; index++;}}
    int i=0;
    while (namesave[i]!='\n' && namesave[i]!='\0'){
        ligne[index]=namesave[i];
        index++; i++;}
    ligne[index]='\n';
    fputs(ligne,file);
    fclose(file);}
}

int Load(char Mat[10][10],int *diff,int *numplayer,int *pass){
    system("cls");
    Color(15,0);
    int value=-1;
    int num=0;
    int index=3;
    int temp=0;
    int i;
    FILE* file;
    FILE* tempfile;
    file = fopen("Saves.txt","r");
    char ligne[100];
    printf("\n\n\n\n\n\n\n\n\n\n                                                                              LOADING : \n\n\n");
    printf("                                                                     0 - Return\n");
    while (fgets(ligne,100,file)) {
        num++;
        printf("                                                                     %d - ",num);
        i=83;
        switch(ligne[0]-48) {
            case 0 : printf("Player Vs Player   :  "); break;
            case 1 : printf("PlayerVsAI ; Easy  :  "); break;
            case 2 : printf("PlayerVsAI ; Hard  :  "); break;}
            while (ligne[i]!='\n') {printf("%c",ligne[i]); i++;}
            printf("\n");}
    fclose(file);
    while (value<0 || value>num) {value=getch(); value-=48;}
    if (value==0) return 0;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");printf("                                           1 - Load");printf("                                          2 - Delete");printf("                                          3 - return");
    while (temp<1 || temp>3) temp=getch()-48;
    if (temp==3) return 2;
    file = fopen("Saves.txt","r");
    if (temp==2) {tempfile = fopen("delete.txt", "w"); deleteLine(file,tempfile,value); fclose(tempfile); fclose(file) ;remove("Saves.txt"); rename("delete.txt", "Saves.txt"); return 0;}
    if (temp==1){
    for(int i=1;i<=value;i++) fgets(ligne,100,file);
    for(int i=0;i<9;i++){
        for(int e=0;e<9;e++){
            Mat[i][e]=ligne[index];
            index++;}}
    *numplayer = ligne[1]-48;
    *pass = ligne[2]-48;
    fclose(file);
    switch(ligne[0]-48) {
        case 0 : *diff=0; return 10;
        case 1 : *diff=1; return 12;
        case 2 : *diff=2; return 12;}}
}
