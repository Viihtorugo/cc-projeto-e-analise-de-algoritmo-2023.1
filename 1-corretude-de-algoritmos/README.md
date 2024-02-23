# Respostas - Corretude de Algoritmos

1) O matemático Al-Khwarizmi foi o responsável por apresentar soluções
sistemáticos para equações lineares e quadráticas. Na sua época, ele apresentou 
a notação posicional decimal para ocidente. Devido a isso, ele é considerado o
Pai da Álgebra, além disso, a palavra Álgebra tem origem de uma variação latina da 
palavra árabe Al-Jab que foi utilizado em seu livro Obra de Restauração e do Balaceamento.
Entretanto, o radical da palavra algoritmo vem da palavra algoritmi, que é a forma latina do
nome Al-Khwarizmi. Assim, o que as duas palavras tem em comum é que ambas estão relacionadas
pela mesma pessoa, porém Álgebra foi a área que o mesmo desenvolveu e o nome algoritmo
é derivado do nome dele em latim.

2) 1 - Prove por indução que n³ + 2n é divisível por 3 para todo n >= 0.

   Base: Sabe-se que 0 é divisível por qualquer número.

   Hipótese: Supanha que n³ + 2n é divisível por 3 para todo n > 0.

   Passo: Seja n um número qualquer e através da fórmula proposta na hipótese n³ + 2n
            a gente tem que o sucessor de n será (n + 1)³ + 2(n + 1), então:

            (n² + 2n + 1)(n + 1) + 2n + 2 =
            n³ + 3n² + 3n + 1 + 2n + 2 =
            n³ + 3n² + 3n + 3 + 2n =
            n³ + 2n + 3n² + 3n + 3

            Pela hipotése é verdade que n³ + 2n é divisível por 3,
            Logo, o restante da equação 3(n² + n + 1) é visível que é
            divisível por 3, pois independete do valor que n² + n + 1 assumir
            a equação continua sendo divisível por 3 devido ter 3 como multiplicador.
    
    2 - Prove por contra-posição. Se 3m é divisível por 2, então m é divisível por 2.

    Se m não é divisível por 2, então 3m não é divisível por 2.

    Suponha que m pertece é um número inteiro e seja ímpar, logo m = 2k + 1,
    para todo k pertecente ao conjunto dos inteiros. Devido a isso, m não é divisível por 2,
    pois ao dividir m por 2 o resultado será que k e resto 1.
    Logo, 3m também não pode ser divisível por 2, pois 3 é um número ímpar e por consequência
    m também é um número ímpar. Com isso, a multiplicação de 2 números ímpares o resultado será 
    um número ímpar.
    
    3 - A soma de 3 números consecutivos é múltiplo de 3, use prova direta.

    Seja n um número qualquer, n + 1 seu sucessor e n - 1 seu antecessor.
    Logo, (n - 1) + n + (n + 1) = n + n + n - 1 + 1 = 3n. Por consequência,
    qualquer valor que n assuma a soma dos 3 números consecutivos será múltiplo de 3.

3) Note que esse problema pode ser representado por um grafo completo de 6 vértices,
ou seja, o grafo terá 15 arestas (segmentos de retas). Ao tentar colorir as arestas de
forma que o número de arestas azuis sejam iguais ao número de aresta brancas não será possível,
pois o número de arestas é ímpar, e como possui apenas 2 cores, sempre terá 1 aresta sobrando.
Devido a isso, ao conectar essa aresta com uma cor será criado o triangulo cuja os lados tem 
a mesma cor.

4) O algoritmo implementado está no arquivo 1.4.cpp, a ideia do algoritmo é retornar
o maior elemento de um vetor.

Como é um algoritmo recursivo, a corretudo é provado através de recursão matemática.

P(n) = "O algoritmo retorna o maior elemento do vetor"

Base: Para k igual a n o algoritmo vai retornar o elemento da posição k no vetor (ou subvetor). 

Hipótese: Suponha que o algoritmo sempre retorna o maior elemento do vetor A[k .. n], tal que k < n.

Passo: Note que as variáveis início e fim indicando o index do primeiro elemento 
e o index do último elemento respectivamente. Com isso, a cada iteração o algoritmo
calcula o index do elemento meio, tal que meio = início + (fim - início) / 2.
Devido a isso, pela hipótese, sempre que inicio < meio a variável a recebe o maior
elemento do subvetor A[inicio .. meio] e sempre que meio + 1 < fim a variável b recebe
o maior elemento do subvetor A[meio + 1 .. fim]. Por fim, verifica-se a é menor que b 
para retornar o maior elemento entre A[inicio .. fim].