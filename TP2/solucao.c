#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "solucao.h"

int min(int a, int b,int c) {
	if(a > b)
		a = b;
	if(a > c)
		a = c;
	return a;
}

// Recebe duas structs do tipo Type
// Returna -1 se a < b e 1 se a > b
// Comparacao feita pela palavra,documento e posicao, nesta ordem.
int compare_key(Type a, Type b) {
	int cmp = strcmp(a.word,b.word);
	if(cmp < 0)
		return -1;
	else if( cmp > 0)
		return 1;
	else if(a.document < b.document)
		return -1;
	else if(a.document > b.document)
		return 1;
	else if(a.position < b.position)
		return -1;
	else
		return 1;
}

// Abre um arquivo de leitura determinado por doc no diretorio dir
// e o coloca no ponteiro f
// Precondicao : o documento deve existir em dir
// Salva o final da string dir em len, concatena dir com doc
// E depois retorna dir ao seu estado inicial
void open_intput_file(char* dir, FILE** f, int doc) {
	int len = strlen(dir);
	snprintf(&(dir[len]),sizeof(dir),"%d",doc );
	*f = fopen(dir,"r");
	dir[len] = '\0';
}

// Abre um aquivo de escrita em dir com nome determinado por doc
// Se ja existir um arquivo de mesmo nome este sera apagado
// Salva o final da string dir em len, concatena dir com doc
// E depois retorna dir ao seu estado inicial
void open_output_file(char* dir, FILE** f, int doc) {
	int len = strlen(dir);
	snprintf(&(dir[len]),sizeof(dir),"%d",doc );
		*f = fopen(dir,"w");
	dir[len] = '\0';
}

//Abre um aquivo chama index em dir e o coloca no ponteiro f
// Se ja existir um arquivo de mesmo nome este sera apagado
// Salva o final da string dir em len, concatena dir com "index"
// E depois retorna dir ao seu estado inicial
void open_index_file(char* dir, FILE **f) {
	int len = strlen(dir);
	strcat(dir,"index");
	*f = fopen(dir,"w");
	dir[len] = '\0';
}

// Le uma palavra de uma conversa e pega sua posicao
// Colocando na struct aux
// Se houve leitura de uma palavra retorna true
// Caso contrario retorna falso
// Precondicao: o arquivo de conversa deve estar aberto em f e ser valido para leitura
bool read_input_file(FILE* f, int doc,Type *aux) {
	aux->position = ftell(f);
	if(aux->position != 0)
		aux->position += 1;
	if(fscanf(f,"%s",aux->word) < 1) {
		return false;
	}
	aux->document = doc;
	return true;

}

// Le uma palavra, sua conversa de origem e sua posicao de um arquivo temporario
// Colocando na struct aux
// Se houve leitura de uma palavra retorna true
// Caso contrario retorna falso
// Precondicao: o arquivo deve estar aberto em f e ser valido para leitura
bool read_tmp_file(FILE* f,Type* key) {
	if(fscanf(f, "%s %d %d\n",key->word,&(key->document),&(key->position) ) > 0 )
		return true;
	return false;
}

// Escreve o conteudo de aux no formato definido para um index no arquivo f
// Precondicao: o arquivo deve estar aberto em f e ser valido para escrita
void write_index_file(FILE *f,Type key, int frequency) {
	fprintf(f, "%s,%d,%d,%d\n",key.word,key.document,frequency,key.position);
}

// Escreve o conteudo de aux no formato definido para um aruivo temporario em f
// Precondicao: o arquivo deve estar aberto em f e ser valido para escrita
void write_output_file(FILE* f, Type key) {
	fprintf(f, "%s %d %d\n",key.word,key.document,key.position );
}

// Recebe o diretorio onde index deve estar e numero do ultimo arquivo criado
// que ja esta totalmente ordenado e contem todas as palavras de todas conversas
// Calcula  a frequencia de cada palavra em cada arquivo e escreve todos os registros
// com suas frequencias no arquivo final index no diretorio definido em out_dir
void create_index(char* out_dir, int last_file) {

	FILE *input,*output;
	char in_dir[10];
	int pos_input;
	int frequency;
	Type aux1,aux2;
	strcpy(in_dir,"./tmp/\0");
	
	open_intput_file(in_dir,&input,last_file);
	open_index_file(out_dir,&output);
	
	while(read_tmp_file(input,&aux1) ) {
	
		// Salva a posicao em que a proxima palavra comeca
		pos_input = ftell(input);
		frequency = 1;
	
		while( read_tmp_file(input,&aux2)) {
			
			// Se a proxima palavra for igual, aumenta a frequecia da palavra
			// e le proxima. Caso contrario sai do loop
			if(aux1.document == aux2.document && strcmp(aux2.word,aux1.word) == 0)
				frequency++;
			else
				break;
	
		}
		
		// Escreve a primeira palvra no index e volta pra posicao salva
		write_index_file(output,aux1,frequency);
		fseek(input,pos_input,SEEK_SET);
		
		// Para a quantidade de palavra iguas encontradas, le e as escreve no index
		for(int i = 1;i < frequency;i++) {
	
			read_tmp_file(input,&aux2);
			write_index_file(output,aux2,frequency);
	
		}
	}
	
	fclose(input);
	fclose(output);

}

// Recebe o numero de arqivos criado pela rodada inicial alem da quantidade de registros
// que cabem na memoria
// Os registros dentro dos arquivos precisam estar ordenados
// Junta os registros dos arquivos em um arquivo e retorna o numero do ultimo arquivo criado
// que contem todos os registros ordenados
// Precondicao: Deve haver um diretorio chamado tmp na root do problema
int merge_files(int file_number,int key_number) {

	FILE** in;
	FILE* out;
	Type aux;
	char dir[13];
	
	strcpy(dir,"./tmp/\0");
	int sort_order = min(file_number,key_number,FOPEN_MAX - 1);
	
	priority_queue queue = new_priority_queue(sort_order);
	int i;
	in = malloc(sizeof(FILE**)*sort_order);
	
	// Enquanto nao houver somente um arquivo nao lido
	// O numero de arquivos totais aumenta e quando sobra somente um arquivo 
	// Este e o arquivo final com todos registros ordenados

	for(int read_files = 0;file_number - read_files > 1;) {

		// Abre sort_order arquivos temporarios ou ate acabar os arquivos nao lidos
		// e le primeiro registro de cada arquivo
		for(i = 0;i < sort_order && read_files < file_number;i++ ) {
	
			read_files++;
			open_intput_file(dir,&(in[i]),read_files);
			read_tmp_file(in[i],&aux);
			fill(aux,queue,i);

		}
	
		// Como a funcao fill nao constroi um heap, deve-se estabelcer a propiedade na fila
		sort_queue(queue);
		file_number++;
		open_output_file(dir,&out,file_number);
	
		while(!empty(queue) ) {
	
			aux = top(queue);
			write_output_file(out,aux);
			
			// Pega o registro com menor valor da fila e o troca com o proximo registro
			// de seu arquivo origem
			// Caso n tenha mais registros a serem lidos no arquivo, somente retira esse resgistro
			// da fila, tornando o arquivo inativo.
			if(read_tmp_file(in[top_flag(queue)],&aux) )
				switch_top(aux,queue,top_flag(queue));
			else
				pop(queue);
	
		}
		for(i--;i >= 0 ;i-- ) {
	
			fclose(in[i]);
	
		}
	
		fclose(out);	
	}

	free(in);
	delete_priority_queue(queue);
	return file_number;

}

// Recebe o diretorio onde estao as conversas, o numero de conversas e a quantidade de registros
// que cabem na memoria
// le as palavras de todas as conversas e as colocam ordenadas em varios arquivos temporarios
// Retorna a quantidade de arquivos criados
// Precondicao: Deve haver um diretorio chamado tmp na root do problema
int initial_run(char* entry_dir, int docs, int key_number) {
	int i;
	char out_dir[13];
	strcpy(out_dir,"./tmp/\0");
	int file_number = 1;
	FILE* entry = NULL;
	FILE* out;
	Type aux;

	priority_queue queue = new_priority_queue(key_number);
	
	// Le registros dos arquivos ate preencher a fila
	for(i = 1; i <= docs && size(queue) < key_number; i++) {
		open_intput_file(entry_dir,&entry,i);
	
		while(size(queue) < key_number && read_input_file(entry,i,&aux)) {
	
			fill(aux,queue,file_number);
	
		}
	
		// Caso ainda a fila n estaja cheia e saiu do loop
		// Abre um novo arquivo
		if(size(queue) < key_number){
	
			fclose(entry);	
	
		}

	}

	// Como a funcao fill nao constroi um heap, deve-se estabelcer a propiedade na fila
	sort_queue_flag(queue);
	i--;
	open_output_file(out_dir,&out,file_number);
	
	// Enquanto todos os arquivos nao forem lidos
	for(;i <= docs;) {
		
		while(read_input_file(entry,i,&aux) > 0) {
			write_output_file(out,top(queue));
		
			// Caso o registro lido for menor que o top da fila
			// Este sera colocado no proximo arquivo
			// Para isso, coloca a file_number + 1, assim, este sempre sera considerado
			// maior que aqueles registro com file_number menor
			if(compare_key(aux,top(queue)) < 0 ) {
				switch_top_flag(aux,queue,file_number + 1);
			}
		
			else {
				switch_top_flag(aux,queue,file_number);
			}

			// Caso o topo da fila seja um registro com file_number maior
			// Deve-se abrir um novo arquivo de saida
			if(top_flag(queue) > file_number) {
		

				file_number++;
				fclose(out);
				open_output_file(out_dir,&out,file_number);
			
			}

		}

		fclose(entry);
		i++;
		if(i <= docs) {
			open_intput_file(entry_dir,&entry,i);
			aux.document = i;
		}
	}

	// Como ja leu todos os registros dos arquivos, coloca os que ainda restam na fila em um arquivo
	while(!empty(queue)) {

		// Caso o topo da fila seja um registro com file_number maior
		// Deve-se abrir um novo arquivo de saida
		if(top_flag(queue) > file_number) {

			file_number++;
			fclose(out);
			open_output_file(out_dir,&out,file_number);
			
		}

		write_output_file(out,top(queue));
		pop_flag(queue);
	}
	fclose(out);
	delete_priority_queue(queue);


	return file_number;
}


// Recebe o diretorio de se encontra as conversas, numero de converso e a quantidade de 
// Registro que cabem na memoria
// Ordena as conversas em entry e colocas em um arquivo em tmp
// Retorna o numero do ultimo arquivo criado contendo todas os registros ordenados
int external_sorting(char* entry, int docs, int key_number) {

	int number_of_files = initial_run(entry, docs, key_number);
	number_of_files = merge_files(number_of_files,key_number);
	return number_of_files;
}

// Recebe o diretorio onde estao as conversas, o diretorio onde o indice deve ser criado
// o numero de conversas e a quantidade de memoria
// Ordena as conversas que ha em entry e cria um indice invertido
// em out
void inverted_index(char* entry,char* out, int docs, int memory) {

	// Como o tamnhado do registro utilizado na fila e 32, o numero maximo de registro
	// e a memoria disponivel dividada por 32
	int key_number = memory/32;
	int number_of_files = external_sorting(entry,docs,key_number);
	create_index(out,number_of_files);
}
