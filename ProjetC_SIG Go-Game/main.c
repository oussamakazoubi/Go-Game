#include "AI.c"

int main()
{
    srand(time(0));
    char input[4];
    char Mat[10][10]={"         ","         ","         ","         ","         ","         ","         ","         ","         "};
    int nav=0;
    int numplayer=1;
    int pass=0; int turn=0;
    List L = (List)malloc(sizeof(intersection));
    L->lin=-1; L->col=-1;
    L->next=NULL;
    int diff=0;
    while (1){
        if (nav<10) {nav=Layout(nav); Empty_Matrix(Mat) ; numplayer=1; turn=0; pass=0; diff=0; if (nav==2) {nav=Load(Mat,&diff,&numplayer,&pass); goban(Mat); turn++;}}
        if (nav==13){diff=2; nav=12;}
        if (nav==12 && turn==0){if (diff==0) diff=1; turn=random(0,1); if (turn==0) nav=GO_AI(Mat,&numplayer,L,&pass); turn++;}
        if (nav>9 && turn==0) {goban(Mat); turn++;}
        if ((nav==10 || nav==11) && diff==0) nav = GO(Mat,input,diff,&numplayer,L,&pass);
        if (nav==10 && diff==1) nav = GO_AI(Mat,&numplayer,L,&pass);
        if (nav==10 && diff==2) nav=GO_AI_Medium(Mat,Matrix,TempMatrix,&numplayer,L,&pass);
        if ((nav==11 || nav==12) && diff>0) nav = GO(Mat,input,diff,&numplayer,L,&pass);}
    return 0;
}
