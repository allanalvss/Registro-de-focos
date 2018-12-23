#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QDebug>
#include <QVector>
#include<QFileDialog>
#include <QDialog>
#include <QMessageBox>
#include "local.h"
#include "cidade.h"
#include "gerador.h"
#include "QFile"
#include <QInputDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    cidade city2;
    cidade jp;
    local *bairros;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void atualizarEstatisticas();
    ~MainWindow();

private slots:
    void on_ins_button_clicked();

    void on_ord_button_clicked();

    void on_ord2_button_clicked();

    void on_actionSalvar_triggered();



    void on_actionCarregar_dados_triggered();


    void on_tbl_data_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void insert_cadastro(local loc,int row);
};

#endif // MAINWINDOW_H
