# Prglib: biblioteca de estruturas de dados elementares

A [Prglib](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Etapa_2:_A_constru%C3%A7%C3%A3o_da_prglib) é uma pequena biblioteca contendo estruturas de dados para fins didáticos. Ela foi escrita para a disciplina de [Programação II](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Introdu%C3%A7%C3%A3o_a_C%2B%2B) da [Engenharia de Telecomunicações](https://wiki.sj.ifsc.edu.br/wiki/index.php/Curso_de_Engenharia_de_Telecomunica%C3%A7%C3%B5es) do [IFSC Câmpus São José](http://www.sj.ifsc.edu.br/). E contém as seguintes estruturas de dados:
* __Fila__: uma fila circular com capacidade definido no momento de sua criação
* __Pilha__: uma pilha cuja capacidade também é definida no instante de sua criação
* __Lista__: uma lista duplamente encadeada, e possivelmente circular (depende da implementação do estudante)
* __Tabela hash__: uma tabela hash com quantidade de linhas (buckets) definida no instante de sua criação. Além disso, por simplicidade as chaves são do tipo string
* __Árvore de pesquisa binária__: uma árvore com operações de balanceamento com algoritmo [AVL](https://en.wikipedia.org/wiki/AVL_tree)

# Código de Cálculo da Distância de Bacon

Este código em C++ calcula a distância de Bacon entre um ator fornecido pelo usuário e o ator Kevin Bacon. A distância de Bacon é uma medida da conexão entre dois atores de cinema através dos filmes em que atuaram. O objetivo é determinar o número mínimo de filmes em que os atores precisam atuar para estarem conectados.

O código está dividido em várias funções e estruturas de dados para realizar a busca em largura (BFS) e a busca em profundidade (DFS) no grafo de atores e filmes. A seguir, vamos descrever cada parte do código:

## Estruturas de Dados

O código define uma estrutura dados que representa informações sobre um ator, incluindo o nome do ator, o caminho percorrido até o ator e a distância em relação ao ator Kevin Bacon.

```cpp
struct dados{
   string ator;
   string cam;
   int dist;
};

```

## Funções de Busca em Profundidade (DFS)
O código inclui duas funções de busca em profundidade: dist_um_dfs e dist_x_dfs. A função dist_um_dfs busca atores que estão a uma distância de um filme (conexão direta) do ator Kevin Bacon. A função dist_x_dfs busca atores que estão a uma distância maior do que um filme do ator Kevin Bacon.

Essas funções são utilizadas pela função procura_dfs, que executa a busca em profundidade para encontrar o ator desejado. Essa função retorna a estrutura dados correspondente ao ator encontrado ou uma estrutura vazia se o ator não for encontrado.

## Funções de Busca em Largura (BFS)
O código também inclui duas funções de busca em largura: distancia_um_bfs e distancia_x_bfs. A função distancia_um_bfs busca atores que estão a uma distância de um filme (conexão direta) do ator Kevin Bacon. A função distancia_x_bfs busca atores que estão a uma distância maior do que um filme do ator Kevin Bacon.

Essas funções são utilizadas pela função procura_bfs, que executa a busca em largura para encontrar o ator desejado. Essa função retorna a estrutura dados correspondente ao ator encontrado ou uma estrutura vazia se o ator não for encontrado.

## Funções Auxiliares
O código também inclui algumas funções auxiliares, como separa, que divide uma string em substrings com base em um separador fornecido, e arruma_nome e arruma_escolha, que ajustam as strings do nome do ator e da escolha do usuário, respectivamente, para que estejam no formato correto.

## Fluxo Principal
O fluxo principal do código está na função main. Nessa função, o usuário é solicitado a fornecer o nome do ator para calcular a distância de Bacon. Em seguida, o usuário é solicitado a escolher entre a busca em largura (BFS) e a busca em profundidade (DFS). Com base na escolha do usuário, a função correspondente (procura_bfs ou procura_dfs) é chamada para realizar a busca e retornar a estrutura dados correspondente ao ator encontrado.

Finalmente, o resultado da busca é exibido na tela, mostrando a distância de Bacon e o caminho percorrido até o ator desejado.

Observação: É importante ressaltar que o código faz referência a um arquivo Mapa.h para utilizar a classe Mapa e a estrutura de dados fila. Além disso, o código também depende de um arquivo de dados dados.txt localizado no diretório ../data/ para construir o grafo de atores e filmes. Certifique-se de fornecer esses arquivos e incluir as bibliotecas necessárias para que o código seja executado corretamente.

Esse é um exemplo básico de implementação do cálculo da distância de Bacon em C++. O código pode ser adaptado e expandido para atender a requisitos específicos ou integrado a outros sistemas, conforme necessário.

<h1 align='center'>Autor</h1>

<a href="https://github.com/jeffersonbcr">
    <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/58866006?v=4" width="100px;" alt=""/><br/>
    <sub><b>Jefferson Botitano</b></sub></a>

<br><br/>


