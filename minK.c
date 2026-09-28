#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void help(void) {
    printf("Commands:\n");
    printf("  about - lists all commands\n");
    printf("  help - shows current version of MinKexec4NT\n");
}

void about(void) {
    printf("MinKexec4NT v1.0.0\n");
    printf("A tiny C-based shell for the NT kernel alike to MinK, a project of Jessie.\n");
}

int main(void) {
    char command[256];

    printf("MinKexec4NT 1.0.0\n");
    printf("MinK is a hyper-minimal shell designed for the NT kernel.\n\n");
    while (1) {
        printf("");

        if (fgets(command, sizeof(command), stdin) == NULL)
            break;

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "help") == 0) {
            help();
        }
        else if (strcmp(command, "about") == 0) {
            about();
        }
        else if (strlen(command) == 0) {
            continue;
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}