#include <windows.h>
#include <string.h>


    void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void gogame(){
    system("cls");
    Color(14,0);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@        @        @         @ @@@@@@@@          \n");
    printf("                                                                  @         @       @        @              @ @       @@       @@ @                 \n");
    printf("                                                                  @         @       @        @             @   @      @ @     @ @ @                 \n");
    printf("                                                                  @         @       @        @            @     @     @ @     @ @ @@@@@@@@          \n");
    printf("                                                                  @    @@@  @       @        @    @@@    @@@@@@@@@    @  @   @  @ @                 \n");
    printf("                                                                  @      @  @       @        @      @   @         @   @   @ @   @ @                 \n");
    printf("                                                                  @      @  @       @        @      @  @           @  @    @    @ @                 \n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@ @             @ @         @ @@@@@@@@          \n");
}



void rectangle(char phrase[])
{int longueur=strlen(phrase);
printf(" ");
    for (int i = 0; i < 105 - longueur ; i++) {
        printf(" ");
    }
    for (int i = 0; i < longueur + 2; i++) {
        printf("-");
    }
    printf(" \n");
    for (int i = 0; i < 105 - longueur ; i++) {
        printf(" ");
    }
    printf("| %s |\n", phrase);
    printf(" ");
    for (int i = 0; i < 105 - longueur ; i++) {
        printf(" ");
    }
    for (int i = 0; i < longueur + 2; i++) {
        printf("-");
    }
    printf(" \n");
}

void gobanpieces(char Mat[10][10],int i){
    for(int e=0;e<8;e++){
        if (Mat[i][e]=='X') Color(6,0); if (Mat[i][e]=='O') Color(3,0); if (Mat[i][e]=='N') Color(2,0);
        printf("%c",Mat[i][e]);
        Color(15,0);
        printf("-----");
    }
}


// goban prend une matrice et affiche la grille de la matrice
void goban(char Mat[10][10]){
    system("cls");
    Color(15,0);
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@        @        @         @ @@@@@@@@          \n");
    printf("                                                                  @         @       @        @              @ @       @@       @@ @                 \n");
    printf("                                                                  @         @       @        @             @   @      @ @     @ @ @                 \n");
    printf("                                                                  @         @       @        @            @     @     @ @     @ @ @@@@@@@@          \n");
    printf("                                                                  @    @@@  @       @        @    @@@    @@@@@@@@@    @  @   @  @ @                 \n");
    printf("                                                                  @      @  @       @        @      @   @         @   @   @ @   @ @                 \n");
    printf("                                                                  @      @  @       @        @      @  @           @  @    @    @ @                 \n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@ @             @ @         @ @@@@@@@@          \n");


    printf("\n\n");
    printf("                                                                                  1     2     3     4     5     6     7     8     9\n");
    printf("                                                                                A ");gobanpieces(Mat,0);if (Mat[0][8]=='X') Color(6,0); if (Mat[0][8]=='O') Color(3,0); if (Mat[0][8]=='N') Color(2,0); printf("%c\n",Mat[0][8]); Color(15,0);
    printf("                                                                                  |     |     |     |     |     |     |     |     |               _________________________\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                B ");gobanpieces(Mat,1);if (Mat[1][8]=='X') Color(6,0); if (Mat[1][8]=='O') Color(3,0); if (Mat[1][8]=='N') Color(2,0); printf("%c",Mat[1][8]);Color(15,0);printf("              |  0 - Pass               | \n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                C ");gobanpieces(Mat,2);if (Mat[2][8]=='X') Color(6,0); if (Mat[2][8]=='O') Color(3,0); if (Mat[2][8]=='N') Color(2,0); printf("%c",Mat[2][8]);Color(15,0);printf("              |  1 - Return             |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                D ");gobanpieces(Mat,3);if (Mat[3][8]=='X') Color(6,0); if (Mat[3][8]=='O') Color(3,0); if (Mat[3][8]=='N') Color(2,0); printf("%c",Mat[3][8]);Color(15,0);printf("              |  2 - Main Menu          |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |                         |\n");
    printf("                                                                                E ");gobanpieces(Mat,4);if (Mat[4][8]=='X') Color(6,0); if (Mat[4][8]=='O') Color(3,0); if (Mat[4][8]=='N') Color(2,0); printf("%c",Mat[4][8]);Color(15,0);printf("              |  3 - Exit               | \n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |              |_________________________|  \n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                F ");gobanpieces(Mat,5);if (Mat[5][8]=='X') Color(6,0); if (Mat[5][8]=='O') Color(3,0); if (Mat[5][8]=='N') Color(2,0); printf("%c\n",Mat[5][8]);Color(15,0);
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                G ");gobanpieces(Mat,6);if (Mat[6][8]=='X') Color(6,0); if (Mat[6][8]=='O') Color(3,0); if (Mat[6][8]=='N') Color(2,0); printf("%c\n",Mat[6][8]);Color(15,0);
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                H ");gobanpieces(Mat,7);if (Mat[7][8]=='X') Color(6,0); if (Mat[7][8]=='O') Color(3,0); if (Mat[7][8]=='N') Color(2,0); printf("%c\n",Mat[7][8]);Color(15,0);
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                  |     |     |     |     |     |     |     |     |\n");
    printf("                                                                                I ");gobanpieces(Mat,8);if (Mat[8][8]=='X') Color(6,0); if (Mat[8][8]=='O') Color(3,0); if (Mat[8][8]=='N') Color(2,0); printf("%c\n",Mat[8][8]);Color(15,0);
    }

int Menu(){
    int value;
    system("cls");
    Color(14,0);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@        @        @         @ @@@@@@@@          \n");
    printf("                                                                  @         @       @        @              @ @       @@       @@ @                 \n");
    printf("                                                                  @         @       @        @             @   @      @ @     @ @ @                 \n");
    printf("                                                                  @         @       @        @            @     @     @ @     @ @ @@@@@@@@          \n");
    printf("                                                                  @    @@@  @       @        @    @@@    @@@@@@@@@    @  @   @  @ @                 \n");
    printf("                                                                  @      @  @       @        @      @   @         @   @   @ @   @ @                 \n");
    printf("                                                                  @      @  @       @        @      @  @           @  @    @    @ @                 \n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@ @             @ @         @ @@@@@@@@          \n");


    printf("\n\n");

    printf("                                                                          __________________________________________________\n");


    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 1 - New Game                     |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 2 - Load Game                    | \n");
    printf("                                                                         |                                                  |\n");
    Color(12,0);
    printf("                                                                         |                 3 - Game Rules                   |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 4 - Quit                         |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |__________________________________________________|\n");
    printf("                                                                                          Entrer un nombre : ");
    value=getch();
    value-=48;
    if (value>4 || value<1) return 0;
    return value;
}

int Play(){
    int value;
    system("cls");
    Color(14,0);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@        @        @         @ @@@@@@@@          \n");
    printf("                                                                  @         @       @        @              @ @       @@       @@ @                 \n");
    printf("                                                                  @         @       @        @             @   @      @ @     @ @ @                 \n");
    printf("                                                                  @         @       @        @            @     @     @ @     @ @ @@@@@@@@          \n");
    printf("                                                                  @    @@@  @       @        @    @@@    @@@@@@@@@    @  @   @  @ @                 \n");
    printf("                                                                  @      @  @       @        @      @   @         @   @   @ @   @ @                 \n");
    printf("                                                                  @      @  @       @        @      @  @           @  @    @    @ @                 \n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@ @             @ @         @ @@@@@@@@          \n");


    printf("\n\n");
    printf("                                                                           __________________________________________________\n");


    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 1 - Player Vs Machine            |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 2 - Player Vs Player             | \n");
    printf("                                                                         |                                                  |\n");
    Color(12,0);
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 3 - Return                       |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |__________________________________________________|\n");
    printf("                                                                                          Entrer un nombre : ");
    Color(14,0);
    value=getch();
    value-=48;
    if (value==1) return 5;
    if (value==2) return 10;
    if (value==3) return 0;
    if (value>4 || value<1) return 1;
}


int Machine(){
    int value;
    system("cls");
    Color(14,0);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@        @        @         @ @@@@@@@@          \n");
    printf("                                                                  @         @       @        @              @ @       @@       @@ @                 \n");
    printf("                                                                  @         @       @        @             @   @      @ @     @ @ @                 \n");
    printf("                                                                  @         @       @        @            @     @     @ @     @ @ @@@@@@@@          \n");
    printf("                                                                  @    @@@  @       @        @    @@@    @@@@@@@@@    @  @   @  @ @                 \n");
    printf("                                                                  @      @  @       @        @      @   @         @   @   @ @   @ @                 \n");
    printf("                                                                  @      @  @       @        @      @  @           @  @    @    @ @                 \n");
    printf("                                                                  @@@@@@@@  @@@@@@@@@        @@@@@@@@ @             @ @         @ @@@@@@@@          \n");


    printf("\n\n");
  printf("                                                                           __________________________________________________\n");


    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 1 - Easy                         |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 2 - Medium                       | \n");
    printf("                                                                         |                                                  |\n");
    Color(12,0);
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |                 3 - Return                       |\n");
    printf("                                                                         |                                                  |\n");
    printf("                                                                         |__________________________________________________|\n");
    printf("                                                                                          Entrer un nombre : ");
    Color(14,0);
    value=getch();
    value-=48;
    if (value==1) return 12;
    if (value==2) return 13;
    if (value==3) return 1;
    if (value>4 || value<1) return 5;
}


// cette fonction afficher les regles de jeu :
int Rules(){
    system("cls");

    // D�finir le plateau de jeu (goban) comme une matrice de caract�res
    char goban[10][10];

    // Initialiser toutes les intersections du goban � un point ('.')
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            goban[i][j] = '.';
        }
    }

    // Placer les pierres initiales au centre du goban
    goban[4][4] = 'O';
    goban[4][5] = 'X';
    goban[5][4] = 'X';
    goban[5][5] = 'O';

    // Afficher les r�gles du jeu et le goban
    printf("\nREGLES DU JEU GO\n\n");
Color(14,0);
    printf("Le jeu de Go est un jeu de strat�gie pour deux joueurs, o� l'objectif est de contr�ler un maximum de territoire sur un plateau de jeu de 19x19 intersections.\n\n");

    printf("Les joueurs placent a tour de r�le des pierres de leur couleur sur les intersections libres du plateau, dans le but de former des groupes de pierres qui entourent des territoires vides.\n");

    printf("Les pierres captur�es sont retir�es du plateau et ajout�es � la r�serve du joueur qui les a captur�es.\n\n");
Color(0,8);
    printf("====>Liberties\n");
Color(6,0);
    printf("In the game of Go, the concept of liberties refers to the number of empty points surrounding a stone on the board. A stone with no liberties is considered ----captured----- and removed from the board. The number of liberties a stone has can change as other stones are placed or removed from the board, and can have a significant impact on the outcome of the game. Therefore, players need to be strategic in their placement of stones to create chains with multiple liberties and to cut off their opponent's liberties. The concept of liberties is central to understanding the tactics and strategies of the game of Go.\n");
Color(5,15);
printf("====>Exemple\n");
Color(5,0);
#define SIZE 9

int board[SIZE][SIZE]; // matrice repr�sentant le plateau de jeu

void init_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0; // initialiser toutes les cases � 0 (case vide)
        }
    }
}

void print_board() {
    printf("  ");
    for (int i = 1; i <= SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("o "); // afficher un pion noir
            } else if (board[i][j] == 2) {
                printf("x "); // afficher un pion blanc
            } else {
                printf(". "); // afficher une case vide
            }
        }
        printf("\n");
    }
}

    init_board();
    board[2][2] = 1; // poser un pion noir � la case (2, 2)
    board[2][3] = 2; // poser un pion blanc � la case (2, 3)

    print_board();

    int liberties = 0; // initialiser le nombre de libert�s � 0
    int i = 2;
    int j = 2;

    // v�rifier les degr�s de libert� de la case (2, 2)
    if (i > 0 && board[i-1][j] == 0) {
        liberties++; // case � gauche est vide
    }
    if (i < SIZE-1 && board[i+1][j] == 0) {
        liberties++; // case � droite est vide
    }
    if (j > 0 && board[i][j-1] == 0) {
        liberties++; // case en haut est vide
    }
    if (j < SIZE-1 && board[i][j+1] == 0) {
        liberties++; // case en bas est vide
    }

    printf("Nombre de libertes : %d\n", liberties);
Color(0,8);
    printf("====>Forbidden move\n");
Color(11,14);
printf("       ====>The suicide:\n");
Color(6,0);
printf("rule in Go is an important rule to prevent players from making moves that would be detrimental to the game's outcome. The rule states that it is illegal to play a move that would leave one's own stones with no liberties unless doing so captures one or more opposing stones. For example, if a player were to play in a position where they had no liberties, they would be committing suicide and the move would be illegal. However, a player can play in a position where they appear to have no liberties if doing so would capture one or more of the opposing player's stones, as this would create a new liberty for their stones.\n");
Color(5,15);
printf("====>Exemple\n");
Color(5,0);
printf("  A B C D E F G H J\n");
printf("1 . . . . . . . . .\n");
printf("2 . . . . . . . . .\n");
printf("3 . . . . . . . . .\n");
printf("4 . . . . . . . . .\n");
printf("5 . . . . x . . . .\n");
printf("6 . . . x B x . . .\n");
printf("7 . . . . x . . . .\n");
printf("8 . . . . . . . . .\n");
printf("9 . . . . . . . . .\n");
Color(11,14);
printf("       ====>K.O rule:\n");
Color(6,0);
printf("The ko rule forbids a player from repeating a previous board position at any time during the game.\n");
printf("Here are three positions where Black and White can capture and recapture a stone: these are ko situations. If White captures a black stone by playing at the � point, Black is forbidden from immediately recapturing the white stone: he must play his next move elsewhere; if White does not connect the ko at �, Black will be able to recapture it.\n");
printf("This rule prevents endless captures and recaptures and can lead to **ko fight** with a cycle of capture, threat (the move played elsewhere), response to the threat, recapture, opponent's threat, and so on. These ko fights are one of the unique features of the game of Go.\n");
Color(5,15);
printf("====>Exemple\n");
Color(5,0);
printf("  A B C D E F G H J\n");
printf("1 . . . . . . . . .\n");
printf("2 . . . . . . . . .\n");
printf("3 . . . . . . . . .\n");
printf("4 . . . . . . . . .\n");
printf("5 . . . o x x . . .\n");
printf("6 . . . x . o . . .\n");
printf("7 . . . . o . . . .\n");
printf("8 . . . . . . . . .\n");
printf("9 . . . . . . . . .\n");
Color(6,0);
printf("In this example, the black player (B) plays at the F7 location, capturing the white stone there. However, the previous white move (at the E6 location) created an identical configuration, with the white stone at the F7 location being captured by the black move at the G6 location. Therefore, the black move at F7 is a KO and cannot be played immediately. The black player must first play a move elsewhere on the board before being allowed to return to F7. This helps to maintain balance in the game and avoid infinite repetitive capture sequences.\n");
Color(0,8);
    printf("====>Rule of Capture\n");
Color(6,0);
    printf("In the game of Go, when a stone has no liberties, meaning it is completely surrounded by the opponent's stones and cannot be played on any vacant intersection adjacent to it, it is captured and removed from the board. This rule is called the ---capture rule---. The stones that are captured are referred to as **prisoners** and they are kept aside to be counted towards the end of the game to determine the winner. The capture rule is an essential part of the game and is used to strategically limit the opponent's potential moves and create opportunities for oneself.\n");

Color(5,15);
printf("====>Exemple\n");
Color(5,0);
printf("  A B C D E F G H J\n");
printf("1 . . . . . . . . .\n");
printf("2 . . . . . . . . .\n");
printf("3 . . . . . . . . .\n");
printf("4 . . . . . . . . .\n");
printf("5 . . . . x . . . .\n");
printf("6 . . . x o . . . .\n");
printf("7 . . . . x . . . .\n");
printf("8 . . . . . . . . .\n");
printf("9 . . . . . . . . .\n");
Color(6,0);
printf("If white plays on Black's last liberty, he captures the stone.\n");Color(0,8);
Color(0,8);
    printf("====>Chain\n");
Color(6,0);
    printf("If a stone of the same color occupies one of the liberties of a stone, the two stones are connected and form a chain. The number of liberties of the chain is the total of adjacent free intersections\n");
Color(5,0);
printf("====>Exemple\n");
Color(5,0);
printf("  A B C D E F G H J\n");
printf("1 . . . . . . . . .\n");
printf("2 . . . . . . . . .\n");
printf("3 . . . . . . . . .\n");
printf("4 . . . x . o . . .\n");
printf("5 . . . o x x . . .\n");
printf("6 . . o x . . x . .\n");
printf("7 . . . o x . . . .\n");
printf("8 . . . . . . . . .\n");
printf("9 . . . . . . . . .\n");
Color(6,0);
printf("In this example, there are three black chains and four white chains. The connected stones are highlighted in black and white. The black stone at 3,3 and the white stones at 2,4 and 3,4 belong to two chains each.\n");

printf("To implement the chain rules in a program, you can store the information for each stone in a data structure (such as a two-dimensional array or a linked list), including fields for the stone's color and its neighboring coordinates. Then, you can traverse the array to find groups of stones of the same color that are adjacent and group them into chains.\n");
 Color(12,0);
 printf("Note that two diagonal intersections are not considered --adjacent--\n\n");
 Color(5,0);
printf("  A B C D E  F G H J\n");
printf("1 . . . . .  . . . .\n");
printf("2 . . . . .  . . . .\n");
printf("3 . . . . .  . . . .\n");
printf("4 . . . . .  . . . .\n");
printf("5 . . . . 1 . . . .\n");
printf("6 . x x x .  . . . .\n");
printf("7 . . . . .  . . . .\n");
printf("8 . . . . .  . . . .\n");
printf("9 . . . . .  . . . .\n");
Color(6,0);
printf("Stone 1 is not connected to the chain of three stones.\n");

   getch();
   return 0;
}


int Layout(int ipt){
    if (ipt==0) return Menu();
    if (ipt==1) return Play();
    if (ipt==2) return 2;
    if (ipt==3) return Rules();
    if (ipt==4) exit(EXIT_SUCCESS);
    if (ipt==5) return Machine();
    if (ipt>9)  return ipt;}
