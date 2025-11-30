#include <stdio.h>

struct Player {
    char name[50];
    int age;
    char position[30];
};

struct Team {
    char name[50];
    char sport[30];
    struct Player players[50];
    int playerCount;
};

void copyString(char dest[], char src[]) {
    int i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void addPlayer(struct Team *t) {
    if(t->playerCount >= 50) {
        printf("Team is full. Cannot add more players.\n");
        return;
    }

    char temp[100];

    printf("Enter player name: ");
    scanf(" %[^\n]", temp);
    copyString(t->players[t->playerCount].name, temp);

    printf("Enter age: ");
    scanf("%d", &t->players[t->playerCount].age);

    printf("Enter position: ");
    scanf(" %[^\n]", temp);
    copyString(t->players[t->playerCount].position, temp);

    t->playerCount++;
    printf("Player added successfully!\n");
}

void searchByPosition(struct Team t) {
    if(t.playerCount == 0) {
        printf("No players available.\n");
        return;
    }

    char target[30];
    printf("Enter position to search: ");
    scanf(" %[^\n]", target);

    int i, found = 0;

    for(i = 0; i < t.playerCount; i++) {
        int match = 1;
        int j = 0;

        while(target[j] != '\0' && t.players[i].position[j] != '\0') {
            if(target[j] != t.players[i].position[j]) {
                match = 0;
                break;
            }
            j++;
        }

        if(match && target[j] == '\0' && t.players[i].position[j] == '\0') {
            printf("\nPlayer Found:\n");
            printf("Name: %s\n", t.players[i].name);
            printf("Age: %d\n", t.players[i].age);
            printf("Position: %s\n", t.players[i].position);
            found = 1;
        }
    }

    if(!found) {
        printf("No player found with this position.\n");
    }
}

void displayTeam(struct Team t) {
    printf("\n--- Team Details ---\n");
    printf("Team Name: %s\n", t.name);
    printf("Sport: %s\n", t.sport);
    printf("Total Players: %d\n", t.playerCount);
    int i;
    for( i = 0; i < t.playerCount; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("Name: %s\n", t.players[i].name);
        printf("Age: %d\n", t.players[i].age);
        printf("Position: %s\n", t.players[i].position);
    }
}

int main() {
    struct Team team;
    team.playerCount = 0;

    char temp[100];

    printf("Enter team name: ");
    scanf(" %[^\n]", temp);
    copyString(team.name, temp);

    printf("Enter sport: ");
    scanf(" %[^\n]", temp);
    copyString(team.sport, temp);

    int choice;

    while(1) {
        printf("\n--- Team Menu ---\n");
        printf("1. Add Player\n");
        printf("2. Display Team Details\n");
        printf("3. Search Player by Position\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            addPlayer(&team);
        }
        else if(choice == 2) {
            displayTeam(team);
        }
        else if(choice == 3) {
            searchByPosition(team);
        }
        else if(choice == 4) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

