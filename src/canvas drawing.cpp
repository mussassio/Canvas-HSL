/*********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         10/2007
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 5
/*********************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <ostream>
#include <cmath>


#include "gl_canvas2d.h"
#define DIM_TELA 600

using namespace std;



float x_g,y_g, x2_g, y2_g = 0;

    class ponto{

        public:
           float pointsize;

           ponto(){
           }
           ponto (ponto (*functocall)(ponto,ponto,float));
           ponto(int x, int y){
                this->x = x;
                this->y = y;
            }
            ponto(int x, int y,float tam){
                this->x = x;
                this->y = y;
                this->pointsize = tam;
            }
            void operator=(const ponto& p1){
                this->x = p1.x;
                this->y = p1.y;
            }
          ponto operator+(const ponto& p1){
                return ponto(this->x + p1.x, this->y + p1.y);
            }
           ponto operator*(float a){
                return ponto(a * this->x, a * this->y);
            }
            ponto operator*(int a){
                return ponto(a * this->x, a * this->y);
            }
             ponto operator*(double a){
                return ponto(a * this->x, a * this->y);
            }
            void operator+=(ponto p0){
                (*this) = (*this) + p0;
            }
            bool operator==(ponto p0){
                if(p0.x == this->x && p0.y == this->y)
                    return true;
                else return false;
            }
            bool DentroDaClickArea(ponto click){
                if((click.x <= this->x + (this->pointsize/2) && click.x >= this->x - this->pointsize/2) &&  (click.y  <= this->y + this->pointsize/2 && click.y >= this->y - this->pointsize/2 ))
                    return true;
                else return false;
            }
            float get_x(){
                return this->x;
            }
            float get_y(){
                return this->y;
            }


        private:
        float x;
        float y;
    };


std::ostream& operator<<(std::ostream& out, ponto p1){
     return out <<"("<<p1.get_x()<<","<<p1.get_y()<<")"<<endl;
}

class Cor{
    public:
        Cor(){}
        Cor(float r, float g, float b){
            this->r = r;
            this->g = g;
            this->b = b;
        }
        inline float  get_r(){
            return this->r;
        }
        inline float get_g(){
            return this->g;
        }
        inline float get_b(){
            return this->b;
        }
        void operator=(const Cor& c1){

            this->r = c1.r;
            this->g = c1.g;
            this->b = c1.b;
        }

    private:

        float r;
        float g;
        float b;

    };

    std::ostream& operator<<(std::ostream& out, Cor c1){
        return out <<"("<<c1.get_r()<<","<<c1.get_g()<<","<<c1.get_b()<<")";
    }



class CaixaCor{
    public:
        CaixaCor(){}
        CaixaCor(ponto p1, Cor c1){
            this->p0 = p1;
            this->c0 = c1;
        }
        void print(){
            cout<<"Cor = "<<c0<<endl;
            cout<<"ponto = "<<p0<<endl;
        }
    private:
        ponto p0;
        Cor c0;
    };

ponto BotaoMouse(0,0,5.0f);
// GLOBAIS
vector<ponto> Pontos;

void desenhaEixos(){
    line(0,DIM_TELA/2,DIM_TELA,DIM_TELA/2);
    line(DIM_TELA/2,DIM_TELA,DIM_TELA/2,0);
}


void MouseDrag(int x, int y){
    x_g = x;
    y_g = y;
}

void render()
{
    Cor c1(1.0,1.0f,1.0f);
    ponto p1(200,200);
    CaixaCor quad(p1,c1);
    quad.print();


}


//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   switch(key)
   {
      case 27:
          exit(0);
	  break;
   }
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y)
{
    static bool pressionadoEsquerdo =  false;
    static bool pressionadoDireito =  false;
    static bool SelecionadoPontoDeControle = false;

    y = DIM_TELA - y;

    switch(state){
    }
}

int main(void)
{
   initCanvas(DIM_TELA, DIM_TELA);
   runCanvas();
}
