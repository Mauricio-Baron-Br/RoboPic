/*******************************************************************************
*Produzido Por Mauricio Baron                                                  *
*Data: 11/10/2020                                                              *
*Versao:1                                                                      *
*Descrisa;                                                                     *
*Firmware produzido para o aprendizado de programa��o de micro controladores,  *
*sua c�pia e distribui��o bem como sua altera��o esta permitada d�s de que     *
*seja feita a refer�ncia ao seu criador.                                       *
*Rob� Pic micro controlado e com sensor de toque, baseado no rob� de mesmo nome* 
*que foi publicado na revista Mecatr�nica F�cil n�mero 13 no ano de 2003,      *
*seu criador Marcio Jose Soares                                                *
*******************************************************************************/
#include <16F628A.h>
#fuses XT, NOMCLR, NOWDT
#use delay(clock=4MHz, crystal=4MHz)

#define direita PIN_A1
#define esquerda PIN_A2


//Funcoes de acionamento dos motores
void FunFrente(){
     output_b(0b01011101);  
     output_bit(direita,0);
     output_bit(esquerda,0);
}
void FunRe(){
    output_b(0b10101110); 
    output_bit(direita,0);
    output_bit(esquerda,0);
    
}
void FunDireita(){
    output_b(0b00000101); 
    output_bit(direita,1);
     
}
void FunEsquerda(){
    output_b(0b00011000); 
    output_bit(esquerda,1);

}


void main(){

    int1 btnDireita;
    int1 btnEsquerda;
  
    while(true){
     
        btnDireita = input(PIN_A3);
        btnEsquerda = input(PIN_A4);
       
        FunFrente();
       
        if(btnDireita == 0 ){
            FunRe();
            delay_ms(1000);
            FunDireita();
            while(input(PIN_A3) == 0);
        }
        if(btnEsquerda == 0 ){
           FunRe();
           delay_ms(1000);
           FunEsquerda();
            while(input(PIN_A4) == 0);
        }
        }
    }
