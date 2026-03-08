#ifndef CWEB_H
#define CWEB_H

#include <curl/curl.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

static inline char* descriptografar(char *dados, int tamanho, int chave) {
    for(int i = 0; i < tamanho; i++) {
        if(dados[i] == '\n' || dados[i] == '\r') {
            dados[i] = '\0';
            break; 
        }
        dados[i] = (char)(dados[i] ^ chave);
    }
    return dados;
}

// Note os 3 argumentos aqui: feedback, login e pontos
static inline void disparar_webhook(char *texto, char *user_login, int pontos) {
    CURL *curl;
    // Tenta abrir o arquivo de config
    FILE *f = fopen("hard_assets/config.txt", "rb");
    if (!f) {
        puts("Erro: Arquivo de config não encontrado.");
        return;
    }

    char url_encriptada[512];
    size_t n = fread(url_encriptada, 1, sizeof(url_encriptada) - 1, f);
    fclose(f);

    if (n > 0) {
        url_encriptada[n] = '\0';
        // Descriptografa a URL
        char *url = descriptografar(url_encriptada, (int)n, 42);

        curl = curl_easy_init();
        if(curl) {
            char json[2048];
            time_t t = time(NULL);
            struct tm *tm_info = localtime(&t);
            char horario[64];
            strftime(horario, sizeof(horario), "%d/%m/%Y %H:%M:%S", tm_info);

            // Monta o JSON com os 3 dados
            snprintf(json, sizeof(json),
                     "{\"content\": \"🎮 **New Feedback!!**\\n**User:** `%s`\\n**Message:** %s\\n🕒 %s \\n**Rating:** %i/10\"}",
                     user_login, texto, horario, pontos);

            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");

            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            curl_easy_perform(curl);

            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
        }
    }
}

#endif