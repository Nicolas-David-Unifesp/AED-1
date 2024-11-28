

#include <stdio.h>
#include <string.h>


typedef struct {
    char pais[50];
    char saudacao[100];
} PaisSaudacao;

int main() {
    // Banco de dados com os países e saudações
    PaisSaudacao bancoDeDados[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    int n = sizeof(bancoDeDados) / sizeof(bancoDeDados[0]);  // N° de paises no banco de dados
    char paisConsulta[50];  // String para armazenar o nome do país que se deseja consultar

    // Loop que lê as entradas
    while (scanf("%49s", paisConsulta) != EOF) {  // Lê até 49 caracteres
        int encontrado = 0;
        
        // Busca do país
        for (int i = 0; i < n; i++) {
            if (strcmp(paisConsulta, bancoDeDados[i].pais) == 0) {
                // Se encontrado, imprime a saudação correspondente
                printf("%s\n", bancoDeDados[i].saudacao);
                encontrado = 1;
                break;
            }
        }

        // Se não encontrado, exibe a mensagem de "not found"
        if (!encontrado) {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
