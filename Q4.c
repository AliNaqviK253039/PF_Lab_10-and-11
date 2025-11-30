#include <stdio.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void copyString(char dest[], char src[]){
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void addMovie(struct Movie movies[], int *count){
    char temp[100];
    printf("Enter movie title: ");
    scanf(" %[^\n]", temp);
    copyString(movies[*count].title, temp);

    printf("Enter genre: ");
    scanf(" %[^\n]", temp);
    copyString(movies[*count].genre, temp);

    printf("Enter director: ");
    scanf(" %[^\n]", temp);
    copyString(movies[*count].director, temp);

    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter rating (0-10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("\nMovie added successfully!\n");
}

void displayMovie(struct Movie m){
    printf("\nTitle: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Director: %s\n", m.director);
    printf("Release Year: %d\n", m.releaseYear);
    printf("Rating: %.1f\n", m.rating);
}

void displayAllMovies(struct Movie movies[], int count){
    if(count == 0){
        printf("\nNo movies to display.\n");
        return;
    }
    int i;
    for(i = 0; i < count; i++){
        displayMovie(movies[i]);
    }
}

void searchByGenre(struct Movie movies[], int count){
    if(count == 0){
        printf("\nNo movies to search.\n");
        return;
    }

    char searchGenre[30];
    printf("Enter genre to search: ");
    scanf(" %[^\n]", searchGenre);

    int i, found = 0;
    for( i = 0; i < count; i++){
        int match = 1;
        int j = 0;
        while(searchGenre[j] != '\0' && movies[i].genre[j] != '\0'){
            if(searchGenre[j] != movies[i].genre[j]){
                match = 0;
                break;
            }
            j++;
        }
        if(match && searchGenre[j] == '\0' && movies[i].genre[j] == '\0'){
            displayMovie(movies[i]);
            found = 1;
        }
    }
    if(!found){
        printf("\nNo movies found in this genre.\n");
    }
}

int main(){
    struct Movie movies[100];
    int movieCount = 0;
    int choice;

    while(1){
        printf("\n--- Movie Management ---\n");
        printf("1. Add Movie\n");
        printf("2. Display All Movies\n");
        printf("3. Search by Genre\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            addMovie(movies, &movieCount);
        }
        else if(choice == 2){
            displayAllMovies(movies, movieCount);
        }
        else if(choice == 3){
            searchByGenre(movies, movieCount);
        }
        else if(choice == 4){
            break;
        }
        else{
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

