#ifndef SOLUCAO_H_
#define SOLUCAO_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct key {
	int document;
	int position;
	char word[20];
} Type;

// Recebe duas structs do tipo Type
// Returna -1 se a < b e 1 se a > b
// Comparacao feita pela palavra,documento e posicao, nesta ordem.
int compare_key(Type a, Type b);

// Abre um arquivo de leitura determinado por doc no diretorio dir
// e o coloca no ponteiro f
// Precondicao : o documento deve existir em dir
void open_intput_file(char* dir, FILE** f, int doc);

// Abre um aquivo de escrita em dir com nome determinado por doc
// Se ja existir um arquivo de mesmo nome este sera apagado
void open_output_file(char* dir, FILE** f, int doc);

//Abre um aquivo chama index em dir e o coloca no ponteiro f
// Se ja existir um arquivo de mesmo nome este sera apagado
void open_index_file(char* dir, FILE **f);

// Le uma palavra de uma conversa e pega sua posicao
// Colocando na struct aux
// Se houve leitura de uma palavra retorna true
// Caso contrario retorna falso
// Precondicao: o arquivo de conversa deve estar aberto em f e ser valido para leitura
bool read_input_file(FILE* f, int doc,Type *aux);

// Le uma palavra, sua conversa de origem e sua posicao de um arquivo temporario
// Colocando na struct aux
// Se houve leitura de uma palavra retorna true
// Caso contrario retorna falso
// Precondicao: o arquivo deve estar aberto em f e ser valido para leitura
bool read_tmp_file(FILE* f,Type* key);

// Escreve o conteudo de aux no formato definido para um index no arquivo f
// Precondicao: o arquivo deve estar aberto em f e ser valido para escrita
void write_index_file(FILE *f,Type key, int frequency);

// Escreve o conteudo de aux no formato definido para um aruivo temporario em f
// Precondicao: o arquivo deve estar aberto em f e ser valido para escrita
void write_output_file(FILE* f, Type key);

// Recebe o diretorio onde index deve estar e numero do ultimo arquivo criado
// que ja esta totalmente ordenado e contem todas as palavras de todas conversas
// Calcula  a frequencia de cada palavra em cada arquivo e escreve todos os registros
// com suas frequencias no arquivo final index no diretorio definido em out_dir
void create_index(char* out_dir, int last_file);

// Recebe o numero de arqivos criado pela rodada inicial alem da quantidade de registros
// que cabem na memoria
// Os registros dentro dos arquivos precisam estar ordenados
// Junta os registros dos arquivos em um arquivo e retorna o numero do ultimo arquivo criado
// que contem todos os registros ordenados
// Precondicao: Deve haver um diretorio chamado tmp na root do problema
int merge_files(int file_number,int key_number);

// Recebe o diretorio onde estao as conversas, o numero de conversas e a quantidade de registros
// que cabem na memoria
// le as palavras de todas as conversas e as colocam ordenadas em varios arquivos temporarios
// Retorna a quantidade de arquivos criados
// Precondicao: Deve haver um diretorio chamado tmp na root do problema
int initial_run(char* entry_dir, int docs, int key_number);

// Recebe o diretorio de se encontra as conversas, numero de converso e a quantidade de 
// Registro que cabem na memoria
// Ordena as conversas em entry e colocas em um arquivo em tmp
// Retorna o numero do ultimo arquivo criado contendo todas os registros ordenados
int external_sorting(char* entry, int docs, int key_number);

// Recebe o diretorio onde estao as conversas, o diretorio onde o indice deve ser criado
// o numero de conversas e a quantidade de memoria
// Ordena as conversas que ha em entry e cria um indice invertido
// em out
void inverted_index(char* entry,char* out, int docs, int memory);

#endif