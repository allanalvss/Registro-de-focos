#include "local.h"

local::local()
{

}

local::local(QString nome, float quant)
{
    bairro=nome;
    quantidade=quant;

}

QString local::getbairro() const
{
    return bairro;
}

void local::setbairro(const QString &value)
{
    bairro=value;
}

int local::getquantidade() const
{
    return quantidade;
}

void local::setquantidade(int value)
{
    quantidade=value;
}

QString local::getrisco()
{
    QString sit;
    if(getquantidade()>50){
        sit="Alto";
    }
    if(getquantidade()>20 and getquantidade()<50){
        sit="Médio";
    }
    else if(getquantidade()<=20) sit="Baixo";
    return  sit;
}



