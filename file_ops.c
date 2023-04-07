#include <stdio.h>
#include <stdlib.h>

void menu();
void add_file();
void edit_file();
void remove_file();

int main(){
  menu();
}

void remove_file(){
  printf("\n");

  char fname[32];

  fflush(stdin);
  printf("Enter filename to be removed: ");
  scanf("%s", &fname);
  
  if(remove(fname) == 0){
    printf("File %s was deleted successfully.\n", fname);
  }
  else{
    printf("Errror: Deletion of file %s was unsuccessful.\n", fname);
  }
  
  menu();
}

void search_file(){
  printf("\n");
  
  char str[12];

  fflush(stdin);
  printf("Enter filename to search: ");
  scanf("%s", &str);
 
  FILE *fsearch;
  fsearch = fopen(str, "r");

  if(NULL == fsearch){
    printf("File %s not found.\n", str);
  }
  else{
    printf("File %s was found in directory.\n", str);
  }

  fclose(fsearch);
}

void edit_file(){
  printf("\n");

  char which_file[32];

  printf("Note: If file is not found, a file will be created.\n");
  
  printf("\n");

  fflush(stdin);
  printf("Enter filename to be edited: ");
  scanf("%s", &which_file);

  printf("\n");

  int which_mode;

  printf("1. Append\n");
  printf("2. Overwrite\n");

  printf("\n");

  fflush(stdin);
  printf("Enter which mode: ");
  scanf(" %d", &which_mode);

  FILE *fpoints;
 
  switch(which_mode){
    case 1:
      fpoints = fopen(which_file, "a");
      break;
    case 2:
      fpoints = fopen(which_file, "w");
      break;
    default:
      printf("Error: Invalid input.\n");
      edit_file();
  }

  int hm_lines;

  fflush(stdin);
  printf("Enter how many lines to write: ");
  scanf(" %d", &hm_lines);

  char what_input[64];
  int MAX = 64;

  fflush(stdin);
  for(int i = 0; i < hm_lines; i++){
    printf("Add_Line [%d]: ", i+1);
    fflush(stdin);
    fgets(what_input, 64, stdin);
    if(fprintf(fpoints, "%s", what_input) != 0){
      printf("Add_Line %d successfully written.\n", (i) + 1);
    }
    else{
      printf("Error: Add_Line %d cannot be written.\n", (i) + 1);
    }
  }
  
  printf("Operation complete.\n");

  fclose(fpoints);

  menu();
}

void add_file(){
  printf("\n");

  char filename[32];

  fflush(stdin);
  printf("Enter filename to be added: ");
  scanf("%s", &filename);

  FILE *fptr = fopen(filename, "w");

  if(NULL == fptr){
    printf("File %s not created successfully.\n", filename);
    menu();
  }
  else{
    printf("File %s created successfully.\n", filename);
  }
  
  fclose(fptr);

  menu();
}

void menu(){
  printf("\n");

  printf("1. Add\n");
  printf("2. Edit\n");
  printf("3. Search\n");
  printf("4. Remove\n");
  printf("5. Exit\n");

  printf("\n");

  int input = 0;

  fflush(stdin);
  printf("Input: ");
  scanf(" %d", &input);

  switch(input){
    case 1:
      add_file();
      break;
    case 2:
      edit_file();
      break;
    case 3:
      search_file();
      break;
    case 4:
      remove_file();
      break;
    case 5:
      printf("\n");
      printf("Exiting...\n");
      exit(1);
    default:
      printf("Invalid input\n");
  }
}

/*
⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣶⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣰⣿⠟⠁⠀⠀⠉⠻⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⡿⠋⠁⠀⠀⠈⢻⣿⡄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣿⡟⠀⠀⠀⠀⠀⠀⠀⠙⢿⣷⣄⢀⣀⣤⣴⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣀⢀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀
⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠟⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠇⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⠀⠀⠀⠀⠀
⠀⠀⠀⢠⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣷⡀⠀⠀⠀
⠀⠀⢠⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣷⡀⠀⠀
⠀⢀⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣧⠀⠀
⠀⣼⣿⣿⣿⣿⣿⣿⣿⠂⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⡆⠀
⢠⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⠀
⢸⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⡆
⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⡇
⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⢿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⠿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡇
⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠖⠚⠛⠙⠓⠲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡇
⢿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇
⢸⣿⣿⣿⣿⣿⠒⠒⠒⠲⠶⠤⢤⣄⣀⠀⠀⠀⠀⠀⠀⢀⡼⠁⠀⠀⢀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⣀⣠⡤⠤⠶⠖⠒⠒⢲⣿⣿⣿⣿⣿⠃
⠈⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠉⠙⠲⣄⡀⠀⢀⡞⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠈⢧⠀⠀⢀⡤⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⡿⠀
⠀⢹⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡾⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠈⢧⠴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⠃⠀
⠀⠀⢿⣿⣿⣿⣿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⡟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⡏⠀⠀
⠀⠀⠈⢿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⢀⣿⣇⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⡟⠀⠀⠀
⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⡟⠛⢛⣛⣛⣛⣛⡛⠛⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⠟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠈⠁⠙⠁⠉⠀⠀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣄⣀⣀⣀⣀⣠⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠻⠿⠿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠋⠉⠀⠀
*/
