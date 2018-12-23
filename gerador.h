#ifndef GERADOR_H
#define GERADOR_H

#include <QObject>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<fstream>
#include "local.h"
#include "cidade.h"
#include <QDebug>

class gerador: public QObject
{
    Q_OBJECT
public:
    gerador();
    static bool salvar_cadastro(QString &arquivo,cidade &city);
    static bool carregar_cadastro(QString &arquivo,cidade &city);

signals:

public slots:
};

#endif // GERADORARQ_H
