#ifndef LOCAL_H
#define LOCAL_H

#include <QObject>
#include <QVector>

class local
{
private:
    QString bairro;
    float quantidade;
    QString risco;
public:
    explicit local();
    local(QString nome, float quant);
    QString getbairro() const;
    void setbairro(const QString &value);

    int getquantidade()const;
    void setquantidade(int value);

    QString getrisco();

signals:

public slots:
};

#endif // LOCALH_H
