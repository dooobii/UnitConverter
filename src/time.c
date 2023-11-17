#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum TimeUnit {
    SECOND,
    HOUR,
    DAY,
    MINUTE,
    MILLISECOND,
    WEEK,
    MONTH,
    YEAR,
    INVALID_UNIT
};

enum TimeUnit stringToUnit(char *unit) {
    if (strcmp(unit, "second") == 0) return SECOND;
    if (strcmp(unit, "hour") == 0) return HOUR;
    if (strcmp(unit, "day") == 0) return DAY;
    if (strcmp(unit, "minute") == 0) return MINUTE;
    if (strcmp(unit, "millisecond") == 0) return MILLISECOND;
    if (strcmp(unit, "week") == 0) return WEEK;
    if (strcmp(unit, "month") == 0) return MONTH;
    if (strcmp(unit, "year") == 0) return YEAR;

    printf("Unit is not valid\n");
    return INVALID_UNIT;
}

int printConvert(float value, enum TimeUnit unit) {
    float valSeconds;

    //Convert value to seconds
    switch (unit) {
        case SECOND:
            valSeconds = value;
            break;
        case HOUR:
            valSeconds = value * 3600;
            break;
        case DAY:
            valSeconds = value * 86400;
            break;
        case MINUTE:
            valSeconds = value * 60;
            break;
        case MILLISECOND:
            valSeconds = value / 1000;
            break;
        case WEEK:
            valSeconds = value * 604800;
            break;
        case MONTH:
            valSeconds = value * 2629800;
            break;
        case YEAR:
            valSeconds = value * 31557600;
            break;
        case INVALID_UNIT://should not append tho
            printf("Invalid unit \n");
            return -1;
    }

    //Printing
    printf("%.3f Milliseconds \n", valSeconds * 1000);
    printf("%.3f Seconds \n", valSeconds);
    printf("%.3f Minutes \n", valSeconds / 60);
    printf("%.3f Hours \n", valSeconds / 3600);
    printf("%.4f Days \n", valSeconds / 86400);
    printf("%.5f Week \n", valSeconds / 604800);
    printf("%.6f Months \n", valSeconds / 2629800);
    printf("%.7f Years \n", valSeconds / 31557600);

    return 0;
}

int main(int argc, char *argv[]) {
    float value;
    char unit[100];
    printf("Enter a value: ");
    scanf("%f", &value);

    while (value < 0) {
        printf("Value must be positive\n");
        printf("Enter a value: ");
        scanf("%f", &value);
    }

    printf("Enter a unit (ex: second, day, hour): ");
    scanf("%s", unit);

    enum TimeUnit newUnit = stringToUnit(unit);
    while (newUnit == INVALID_UNIT) {
        printf("Enter a unit (ex: second, day, hour): ");
        scanf("%s", unit);
        newUnit = stringToUnit(unit);
    }

    return printConvert(value,newUnit);
}
