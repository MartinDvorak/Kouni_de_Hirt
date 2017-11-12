#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbtab.h"
#include "token.h"


#ifndef OPSTR
typedef struct semantic_operation{
	char op;  // what is operation
	int l_convert; // left value need convert
	int r_convert; // right valur need convert
}Toperation;
#endif
#define OPSTR

// vloze pouze build in fce do stromu globalniho
void semantic_insert_build_in();

// convertuje type_vlaue na type
int semantic_id_type_convert(int type);

// prevede char na #define hodnotu 'i' -> INTEGER
int semantic_convert_data_type (char c);

// promenou v tokenu vezme najde ve stromu - neni err
// a pote porovna s datovym typev c char data_type
// indikuje implicitni konverze
int semantic_id(Ttnode_ptr root, TToken* t, char data_type);

// stejne jako semantic_id akorat vstup je string param a pohybuje se pomoci position
int semantic_id_param(TToken *t, char* param, int* position);

// nalezne jestli existuje fce a tomom vrátí jeji parametry v  char*param
int semantic_fce_param(Ttnode_ptr root, TToken* t, char* param);

// vlozi pokud neexistuje jinak false
int semantic_insert(Ttnode_ptr* root, char* name, Tdata* data);

// false neexistuje, v typu bude hodnota type promene
int semantic_id_type(Ttnode_ptr root,TToken* t,int* type );

// local find id
int semantic_find_id(TToken* t);

// kouka jeslti jsou nejake funkce ktere nejsou definovane ale jsou volane (volane s deklaraci)
int semantic_call_undefined_fce();

// string - postfix notace, type array - dat. typy promennych,, arr - pole struct promennych, num_of_arr - pocet vyslednych prvku
// zkontroluje dat type a pretypuje popripade promenne
int semantic_exp(char* string, int* type_array, Toperation* arr, int* num_of_arr, int* exp_ret);


int semantic_check_lside_rside(int l_side, int r_side);

void semantic_return_type(int glob_var,int local,int ret_type);