#include "v_do_check.h"
#include "input&output.h"
#include "players_turns.h"

void saving( FILE* game )
{
    if (game != NULL)
    {
        fwrite(&game_mode, sizeof(int), 1, game);
        fwrite(v_lines, sizeof(int), 30, game);
        fwrite(h_lines, sizeof(int), 30, game);
        fwrite(boxes, sizeof(int), 25, game);
        fwrite(&p1, sizeof(struct player), 1, game);
        fwrite(&p2, sizeof(struct player), 1, game);
        fwrite(&turn, sizeof(int), 1, game);
        fwrite(dots ,sizeof(int) , 36 , game);
        fwrite(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully saved.\n");
    }
    else
    {
        printf("Error opening file for saving.\n");
    }
}

void reading( FILE* game )
{
    if (game != NULL)
    {
        fread(&game_mode, sizeof(int), 1, game);
        fread(v_lines, sizeof(int), 30, game);
        fread(h_lines, sizeof(int), 30, game);
        fread(boxes, sizeof(int), 25, game);
        fread(&p1, sizeof(struct player), 1, game);
        fread(&p2, sizeof(struct player), 1, game);
        fread(&turn, sizeof(int), 1, game);
        fread(dots ,sizeof(int) , 36 , game);
        fread(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully reload.\n");
        if (game_mode == 1)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            one_player_game();
        }
        else if (game_mode == 2)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            two_player_game();
        }
    }
    else
    {
        printf("Error opening file for reload.\n");
    }
}
int save_game(){

    printf("1_file1\n2_file2\n3_file3\n"); int choise ; scanf("%d" , &choise) ;
    switch (choise)
    {
    case 1:
        FILE *game1 = fopen("game1.bin", "wb");
        saving( game1 ) ;
        break;
    case 2:
        FILE *game2 = fopen("game2.bin", "wb");
        saving( game2 ) ;
        break;
    case 3:
        FILE *game3 = fopen("game3.bin", "wb");
        saving(game3) ;
        break;
    default:
        printf("invalid input!\n") ;
        break;
    }
    return turn ; 
}
void load_game(){
    printf("1_file1\n2_file2\n3_file3\n") ; int choise ; scanf("%d" , &choise ) ;
    switch (choise)
    {
    case 1:
        FILE *game1 = fopen("game1.bin", "ab+");
        reading(game1);
        break;
    case 2:
        FILE *game2 = fopen("game2.bin", "ab+");
        reading(game2);
        break;
    case 3:
        FILE *game3 = fopen("game3.bin", "ab+");
        reading(game3);
        break;
    default:
        printf("invalid input!\n") ;
        break;
    }
}