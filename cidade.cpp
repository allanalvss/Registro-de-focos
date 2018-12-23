#include "cidade.h"

bool compar(local a, local b){
    return a.getquantidade()<b.getquantidade();
}

bool compar_name(local a, local b){
    return a.getbairro()<b.getbairro();
}

cidade::cidade(QObject *parent){

}


void cidade::inserirbairro(const local a)
{
    Cidade.push_back(a);
}

float cidade::media_de_focos()
{
    float quants=0;
    int tam=Cidade.size();
    for(int i=0;i<Cidade.size();i++){
        quants+=Cidade[i].getquantidade();
    }
    return quants/tam;
}

void cidade::EditBairro(int index, QString value)
{
    Cidade[index].setbairro(value);
}

void cidade::EditQuants(int index, int num)
{
    Cidade[index].setquantidade(num);
}


QString cidade::maior_risco()
{
    local *maior = std::max_element(Cidade.begin(),Cidade.end(),compar);
    return maior->getbairro();
}

QString cidade::menor_risco()
{
    local *menor = std::min_element(Cidade.begin(),Cidade.end(),compar);
    return menor->getbairro();
}

local cidade::getloc(int i)
{
    return Cidade[i];
}

void cidade::ordernarname()
{
    std::sort(Cidade.begin(), Cidade.end(),compar_name);
}

void cidade::ordenar_quantidade()
{
    ordernarname();
    std::stable_sort(Cidade.begin(),Cidade.end(),compar);
}

local cidade::operator[](int i)
{
    return Cidade[i];
}

int cidade::size()
{
    return Cidade.size();
}




