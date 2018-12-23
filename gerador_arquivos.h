#ifndef GERADORARQ_H
#define GERADORARQ_H

#include <QObject>
#include<QVector>
#include<QFile>
#include<QTextStream>
#include<fstream>
#include "local.h"
#include "cidade.h"
#include <QDebug>

class geradorarq : public QObject
{
    Q_OBJECT
public:
    geradorarq();
    static bool salvar_cadastro(QString &arquivo,cidade &Cidade);
    static bool carregar_turma(QString &arquivo,cidade &cidade);

signals:

public slots:
};

#endif // GERADORARQ_H
