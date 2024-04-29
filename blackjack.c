#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int cartas[10] = {1,2,3,4,5,6,7,8,9,10};
    int cartasUser = 0, cartasCasa = 0, decisao, dinheiro = 500, aposta;
    int blackJack, vitoria, raiseBom, raiseRuim,apostaRaise;

    do{
        cartasCasa = 0;
        cartasUser = 0;
        cartasCasa += cartas[rand() % 10];
        cartasUser += cartas[rand() % 10];
        printf("Faça a sua aposta (min. $100)\n");
        printf("Saldo disponível: $%d\n\n", dinheiro);
        scanf("%d", &aposta);
        blackJack = (2.5 * aposta);
        vitoria = (2 * aposta);
        raiseBom = (2.5 * aposta);
        raiseRuim = (1.5 * aposta);
        if(aposta < 100){
            printf("A aposta mínima é de $100, tente novamente.\n\n");
            continue;
        } else if(aposta > dinheiro){
            printf("Saldo não disponível.\n\n");
            continue;
        } else {
            dinheiro -= aposta;
            printf("Sua soma = %d\n", cartasUser);
            printf("Soma da casa = %d\n", cartasCasa);
            while(1){
                if(cartasCasa < 21 && cartasUser < 21){
                    printf("Escolha:\n");
                    printf("1. Comprar  2. Manter  3. Desistir\n");
                    scanf("%d", &decisao);

                    if(decisao == 1 && cartasCasa > 17){
                        cartasUser += cartas[rand() % 10];
                        if (cartasUser > 21){
                            printf("Você perdeu!\n\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            break;
                        } else if (cartasUser == 21){
                            printf("Blackjack!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            dinheiro += blackJack;
                            break;
                        } else {
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            continue;
                        }
                    } else if(decisao == 1 && cartasCasa <= 17){
                        cartasUser += cartas[rand() %10];
                        if(cartasCasa > 21){
                            printf("Você venceu! A casa estourou!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            dinheiro += vitoria;
                            break;
                        } else if(cartasUser == 21){
                            printf("Blackjack!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            dinheiro += blackJack;
                            break;
                        } else if (cartasCasa == 21){
                            printf("Blackjack da Casa!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            break;
                        } else if (cartasUser > 21){
                            printf("Você perdeu!\n\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            break;
                        } else {
                            cartasCasa += cartas[rand() % 10];
                            if(cartasCasa > 21){
                                printf("Você venceu! A casa estourou!\n");
                                printf("Sua soma = %d\n", cartasUser);
                                printf("Soma da casa = %d\n", cartasCasa);
                                dinheiro += vitoria;
                                break;
                            } else if (cartasCasa == 21){
                                printf("Blackjack da Casa!\n");
                                printf("Sua soma = %d\n", cartasUser);
                                printf("Soma da casa = %d\n", cartasCasa);
                                break;
                            } else {
                                printf("Sua soma = %d\n", cartasUser);
                                printf("Soma da casa = %d\n", cartasCasa);
                                continue;
                            }
                        }
                    } else if(decisao == 2 && cartasCasa < cartasUser){
                        cartasCasa += cartas[rand() % 10];
                        if(cartasCasa > 21){
                            printf("Você venceu! A casa estourou!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            dinheiro += vitoria;
                            break;
                        } else if (cartasCasa == 21){
                            printf("Blackjack da Casa!\n");
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            break;
                        } else {
                            printf("Sua soma = %d\n", cartasUser);
                            printf("Soma da casa = %d\n", cartasCasa);
                            continue;
                        }
                    } else if(decisao == 2 && cartasCasa >= cartasUser){
                        printf("Você perdeu!\n\n");
                        printf("Sua soma = %d\n", cartasUser);
                        printf("Soma da casa = %d\n", cartasCasa);
                        break;
                    } else {
                        printf("Você desistiu!\n");
                        printf("Sua soma = %d\n", cartasUser);
                        printf("Soma da casa = %d\n", cartasCasa);
                        break;
                    }
            }
        }
        }
    }while(dinheiro > 100);
    printf("GAME OVER");
}
