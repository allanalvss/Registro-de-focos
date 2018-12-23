#include "gerador.h"


gerador::gerador()
{

}

bool gerador::salvar_cadastro(QString &arquivo, cidade &city)
{

    QFile file(arquivo);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<city.size();i++){
        out<<city[i].getbairro()<<","<<city[i].getquantidade()<<"\n";
    }

    file.close();
    return true;
}

bool gerador::carregar_cadastro(QString &arquivo, cidade &city)
{
    QFile file(arquivo);

       if(!file.open(QIODevice::ReadOnly)){
           return false;
       }

       QTextStream in(&file);

       QString linha;

       while(!in.atEnd()){
           linha = in.readLine();

           QStringList dados = linha.split(",");

           local a(dados[0],dados[1].toFloat());
           city.inserirbairro(a);

       }
       return true;
}
