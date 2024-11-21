// Name:Masoom Khan Roll#24k-0001  BAI 1A       LAB:10   section:2    Q2
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

// Define the structure for movie information
typedef struct {
    char title[100];
    char genre[50];
    char director[50];
    int releaseYear;
    float rating;
} Movie;

// Function prototypes
void addMovie(Movie movies[], int *count);
void searchMoviesByGenre(Movie movies[], int count, const char *genre);
void displayAllMovies(Movie movies[], int count);
//start main
int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre \n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                searchMoviesByGenre(movies, count, "Horror");
                break;
            case 3:
                displayAllMovies(movies, count);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//end main
// Function to add a new movie
void addMovie(Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Maximum movie limit reached.\n");
        return;
    }

    printf("Enter movie title: ");
    // Clear the newline character
    getchar(); 
    fgets(movies[*count].title, sizeof(movies[*count].title), stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, sizeof(movies[*count].genre), stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter dirextor's name: ");
    fgets(movies[*count].director, sizeof(movies[*count].director), stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter rating (out of 10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie sdded successfully!\n");
}
// end add function
// Function to search movies by genre
void searchMoviesByGenre(Movie movies[], int count, const char *genre) {
    printf("\nMovies in genre \"%s\":\n", genre);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(movies[i].genre, genre) != NULL) {
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("<----------------------------->\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in the genre \"%s\".\n", genre);
    }
}
//end search function
// Function to display all movies
void displayAllMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("<--------------------------------------------------->\n");
    }
}
//end display function