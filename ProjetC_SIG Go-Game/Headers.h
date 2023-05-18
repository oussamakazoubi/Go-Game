

typedef struct _intersection{
     int lin;
     int col;
     struct _intersection* next;
     } intersection;

typedef intersection* List;



// Display
void Color(int,int);
void gogame();
void rectangle(char sentence[]);
void gobanpieces(char Mat[10][10],int);
void goban(char Mat[10][10]);
int Menu();
int Play();
int Machine();
int Rules();
void print_board();


// Process
void Recieve_Input(char input[4],int numplayer);
int Validate_Input(char T[5]);
void NextPlayer(int *numplayer);
void Add_Intersection(List Q, List L);
void freelist(List L);
int isInside(int x,int y,List L);
int scout(int x,int y,int num,char Mat[10][10],List L);
void Matrix_Capture(char Mat[10][10],List L);
int reverse_scout(int x,int y,int num,char Mat[10][10],List L);
int Check_Affect(char Mat[10][10],int x,int y,int *numplayer, List L);
void Matrix_Remove(char Mat[10][10]);
void surround(char Mat[10][10],int x,int y,List L,int *black,int *white);
void neutren(char Mat[10][10],List L);
void blacken(char Mat[10][10],List L);
void whiten(char Mat[10][10],List L);
void territory(char Mat[10][10],List L);
void claim_territory(char Mat[10][10],List L);
int Endgame(char Mat[10][10],List L);
int GO(char Mat[10][10],char input[4],int diff,int *numplayer, List L,int *pass);
void deleteLine(FILE *src, FILE *temp,int line);
void Save(char Mat[10][10],int diff,int numplayer,int pass);
int Load(char Mat[10][10],int *diff,int *numplayer,int *pass);


//AI
int random(int min, int max);
int Check_AI(char Mat[10][10],int x,int y,int *numplayer, List L);
int GO_AI(char Mat[10][10],int *numplayer, List L,int *pass);
void Rotate(char Matrix[10][10],char TempMatrix[10][10]);
void Copy(char Matrix[10][10],char TempMatrix[10][10]);
void Empty_Matrix(char Matrix[10][10]);
void Convert(char Mat[10][10],char Let);
int TSU(char Mat[10][10],char Tem[10][10]);
int TSUME(char Mat[10][10],char Tem[10][10]);
int TSUMEGO(char Mat[10][10],char Matrix[10][10],char Tem[10][10],int *numplayer);
int check_scout(int x,int y,int num,char Mat[10][10],List L,char piece);
int Save_Capture(char Mat[10][10],int *numplayer, List L);
int GO_AI_Medium(char Mat[10][10],char Matrix[10][10],char Tem[10][10],int *numplayer, List L,int *pass);
