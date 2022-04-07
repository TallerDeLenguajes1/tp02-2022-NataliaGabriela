#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define CANTIDAD 5
struct compus{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
};
typedef struct compus compu;
//funciones 
compu cargarpc(compu pc,char *tipo);
compu cargarpuntero(compu *p,char *tipo);
void mostrarpc(compu *p);
void mostrarlistapc(compu *p);
void pcmasvieja(compu *p);
void mayorvelocidad(compu *p);
int main(){
    srand(time(NULL));
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"},*tipo=tipos[0];
    fflush(stdin);
    compu pc,arre_pc[CANTIDAD],*p_pc=arre_pc;
    //cargar datos
    pc=cargarpc(pc,tipo);
    //cargar puntero
    *p_pc=cargarpuntero(p_pc,tipo);
    mostrarlistapc(p_pc);
    printf("\n---------------------------\n");
    //fflush(stdin);
    //PC mas vieja
    pcmasvieja(p_pc);
    printf("\n---------------------------\n");
    //PC mas rapida
    mayorvelocidad(p_pc);
    scanf(" %c");
    return 0;
}
compu cargarpc(compu pc,char *tipo){
    
    pc.velocidad=1 + rand() % (3-1);
    pc.anio=2015 + rand() % (2022-2015);
    pc.cantidad=1 + rand() % (8-1);
    pc.tipo_cpu=tipo+ ( rand ()% 6 * 10 );
    
    return pc;
}
compu cargarpuntero(compu *p,char *tipo){
    compu pc;
    for ( int i = 0; i < CANTIDAD; i++)
    {
        *(p+i)=cargarpc(pc,tipo);
        
    }
   return *p;

}
void mostrarpc(compu *p){
    printf("Velocidad: %d\n",p->velocidad);
    printf("Anio: %d\n",p->anio);
    printf("Cantidad: %d\n",p->cantidad);
    printf("Tipo de CPU: %s",p->tipo_cpu);
    printf("\n\n");
}
void mostrarlistapc(compu *p){
    int i;
    for ( i = 0; i < CANTIDAD; i++)
    {
       mostrarpc(p+i);
    }   
}
void pcmasvieja(compu *p){
      int i,min=2022,aux1,j,aux;
    for ( i = 0; i < CANTIDAD; i++)
    {
        aux1=(p+i)->anio;
             
        if (aux1<min)
        {   
            min=aux1;                
            //aux=i;
        }
            
    }
    printf("La PC mas vieja es: \n");
    for ( j = 0; j < CANTIDAD; j++)
    {
        if (min==(p+j)->anio)
        {  
         mostrarpc(p+j);
        }
        //p++;
    }    
}
void mayorvelocidad(compu *p){
    int i,max=0,aux,aux1,j;
    for ( i = 0; i < CANTIDAD; i++)
    {
            aux1=(p+i)->velocidad;
             
            if (aux1>max)
            {   
                max=aux1;
                //aux=i;
            }
            
    }
    printf("La PC mas veloz es: \n");
    for ( j = 0; j < CANTIDAD; j++)
    {
        if (max==(p+j)->velocidad)
        {
        mostrarpc(p+j);
        }
        
    }
    
    
}