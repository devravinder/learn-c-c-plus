#include "weather.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/* buffer for HTTP response */
struct Memory {
    char *data;
    size_t size;
};

/* callback used by libcurl */
static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {

    size_t total = size * nmemb;

    struct Memory *mem = (struct Memory *)userp;

    char *ptr = realloc(mem->data, mem->size + total + 1);

    if(!ptr) return 0;

    mem->data = ptr;

    memcpy(&(mem->data[mem->size]), contents, total);

    mem->size += total;
    mem->data[mem->size] = 0;

    return total;
}

void fetchWeather(const char *city) {

    CURL *curl;
    CURLcode res;

    struct Memory chunk = {0};

    curl = curl_easy_init();

    if(!curl) {
        printf("Curl init failed\n");
        return;
    }

    char url[256];

    /* free test API (no key required) */
    snprintf(url, sizeof(url),
        "https://wttr.in/%s?format=3", city);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK) {
        printf("Request failed: %s\n", curl_easy_strerror(res));
    } else {
        printf("\nWeather Info:\n%s\n", chunk.data);
    }

    free(chunk.data);
    curl_easy_cleanup(curl);
}
