#include <stdio.h>
#include <stdlib.h>
#include "notas.h" // Importa a nossa biblioteca

int main() {
    // Declaração de Variáveis
    int qtdAlunos = 0;
    int opcao = 0;
    int notasCadastradas =0; // Flag para controlar se já digitou notas
    
    // Matriz: [Linhas = Alunos] [Colunas = Avaliações]
    float notas[MAX_ALUNOS][QTD_NOTAS];
    
    // Vetor: Armazena a média de cada aluno
    float medias[MAX_ALUNOS];
    
    float maiorNota, menorNota;

    // 1. Validação da quantidade de alunos (do...while)
    do {
        printf("Digite a quantidade de alunos da turma (1 a %d): ", MAX_ALUNOS);
        scanf("%d", &qtdAlunos);

        if (qtdAlunos < 1 || qtdAlunos > MAX_ALUNOS) {
            printf("Erro: Quantidade invalida. Tente novamente.\n");
        }
    } while (qtdAlunos < 1 || qtdAlunos > MAX_ALUNOS);

    // 2. Menu Principal (do...while)
    do {
        printf("\n====================================\n");
        printf("       SISTEMA ACADEMICO v1.0       ");
        printf("\n====================================\n");
        printf("1. Cadastrar/Alterar notas\n");
        printf("2. Calcular e Exibir Medias\n");
        printf("3. Exibir Maior e Menor Nota da Turma\n");
        printf("4. Listar Aprovados e Reprovados\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Estrutura de Decisão do Menu (switch)
        switch (opcao) {
            case 1:
                lerNotas(notas, qtdAlunos);
                // Calcula as médias automaticamente logo após ler as notas
                calcularMedias(notas, medias, qtdAlunos); 
                notasCadastradas = 1; // Marca que as notas existem
                break;

            case 2:
                if (notasCadastradas) {
                    exibirMedias(medias, qtdAlunos);
                } else {
                    printf("\nAtencao: Cadastre as notas primeiro (Opcao 1)!\n");
                }
                break;

            case 3:
                if (notasCadastradas) {
                
                    maiorMenorNota(notas, qtdAlunos, &maiorNota, &menorNota);
                    printf("\n--- Extremos da Turma ---\n");
                    printf("Maior nota encontrada: %.2f\n", maiorNota);
                    printf("Menor nota encontrada: %.2f\n", menorNota);
                } else {
                    printf("\nAtencao: Cadastre as notas primeiro (Opcao 1)!\n");
                }
                break;

            case 4:
                if (notasCadastradas) {
                    listarAprovadosReprovados(medias, qtdAlunos);
                } else {
                    printf("\nAtencao: Cadastre as notas primeiro (Opcao 1)!\n");
                }
                break;

            case 5:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
