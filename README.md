Trabalho Final – Estrutura de Dados

Estudantes: Geovanni Martins, Jeovana Miranda e Lívia Alkimim
Curso: Análise e Desenvolvimento de Sistemas – 2º Semestre
Disciplina: Estrutura de Dados

  Este trabalho tem como objetivo compreender como diferentes estruturas de árvores organizam dados e influenciam a eficiência das operações de busca, inserção e remoção. A Árvore Binária de Busca (BST) ilustra a hierarquia aplicada à localização de elementos. As Árvores AVL e Rubro-Negra evidenciam a importância do balanceamento na manutenção do desempenho, reduzindo a altura da árvore e tornando as operações mais eficientes. A Árvore B demonstra como grandes volumes de dados podem ser estruturados de forma otimizada, sendo amplamente utilizada em bancos de dados e sistemas de arquivos. A Trie destaca a busca eficiente por palavras e prefixos, sendo empregada em sistemas de autocompletar e análise de texto. Por fim, o Heap apresenta o conceito de priorização, fundamental em algoritmos que selecionam o elemento mais relevante primeiro.
Esse conjunto de estruturas permite compreender como diferentes abordagens afetam diretamente o desempenho das aplicações, reforçando a importância de escolher a estrutura adequada para cada tipo de problema.


## Compilação dos Programas

Para compilar os códigos desenvolvidos, utilizou-se o compilador **GCC** (GNU Compiler Collection). A opção `-o` permite definir o nome do executável gerado após a compilação. Para compilar o arquivo referente à implementação de Heap Binária (`heapbinaria.c`), utiliza-se o comando:

```
gcc heapbinaria.c -o heapbinaria
```

Da mesma forma, o código da Árvore Binária de Busca (`bst.c`) pode ser compilado através do comando:

```
gcc bst.c -o bst
```

Após a execução desses comandos no terminal, serão gerados os executáveis `heapbinaria` e `bst`, que podem ser executados diretamente com:

```
./heapbinaria
```

e

```
./bst
```

