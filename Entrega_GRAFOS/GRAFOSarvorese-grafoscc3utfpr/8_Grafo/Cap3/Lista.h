#include "TAD_ListaLinear.h"

#include "Operacoes/0_structs.h"

#include "Operacoes/1_criarLista.h"
#include "Operacoes/1_1_criarListaComTamanho.h"

#include "Operacoes/2_incluirInfo.h"
#include "Operacoes/2_1_incluirInfoInicio.h"
#include "Operacoes/2_2_incluirInfoMeio.h"
#include "Operacoes/2_3_incluirInfoOrdenada.h"

#include "Operacoes/3_excluirInfo.h"
#include "Operacoes/3_1_excluirInfoPos.h"

#include "Operacoes/4_contemInfo.h"

#include "Operacoes/5_imprimirLista.h"

#include "Operacoes/6_destruirLista.h"

#include "Operacoes/6_2_destruirListaInfo.h"

#include "Operacoes/7_duplicarLista.h"

#include "Operacoes/8_dividirLista.h"

#include "Operacoes/13_unirListas.h"

#include "Operacoes/9_buscarNohInfo.h"

#include "Operacoes/10_buscarInfoPos.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#ifdef _WIN32
#include <conio.h>
#else
#define getch() getchar()
#endif