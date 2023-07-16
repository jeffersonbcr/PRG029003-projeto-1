#include <iostream>
#include "Mapa.h"

using namespace std;
using prglib::pilha;
struct dados{
   string ator;
   string cam;
   int dist;
};
bool dist_um_dfs(string ator_desejado,pilha<dados> & pd1){
   Mapa mapa("../data/dados.txt");
   dados ponto = pd1.pop();
   fila <string> filmes_1 = mapa.obtem_filmes(ponto.ator);
   while(! filmes_1.vazia()){
       string filme = filmes_1.desenfileira();
       fila<string> atores_um = mapa.obtem_atores(filme);
       while(! atores_um.vazia()){
           string ator_um = atores_um.desenfileira();
           dados ponto_um;
           ponto_um.dist = 1;
           ponto_um.cam = "Kevin Bacon->" + filme + "->" + ator_um;
           ponto_um.ator = ator_um;
           pd1.push(ponto_um);
           if(ator_um == ator_desejado) return true;
       }
   }
   return false;
}

bool dist_x_dfs(string ator_desejado,pilha<dados> & pdx){
   Mapa mapa("../data/dados.txt");
   while(! pdx.vazia()){
           dados ponto_x = pdx.pop();
           while(ponto_x.dist>7){
               ponto_x =pdx.pop();
           }
           fila<string> filmes_x = mapa.obtem_filmes(ponto_x.ator);
           while(! filmes_x.vazia()){
               string filme_x = filmes_x.desenfileira();
               fila<string> atores_x = mapa.obtem_atores(filme_x);
               while(! atores_x.vazia()){
                   dados ponto_x2 = ponto_x;
                   string ator_x2 = atores_x.desenfileira();
                   ponto_x2.ator = ator_x2;
                   ponto_x2.dist = ponto_x2.dist + 1;
                   ponto_x2.cam = ponto_x2.cam + "->" + filme_x + "->" + ator_x2;
                   pdx.push(ponto_x2);
                   if(ator_x2 == ator_desejado) return true;
               }
           }
       }
}

struct dados procura_dfs(string ator_desejado,pilha<dados> & pdados){
   bool ok,x=false;
   dados ponto_bacon;
   ponto_bacon.dist = 0;
   ponto_bacon.ator = bacon;
   ponto_bacon.cam = "Kevin Bacon";
   pdados.push(ponto_bacon);
   dados ponto = pdados.top();
   if(pdados.top().dist == 0){
       ok = dist_um_dfs(ator_desejado,pdados);
       if(ok == true) return pdados.pop();
       else {
           x = dist_x_dfs(ator_desejado,pdados);
           if(x == true) return pdados.pop();
       }
   }


}

bool distancia_um_bfs(string ator_desejado,fila<dados> & qd1){
   Mapa mapa("../data/dados.txt");
   fila<string> qf = mapa.obtem_filmes(bacon);
   pilha <dados> pd(999999);

   while(! qf.vazia()){
       string filme = qf.desenfileira();
       fila<string> filmes_um = mapa.obtem_atores(filme);
       while(! filmes_um.vazia()){
           dados ponto;
           string ator_x = filmes_um.desenfileira();
           ponto.dist = 1;
           ponto.cam= bacon + "->" + filme + "->" + ator_x;
           ponto.ator = ator_x;
           qd1.enfileira(ponto);
           if(ponto.ator == ator_desejado) return true;
           else {
               qd1.enfileira(ponto);
           }
       }
   }
   return false;
}
bool distancia_x_bfs(string ator_desejado,fila<dados> & qdx){
   Mapa mapa("../data/dados.txt");
   while(!qdx.vazia()){
       dados ponto_2 = qdx.desenfileira();
       fila<string> filmes = mapa.obtem_filmes(ponto_2.ator);
       while(! filmes.vazia()){
           string filme2 = filmes.desenfileira();
           fila<string> atores2 = mapa.obtem_atores(filme2);
           while(!atores2.vazia()){
               dados ponto2=ponto_2;
               string ator2 = atores2.desenfileira();
               ponto2.dist = ponto2.dist + 1;
               ponto2.cam = ponto2.cam + "->" + filme2 + "->" + ator2;
               ponto2.ator = ator2;
               qdx.enfileira(ponto2);
               if(ponto2.ator == ator_desejado) return true;
           }
       }
   }
}

struct dados procura_bfs(string ator_des,fila<dados> & qdados){
   bool x=false;
   bool ok = distancia_um_bfs(ator_des,qdados);
   if(ok == true){
       int tam = qdados.comprimento();
       for(int ct = 0;ct< tam-1;ct++){
           qdados.desenfileira();
       }
       return qdados.desenfileira();
   }
   else{
      x = distancia_x_bfs(ator_des,qdados);

   }
   if (x == true) {
       int comp = qdados.comprimento();
       for (int i = comp; i != 1; i--) {
           qdados.desenfileira();
       }
       return qdados.desenfileira();
   }
}

int main() {
   fila<dados> qdata(9999999);
   pilha<dados> pdata(99999);
   string ator_de_busca;
   dados data;
   cout << "Programa distância de bacon iniciado." << endl;
   cout << "digite o nome do ator para calcular a distância de bacon: ";
   getline(cin,ator_de_busca);
   data = procura_dfs(ator_de_busca,pdata);
   cout << data.dist << endl;
   cout << data.cam << endl;

}
#include <iostream>
#include "Mapa.h"

using namespace std;
using prglib::pilha;
struct dados{  //Declaração struct contendo string e int.
   string ator;
   string cam;
   int dist;
};

void separa(string algo, char sep, fila<string> & q) { //Função separa uma string em substrings e enfileira as mesmas.
   int pos = 0; //Declaração de variáveis.
   int pos0 = 0; //Declaração de variáveis.
   string palavra; //Declaração de variáveis.
   if (algo.size() == 0); //Condicional verifica tamanho da string de tamanho igual a zero.
   else {  //Senão
       do {
           pos = algo.find_first_not_of(sep,pos); //pos recebe posição que não seja primeira ocorrência igual ao separador.
           pos0 = algo.find_first_of(sep,pos); //pos0 recebe posição que seja primeira ocorrência igual ao separador.
           palavra = algo.substr(pos,pos0 - pos); // palavra recebe substring.
           q.enfileira(palavra); //palavra sendo enfileirada.
           if(algo.find_first_not_of(sep,pos) == string::npos) break; //Condicional verifica se está no final da string;
           pos = algo.find_first_not_of(sep,pos0); // pos recebe uma nova posição.
       } while (pos != string::npos); // Loop acontece enquanto pos seja diferente do final da string.
   }
}

bool dist_um_dfs(string ator_desejado,pilha<dados> & pd1){ //Função retorna bool para distãncia igual a um dfs.
   Mapa mapa("../data/dados.txt"); //Declaração de variáveis.
   dados ponto = pd1.pop(); //Declaração de variáveis.
   fila <string> filmes_1 = mapa.obtem_filmes(ponto.ator); //Declaração de variáveis.
   while(! filmes_1.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
       string filme = filmes_1.desenfileira(); // recebendo dado da fila.
       fila<string> atores_um = mapa.obtem_atores(filme); // gera uma fila a partir da string filme.
       while(! atores_um.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
           string ator_um = atores_um.desenfileira(); // recebendo dado da fila.
           dados ponto_um; //Declaração de variáveis.
           ponto_um.dist = 1; //inteiro da struct recebe valor um.
           ponto_um.cam = "Kevin Bacon->" + filme + "->" + ator_um; //string cam da struct recebe dados vindo das filas.
           ponto_um.ator = ator_um;  //string ator da struct recebe string ator_um;
           pd1.push(ponto_um); //empilhando struct.
           if(ator_um == ator_desejado) return true; //se condicional for verdadeiro retorna struct.
       }
   }
   return false; //caso saia do loop retorna false.
}

bool dist_x_dfs(string ator_desejado,pilha<dados> & pdx){ //Função retorna bool para um determinado valor de distância em relação ao ator desejado.
   Mapa mapa("../data/dados.txt"); //Declaração de variáveis.
   while(! pdx.vazia()){ //Loop ocorre enquant ofila não estiver vazia.
           dados ponto_x = pdx.pop(); //recebendo dado da pilha.
           while(ponto_x.dist>7){ //loop ocorre se o inteiro da struct for maior q 7.
               ponto_x =pdx.pop(); //enquanto loop ocorrer struct recebe dado da pilha.
           }
           fila<string> filmes_x = mapa.obtem_filmes(ponto_x.ator); //fila recebe todos os filmes obtidos atraves do ator da struct.
           while(! filmes_x.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
               string filme_x = filmes_x.desenfileira(); //Recebendo dado da fila.
               fila<string> atores_x = mapa.obtem_atores(filme_x); //fila recebe todos os atores do filme passado por parâmetro.
               while(! atores_x.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
                   dados ponto_x2 = ponto_x; //struct recebe dados de outra struct.
                   string ator_x2 = atores_x.desenfileira(); //string recebe valor da fila.
                   ponto_x2.ator = ator_x2; //string ator da struct recebe ator.
                   ponto_x2.dist = ponto_x2.dist + 1; //inteiro da struct recebe incrimento.
                   ponto_x2.cam = ponto_x2.cam + "->" + filme_x + "->" + ator_x2; //string cam da struct recebe concatenação de dados sendo analisados.
                   pdx.push(ponto_x2); //empilha struct.
                   if(ator_x2 == ator_desejado) return true; //condicional verifica se encontrou ator desejado.
               }
           }
       }
}

struct dados procura_dfs(string ator_desejado,pilha<dados> & pdados){ //função realiza a procura em largura.
   bool booleano1,booleano2=false; //Declaração de variáveis.
   dados ponto_bacon; //Declaração de variáveis.
   ponto_bacon.dist = 0; //inteiro da struct recebe valor.
   ponto_bacon.ator = bacon; //string ator da struct recebe valor.
   ponto_bacon.cam = "Kevin Bacon"; //string cam da struct recebe valor.
   pdados.push(ponto_bacon); //empilha struct.
   dados ponto = pdados.top(); //struct recebe dado que está no topo da pilha.
   if(pdados.top().dist == 0){ //caso topo tenha distância igual a zero.
       booleano1 = dist_um_dfs(ator_desejado,pdados); //booleano1 recebe valor da função dist_um_bfs.
       if(booleano1 == true) return pdados.pop(); //se condicional verdadeiro retorna primeiro valor da pilha.
       else {
           booleano2 = dist_x_dfs(ator_desejado,pdados); //booleano2 recebe valor da função dist_x_dfs.
           if(booleano2 == true) return pdados.pop(); //se condicional verdadeiro retorna primeiro valor da pilha.
       }
   }
}

bool distancia_um_bfs(string ator_desejado,fila<dados> & qd1){ //Função retorna bool para um determinado valor de distância em relação ao ator desejado.
   Mapa mapa("../data/dados.txt"); //Declaração de variáveis.
   fila<string> qf = mapa.obtem_filmes(bacon); //fila recebe todos os filmes de bacon.
   pilha <dados> pd(999999); //Declaração de variáveis.

   while(! qf.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
       string filme = qf.desenfileira(); //recebe valor da fila.
       fila<string> filmes_um = mapa.obtem_atores(filme); //fila recebe todos os atores da string filme.
       while(! filmes_um.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
           dados ponto; //Declaração de variáveis.
           string ator_x = filmes_um.desenfileira(); //Recebendo valor da fila.
           ponto.dist = 1; //inteiro da struct recebe valor um.
           ponto.cam= bacon + "->" + filme + "->" + ator_x; //string cam da struct recebe caminho a ser analisado.
           ponto.ator = ator_x; //string ator da struct recebe valor de ator_x.
           qd1.enfileira(ponto); //enfileirando struct.
           if(ponto.ator == ator_desejado) return true; //caso encontre ator_desejado retorna true,
           else { //Senão.
               qd1.enfileira(ponto); //enfileira struct.
           }
       }
   }
   return false; //Caso saia do loop retorna false.
}
bool distancia_x_bfs(string ator_desejado,fila<dados> & qdx){ //Função retorna bool para um determinado valor de distância em relação ao ator desejado.
   Mapa mapa("../data/dados.txt"); //Declaração de variáveis.
   while(!qdx.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
       dados ponto_2 = qdx.desenfileira(); //recebendo dado da fila.
       fila<string> filmes = mapa.obtem_filmes(ponto_2.ator); //fila recebe todos os filmes da string ponto_2.ator.
       while(! filmes.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
           string filme2 = filmes.desenfileira(); //recebendo dado da fila.
           fila<string> atores2 = mapa.obtem_atores(filme2); //fila recebe todos os atores da string filme2.
           while(!atores2.vazia()){ //Loop ocorre enquanto não estiver vazia.
               dados ponto2=ponto_2; //struct recebe valor de outra struct.
               string ator2 = atores2.desenfileira(); //recebendo valor da fila.
               ponto2.dist = ponto2.dist + 1; //incrimento da distãncia.
               ponto2.cam = ponto2.cam + "->" + filme2 + "->" + ator2; //anexo do caminho sendo analisado.
               ponto2.ator = ator2; //string da struct recebe valor de string ator2.
               qdx.enfileira(ponto2); //enfileira struct.
               if(ponto2.ator == ator_desejado) return true; //se ator desejado for encontrado retorna true.
           }
       }
   }
}

struct dados procura_bfs(string ator_des,fila<dados> & qdados){ //função realiza a procura em profundidade.
   bool booleano2=false; //Declaração de variáveis.
   bool booleano1 = distancia_um_bfs(ator_des,qdados); //Booleano recebe valor da função distancia_um_bfs
   if(booleano1 == true){ //Se condicional for verdadeiro.
       int tam = qdados.comprimento(); //recebendo valor do comprimento da fila.
       for(int ct = 0;ct< tam-1;ct++){ //Loop que desenfileira todos os valores da fila menos o ultimo.
           qdados.desenfileira(); //descartando valores da fila.
       }
       return qdados.desenfileira(); //retorna ultima valor da fila.
   }
   else{
      booleano2 = distancia_x_bfs(ator_des,qdados); //Booleano recebe valor da função distancia_x_bfs

   }
   if (booleano2 == true) { //Se condicional for verdadeiro.
       int comp = qdados.comprimento(); //recebendo valor do comprimento da fila.
       for (int i = comp; i != 1; i--) { //Loop que desenfileira todos os valores da fila menos o ultimo.
           qdados.desenfileira(); //descartando dados da fila.
       }
       return qdados.desenfileira(); //retorna ultimo dado da fila.
   }
}
string arruma_nome(string ator){ //Função arruma string.
   fila<string> qs(999); //Declaração de variáveis.
   string aux; //Declaração de variáveis.
   separa(ator,' ',qs); //Separando a string em substrings e armazenando na fila.
   while(! qs.vazia()){ //Loop ocorre enquanto fila não estiver vazia.
       string w = qs.desenfileira(); // recebendo dado da fila.
       for(int ct=0;ct<w.size();ct++){ //Loop percorre string.
           if(ct == 0){ //Se posição for igual a 0 faz.
               w[ct] = toupper(w[ct]); //posição da string recebe seu valor em maiuscula.
           }
           else {
               w[ct] = tolower(w[ct]); //posição da string recebe seu valor em minuscula.
           }
       }
       aux = aux + w + " "; //concatenação de dados na string.
   }
   aux.pop_back(); //remove o valor da ultima posição da string.
   return aux; //retorna string modificada.
}
void arruma_escolha(string & escolha){ //Função arruma string.
   for(int i =0;i<escolha.size();i++){ //loop que percorre posições da string.
       escolha[i] = toupper(escolha[i]); //posições da string recebe valores em maiuscula.
   }
}
int main() {
   fila<dados> qdata(9999999); //Declaração de variáveis.
   fila<string> qs (999); //Declaração de variáveis.
   pilha<dados> pdata(999999); //Declaração de variáveis.
   string ator_de_busca,escolha; //Declaração de variáveis.
   dados data_bfs,data_dfs; //Declaração de variáveis.
   cout << "Programa distância de bacon iniciado." << endl; //Imprime na tela um texto.
   cout << "digite o nome do ator para calcular a distância de bacon: "; //Imprime na tela um texto.
   getline(cin,ator_de_busca); //captura dado do teclado.
   ator_de_busca = arruma_nome(ator_de_busca); //função arruma string.
   cout << "Digite a forma de busca do ator para ser calculado a distância de bacon, BFS para busca em largura ou DFS para busca: "; //Imprime na tela texto.
   getline(cin,escolha); //captura dado do teclado.
   arruma_escolha(escolha); //função arruma string.
   if(escolha == "BFS"){
       data_bfs =procura_bfs(ator_de_busca,qdata); //struct recebe valor retornado da função.
       cout << "Distância de Bacon = " << data_bfs.dist << endl; //Imprime na tela distância.
       cout << data_bfs.cam << endl; //Imprime na tela caminho.
   }
   else if( escolha == "DFS"){
       data_dfs =procura_dfs(ator_de_busca,pdata); //struct recebe valor retornado da função.
       cout << "Distância de Bacon = " << data_dfs.dist << endl; //Imprime na tela distância.
       cout << data_dfs.cam << endl; //Imprime na tela caminho.
   }
   else {
       cout << "opção inválida" << endl; //Imprime na tela um texto.
   }
   return 0;
}


