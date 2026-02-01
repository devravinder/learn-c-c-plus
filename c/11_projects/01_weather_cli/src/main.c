#include <stdio.h>
#include "weather.h"

int main() {

    char city[50];

    printf("Enter city name: ");
    scanf("%49s", city);

    fetchWeather(city);

    return 0;
}
