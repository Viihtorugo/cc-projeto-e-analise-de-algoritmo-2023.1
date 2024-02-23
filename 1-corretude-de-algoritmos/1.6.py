def imprime_regua(ordem, comprimento, espacos=0):
    if ordem == 0:
        return
    else:
        # Imprime traço no ponto médio
        print(f"{espacos * ' '}{ordem} . {'-' * comprimento}")

        # Imprime traço nos pontos médios dos subintervalos superior e inferior
        for i in range(1, 2 ** ordem - 1):
            print(f"{espacos * ' '}{ordem} . {'-' * (comprimento - 1)}")

        # Chamadas recursivas para os subintervalos superior e inferior
        imprime_regua(ordem - 1, comprimento - 1, espacos + 1)
        imprime_regua(ordem - 1, comprimento - 1, espacos + 1)

# Exemplo de uso para uma régua de ordem 4
ordem_exemplo = 4
comprimento_inicial = 2 ** ordem_exemplo
imprime_regua(ordem_exemplo, comprimento_inicial)