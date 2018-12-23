#include "gerador_arquivos.h"

geradorarq::geradorarq()
{

}

bool geradorarq::salvar_cadastro(QString &arquivo, cidade &Cidade)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<Cidade.size();i++){
        out<<Cidade[i].getbairro()<<","<<Cidade[i].getquantidade()<<"\n";
    }

    file.close();
    return true;
}


