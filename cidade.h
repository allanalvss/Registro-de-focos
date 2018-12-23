#ifndef CIDADE_H
#define CIDADE_H

#include <QObject>
#include <local.h>
#include <QVector>
#include <algorithm>

class cidade : public QObject
{
private:
    QVector<local>Cidade;
    Q_OBJECT
public:
    explicit cidade(QObject *parent = nullptr);
    void inserirbairro(const local a);
    float media_de_focos();
    void setBairro(int index,QString value);
    void setQuants(int index, int num);
    QString maior_risco();
    QString menor_risco();
    local getloc(int i);
    void ordernarname();
    void ordenar_quantidade();
    local operator[](int i);
    int size();

signals:

public slots:
};

#endif // CIDADE_H
